



class Solution {
    public boolean isMatch(String s, String p) {
        if(p.isEmpty()){
            return s.isEmpty();
        }
        boolean firstMatch =(!s.isEmpty() && (p.charAt(0)== s.charAt(0)|| p.charAt(0)=='.'));
                             if (p.length()>=2 && p.charAt(1)=='*')
// Check the first characters if not empty.
                             {
                                 return (isMatch(s,p.substring(2)) || (firstMatch && isMatch(s.substring(1),p)));
                             // Recusively check with first match wheather substring is matching or not.
It will get incremented automatically.
			     }
                             else{
                                 return(firstMatch && isMatch(s.substring(1), p.substring(1)));
// Else String is less than 2
                             }
        }
}