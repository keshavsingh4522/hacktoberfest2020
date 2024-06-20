#include <iostream>
using namespace std;
/**
 * 
 *  Aman Upadhyay
 *  Amity University Kolkata
 * 
*/
int main(int argc, const char* args[]){
    int actualDay;
    int actualMonth;
    int actualYear;
    int expectedDay;
    int expectedMonth;
    int expectedYear;

    
    cin >> actualDay;   
    cin >> actualMonth; 
    cin >> actualYear;  
    cin >> expectedDay;
    cin >> expectedMonth;
    cin >> expectedYear;

    int fine = 0;

    if(expectedYear == actualYear){
        if(expectedMonth < actualMonth){
            fine = (actualMonth - expectedMonth) * 500;
        }
        else if( (expectedMonth == actualMonth) 
                && (expectedDay < actualDay) ){
            fine = (actualDay - expectedDay) * 15;
        }
    }
    else if(expectedYear < actualYear){
        fine = 10000;
    }
    cout << fine << endl;
    return 0;
}
