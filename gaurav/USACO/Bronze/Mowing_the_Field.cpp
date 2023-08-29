/* 
ID: kaden
TASK: force 
LANG: C++
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>

using namespace std;
#define ll long long 

ll N;
// the worst case is that you go in one direction for 10*100 = 1000 steps
// therefore, 2000 suffices as you start in the middle to ensure for all 4 directions
bool field[2000][2000]; // the grass field
ll times [2000][2000];  // the time at which the grass gets cut

void setIO(string s) {
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
void check (ll posX, ll posY,ll t, ll& x) { // checks if the grass has been cut
	if (field[posY][posX]) { // this indicates that the grass has been cut, so we may update x
		x = min(x, t - times[posY][posX]);
	}
	times[posY][posX] = t;	// update the time at which the grass gets cut regardless
}
void solve () {
	ll posX = 1000, posY = 1000; // start in the middle of the grass field
	ll t = 1, x = 1000;  // assume x to be something big
	field[posY][posX] = 1; // cut the initial spot with time being 0
	for (ll i =0; i < N; ++i) {
		char D; ll step; cin >> D >> step;
		
		for (ll j = 0; j < step; ++j) { // iterates over the steps
			switch (D) { // updates coordinates
				case 'N':
					posY += 1;
					break;
				case 'S':
					posY -= 1;
					break;
				case 'E':
					posX += 1;
					break;
				case 'W':
					posX -= 1;
					break;
				default:
					break;	
			}
			check(posX, posY, t, x); // checks and updates
			field[posY][posX] = 1;
			t += 1;
		}	
	}
	if (x == 1000) x = -1;	// we didn't revisit any grass field
	cout << x;
}

int main() {
    ios_base::sync_with_stdio(0);
    setIO("mowing");
    cin >> N;
    solve();
    return 0;
}   