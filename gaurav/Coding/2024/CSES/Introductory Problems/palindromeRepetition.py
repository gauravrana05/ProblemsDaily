s = input()
n = [0]*26
for i in range(27):
    n.append(0)

for i in s:
    n[ord(i) - 64] += 1

ans = []

count = 0;
for i in n:
    if( i % 2 != 0):
        count += 1;

if(len(s) % 2 != 0 and count > 1 ):
    print("NO SOLUTION")
elif(len(s) %2 == 0 and count > 0):
    print("NO SOLUTION")
else:
    index = 0;
    for i in n:
        if( i != 0 and i % 2 == 0 ):
            temp = i/2;
            while(temp):
                print(chr(index + 64), end = "")
                ans.append(chr(index + 64));
                temp -= 1;
        index += 1
    index = 0;
    for i in n:
        if( i % 2 != 0 ):
            temp = i // 2;
            while(temp > 0):
                print(chr(index + 64), end = "")
                ans.append(chr(index + 64));
                temp -= 1;
            ans.append(chr(index + 64))
        index += 1

for i in reversed(ans): 
    print(i, end = "")
