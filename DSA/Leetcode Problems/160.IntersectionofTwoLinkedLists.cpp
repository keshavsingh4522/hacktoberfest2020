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
    int getCount(ListNode* head){
        ListNode* current = head; 
        int count = 0;  
        while (current != NULL) { 
            count++; 
            current = current->next; 
        } 
        return count; 
    }
    ListNode * _getIntesectionListNode(int d, ListNode* head1, ListNode* head2) 
    {  
        ListNode* current1 = head1; 
        ListNode* current2 = head2; 
        for (int i = 0; i < d; i++) { 
            if (current1 == NULL) { 
                return NULL; 
            } 
            current1 = current1->next; 
        } 
        while (current1 != NULL && current2 != NULL) { 
            if (current1 == current2) 
                return current1; 
            current1 = current1->next; 
            current2 = current2->next; 
        }
        return NULL; 
    }
    ListNode *getIntersectionNode(ListNode *head1,ListNode *head2) {
        int c1 = getCount(head1); 
        int c2 = getCount(head2); 
        int d; 
        if (c1 > c2) { 
            d = c1 - c2; 
            return _getIntesectionListNode(d, head1, head2); 
        } 
        else { 
            d = c2 - c1; 
            return _getIntesectionListNode(d, head2, head1); 
        } 
    }
};