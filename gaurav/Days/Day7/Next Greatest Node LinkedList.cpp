/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int countN(ListNode * head){
        if(head == NULL)
            return 0;
        return 1 + countN(head->next);
    }

    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ans;
        if(!head)
            return ans;
        cout<<" ye chandan ki door";
        int size = countN(head);
        for(int i = 0; i < size; i++){
        ListNode* temp = head;
            int t = i;
            while(t--)
                temp = temp->next;
            t = i ;
            int data = temp->val;
            bool a = false;
            while(t < size){
                if(data < temp->val){
                    ans.push_back(temp->val);
                    a = true;
                    break;
                }
                temp = temp->next;
                t++;
            }
            if(!a)
                ans.push_back(0);
        }    
    return ans;
    }
};