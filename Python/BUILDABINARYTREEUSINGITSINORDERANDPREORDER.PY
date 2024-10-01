class BinaryTree:
    def __init__(self,data):
        self.data=data
        self.left=None
        self.right=None

import queue
def treefromInordernPreorder(inorder,preorder):
    if len(preorder)==0 or len(inorder)==0:
        return None
    rootdata=preorder[0]
    root=BinaryTree(rootdata)
    i=-1
    i=inorder.index(rootdata)
    if i==-1:
        return None
    leftinorder=inorder[:i]
    rightinorder=inorder[i+1:]
    leftpreorder=preorder[1:i+1]
    rightpreorder=preorder[i+1:]
    root.left=treefromInordernPreorder(leftinorder,leftpreorder)
    root.right=treefromInordernPreorder(rightinorder,rightpreorder)
    return root

def printTree(root):
    if root==None:
        return
    inputq=queue.Queue()
    outputq=queue.Queue()
    inputq.put(root)
    while (not(inputq.empty())):
        while (not(inputq.empty())):
            curr=inputq.get()
            print(curr.data,end=" ")
            if curr.left!=None:
                outputq.put(curr.left)
            if curr.right!=None:
                outputq.put(curr.right)
        print()
        inputq,outputq=outputq,inputq

print("ENTER THE LIST REPRESENTING INORDER :")
inorder=[int(x) for x in input().split(" ")]
print("ENTER THE LIST REPRESENTING PREORDER :")
preorder=[int(x) for x in input().split(" ")]
root=treefromInordernPreorder(inorder,preorder)
printTree(root)