// C++ program to assign usernames to users
#include <bits/stdc++.h>
using namespace std;
 
#define MAX_CHAR 26
 
struct additional {
 
    // is checks if the current node is
    // leaf node or not
    bool is;
 
    // add counts number of concatenations
    // of string are present in Trie
    int add;
};
 
// represents Trie node
struct Trie {
 
    // MAX_CHAR character children
    Trie* character[MAX_CHAR];
 
    // 10 numbers (from 0 to 9)
    Trie* number[10];
 
    // one additional struct children
    additional a;
};
 
// function to get new node
Trie* getnew()
{
    // initialising the Trie node
    Trie* node = new Trie;
    node->a.is = false;
    node->a.add = -1;
    for (int i = 0; i < MAX_CHAR; i++)
        node->character[i] = NULL;
    for (int i = 0; i < 10; i++)
        node->number[i] = NULL;
    return node;
}
 
// inserting a string into Trie
void insert(Trie*& head, string s)
{
    Trie* curr = head;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] - 'a' < 0) {
            if (curr->number[s[i] - '0'] == NULL) {
                curr->number[s[i] - '0'] = getnew();
            }
            curr = curr->number[s[i] - '0'];
        }
        else {
            if (curr->character[s[i] - 'a'] == NULL)
                curr->character[s[i] - 'a'] = getnew();
            curr = curr->character[s[i] - 'a'];
        }
    }
    curr->a.is = true;
}
 
// returns the structure additional
additional search(Trie* head, string s)
{
    additional x;
    x.is = false;
    x.add = -1;
 
    // if head is null directly return additional x
    if (head == NULL)
        return x;
    Trie* curr = head;
 
    // checking if string is present or not and
    // accordingly returning x
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - 'a' < 0) {
            curr = curr->number[s[i] - '0'];
        }
        else
            curr = curr->character[s[i] - 'a'];
        if (curr == NULL)
            return x;
    }
    x.is = curr->a.is;
    x.add = curr->a.add;
    return x;
}
 
// special function to update add variable to z
void update(Trie* head, string s, int z)
{
    Trie* curr = head;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] - 'a' < 0)
            curr = curr->number[s[i] - '0'];
        else
            curr = curr->character[s[i] - 'a'];
    }
    curr->a.add = z;
}
 
void printUsernames(string username[], int n)
{
    // Initialing a Trie root
    Trie* head = getnew();
 
    // Assigning usernames one by one
    for (int i = 0; i < n; i++) {
        string s = username[i];
        additional x = search(head, s);
 
        // if string is not present directly return it
        if (x.is == false) {
            cout << s << endl;
            insert(head, s);
        }
 
        // to_string(x) converts integer x into string
        else if (x.is == true) {
 
            // start from x.add+1
            int y = x.add + 1;
            string x = s;
 
            // continuing searching the string
            // until a free username is found
            while (1 < 2) {
 
                // if free username is found
                if (search(head, x + to_string(y)).is == false) {
 
                    // print it insert it and update add
                    cout << x << y << endl;
                    insert(head, x + to_string(y));
                    update(head, s, y);
                    break;
                }
                // else increment y
                else if (search(head, x + to_string(y)).is == true)
                    y++;
            }
        }
    }
}
 
// driver function
int main()
{
    string name[] = { "week", "week0", "week1", "week" };
    int n = sizeof(name) / sizeof(name[0]);
    printUsernames(name, n);
    return 0;
}