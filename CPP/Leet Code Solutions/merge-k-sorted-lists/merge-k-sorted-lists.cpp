/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.

*/


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<lists.size();i++)
            if(lists[i])
                pq.push({lists[i]->val,i});
        ListNode* ans= new ListNode(-1);
        ListNode* head=ans;
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            lists[top.second]=lists[top.second]->next;
            if(lists[top.second]!=NULL)
                pq.push({lists[top.second]->val,top.second});
            ans->next=new ListNode(top.first);
            ans=ans->next;
            
        }
        return head->next;
        
    }
};