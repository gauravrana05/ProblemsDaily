n, m = map(int, input().split())

p = list(map(int, input().split()))

light =[False] * (n + 1)

for i in p:
    light[i] = True;

    i = 0; 
    j = 0;
    ans = 1;
    while(i < n + 1):
        while(j < n and not light[j] ):
            j += 1
        
        ans = max(ans, j - i)
        if(j == n):
            break;
        i = j
        j +=1
    
    print(ans, end = " ")
        
        

