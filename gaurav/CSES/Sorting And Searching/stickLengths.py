n = int(input())
a = list(map(int, input().split()))

a.sort()

mid = n // 2

ans = 0

st = 0
while(st < mid):
    ans += a[mid] - a[st]; 
    st+=1
n-=1
while(mid < n):
    ans += a[n] - a[mid];
    n -=1 
print(ans)