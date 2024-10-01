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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = NULL;
        int carry = 0;
        ListNode* head = NULL;
        int num1 , num2;
        while(l1!=NULL or l2!=NULL)
        {
        
            num1 = l1?l1->val:0;
            num2 = l2?l2->val:0;

            int ans = (carry+num1+num2)%10;
            carry = (carry+num1+num2)/10;

            ListNode* var = new ListNode(ans);
            
            if(!head)
            {
                head = var;
                temp = var;
            }
            else
            {
                temp->next = var;
                temp = var;
            }
        
          if(l1) 
              l1 = l1->next;
          if(l2)
              l2 = l2->next;
        
        }
        
        if(carry)
        {
            ListNode* another_node = new ListNode(1);
            temp->next = another_node;
            temp = another_node;
        }
           
        return head;
    }
};
