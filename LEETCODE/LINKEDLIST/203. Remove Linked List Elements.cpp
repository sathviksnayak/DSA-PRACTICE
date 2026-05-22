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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        if(head->val==val && !head->next) return nullptr;

        ListNode dummy(0);
        dummy.next=head;
        ListNode* pre=&dummy;
        ListNode *p=pre->next;
        
        while(p){
            if(p->val==val){
               pre->next=p->next;
                p=p->next;
            }
            else{
                pre=p;
                p=p->next;

            }

            
        }
       return dummy.next; 
    }
};