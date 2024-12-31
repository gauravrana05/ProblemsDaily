n = int(input())

a = []

a.extend(list(map(int, input().split())))
# ans = 0;
# count = 0

# store = set()

# i = 0
# j = 0;
# while(i < n):
#     if n[i] not in store:
#         count+=1;
#         ans = max(count, ans)
#         store.add(i)
#     else:
#         j = i;
#         count = 1;
#         store.clear();
#         store.add(i)
#     i+=1;
# print(ans)

map = set()

ans = 0;

i = 0;
j = 0;
while( j < n):
    while(a[j] in map):
        map.remove(a[i]);
        i+=1;
    map.add(a[j])

    ans = max(ans, j - i + 1);

    j+=1;

print(ans)