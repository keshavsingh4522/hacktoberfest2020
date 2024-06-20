#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1=l1;
        ListNode *p2=l2;
        ListNode *MergedList=new ListNode(0);
        ListNode *p3=MergedList;
        while(p1!=nullptr && p2!=nullptr){
            if(p1->val<p2->val){
                p3->next=p1;
                p1=p1->next;
                p3=p3->next;
            }
            else {
                p3->next=p2;
                p2=p2->next;
                p3=p3->next;
            }
        }
        while(p1!=nullptr){
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        while(p2!=nullptr){
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
        return MergedList->next;
    }
};
int main(){
    // /l1 = [1,2,4], l2 = [1,3,4]
    ListNode *l1=new ListNode(1);
    l1->next=new ListNode(2);
    l1->next->next= new ListNode(4);
    ListNode *l2=new ListNode(1);
    l2->next= new ListNode(3);
    l2->next->next=new ListNode(4);
    ListNode *p1=l1;
    ListNode *p2=l2;
    
    // cout<<p->val<<" ";
    // cout<<p->next->val<<" ";
    // cout<<p->next->next->val<<" ";
    Solution obj;
    ListNode *p3=obj.mergeTwoLists(p1,p2);
    while(p3!=nullptr){
        cout<<p3->val<<" ";
        p3=p3->next;
    }
}