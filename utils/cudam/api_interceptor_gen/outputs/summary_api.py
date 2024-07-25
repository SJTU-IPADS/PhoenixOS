import re

filename = "cudnn.cpp"
match_field = 'head'

number = 0

with open(filename, "r") as file:
    for line in file:
        if re.match(rf'^\s*#undef[^\n]*({match_field})[^\n]*', line, re.IGNORECASE):
            print(line)
            number += 1

    print(f'overall: {number}')
