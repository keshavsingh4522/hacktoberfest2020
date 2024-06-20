#include<bits/stdc++.h>
using namespace std;
struct Job{
    int start_time,end_time,id;
};
bool comparator(Job j1,Job j2)
{
   return j1.end_time < j2.end_time;

}
int main()
{
    int number_of_jobs,deadline;
    cout<<"\nEnter number of jobs:\n";
    cin>>number_of_jobs;
    vector<Job> data(number_of_jobs);
    vector<Job> selected_jobs_id;
    cout<<"\nEnter Start time and Finish Time:\n";
    for(int i = 0;i<number_of_jobs;i++)
        cin>>data[i].start_time >> data[i].end_time,data[i].id = i;
    sort(data.begin(),data.end(),comparator);
    cout<<"\nEnter deadline:\n";
   cin>>deadline;
   if(data[0].end_time <= deadline)
   selected_jobs_id.push_back(data[0]);
    for(int i = 1;i<number_of_jobs;i++)
    {
        Job prev = *(selected_jobs_id.end()-1);
        if( data[i].start_time >= prev.end_time and data[i].end_time <= deadline)
        selected_jobs_id.push_back(data[i]);
    }
    cout<<"Selected Job Id's are :\n";
    for(Job elem : selected_jobs_id)
    cout<<elem.id<<" ";
    

}