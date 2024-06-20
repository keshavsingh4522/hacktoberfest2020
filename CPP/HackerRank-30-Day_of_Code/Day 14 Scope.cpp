#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity Kolkata University
 * 
*/
class Difference
{
    private:
    vector<int> elements;
    public:
    int maximumDifference;

    Difference(vector<int> a)
    {
        elements = a;
        maximumDifference = 0;
    }
    void computeDifference()
    {
        int n = elements.size()-1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (maximumDifference < abs(elements[i] - elements[j+1]))
                {
                    maximumDifference = abs(elements[i] - elements[j+1]);
                }
                
            }
            
        }
        
    }
};

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;
        a.push_back(e);
    }
    
    Difference d(a);
    d.computeDifference();
    cout << d.maximumDifference;
    return 0;

}