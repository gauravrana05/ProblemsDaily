# author: dqgr
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i, j = 0, 0
ans = 0

while( i < len(a) and j < len(b)):
  if a[i] != b[j] :
    if a[i] < b[j]:
      i+=1
    else:
      j+=1
  else:
    t_i, t_j = 1, 1
    while i < len(a) - 1 and a[i] == a[i+1]:
      t_i += 1
      i += 1
    while j < len(b) - 1 and b[j] == b[j+1]:
      t_j += 1
      j += 1
    ans += t_i * t_j
    i+=1
    j+=1
print(ans)