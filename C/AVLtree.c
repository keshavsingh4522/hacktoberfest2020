#include<stdio.h>
#include<stdlib.h>

struct AVLNode
{
	int value,height;
	struct AVLNode* left;
	struct AVLNode* right;
};
int getHeight(struct AVLNode* r)
{
	int htl,htr;
    	if(r == NULL)
        	return -1;
    	else{
        	htl = getHeight(r->left);
        	htr = getHeight(r->right);
        	return ((htl > htr)? htl : htr ) + 1;
        }
}

int getBalance(struct AVLNode* r)
{
	return getHeight(r->left) - getHeight(r->right);
}

struct AVLNode* singleRotateLeft(struct AVLNode* p)
{
	struct AVLNode* RC = p->right;
	p->right = RC->left ;
	RC->left = p;

	p->height = getHeight(p);
	RC->height = getHeight(p);
	return RC;
}
struct AVLNode* singleRotateRight(struct AVLNode* p)
{
	struct AVLNode* LC = p->left;
	p->left = LC->right ;
	LC->right = p;

	p->height = getHeight(p);
	LC->height = getHeight(p);
	return LC;
}
struct AVLNode* doubleRotateLeftRight(struct AVLNode* p)
{
	struct AVLNode * LC;
	LC = p->left;
	p->left = singleRotateLeft(p->left);
	p = singleRotateRight(p);

	return p;
}
struct AVLNode* doubleRotateRightLeft(struct AVLNode* p)
{
	struct AVLNode * RC;
	RC = p->right;
	p->right = singleRotateRight(p->right);
	p = singleRotateLeft(p);

	return p;
}
struct AVLNode* findMin(struct AVLNode* ptr)
{
	while( ptr->left != NULL)
		ptr = ptr->left;
	return ptr;
}
struct AVLNode* insert_val(struct AVLNode* r,int val)
{
	if(r == NULL)
	{
		struct AVLNode* newNode;
		newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
		if(newNode == NULL)
		{
			printf("Error in malloc\n");
			return r;
		}
		newNode->value = val;
		newNode->height = 0;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if(val < r->value)
	{
		r->left = insert_val(r->left,val);
		if(getBalance(r) == 2)
		{
			if(val < r->left->value)
				r = singleRotateRight(r);
			else
				r = doubleRotateLeftRight(r);
		}
	}
	else
	{
		r->right = insert_val(r->right,val);
		if(getBalance(r) == -2)
		{
			if(val >= r->right->value)
				r = singleRotateLeft(r);
			else
				r = doubleRotateRightLeft(r);
		}
	}
	r->height = getHeight(r);
	return r;
}

struct AVLNode* delete(struct AVLNode* r,int val){
	struct AVLNode* temp;
	int balance;

	if(r == NULL)
		return r;
	if(val < r->value)
		r->left = delete(r->left,val);
	else if(val > r->value)
		r->right = delete(r->right,val);
	else{
		if(r->left == NULL){
			temp = r->right;
			free(r);
			r = temp;
		}
		else if(r->right == NULL){
			temp = r->left;
			free(r);
			r = temp;
		}
		else
		{
			temp = findMin(r->right); 
			r->value = temp->value;
			r->right = delete(r->right , temp->value);
		}
		if(r == NULL)
			return r;
		if(getBalance(r) == 2){
			if(getBalance(r->left) >= 0)
					return singleRotateRight(r);
			else
					return doubleRotateLeftRight(r);
		}
		if(getBalance(r) == -2){
			if(getBalance(r->right) <= 0) 
				return singleRotateLeft(r);
			else 
				return doubleRotateRightLeft(r);
		}
		r->height = getHeight(r);
		return r;
	}
}
void printlevel(struct AVLNode*r,int i)
{
	if(i==0)
	{
		if(r==NULL)
		{
			return;
		}
		else
		{
			printf("%d ",r->value);
		}
	}
	else
	{
		printlevel(r->left,i-1);
		printlevel(r->right,i-1);
	}
}
void levelorder(struct AVLNode*r)
{
	int i,j;
	j=getHeight(r);
	printf("\n");
	for(i=0;i<=j;i++)
	{
		printlevel(r,i);
		printf("\n");
	}
}
void main(){
	int n,val;
	struct AVLNode* root = NULL;
	printf("\n 1.Insert \t\n 2.Delete \t\n 3.Levelorder \t\n 4.EXIT \t\n");
	do
	{
		printf("\nEnter choice = ");
		scanf("%d",&n);
	switch(n)
	{
		case 1:
			printf("Enter the value = ");
			scanf("%d",&val);
			root = insert_val(root,val);
			break;
		case 2:
			printf("Enter the value you want to delete = ");
			scanf("%d",&val);
			root = delete(root,val);
			break;
		case 3:
			printf("The Levelorder Of AVLTree = ");
			levelorder(root);
			printf("\n");
			break;
		case 4:
			printf("EXIT");
	}
	}while(n!=4);
}

/* ""OUTPUT""

 1.Insert
 2.Delete
 3.Levelorder
 4.EXIT

Enter choice = 1
Enter the value = 50

Enter choice = 1
Enter the value = 20

Enter choice = 1
Enter the value = 60

Enter choice = 1
Enter the value = 10

Enter choice = 1
Enter the value = 8

Enter choice = 1
Enter the value = 15

Enter choice = 1
Enter the value = 32

Enter choice = 3
The Levelorder Of AVLTree =
20
10 50
8 15 32 60


Enter choice = 2
Enter the value you want to delete = 20

Enter choice = 3
The Levelorder Of AVLTree =
32
10 50
8 15 60


Enter choice = 2
Enter the value you want to delete = 50

Enter choice = 3
The Levelorder Of AVLTree =
32
10 60
8 15


Enter choice = 4
EXIT

*/