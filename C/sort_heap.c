#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
int main() 
{ 
    vector<int> v = {8, 6, 2, 1, 5, 10};  
   
    make_heap(v.begin(), v.end()); 
   
    cout << "heap:   "; 
    for (const auto &i : v) { 
     cout << i << ' '; 
    }    
   
    sort_heap(v.begin(), v.end()); 
   
    std::cout <<endl<< "now sorted:   "; 
    for (const auto &i : v) {                                                    
        cout << i << ' '; 
    }    
    std::cout <<endl; 
} 
