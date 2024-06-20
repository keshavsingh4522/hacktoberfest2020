#include <iostream>
#include <vector>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    int sw = 0;
    
    for (int i = 0; i < n; i++) {
        int numberOfSwaps = 0;
    
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
        sw += numberOfSwaps;
    
        if (numberOfSwaps == 0) {
            break;
        }
    }
    
    cout << "Array is sorted in " << sw << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;

    return 0;
}




