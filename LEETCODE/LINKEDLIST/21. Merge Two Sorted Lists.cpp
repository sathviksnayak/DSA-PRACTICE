/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 class Solution{
    public:
 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *temp=new ListNode(0);
    ListNode *l3=temp;
    while(list1&&list2){
        if(list1->val<=list2->val){
            l3->next=list1;
            list1=list1->next;
        }
        else{
            l3->next=list2;
            list2=list2->next;
        }

        l3=l3->next;
    }
    l3->next =( list1!=nullptr )?list1:list2;
    return temp->next;
}
};