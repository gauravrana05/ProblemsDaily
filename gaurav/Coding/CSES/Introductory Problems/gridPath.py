inPath = input()

visited = []
for i in range(9):
    temp = []
    for j in range(9):
        temp.append(False);
    visited.append(temp);

dr = [-1, 0, 1, 0];
dc = [0, 1, 0, -1];

for i in range(9):
    visited[i][8] = True;
    visited[8][i] = True;
    visited[i][0] = True;
    visited[0][i] = True;

path = []

import time

start = time.time()

def solve(ind, i, j, visited, ans):
    
    if( not visited[i-1][j] and not visited[i+1][j] and visited[i][j+1] and visited[i][j-1]):
        return;
    
    if(not visited[i][j+1] and not visited[i][j-1] and visited[i+1][j] and visited[i-1][j]):
        return;

    if (i == 7 and j == 1):
        if(ind == 48):
            ans[0] += 1
        return

    if(ind == 48):
        return;
    
    visited[i][j] = True

    for x in range(4):
        nx = i + dr[x];
        nc = j + dc[x];
        if(visited[nx][nc]):
            continue;
        solve(ind + 1, nx, nc, visited, ans);

    visited[i][j] = False

ans = [0]
solve(0, 1, 1, visited, ans)

print(ans)

end = time.time()

print("The execution time for the program is",end - start)


