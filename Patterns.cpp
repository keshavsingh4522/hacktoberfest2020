/*
Approach method : -
1. No of lines = No of rows = No of times outer loop will run 
2. Identify for every row no 
   *How many columns are there 
   *Types of elements in columns
3. What do you need to print   
*/

#include<iostream>
using namespace std;

void pattern1(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for (int column = 0; column < noOfLines; column++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern2(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for (int column = 0; column <= row; column++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern3(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for (int column = 0; column < noOfLines-row; column++)   // int column = noOfLines; column >= row; column--
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern4(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for (int column = 0; column <= row; column++)
        {
            cout<<column + 1;
        }
        cout<<endl;
    }
}

void pattern5(int noOfLines){
    for(int row = 0; row < 2*noOfLines-1; row++){
        int totalColumnInRow = row<noOfLines ? row+1 : 2*noOfLines-1-row;
        for(int column = 0; column < totalColumnInRow; column++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern6(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < noOfLines-row-1; column++){
            cout<<" ";
        }
        for(int column = 0; column <= row; column++){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern7(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < row; column++){
            cout<<" ";
        }
        for(int column = 0; column < noOfLines-row; column++){
            cout<<"*";
        }       
        cout<<endl;
    }
}

void pattern8(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < noOfLines-row-1; column++){
            cout<<" ";
        }
        for(int column = 0; column < 2*row+1; column++){
            cout<<"*";
        }       
        cout<<endl;
    }
}

void pattern9(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < row; column++){
            cout<<" ";
        }
        for(int column = 0; column < 2*(noOfLines-row)-1; column++){
            cout<<"*";
        }       
        cout<<endl;
    }
}

void pattern10(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < noOfLines-row-1; column++){
            cout<<" ";
        }
        for(int column = 0; column < row+1; column++){
            cout<<"* ";
        }       
        cout<<endl;
    }
}

void pattern11(int noOfLines){
    for(int row = 0; row < noOfLines; row++){
        for(int column = 0; column < row; column++){
            cout<<" ";
        }
        for(int column = 0; column < noOfLines-row; column++){
            cout<<"* ";
        }       
        cout<<endl;
    }
}

void pattern12(int noOfLines){
    for(int row = 0; row < 2*noOfLines; row++){
        int totalSpaceInRow = row<noOfLines ? row : 2*noOfLines-row-1;
        int totalStarsInRow = row<noOfLines ? noOfLines-row : row-noOfLines+1;
        for(int spaceColumn = 0; spaceColumn < totalSpaceInRow; spaceColumn++){
            cout<<" ";
        }
        for(int starColumn = 0; starColumn < totalStarsInRow; starColumn++){
            cout<<"* ";
        }   
        
        cout<<endl;
    }
}

// void pattern13(int noOfLines){
//     for(int row = 0; row < noOfLines-row-1; row++){
//         cout<<" ";
//     }
//     int formula = row<2 ? row+1 : 
//     for(int column = 0; column < row+1; column++){
//         cout<<"* ";
//     }
//     for(int miss = 3; miss<)
//     cout<<endl;
// }


int main()
{
    int noOfLines;
    cout<<" NO OF LINES "<<endl;
    cin>>noOfLines;
    cout<<"\n"<<" Patterns are "<<endl;
    pattern1(noOfLines);
    cout<<endl;
    pattern2(noOfLines);
    cout<<endl;
    pattern3(noOfLines);
    cout<<endl;
    pattern4(noOfLines);
    cout<<endl;
    pattern5(noOfLines);
    cout<<endl;
    pattern6(noOfLines);
    cout<<endl;
    pattern7(noOfLines);
    cout<<endl;
    pattern8(noOfLines);
    cout<<endl;
    pattern9(noOfLines);
    cout<<endl;
    pattern10(noOfLines);
    cout<<endl;
    pattern11(noOfLines);
    cout<<endl;
    pattern12(noOfLines);
    cout<<endl;
}