# bitsh.py
# 
# Evaluates Python expressions and pronts the result in various bases
# The promt is of the form "${mode}= ", where "mode" is the system to print
#  numbers with.
# To switch modes, type "mode [b|x|d]" at the prompt.
# Example session:
# 
#   x= 16
#   0xf
#   x= 17
#   0x1f
#   x= mode b
#   b= 2
#   0b10
#   b= 1 << 3
#   0b1000

mode = 'x'
table = {'x': hex, 'b': bin, 'd': str}

def mask(n):
    return ~(~0 << n)

while mode != '=P':
    inp = input(mode + '= ')
    if inp.startswith('mode '):
        mode = inp[5:]
        continue
    elif inp.startswith('set '):
        val = table[mode](eval(inp[6:]))
        exec(inp[5] + '=' + val)
        continue
    print(table[mode](eval(inp)))
