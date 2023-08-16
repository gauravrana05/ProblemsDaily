
n = input()

count = 1;
ans = 1

for c in range(len(n) - 1):
    if(n[c] == n[c + 1]):
        count = count + 1;
    else:
        count = 1;
    if(count > ans):
        ans = count;

print(ans)