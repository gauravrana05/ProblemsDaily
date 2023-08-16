n = int(input())

sum = n *(n + 1) // 2;

if(sum % 2 != 0):
    print("NO")
else:
    print("YES")

    s1 = []
    s2 = []
    sum1 = 0
    sum2 = 0
    start = n;
    while(start > 0):
        if(sum1 + start <= sum / 2 ):
            s1.append(start);
            sum1 = sum1 + start;
        else:
            s2.append(start);
        start = start - 1; 
    print(len(s1))
    for i in s1:
        print(i, end=" ")
    print("")
    print(len(s2))
    for i in s2:
        print(i, end=" ")

