//Radix Sort
//Radix Sort is similar to Bucket/Bin sort and different at the same time.
//Instead of taking the whole number as index into consideration, it works on the basis of a particular digit.
//Starting from the last digit, it keeps on sorting and storing and repeats same process with the digit with comes before it,
//till all the digits of the max number is exhausted.

//Time Complexity = O(dn) where d = no. of digits and n = no. of elements
//Space complexity = O(n)
#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *first, *last;

    public:
    LinkedList(){first = last = NULL;}
    ~LinkedList();
    void Insert(int x);
    int Delete();
    bool isEmpty();
};

LinkedList :: ~LinkedList()
{
    Node *p;
    while(first){
        first = first->next;
        delete p;
    }
    first = last = NULL;
}

void LinkedList :: Insert(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL)
        first = last = t;
    else{
        last->next = t;
        last = last->next;
    }
}

int LinkedList :: Delete()
{
    if(first == NULL)  return -1;
    Node * tr = first;
    first = first->next;
    int x = tr->data;
    delete tr;
    return x;
}

bool LinkedList :: isEmpty()
{
    return first == NULL;
}

int Max(int A[], int n)
{   
    int mx = INT32_MIN;;
    for(int i=0; i < n; i++)
        if(mx < A[i]) mx = A[i];
    return mx;
}

void RadixSort(int A[], int n)
{
    int max = Max(A, n), d = 1;
    LinkedList *bin = new LinkedList[n];

    while(d < max)
    {
        //1 Pass
        //Insertion according to kth digit where k = log(d)+1
        for(int i=0; i < n; i++)
            bin[(A[i]/d)%10].Insert(A[i]);
        
        int i=0;
        for(int j=0; j < n; j++)
        {
            while(!bin[j].isEmpty())
                A[i++] = bin[j].Delete();
        }
        d = d*10;
    }

}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    //int A[] = {237, 140, 259, 348, 152, 163, 1244, 48, 36, 62};
    //int n = sizeof(A)/sizeof(A[0]);
    
    RadixSort(A, n);
    //Display
    cout << "Sorted List : ";
    for(int i=0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
