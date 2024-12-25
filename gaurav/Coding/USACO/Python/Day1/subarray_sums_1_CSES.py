n, x = map(int, input().split())
arr = list(map(int, input().split()))

i = 0
j = 0

sum, res = 0, 0

while j < n:
    sum += arr[j]
    while sum > x:
        sum -= arr[i]
        i += 1
    res += sum == x
    j += 1

print(res)

