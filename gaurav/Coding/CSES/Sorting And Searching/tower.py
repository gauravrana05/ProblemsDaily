from bisect import bisect

n = int(input())

a = []
a.extend(list(map(int, input().split())))

# ans = 1; 
# max = a[0]
# i = 1;
# while(i < n):
#     if(a[i] >= max):
#         max = a[i]
#         ans+=1;
#     i+=1

i = 1;
towers = []
towers.append(a[0])

while(i < n):
    itr = bisect(towers, a[i]);

    if(itr < len(towers)):
        towers[itr] = a[i]
    else:
        towers.append(a[i])
    i += 1
print(len(towers))