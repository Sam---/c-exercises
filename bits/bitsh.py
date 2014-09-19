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
