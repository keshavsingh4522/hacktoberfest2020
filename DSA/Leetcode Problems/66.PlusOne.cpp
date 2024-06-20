class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
                digits[i]=digits[i]+1;
                break;
            }
            
        }if(digits[0]) 
            return digits;

        else {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
/*
works till long long values 
class Solution {
public:
    long long int  count(long long int a){
        int count=0;
        if(a==0){
            count=1;
        }
        while(a>0){
            count ++;
            a=a/10;
        }
        return count;
    }
    vector<int> plusOne(vector<int>& digits) {
        long long int digit=0;
        for(int i=0;i<digits.size();i++){
            digit=digit*10+digits[i];
        }
        long long int count1=count(digit);
        digit=digit+1;
        long long int count2=count(digit);
        if(count2>count1){
            int n=digits.size();
            for(int i=0;i<=digits.size();i++){
                if(i==digits.size()){
                    digits.push_back(digit);
                    break;
                }
                else{
                    digits[i]=digit/pow(10,n);
                    digit=digit%(long long int)pow(10,n);
                    n--;
                }
            }
        }
        else{
            int n=digits.size()-1;
            for(int i=0;i<digits.size();i++){
                digits[i]=digit/pow(10,n);
                digit=digit%(long long int)pow(10,n);
                n--;
            }
        }
        return digits;
    }
};
*/