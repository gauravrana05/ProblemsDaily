n,m = map(int,input().split())
aa = [0]
aa.extend(list(map(int,input().split())))
aa_pos = [0]*(n+1)


for i in range(n+1):
    aa_pos[aa[i]] = i

count = 1
for i in range(1,n):
    count += aa_pos[i]>aa_pos[i+1]

res = []
for _ in range(m):
    check = set()
    l,r = map(int,input().split())
    if aa[l]+1 <= n:
        check.add((aa[l],aa[l]+1))
    if aa[l]-1 >= 1:
        check.add((aa[l]-1,aa[l]))
    if aa[r]+1 <= n:
        check.add((aa[r],aa[r]+1))
    if aa[r]-1 >= 1:
        check.add((aa[r]-1,aa[r]))
    #checking
    for i in check:
        count -= aa_pos[i[0]]>aa_pos[i[1]]
    #swapping
    aa[l],aa[r] = aa[r],aa[l]
    aa_pos[aa[l]] = l
    aa_pos[aa[r]] = r
    #checking
    for i in check:
        count += aa_pos[i[0]]>aa_pos[i[1]]
    res.append(count)

for i in res:
    print(i)


    




