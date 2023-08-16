size  = int(input())
n = list(map(int, input().split()))

n.sort()
n.append(-1)
ans = 0;
# print(n, len(n))
for i in range(0, len(n) - 1):
    # print(i)
    if(n[i] == n[i + 1] ):
        continue;
    # print(ans)
    ans += 1;
print(ans);