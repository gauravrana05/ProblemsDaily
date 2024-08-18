n, x = map(int, input().split())
a = list(map( int, input().split()))

p = [(a[i], i + 1) for i in range(n)]

p.sort()

for i in range(n):
    left = 0
    right = n - 1

    while left < right:
        target = x - p[i][0]

        if left ! = i and right != i and p[left][0] + p[right][0] == target:
            print(p[left][1], p[right][1], p[i][1])
            exit()

        elif p[left][0] + p[right][0] < target:
            left += 1

        else:
            right -= 1
print("IMPOSSIBLE")
