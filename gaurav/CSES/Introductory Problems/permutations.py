
from collections import deque

n = int(input())

ans = [4, 2, 5, 3, 1]

ans = deque(ans)

if (n > 4):
    while (n > 5):
        if (n % 2 == 0):
            ans.appendleft(n)
        else:
            ans.append(n)
        n = n - 1

    for i in list(ans):
        print(i, end=" ")
elif (n == 4):
    print(2, 4, 1, 3, end=" ")
elif (n == 1):
    print(1, end=" ")
else:
    print("NO SOLUTION")
