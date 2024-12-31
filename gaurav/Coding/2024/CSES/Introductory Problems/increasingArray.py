size = int(input())

n = list(map(int, input().split()))

ans = 0;
for i in range(size):
    if(i > 0):
        if(n[i] > n[i-1]):
            continue;
        else:
            ans = ans + n[i - 1] - n[i];
            n[i] = n[i - 1]; 

print(ans)
