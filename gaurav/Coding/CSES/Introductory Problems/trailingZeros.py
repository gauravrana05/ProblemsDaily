n = int(input())

ans = 0
while(n):
    ans += n //5;
    n = n // 5;
print(ans)