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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            if(n==1){
                delete head;
                return NULL;
            }
            return head;
        }
        
        ListNode*temp=head,*curr;
        // if(head->next->next==NULL){
        // if(n==2){
        //     head=head->next;
        //     delete temp;
        //     return head;
        // }
        // }
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        curr=head;
        while(temp->next!=NULL ){
            curr=curr->next;
            temp=temp->next;
        }
        cout<<curr->val<<" "<<temp->val<<" ";
        
        temp=curr->next;
        curr->next=temp->next;
        delete temp;
        return head;
    }
};