import os
import re

def locate_target_file(date_folder: str, q_num: str) -> str:
    if not q_num.startswith('q'):
        q_num = 'q' + q_num

    potential_path = os.path.join(date_folder, f"{q_num}.cpp")
    if os.path.exists(potential_path):
        print(f"Located file at: {potential_path}")
        return potential_path
    return ""

def determine_char_param_indices(lines: list) -> set:
    """
    Parses the C++ function signature inside the target file to identify
    parameters that expect single character literals (char, vector<char>, etc.).
    """
    code_text = "".join(lines)
    match = re.search(r'([\w:<>\s*&]+)\s+([a-zA-Z_]\w*)\s*\(([^)]*)\)', code_text)
    if not match:
        return set()

    params_str = match.group(3).strip()
    if not params_str:
        return set()

    # Split parameters safely accounting for template brackets like vector<vector<char>>
    raw_params = []
    depth = 0
    current = []
    for char in params_str:
        if char == '<':
            depth += 1
        elif char == '>':
            depth -= 1
        if char == ',' and depth == 0:
            raw_params.append(''.join(current).strip())
            current = []
        else:
            current.append(char)
    if current:
        raw_params.append(''.join(current).strip())

    char_indices = set()
    for idx, p in enumerate(raw_params):
        p_match = re.search(r'^(.*?)\s*([a-zA-Z_]\w*)$', p)
        if p_match:
            p_type = p_match.group(1).strip()
            # If the parameter contains 'char' and not 'string', flag it
            if re.search(r'\bchar\b', p_type) and not re.search(r'\bstring\b', p_type):
                char_indices.add(idx)

    return char_indices

def fix_tokens_line(line: str, char_indices: set) -> str:
    # 1. Convert brackets [ ] -> { }
    line = line.replace('[', '{').replace(']', '}')

    # 2. If no char-based parameters exist, keep quotes intact
    if not char_indices:
        return line

    # 3. Smart quote conversion: convert single-character strings "a" -> 'a'
    def replace_quote(match):
        val = match.group(1)
        if len(val) == 1 or (len(val) == 2 and val.startswith('\\')):
            return f"'{val}'"
        return f'"{val}"'

    return re.sub(r'"([^"\\]*(\\.[^"\\]*)*)"', replace_quote, line)

def replace_in_cpp_file():
    date_folder = input("Enter date folder:\n").strip()
    q_num = input("Enter q number:\n").strip()

    target_path = locate_target_file(date_folder, q_num)

    if not target_path:
        print(f"Error: File for '{q_num}' not found in folder '{date_folder}'.")
        return

    try:
        with open(target_path, 'r', encoding='utf-8') as file:
            lines = file.readlines()

        char_indices = determine_char_param_indices(lines)

        updated_lines = []
        for line in lines:
            if "tokens" in line:
                line = fix_tokens_line(line, char_indices)
            updated_lines.append(line)

        with open(target_path, 'w', encoding='utf-8') as file:
            file.writelines(updated_lines)

        print(f"Successfully updated {target_path}")

    except OSError as e:
        print(f"File operation failed: {e}")

if __name__ == "__main__":
    replace_in_cpp_file()
