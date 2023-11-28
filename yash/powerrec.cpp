#include<iostream>
using namespace std;

int powe(int a){
	if(a == 0){
		return 1;
	}
	
	return powe(a-1)*2;


}



int main(){
	int a;
	cin>>a;
	cout<<powe(a);
}
