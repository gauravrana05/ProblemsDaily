n, target = list(map(int ,input().split()))
nums = list(map(int, input().split()))
values = []

for i in range(n):
    values.append([nums[i], i + 1])

values.sort()

ans = []
left = 0
right = n - 1

while left < right:
    lr_sum = values[left][0] + values[right][0]
    if lr_sum == target:
        ans.append(str(values[right][1]))
        ans.append(str(values[left][1]))
        break
    elif lr_sum > target: 
        right -= 1
    else:
        left += 1
print(" ".join(ans) if ans else "IMPOSSIBLE")
    
