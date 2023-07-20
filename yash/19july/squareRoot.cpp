#include<iostream>
using namespace std;
int main(){
	int input;
	cin >> input;
	int st = 0; int end = input;
	int mid = st + (end-st)/2;
	int ans;
	while (st<=end){
		int square = mid*mid;
		if(square > input){end = mid-1;}
		else if (square < input){ans = mid;st = mid+1;}
		else {cout<<mid; return mid;}
		mid = st + (end-st)/2;
	}

	cout<<ans;
}
