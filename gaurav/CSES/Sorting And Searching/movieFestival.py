n = int(input())

events = []

for i in range(n):
    val = list(map(int, input().split()))
    events.append(val)

events.sort(key = lambda x: x[1])

ans = 0
end = 0;

for i in events:
    if( i[0] >= end):
        ans+=1
        end = i[1]

print(ans)
