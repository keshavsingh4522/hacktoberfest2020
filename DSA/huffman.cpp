#include <bits/stdc++.h>
using namespace std;

class node 
{   
    public:
        char data;
        int freq;
        node *left, *right;

        node(char data, int freq)
        {
            left = right = nullptr;
            this -> data = data;
            this -> freq = freq;
        }
};

class custom_comp
{
    public:
        bool operator()(node* left, node* right)
        {
            return left -> freq > right -> freq;
        }
};

void print_codes(node *root, string res)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> data != '*')
    {
        cout << root -> data << ": " << res << endl;
    }

    print_codes(root -> left, res + "0");
    print_codes(root -> right, res + "1");
}

void huffman_codes(vector<char> & characters, vector<int>& freq, int n)
{
    node *left, *right, *top;
    
    priority_queue<node*, vector<node*>, custom_comp> min_heap;
    
    for(int i = 0; i < n; i++)
    {
        min_heap.push(new node(characters[i], freq[i]));
    }

    while(min_heap.size() > 1)
    {
        left = min_heap.top();
        min_heap.pop();

        right = min_heap.top();
        min_heap.pop();

        top = new node('*', left -> freq + right -> freq);

        top -> left = left;
        top -> right = right;

        min_heap.push(top);
    }

    print_codes(min_heap.top(), "");
}

int main()
{
    string to_encode = "aaabbbcccdddd";
    set<char> unique_char;
    
    vector<int> freq;
    
    for(auto e: to_encode)
    {
        unique_char.insert(e);
    }
    
    vector<char> characters {unique_char.begin(), unique_char.end()};
    sort(characters.begin(), characters.end());
    
    for(auto e: characters)
    {
        int count = 0;
        for(auto c: to_encode)
        {
            if(c == e)
            {
                count++;
            }
        }
        freq.emplace_back(count);
    }
    
    int n = characters.size();
    huffman_codes(characters, freq, n);

return 0;
}

