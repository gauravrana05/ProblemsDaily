s = input()

ans = set()

str = list(s)

def solve( str, l, r, ans):
    
    if(l == r):
        # print(str)
        ans.add("".join(str));
        return;
    
    for i in range(l, r):
        str[i], str[l] = str[l], str[i];
        solve(str, l + 1, r, ans);
        str[i], str[l] = str[l], str[i];

solve(str, 0, len(str), ans);

print(len(ans))
ans = sorted(ans)
for i in ans:
    print(i)