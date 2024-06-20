import java.util.*;


class longest_common_substring
{
	public static void main(String s[])
	{
		String text1="abcde";
		String text2="ace";
		char ch1[] = text1.toCharArray();
        char ch2[] = text2.toCharArray();
		//System.out.println(ch1);
		List<Character> al = new ArrayList<>();
        HashMap<Character,Integer> hm = new HashMap<>();
		for(int i=0;i<ch1.length;i++)
        {
            if(!hm.containsKey(ch1[i]))
            {
                hm.put(ch1[i],i);

            }
        }
        
        //System.out.println(hm);
		
		//If ch 1 contains characters of ch2 append them in a list.
		for(int i=0;i<ch2.length;i++)
		{
			if(hm.containsKey(ch2[i]))
			{
				al.add(ch2[i]);
			}
		}
		
		//Converting character list to String.
	    String str = al.toString().replaceAll("[,\\s\\[\\]]", "");
		System.out.println(str);
        
				
        
        
 	}
}
	
	 
