import math
n = int(input())

arr = list(map(int, input().split()))

# tsum = 0;

# for i in arr:
#     tsum += i;

# mid = tsum // 2;
# print("Bro I'm the mid", mid)
# arr.sort()
# print(arr)
# ans = math.inf
# l = 0;
# r = 0;
# sum = 0;
# while(r < n):
#     if(sum < mid):
#         print("updating sum to", sum + arr[r])
#         sum += arr[r];
#         print("updating Answer to min of ", ans, (tsum - sum) - sum )
#         ans = min(ans, abs((tsum - sum) - sum) )
#         r+=1;
#     elif( sum == mid):
#         ans = 0;
#         break;
#     else:
#         print("updating Answer to min of ", ans, sum - (tsum - sum) )
#         ans = min(ans, abs(sum - (tsum - sum)) )
#         sum -= arr[l];
#         l+=1;
# print(ans)

def solve(i, lefSum, rigSum):
    if(i == n):
        return abs(lefSum - rigSum)
    
    return min(solve(i+1, lefSum + arr[i], rigSum), solve(i+1, lefSum, rigSum + arr[i]));

ans = solve( 0, 0 , 0);

print(ans);
