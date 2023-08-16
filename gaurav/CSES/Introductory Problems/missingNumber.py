size = int(input())
n = list(map(int, input().split()))

n.sort()

iter = 0;
ans = 0;
while(iter < size - 1):
    if( n[iter] != iter + 1):
        ans = iter + 1;
        break;
    iter = iter + 1;

if(ans == 0):
    ans = size;
print(ans)
