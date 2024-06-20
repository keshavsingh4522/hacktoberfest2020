// *
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //node for storing the resulting sum
        ListNode* head=new ListNode(0);
        ListNode* curr=head;
        int carry=0;
        while(l1||l2){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            curr->next=new ListNode((val1+val2+carry)%10);
            carry=(val1+val2+carry)/10;
            curr=curr->next;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        if(carry!=0){
            curr->next=new ListNode(carry);
        }
        return head->next;
    }
};