#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

       int n = digits.size();
       vector<int> ans;

       if(n == 1){
           if(digits[0] == 9){
               digits.pop_back();
               digits.push_back(1);
               digits.push_back(0);
               return digits;
           }
           else if(digits[0] == 0){
               digits.pop_back();
               digits.push_back(1);
               return digits;
           }
           else
            {
                digits.pop_back();
                 digits.push_back(digits[0] + 1);
                return digits;
            }
       }
       else{
           int i = n - 1;
            if(digits[ i ] == 9){
                
                while(i >= 0 && digits[i] == 9 ){
                        digits[i] = 0;
                        i--;
                    }
                    if(i >= 0){
                    digits[i] += 1;
                    return digits;
                    }
                    else{
                        digits.push_back(1);
                        swap(digits[n], digits[0]);
                        return digits;
                    }
                    
                    }
                else{
                    digits[i] += 1; 
                    return digits;
                }
            
            }
        
            return ans;
            }
    };