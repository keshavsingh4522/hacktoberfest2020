// Without Disjoint Set
#include<bits/stdc++.h>
using namespace std;
struct Job {
    char id;
    int profit,deadline;
};
bool comparator(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}
int main()
{
 
 int n, space_for_jobs = 0;
 cout<<"\n Enter number of Jobs : \n";
 cin>>n;
 vector<Job> data(n);
 cout<<"Specify Job Details\n";
 for(int i = 0;i<n;i++)
 {
     cin>>data[i].id >> data[i].deadline >> data[i].profit;
     space_for_jobs = max(space_for_jobs, data[i].deadline);

 }
 sort(data.begin(),data.end(),comparator);
 vector<char> selected_jobs(space_for_jobs,'?'); // ? Denotes Slot for Job is Empty
 for(Job elem : data)
 {
     int deadline = elem.deadline - 1;
     for(int i = deadline ; i >= 0;i--)
     {
         if(selected_jobs[i] == '?')
         {
             selected_jobs[i] = elem.id;
             break;
         }
     }
 }
cout<<"Selected Jobs are : \n";
 for(char elem : selected_jobs)
 {
     if(elem != '?')
     cout<<elem<<" ";
 }

}