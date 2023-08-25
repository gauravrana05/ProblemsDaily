n = int(input())

x = list(map(int, input().split()))

x.sort()

ans = 1
st = 0;

while(st < n):

    if(ans < x[st] ):
        break
    else:
        ans += x[st]
    st+=1;

print(ans)