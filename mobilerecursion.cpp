#include <iostream>
#include<vector>

using namespace std;

 

void solve(int input[],string output,int index, vector<string> mapping, vector<string>& ans){

    if(index>=3){

        ans.push_back(output);

       

        return;

    }

 

    string curr = mapping[input[index++]];

    for(int i = 0; i<curr.length(); i++  ){

        output+=curr[i];

        solve(input,output,index,mapping,ans);

        output.pop_back();

    }

   

    

    

}

 

 

int main()

{

    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    int input[3] = {2,3,4};

    int index = 0;

    vector<string> ans;

    string output = "";

    solve(input,output,index,mapping,ans);

    for(int i = 0; i<ans.size();i++){

        cout<<ans[i]<<" ";

    }

    return 0;

}
