class Solution {
public:
    string defangIPaddr(string address) {
        string answer="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                answer=answer+'['+'.'+']';
            }
            else{
                answer+=address[i];
            }
        }
        return answer;
    }
};