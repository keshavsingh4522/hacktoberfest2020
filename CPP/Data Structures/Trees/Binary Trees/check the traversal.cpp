//@soumyaagr427

#include <bits/stdc++.h> 
using namespace std; 


class Solution{
    public:
    
  bool checktree(int preorder[], int inorder[], int postorder[], int len) 
    { 
    	if (len == 0)
        return 1;
 
 
    if (len == 1)
        return (preorder[0] == inorder[0])
               && (inorder[0] == postorder[0]);
 

    
    int idx= -1, f = 0;
    
    for (int i = 0; i < len; ++i)
        if (inorder[i] == preorder[0]) 
        {
            idx = i;
            break;
        }
   
    if(idx != -1)
    {
      for(int i = 0; i < len; i++)
        if(preorder[0] == postorder[i])
        {f = 1; break;}
    }
 
    if (idx == -1 || f == 0)
        return 0;
 
    int ret1
        = checktree(preorder + 1, inorder, postorder, idx);
 
    // check for the right subtree
    int ret2
        = checktree(preorder + idx + 1, inorder + idx + 1,
                    postorder + idx, len - idx - 1);
 
    // return 1 only if both of them are
    // correct else 0
    return (ret1 && ret2);
    	
    } 

};



int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 
