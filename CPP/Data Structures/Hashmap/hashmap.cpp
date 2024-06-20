#include <iostream>
#include "hashmapClass.h" // Include the header file for your custom hashmap class.
#include <string>
using namespace std;

int main (){
    map <int> ourmap(13); // Create an instance of your hashmap with a size of 13.
    string key;
    int value;
    
    cout << "Enter key (Enter 0 for termination) : ";
    cin >> key;

    // Continue taking key-value pairs from the user until they enter "0".
    while (key != "0"){
        cout << "Enter Value of " << key << " : ";
        cin >> value;
        
        // Insert the key-value pair into your hashmap.
        ourmap.insert(key, value);
        
        cout << "Enter another key (Enter 0 for termination) : ";
        cin >> key;
    }
    
    cout << endl;
    
    // Display the contents of your hashmap.
    ourmap.display();
    
    // Remove a specific key ("Gopal") from your hashmap.
    ourmap.removeKey("Gopal");
    
    cout << "List after removing key" <<  endl;
    
    // Display the contents of your hashmap again after removing the key.
    ourmap.display();
    
    return 0;
}
