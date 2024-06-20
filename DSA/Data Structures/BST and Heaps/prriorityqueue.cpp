#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class PriorityQueue
{
    vector<int> x;
    public:
    PriorityQueue()
    {
        x.push_back(0);
    }


    public:
   void maxheapify(int index)
   {
       int leftchild = x[2*index],rightchild = x[2*index + 1],largest = index;
       if (2*index <= x.size()-1 and leftchild > x[index])
       largest = 2*index;

       if((2*index + 1) <= x.size()-1 and rightchild > x[index])
       largest = 2*index + 1;

       if(largest != index)
       {
           swap(x[index],x[largest]);
           maxheapify(largest);
       }
   }

   void increasekey(int index, int key)
   {
       if(key < x[index])
   {cout<<"Your element is shorter .\n";
       return ;}
    x[index] = key;

    while(index > 1 and x[(index/2)]<x[index])
    {
        swap(x[index],x[(index/2)]);
        index = index/2;
    }

       
   }
   void insert(int elem)
   {
       x.push_back(INT_MIN);
       increasekey(x.size()-1,elem);
   }
   int maximum ()
    {
        return x[1];
    }
    int extractmaximum()
    {
        if(x.size()-1 <1)
        {
            cout<<"Underflow \n";
            return -1;
        }
        int maximum = x[1];
        swap(x[1],x[x.size()-1]);
        maxheapify(1);
        x.pop_back();
        return maximum;
    

    }
    void display ()
    {

        cout<<"\nThe priority queue looks like: ";
        for(int i = 1;i<x.size();i++)
        cout<<x[i]<<" ";
    }

};

int main()
{
    int elem,choice,newvalue,get_max;
    PriorityQueue obj;
    while(true)
    {
        cout<<"\nPriority Queue Menu: \n";
        cout<<"1. Insert New elem\n";
        cout<<"2. Current Maximum elem\n";
        cout<<"3. Extract Maximum elem\n";
        cout<<"4. Increase priority of existing elem\n";
        cout<<"5. Print Priority Queue(Max Heap Fashion)\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<"\nEnter element to be inserted: ";
        cin>>elem;
        obj.insert(elem);
        break;

        case 2:
        cout<<"\nMaximum element in priority queue is : "<<obj.maximum();
        break;

        case 3:
         get_max = obj.extractmaximum();
        if (get_max != -1)
        cout<<"\nMaximum element extracted. It is : "<<get_max;
        break;

      case 4:
    cout<<"\nEnter existing index and its key: ";
    cin>>elem>> newvalue;
    obj.increasekey(elem,newvalue);
    break;

        case 5:
        obj.display();
        break;

        case 6 :
        cout<<"\n Exiting...";
        exit(1);
        break;

        
        }
    }
}