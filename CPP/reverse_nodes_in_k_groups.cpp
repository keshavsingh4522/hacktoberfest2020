/* 25. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode * prev = newHead, *curr = newHead, *nxt = newHead;
        int cnt = 0;
        while(curr->next!=NULL) {
            cnt++;
            curr = curr->next;
        }
        int nooftimes = cnt/k;
        while(nooftimes-->0) {
            curr = prev->next;
            nxt = curr->next;
            for(int i=1;i<k;i++) {
                curr->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = curr->next;
            }
            prev = curr;
        }
        return newHead->next;
    }
};