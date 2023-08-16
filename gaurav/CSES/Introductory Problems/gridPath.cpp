#include<iostream>
#include<vector>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int p[48];
bool visited[9][9];

int solve(int pathIndex, int x, int y){

    if(visited[x][y+1] &&  visited[x][y-1] && !visited[x-1][y] && !visited[x+1][y]){
        return 0;
    }
    if(visited[x-1][y] && visited[x+1][y] && !visited[x][y-1] && !visited[x][y+1]){
        return 0;
    }

    if(x == 7 && y ==1 ){
        if(pathIndex == 48){
            return 1;
        }
        return 0;
    }
    
    if(pathIndex == 48)
        return 0;


    visited[x][y] = true;
    int ret = 0;

    if(p[pathIndex] < 4){
        int nx = x + dr[p[pathIndex]];
        int nc = y + dc[p[pathIndex]];
        if(!visited[nx][nc]){
            ret += solve(pathIndex + 1, nx, nc);
        }
    }
    else{
        for(int i = 0; i < 4; i++ ){
            int nx = x + dr[i];
            int nc = y + dc[i];
            if(visited[nx][nc])
                continue;
            ret += solve(pathIndex + 1, nx, nc);
        }
    }
    visited[x][y] = false;  
    return ret;
}


int main(){

    string line;
	getline(cin, line);

	for (int i = 0; i < 48; i++) {
		char cur = line[i];

		if (cur == 'U') p[i] = 0;
		else if (cur == 'R') p[i] = 1;
		else if (cur == 'D') p[i] = 2;
		else if (cur == 'L') p[i] = 3;
		else p[i] = 4;  
	}

    for(int i = 0; i< 9; i++){
        visited[i][0] = true;
        visited[0][i] = true;
        visited[8][i] = true;
        visited[i][8] = true;

    }
    for(int i = 1; i < 8; i++){
        for(int j = 1; j < 8; j++){
            visited[i][j] = false;
        }
    }

    cout<<solve(0, 1, 1)<<endl;;

    return 0;
}
