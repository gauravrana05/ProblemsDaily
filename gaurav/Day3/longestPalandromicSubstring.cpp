#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPal(string s){
        int st = 0; 
        int end = s.size() - 1;
        // cout<<endl;
        while(st < end){
            // cout<<s[st]<<s[end]<<" ";
            if(s[st] != s[end]){
                // cout<<"Not pal"<<endl;
                return false;
            }
            st++;
            end--;
        }
        // cout<<endl;
        return true;
    }
    
    string longestPalindrome(string s) {

        if(s.length() < 2  ){
            return s;
        }
        
        int n = s.length();
        vector<string> m;

        for(int i = 0; i < n; i++){
            string temp = "";
            for( int j = 1; j < n; j++ ){
                temp += s[j];
                m.push_back(temp);
            }
        }
        string ans = "";
        int  si = 0;
        for(auto i : m){
                
                if(isPal(i)){    
       
                    int b = i.length();
                    if (si <  b ){
                        si =  b;
                        ans = i;
                    
                        }
                    }
                }
        return ans;
    }
};

