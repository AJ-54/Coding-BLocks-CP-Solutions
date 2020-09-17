string = input()
if string[0] == 'x':
    inp1,inp2 = string[2:].split("=")
    inp1 = int(inp1)
    inp2 = int(inp2)
    print(inp2-inp1)
elif string[-1] == 'x':
    inp1,inp2 = string[:len(string)-2].split("+")
    inp1 = int(inp1)
    inp2 = int(inp2)
    print(inp2+inp1)
else:
    inp1,inp2 = string.split("+")
    inp2 = inp2[2:]
    inp1 = int(inp1)
    inp2 = int(inp2)
    print(inp2-inp1)

