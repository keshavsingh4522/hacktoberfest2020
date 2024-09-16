###  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.   ###



class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        cur, nxt, pre = dummy, dummy, dummy
        cnt = 0
        while cur.next:
            cnt += 1
            cur = cur.next
        while cnt >= k:
            cur = new = pre.next
            nxt = cur.next
            for _ in range(k-1):
                tmp = nxt.next
                nxt.next = cur
                cur = nxt
                nxt = tmp
            pre.next = cur
            new.next = nxt
            pre = new
            cnt -= k
        return dummy.next
