class Solution {
    public int countGoodSubstrings(String s) {
        int count=0;
        int l=s.length();
        for(int i=2;i<l;i++){
            char c1=s.charAt(i-2);
             char c2=s.charAt(i-1);
             char c3=s.charAt(i);
            if(c1!=c2 &&c1!=c3 && c2!=c3)
                count++;
        }
        return count;
    }
}
