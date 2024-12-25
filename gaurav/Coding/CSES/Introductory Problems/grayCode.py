n = int(input())


def printCode(item, code):
    
    if(item == 0):
        return;
    last = item & 1;
    # print("last",last, item, item and 1)
    item = item >> 1;
    prev = item & 1;

    if(prev == 0):
        code.insert(0,last);
    else:
        # print("bro perv is 1", last)
        code.insert(0,1 - last);
    printCode(item, code);

i = 0;
while(i < 2 ** n):
    if(i < 2):
        temp = n - 1;
        while(temp):
            print(0, end="")
            temp -= 1;
        print(i, end ="")
        print("")
        i += 1;
        continue
    
    code = []
    printCode(i, code);

    while(len(code) != n):
        code.insert(0,0);
    for j in code: 
        print(j, end = '')
    print("")
    i += 1