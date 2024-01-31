#include <iostream>
#include<vector>

using namespace std;

bool checkpalindrome(string s, int st, int e){

	while(st<=e){
		if(s[st++]==s[e--]){continue;}
		else return false;
	}
return true;

}

void print(vector<string> ans){

	for(auto i:ans){cout<<i<<endl;}

}



void findsuspects(string s){
	vector<string> ans;
	int index=0;
	for(int i=0;i<s.length();i++){

		for(int j=s.length()-1;j>i;j--){

			if(s[i]==s[j]){
				if(checkpalindrome(s,i,j)){
					ans.push_back(s.substr(i,j-i+1));
				}
			}

		}

	}

print(ans);
}



int main(){


	string s = "aaaabbaa";
	findsuspects(s);



}
