n = int(input())

a = list(map(int, input().split()))


cSum = 0
mSum = a[0]

st = 0;
while(st < n):

    cSum += a[st];

    mSum = max(cSum, mSum);

    if(cSum < 0):
        cSum = 0;
    st +=1;
print(mSum)