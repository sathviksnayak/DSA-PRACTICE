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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;

        if(!slow->next) return true;
        while( fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *a=head;

        ListNode *b=a->next;
        
        ListNode *c=b->next;

        if(!c){
            if(a->val==b->val) return true;
            else return false;
        }
        if(c==fast){
            if(a->val==c->val) return true;
            else return false;
        }
        a->next=NULL;
        while(b!=slow){
            b->next=a;
            a=b;
            b=c;
            c=c->next;
        }
        if(fast){
            slow=slow->next;
        }
        while(a && slow){
            if(a->val!=slow->val){
                return false;
            }
            a=a->next;
            slow=slow->next;
        }
        return true;
        
    
        
    }
};