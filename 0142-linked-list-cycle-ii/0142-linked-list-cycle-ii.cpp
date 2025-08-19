/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* curr = head;
        unordered_map<ListNode*,int> mpp;

        while(curr!=NULL){
            if(mpp.find(curr) != mpp.end()){
                return curr;
            }
            mpp.insert({curr,1});
            curr = curr->next;
        }

        return NULL;
    }
};