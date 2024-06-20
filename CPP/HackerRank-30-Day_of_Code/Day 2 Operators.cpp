#include <iostream>
#include <cmath>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main()
{
    int tipPercent, taxPercent,totalCost;
    double mealCost;

    cin >> mealCost >> tipPercent >> taxPercent;

    double tip = mealCost * tipPercent / 100;
    double tax = mealCost * taxPercent / 100;

    totalCost = round(mealCost + tip + tax);
    cout << totalCost;

    return 0;
}