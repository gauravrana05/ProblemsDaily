n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i,j,k = 0,0,0
c = [0] * (n + m)

while i < len(a) or j < len(b):
    if j == len(b) or (i < len(a) and a[i] < b[j]):
        c[k] = a[i]
        i += 1
    else:
        c[k] = b[j]
        j += 1
    k += 1

for i in c:
    print(i)
