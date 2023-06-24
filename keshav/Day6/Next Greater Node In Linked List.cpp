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

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> s;
        int i = 0;
        while(head){
            ans.push_back(0);
            while(!s.empty() && s.top().first < head->val){
                pair<int,int> k = s.top();
                s.pop();
                ans[k.second] = head->val;
            }
            s.push({head->val,i++});
            head = head->next;
        }
        return ans;
    }
};