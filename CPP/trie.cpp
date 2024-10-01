class node{
public:
    char data;
    unordered_map<char,node*>m;
    bool isTerminal;

    node(char a){
        this->data=a;
        this->isTerminal=false;
    }

};
////////////////////////////////// prefix Trie implementation////////////////////////////////////////////////////////
class Trie{
public:
    node*root;

    Trie(){
        root= new node('\0');
    }

    void insert(string s){
        node*temp = root;
        for(auto ch:s){
            if(temp->m.count(ch)==0){
                node*n= new node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];

        }
        temp->isTerminal=true;

    }

    bool search(string s){
        node*temp = root;
        for(auto ch:s){
            if(temp->m.count(ch)==0){
                return false;
            }
            else{
                temp=temp->m[ch];
            }

        }
        return temp->isTerminal;


    }





};
