import os
import re
import sys

def write_file(code: str, file_path: str) -> None:
    os.makedirs(os.path.dirname(file_path), exist_ok=True)
    with open(file_path, 'w', encoding='utf-8') as f:
        f.write(code)
    print(f"Successfully generated: {file_path}")

def parse_signature(raw_code: str):
    # Strip C++ comments
    cleaned = re.sub(r'//.*?\n', '', raw_code)
    cleaned = re.sub(r'/\*.*?\*/', '', cleaned, flags=re.DOTALL)

    # Strip access specifiers (public:, private:, protected:)
    cleaned_no_access = re.sub(r'\b(public|private|protected)\s*:', '', cleaned)

    # Match function definition anywhere in the snippet
    match = re.search(r'([\w:<>\s*&]+)\s+([a-zA-Z_]\w*)\s*\(([^)]*)\)', cleaned_no_access)
    if not match:
        raise ValueError("Could not parse a valid C++ function signature from input.")

    ret_type = match.group(1).strip()
    func_name = match.group(2).strip()
    params_str = match.group(3).strip()

    params = []
    if params_str:
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

        for p in raw_params:
            p_match = re.search(r'^(.*?)\s*([a-zA-Z_]\w*)$', p)
            if p_match:
                p_type = p_match.group(1).strip()
                p_name = p_match.group(2).strip()
                params.append((p_type, p_name))

    # Filter out duplicate struct definitions if pasted from LeetCode
    filtered_lines = []
    skip = False
    for line in raw_code.splitlines():
        if re.search(r'struct\s+(TreeNode|ListNode)\s*\{', line):
            skip = True
        if not skip:
            filtered_lines.append(line)
        if skip and line.strip() == "};":
            skip = False

    return ret_type, func_name, params, "\n".join(filtered_lines)

def clean_type_for_struct(type_str: str) -> str:
    clean = re.sub(r'\b(const|public|private|protected)\b', '', type_str)
    clean = clean.replace(':', '').replace('&', '').strip()
    return clean

def build_code():
    q_num = input("Enter q number:\n").strip()
    if not q_num.startswith('q'):
        q_num = 'q' + q_num

    date_folder = input("Enter date:\n").strip()
    target_path = os.path.join(date_folder, f"{q_num}.cpp")

    # Guard: check if file already exists
    if os.path.exists(target_path):
        print(f"File '{target_path}' already exists! Aborting.")
        sys.exit(0)

    print("Enter leetcode starter function (end input with '};' on a new line):")
    lines = []
    while True:
        line = input()
        lines.append(line)
        if line.strip() == "};":
            break

    raw_input = "\n".join(lines)
    ret_type, func_name, params, cleaned_leetcode_code = parse_signature(raw_input)

    is_void = (ret_type == "void")
    result_type = clean_type_for_struct(params[0][0]) if is_void and params else clean_type_for_struct(ret_type)

    struct_fields = []
    arg_names = []
    for p_type, p_name in params:
        st_type = clean_type_for_struct(p_type)
        struct_fields.append(f"    {st_type} {p_name};")
        arg_names.append(f"data.{p_name}")

    struct_fields.append(f"    {result_type} ans;")
    struct_fields.append(f"    {result_type} res;")
    struct_body = "\n".join(struct_fields)

    args_str = ", ".join(arg_names)
    solve_call = f"s.{func_name}({args_str});"

    if is_void:
        first_param_name = params[0][1] if params else "data"
        handle_body = f"    {solve_call}\n    data.res = data.{first_param_name};"
    else:
        handle_body = f"    data.res = {solve_call}"

    cpp_template = f"""#include "../timer.h"

{cleaned_leetcode_code}

struct token {{
{struct_body}
}};

void handle(token& data) {{
    Solution s;
{handle_body}
}}

void runTests(vector<token>& tokens) {{
    cout << '\\n';
    for(token& t : tokens) {{
        handle(t);
        cout << "Output:   ";
        display(t.res);
        cout << "\\nExpected: ";
        display(t.ans);
        cout << "\\n\\n";
    }}
}}

int main() {{
    const int n = 1;
    vector<token> tokens;
    tokens.push_back({{}});

    auto start = high_resolution_clock::now();
    runTests(tokens);
    auto end = high_resolution_clock::now();

    showRunTime(start, end);
}}
"""
    write_file(cpp_template.strip(), target_path)

if __name__ == "__main__":
    build_code()
