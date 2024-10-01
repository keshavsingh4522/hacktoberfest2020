class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        
        if(len2>len1){
            swap(a,b);
            swap(len1,len2);
        }
        for(int i=0;i<len1-len2;i++){
            b.insert(i,"0");
        }
        
        string result = "";
        int i=0;
        int carry = 0;
        reverse(a.begin(),a.end());        
        reverse(b.begin(),b.end());

        while(i!=a.size()){
            int sum = carry + (a[i]-'0') + (b[i]-'0');
            carry = sum/2;
            result += sum%2 + '0'; 
            i++;
        }       
        if(carry) 
            result += carry + '0';
        reverse(result.begin(),result.end());
        return result;    
    }
};
