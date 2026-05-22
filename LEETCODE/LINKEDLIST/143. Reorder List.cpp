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
    void reorderList(ListNode* head) {
        if(!head->next) return;
        if(!head->next->next) return;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* x=slow->next;
        slow->next=nullptr;
        ListNode* y=x->next;
        x->next=nullptr;
        while(y){
            ListNode* z=y->next;
            y->next=x;
            x=y;
            y=z;
        }ListNode* ptr=head;
        while(x){
            ListNode* a=ptr->next;
            ListNode* b=x->next;
            ptr->next=x;
            x->next=a;
            ptr=a;
            x=b;
        }

       
       
    }
};