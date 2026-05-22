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
    bool hasCycle(ListNode *head) {
       ListNode *slow=head;
       ListNode *fast=head;
       if(slow==NULL){
        return false;
       }
       while(true){
        slow=slow->next;
        fast=fast->next;
        if(fast==NULL) return false;
        fast=fast->next;

        if(fast==slow){
            return true;
        }
        if(fast==NULL){
            return false;
        }
       } 
    }
};