#include <iostream>
#include <queue>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

deque<Node*> treeQueue;

void levelOrder(Node* root){
    if( root ){
        treeQueue.push_back(root);
    }
    while( !treeQueue.empty() ){  
        Node* tree = treeQueue.front();
        treeQueue.pop_front();

        cout << tree->data << " ";

        if( tree->left ){
            treeQueue.push_back( tree->left );
        }
        if( tree->right ){
            treeQueue.push_back( tree->right );
        }
    }
}

};
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}