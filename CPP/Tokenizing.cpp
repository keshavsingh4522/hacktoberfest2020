#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){

	char Mystring[50] = "x=45; y=22; z=91";
	
	char *token = strtok(Mystring ,"=;" );
	
	while(token != NULL){
		cout<<token <<endl;
		token = strtok(NULL, "=;");
	}

return 0;

}
