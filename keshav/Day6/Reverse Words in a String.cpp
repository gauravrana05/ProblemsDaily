class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(char c : s){
            if(c==' '){
                if(temp.size()!=0){
                    st.push(temp);
                    temp = "";
                }
            }
            else{
                temp.push_back(c);
            }
        }
        if(temp.size()!=0) st.push(temp);
        string ans ; 
        while(!st.empty()){
            ans = ans + st.top()+" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};