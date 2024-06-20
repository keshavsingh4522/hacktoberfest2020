class Solution {
public:
    string addBinary(string a, string b) {
        int na=a.size();
        int nb=b.size();
        char carry='0';
        if(na<nb){
            string temp;
            temp=a;
            a=b;
            b=temp;
        }
        na=a.size();
        nb=b.size();
        if(na>=nb){
            int i=nb-1;
            int j=na-1;
            for(;i>=0;i--){
                if(a[j]=='0' && b[i]=='0' && carry=='0'){
                    a[j]='0';
                }
                else if(a[j]=='0' && b[i]=='0' && carry=='1'){
                    a[j]='1';
                    carry='0';
                }
                else if(a[j]=='0' && b[i]=='1' && carry=='0'){
                    a[j]='1';
                }
                else if(a[j]=='1' && b[i]=='0' && carry=='0'){
                    a[j]='1';
                }
                else if(a[j]=='1' && b[i]=='0' && carry=='1'){
                    a[j]='0';
                    carry='1';
                }
                else if(a[j]=='0' && b[i]=='1' && carry=='1'){
                    a[j]='0';
                    carry='1';
                }
                else if(a[j]=='1' && b[i]=='1' && carry=='0'){
                    a[j]='0';
                    carry='1';
                }
                else if(a[j]=='1' && b[i]=='1' && carry=='1'){
                    a[j]='1';
                    carry='1';
                }
                j--;
            }
            if(carry=='0'){
                return a;
            }
            if(carry=='1'){
                while(j>=0){
                    if(a[j]=='1'){
                        a[j]='0';
                        carry='1';
                    }
                    else{
                        a[j]='1';
                        carry='0';
                        break;
                    }
                    j--;
                }
            }
            if(carry=='1'){
                return '1'+a;
            }
        }
        return a;
    }
};