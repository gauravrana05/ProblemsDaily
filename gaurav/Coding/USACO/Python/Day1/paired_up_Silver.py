import sys

sys.stdin = open("pairup.in", 'r')
sys.stdout = open("pairup.out", 'w')

n = int(input())
all_cows = []

for _ in range(n):
    num_cows, milk_time = map(int, input().split())
    all_cows.append([milk_time, num_cows])

all_cows.sort()
left, right = 0, n - 1

ans = 0

while left <= right:
    sub = min(all_cows[left][1], all_cows[right][1])
    ans = max(all_cows[left][0] + all_cows[right][0])
    if left == right:
        sub /= 2
    all_cows[left][1] -= sub
    all_cows[right][1] -= sub

    if all_cows[left][1] == 0:
        left += 1
    if all_cows[right][1] == 0:
        right -= 1

print(ans)

