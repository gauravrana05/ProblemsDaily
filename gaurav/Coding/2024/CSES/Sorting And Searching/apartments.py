[n, m , k] = list(map(int, input().split()))

desSizes = list(map(int, input().split()))

aprtSizes = list(map(int, input().split()))


ans = 0;
desSizes.sort();
aprtSizes.sort();

itrA = 0;
itrD = 0;
while( itrA < m and itrD < n):
    if(aprtSizes[itrA] >= desSizes[itrD] - k and aprtSizes[itrA] <= desSizes[itrD] + k ):
        ans+=1;
        itrA+=1;
        itrD+=1;
    elif(aprtSizes[itrA] < desSizes[itrD] - k):
        itrA+=1;
    else:
        itrD+=1;
print(ans)