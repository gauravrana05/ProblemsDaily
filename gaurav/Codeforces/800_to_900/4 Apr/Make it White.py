from collections import deque
 
def solve():
    n = int(input())
    s = deque(input())
    while len(s) > 0 and s[0] == 'W':
        s.popleft()
    while len(s) > 0 and s[-1] == 'W':
        s.pop()
    print(len(s))
    
 
for _ in range(int(input())):
    solve()