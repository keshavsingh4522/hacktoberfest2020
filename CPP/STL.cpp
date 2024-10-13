#include<bits/stdc++.h>
#include<vector>
#include<array>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
int main()
{
	cout<<endl<<endl<<endl<<"VECTORS"<<endl<<endl<<endl;
    vector<int>v1; //syntax for declaring a vector
    v1.push_back(1); //enter a value in vector
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    cout<<"values of  v1--"<<endl;
    for(int i=0;i<v1.size();i++) //method1 to output the values of vector
    {
    	cout<<v1[i]<<endl;
	}
	v1.pop_back(); //this function deletes the last value inserted in the vector
	cout<<"after popping"<<endl;
	for(auto member:v1)  //method2 to output the values of vector
	{
		cout<<member<<endl;
	}
	vector<int>v2;
	v2={10,20,30}; //another method of inputing values in vector
	cout<<endl;
	cout<<"values of v2--"<<endl;
	for(auto member:v2)
	{
		cout<<member<<endl;
	}
	cout<<endl;
	swap(v1,v2); //this function swaps the values btw two vectors
	cout<<"after swap function--"<<endl;
	cout<<"values in v1-- "<<endl;
	for(auto member:v1)
	{
		cout<<member<<endl;
	}
	cout<<"values in v2-- "<<endl;
	for(auto member:v2)
	{
		cout<<member<<endl;
	}
	cout<<endl;
	vector<int>v3;
	v3={6,4,10,8};
	cout<<"values of v3 before sort function--"<<endl;
	for(auto member:v3)
	{
		cout<<member<<endl;
	}
	sort(v3.begin(),v3.end()); 
	//this function sorts the values of the given vector in accending order (by default) 
	//to sort in another way give condition using another iteration in the function **see yt for help
	cout<<"values of v3 after sort function-- "<<endl;
	for(auto member:v3)
	{
		cout<<member<<endl;
	}
	cout<<endl<<"capacity of the vector v3-- "<<v3.capacity()<<endl; //gives the capacity of the vector
	cout<<"\n size of the vector v3-- "<<v3.size()<<endl; //gives the no of elements present in the vector
	cout<<endl<<"1st element of the vector v3-- "<<v3.front()<<endl; //gives the 1st element in vector
	cout<<"last element of vector v3--  "<<v3.back()<<endl; //gives the last element in vector
	cout<<"after erasing the 1st value of v3..."<<endl;
	v3.erase(v3.begin());//erases the 1st value
	for(auto member:v3)
	{
		cout<<member<<endl;
	}
	v3.clear();//clears the vector
	cout<<endl<<"after clearing vector v3 and printing the values..."<<endl;
	for(auto i:v3)
	{
		cout<<endl<<i;
	}
	//v.erase(v.begin()+6);
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"PAIR"<<endl<<endl<<endl;
	pair<int,char>p1; //syntax to declare a pair
	p1.first=17; //syntax to declare the 1st element of the pair
	p1.second='s'; //syntax to declare 2nd element of the pair
	cout<<endl<<"the values of pair"<<endl<<p1.first<<endl<<p1.second<<endl; //syntax to give output of the pair
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"ARRAY"<<endl<<endl<<endl;
	array<int,5>arr={1,2,3,4,5}; //implementation of int type array of size 5
	cout<<"1st element -- "<<arr.front()<<endl;
	cout<<"last element-- "<<arr.back()<<endl;	
	if(arr.empty()==0) //to check array empty or not if not gives 0 if empty gives 1
	{
		cout<<endl<<"array not empty.."<<endl;
	}
	cout<<endl<<"size of the array-- "<<arr.size()<<endl; //gives the size of the array
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"DEQUE"<<endl<<endl<<endl; 
	deque<int>d;
	d.push_back(2); //inputs value at back
	d.push_back(1);
	d.push_back(3);
	d.push_front(4); //inputs value at front
	cout<<endl<<"outputing the values of deque-- ";
	for(auto i:d) //1st method of outputting
	{
		cout<<endl<<i<<endl;
	}	
	d.pop_back(); //pops the last value
	int dsize=d.size(); //gives the size of the deque
	cout<<endl<<"output after popping back.."<<endl;
	for(int i=0;i<dsize;i++) //2nd method of outputting
	{
		cout<<d[i]<<endl;
	}
	d.pop_front(); //pops the first value
	cout<<endl<<"output after popping front.."<<endl;
	for(int i=0;i<dsize;i++) 
	{
		cout<<d[i]<<endl;
	}
	d.erase(d.begin(),d.begin()+1); //erases from 1st value to value after it
	cout<<endl<<"after erase function..."<<endl;
	for(auto i:d) 
	{
		cout<<endl<<i<<endl;
	}
	d.empty();//empty's the deque
	cout<<endl<<"after emptying the dequeee..."<<endl;
	for(auto i:d) 
	{
		cout<<endl<<i<<endl;
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"LIST"<<endl<<endl<<endl;
	list<int>l; //implementing list
	l.push_back(2); //enter the value at last
	l.push_back(1);
	l.push_front(0); //enter value at front
	cout<<endl<<"values in list..."<<endl;
	for(auto i:l) //output method
	{
		cout<<endl<<i<<endl;
	}
	l.pop_back(); //pops the last value
	cout<<endl<<"after popping back..."<<endl;
	for(auto i:l)
	{
		cout<<endl<<i<<endl;
	}
	l.pop_front(); //pops the 1st value
	cout<<endl<<"after popping front..."<<endl;
	for(auto i:l)
	{
		cout<<endl<<i<<endl;
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"STACK"<<endl<<endl<<endl; //works in lifo algorithm
	stack<int>st;
	st.push(2);
	st.push(0);
	st.push(7);
	st.push(25); //last in
	int stsize=st.size(); //gives size of stack
	cout<<"\n size of stack--- "<<stsize<<endl;
	cout<<"\n outputing the values...";
	for(int i=0;i<stsize;i++) //1st method of output
	{
		cout<<endl<<st.top()<<endl;
		st.pop(); //first out
	}
	if(st.empty()==true)
	{
		cout<<endl<<"stack is empty now"<<endl;
	}
	st.push(2);
	st.push(0);
	st.push(7);
	st.push(25);
	cout<<endl<<"output 2nd method..."<<endl;
	while(st.size()!=0) //2nd way of output
	{
		cout<<endl<<st.top()<<endl;
		st.pop();
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"QUEUE"<<endl<<endl<<endl; //same as stack just works in fifo algorithm
	queue<int>qu;
	qu.push(23);
	qu.push(67);
	qu.push(46);
	qu.push(65);//first in 
	qu.pop(); //first out
	cout<<"\n front-- "<<qu.front()<<endl;//gives the value at front
	cout<<"\n back-- "<<qu.back()<<endl;//gives the value at back
	while(qu.size()!=0) //gives the size
	{
		cout<<endl<<qu.front()<<endl;
		qu.pop();
	}
	qu.empty();//deletes the queue
	cout<<endl<<"after emptying queue.."<<endl;
	while(qu.size()!=0) 
	{
		cout<<endl<<qu.front()<<endl;
		qu.pop();
	}
	if(qu.empty()==true)
	{
		cout<<endl<<"queue is empty now.."<<endl;
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"PRIORITY QUEUE"<<endl<<endl<<endl;
	priority_queue<int>max; //implementation of priority queue prints value from higher to lower
	max.push(35);
	max.push(87);
	max.push(100);
	cout<<"prints in decessending order..."<<endl;
	while(max.size()!=0)
	{
		cout<<endl<<max.top()<<endl;
		max.pop();
	}
	priority_queue<int,vector<int>,greater<int>>min; //implementation of priority queue prints value from lower to higher
	min.push(100);
	min.push(35);
	min.push(87);
	cout<<"prints in acessending order..."<<endl;
	while(min.size()!=0)
	{
		cout<<endl<<min.top()<<endl;
		min.pop();
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"SET"<<endl<<endl<<endl;//gives us sorted order (acescending) and only unique values
	set<int>set1; //implement 
	set1.insert(12); //inserting values
	set1.insert(12);
	set1.insert(12);
	set1.insert(6);
	set1.insert(0);
	set1.insert(12);
	set1.insert(4);
	for(auto  i:set1)
	{
		cout<<i<<endl;
	}
	//
	//
	//
	//
	//
	//
	//
	cout<<endl<<endl<<endl<<"MAP"<<endl<<endl<<endl;
	map<int,char>map1; //implement of map having int type pointer and char type value
	map1[2]='a';
	map1[1]='b';
	map1[3]='c';
	map1[1]='b';
	map1[1]='d';
	map1[2]='z';
	cout<<"output of pointers in map..."<<endl;
	for(auto i:map1)
	{
		cout<<i.first<<endl; //i.first prints the pointers in sorted order
	}
	cout<<"output of values in map..."<<endl;
	for(auto i:map1)
	{
		cout<<i.second<<endl; //i.second prints the values in sorted order
	}
    return 0;
}