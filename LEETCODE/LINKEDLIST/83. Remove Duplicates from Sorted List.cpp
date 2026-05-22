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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return nullptr;
        ListNode *last=head;
        ListNode *next1=head->next;
        
        while(next1){
            if(next1->val==last->val){
                while(last->val==next1->val){
                    next1=next1->next;
                    if(next1==NULL){
                        break;
                    }
                }
            last->next=next1;
            }
            last=last->next;
            if(next1 ){
                next1=next1->next;
            }
            else{
                break;
            }
        }

        return head;
        
    }
};