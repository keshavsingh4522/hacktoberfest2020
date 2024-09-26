#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;

struct Listnode{
  int val;
  ListNode *next;
  ListNode(int c){
    val=c;
    next=NULL;
  }
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
            # Imagine the lists as follows:
                    |---------
                              \
                                --------
                              /
               -----|---------
        
            # Now, we can clearly see that the point of intersection is equidistant from the node at | for both lists
            # How to find this node |?
            
            # Traverse both lists at a one-node-at-a-time pace. Let S be the pointer to the shorter LL, and L be the pointer to the longer LL
                    |---------
                              \
                                --L----S
                              /
               -----|---------
               
               L will be exactly 5 steps(in this case) behind S, because that is the length difference bw these two LL
               
               Move both pointers forward by one. S becomes null.
               
               Now restart the pointer S at the beginning of the longer LL
               
                    |---------
                              \
                                ---L----
                              /
               S----|---------
               
               When L reaches the end, S will have crossed the extra distance at the beginning. Restarting L at the shorter LL leads to:
                    L--------
                              \
                                --------
                              /
               -----S---------
               
               Et voila! We can easily find the point of intersection now!
          
                Note that - for linked lists with no intersection, the point of intersection will simply by the end of both LL:
                    |--------
                              \
                                NULL
                              /
               -----|---------
        */
        
        if(!headA){
            return headB;
        }
        if(!headB){
            return headA;
        }
        
        ListNode *A=headA,*B=headB;
        while(A && B && A!=B){
            A=A->next;
            B=B->next;
            
            if(A==B){
                return A;
            }
            
            if(!A){
                A=headB;
            }
            if(!B){
                B=headA;
            }
        }
        
        return A; 
    }

int main(){
  //call getIntersectionNode()
}
