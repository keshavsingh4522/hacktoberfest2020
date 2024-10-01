#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node{
	int data;
	Node *right=NULL,*left=NULL;
	Node *parent=NULL;
};
int ok=0;
class Tree{
	public:
		Node *node=NULL;
		Node *MakeNode(int data){
			Node *temp=new Node;
			temp->data=data;
			return temp;
		}
		void addRoot(int data){
			node=MakeNode(data);
		}
		Node *find(int data){
			queue<Node*>list;
			list.push(node);
			while(!list.empty()){
				Node *temp=list.front();
				if(temp->data==data){
					return temp;
				}
				if(temp->right!=NULL){
					list.push(temp->right);
				}
				if(temp->left!=NULL){
					list.push(temp->left);
				}
				list.pop();
			}
			return NULL;
		}
		void addRight(int Parent, int data){
			Node *temp=MakeNode(data);
			if(this->node==NULL){
				node=temp;
				return;
			}
			
			Node *parent=find(Parent);
			temp->parent=parent;
			if(parent==NULL){
				cout<<"Exception: find not found"<<endl;
			}else{
				if(parent->right!=NULL){
					cout<<"Exception: Can't insert node"<<endl;
				}else{
					parent->right=temp;
				}
			}
		}
		void addLeft(int Parent, int data){
			Node *temp=MakeNode(data);
			if(this->node==NULL){
				node=temp;
				return;
			}
			Node *parent=find(Parent);
			temp->parent=parent;
			if(parent==NULL){
				cout<<"Exception: find not found"<<endl;
			}else{
				if(parent->left!=NULL){
					cout<<"Exception: Can't insert node"<<endl;
				}else{
					parent->left=temp;
				}
			}
		}
		
		void removeLeft(int data){
			Node *temp=find(data);
			if(temp==NULL){
				cout<<"Can't remove"<<endl;
				return;
			}
			if(temp->left==NULL){
				return;
			}
			if(temp->left->right== NULL && temp->left->left ==NULL){
				temp->left=NULL;
			}else{
				cout<<"Can't remove"<<endl;
			}
		}
		void removeRight(int data){
			Node *temp=find(data);
			if(temp==NULL){
				cout<<"Can't remove"<<endl;
				return;
			}
			if(temp->right==NULL){
				return;
			}
			if(temp->right->right== NULL && temp->right->left ==NULL){
				temp->right=NULL;
			}else{
				cout<<"Can't remove"<<endl;
			}	
		}
		
		//chieu cao cay bang de quy
		int heightTree(Node *p){
			if(p==NULL) return 0;
			return max(heightTree(p->left),heightTree(p->right))+1;
		}
		//chieu cao cay bang khu de quy
		int heightTree(){
			if(node==NULL) return 0;
			int h=0;
			queue<Node*>list;
			list.push(node);
			while(!list.empty()){
				int n=list.size();
				while(n--){
					Node *temp=list.front();
					if(temp->right!=NULL){
						list.push(temp->right);
					}
					if(temp->left!=NULL){
						list.push(temp->left);
					}
					list.pop();
				}
				h++;
			}
			return h;
		}
		
		void duyetTruoc(Node *node){
			if(node!=NULL){
				cout<<node->data<<" ";
				duyetTruoc(node->left);
				duyetTruoc(node->right);
			}
		}
		void duyetGiua(Node *node){
			if(node!=NULL){
				duyetGiua(node->left);
				cout<<node->data<<" ";
				duyetGiua(node->right);
			}
		}
		void duyetSau(Node *node){
			if(node!=NULL){
				duyetSau(node->left);
				duyetSau(node->right);
				cout<<node->data<<" ";
			}
		}
		void duyetTruoc(){
			if(node==NULL){
				cout<<"null"<<endl;
				return;
			}
			vector<Node*>daduyet;
			stack<Node*> list;
			list.push(node);
			daduyet.push_back(node);
			cout<<node->data<<" ";
			while(!list.empty()){
				Node *p=list.top();
				Node *left=p->left, *right= p->right;
				int l=0,r=0;
				for(int i=0;i< daduyet.size();i++){
					if(daduyet[i]==left) l=1;
					if(daduyet[i]==right) r=1;
				}
				if(l==0 && left!=NULL){
					list.push(left);
					daduyet.push_back(left);
					cout<<left->data<<" ";
				}else{
					if(r==0&& right!=NULL){
						list.push(right);
						daduyet.push_back(right);
						cout<<right->data<<" ";
					}else{
						list.pop();
					}
				}
			}
		}
};
Tree t;
void menu(){
	int key;
	while(true){
		cout<<endl<<"1. tao node goc cho cay"<<endl;
		cout<<"2. them node la ben trai cho node x"<<endl;
		cout<<"3. them node la ben phai cho node x"<<endl;
		cout<<"4. loai node la ben trai cho node x"<<endl;
		cout<<"5. loai node la ben phai cho node x"<<endl;
		cout<<"6. tim node x"<<endl;
		cout<<"7. duyet cay"<<endl;
		cout<<"chon: ";
		cin>>key;
		switch(key){
			case 1:{
				system("cls");
				int root;
				cout<<"Nhap node goc: ";
				cin>>root;
				t.addRoot(root);
				break;
			}
			case 2:{
				system("cls");
				int data, root;
				cout<<"Nhap node: ";
				cin>>root;
				cout<<"Nhap noi dung cua node them: ";
				cin>>data;
				t.addLeft(root,data);
				break;
			}
			case 3:{
				system("cls");
				int data, root;
				cout<<"Nhap node: ";
				cin>>root;
				cout<<"Nhap noi dung cua node them: ";
				cin>>data;
				t.addRight(root,data);
				break;
			}
			case 4:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.removeLeft(root);
				break;
			}
			case 5:{
				system("cls");
				int root;
				cout<<"Nhap node: ";
				cin>>root;
				t.removeRight(root);
				break;
			}
			case 6:{
				system("cls");
				int data;
				cout<<"nhap noi dung node can tim: ";
				cin>>data;
				Node *pos= t.find(data);
				if(pos==NULL) cout<<"khong ton tai node"<<endl;
				else cout<<"node can tim co dia chi: "<<pos<<endl;
				break;
			}
			case 7:{
				system("cls");
				cout<<"Cay: ";
				t.duyetTruoc();
				break;
			}
		}
	}
}
main(){
	menu();
}
