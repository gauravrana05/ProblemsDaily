#incldue<iostream>
#include<vector>
using namespace std;

class OrderedStream {
public:
    int size;
    int curr;
    vector<string> data;
    OrderedStream(int n) {
        size = n;
        curr = 0;
        data.resize(size);

    }
    
    vector<string> insert(int idKey, string value) {
        
        data[idKey - 1] = value;
        
        int i = curr;

        vector<string> ans;
        while(i < size){
            if(data[i] == "")
            {
                break;
            }
            ans.push_back(data[i]);
            i++;
        }
        curr = i ;
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */