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
    ListNode* findNewTail(ListNode* temp, int k){
        int cnt = 1;
        while(temp!=NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }

        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0) return head;

        ListNode* tail = head;
        int cnt = 1;
        while(tail->next != NULL){
            tail = tail->next;
            cnt++;
        }

        if(k % cnt == 0) return head; //no need to do anythin

        tail->next = head; //make the list circular so we can break at any point
        k = k % cnt;

        ListNode* newTail = findNewTail(head,cnt-k);
        head = newTail->next;
        newTail->next = NULL;

        return head;
    }
};