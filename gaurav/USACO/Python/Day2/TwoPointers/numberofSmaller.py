#author dqgr
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i,j = 0,0
res = [0] * m 
for j in range(m):
  while i < len(a) and a[i] < b[j]:
    i+=1
  res[j] = i
for i in res:
  print(i, end =" ")
