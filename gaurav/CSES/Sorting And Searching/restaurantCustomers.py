# n = int(input())

# time = []

# for i in range(n):
#     [st, end] = list(map(int, input().split()))
#     time.append([st,1]);
#     time.append([end,-1]);

# time.sort()

# ans = 0;

# count = 0; 
# for i in time:
#     count += i[1]
#     ans = max(ans, count)
# print(ans)


# tmap = dict()
# times = []
# for _ in range(int(input())):
#     [st, end] = list(map(int,input().split()))
#     tmap[st] = 1;
#     tmap[end] = -1;
#     times.append(st);
#     times.append(end);
# times.sort()

# ans = 0;
# count = 0;

# for i in times:
#     count += tmap[i]
#     ans = max(count, ans)
# print(ans)

n = int(input())

arrival = []
leave = []

for i in range(n):
    [x, y] = list(map(int,input().split()))
    arrival.append(x)
    leave.append(y)

arrival.sort()
leave.sort()

# print(arrival, leave)
ma = 0
current = 0
i , j = 0,0

while i < n and j < n:
    if arrival[i] < leave[j]:
        current +=1
        # print(current)
        i += 1
    else:
        current -=1
        j +=1

    if ma < current:
        ma = current
        # print(ma)


print(ma)