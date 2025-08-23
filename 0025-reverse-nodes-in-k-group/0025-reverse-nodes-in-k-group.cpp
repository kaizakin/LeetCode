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
    void reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* nextNode = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = nextNode;
        }
    }
    ListNode* findkthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            k--;
            temp = temp->next;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kthNode = findkthNode(temp,k);

            if(!kthNode){
                if(prevNode) prevNode->next = temp;

                break;
            } 

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseLL(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};