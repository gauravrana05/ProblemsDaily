[n, x] = list(map(int,input().split()))
a = list(map(int, input().split()))

values = []
for i in range(n):
    values.append([a[i], i+1])

values.sort()
st = 0; 
end = n - 1

while(st < end):
    if(values[st][0] + values[end][0] == x):
        print(values[st][1], values[end][1])
        break
    elif((values[st][0] + values[end][0]) < x):
        st+=1
    else:
        end-=1
if(st >= end):
    print("IMPOSSIBLE")
