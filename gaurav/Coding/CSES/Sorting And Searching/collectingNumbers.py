n = int(input())

a = list(map(int, input().split()))

list  = []

for i in range(len(a)):
    list.append([a[i],i])

ans = 1
list.sort()
for i in range(n - 1):
    if(list[i][1] > list[i+1][1]):
        ans+=1;
print(ans)