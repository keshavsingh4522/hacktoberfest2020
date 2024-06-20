class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1) return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=dummy;
        ListNode* nextptr=dummy;
        int count=0;
        while(curr->next!=NULL)
            {
            count++;
            curr=curr->next;
            }
        while(count>=k){
            curr=prev->next;
            nextptr=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nextptr->next;
                nextptr->next=prev->next;
                prev->next=nextptr;
                nextptr=curr->next;
            }
            prev=curr;
            count-=k;
        }
        return dummy->next;
    }
};
