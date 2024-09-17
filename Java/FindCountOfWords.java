package abc.test;


public class FindCountOfWords {

	public static void main(String[] args) {
		//input string
		String input1="dwsrrrrrmkdrrrrr";
		//input word
		String word="rr";
	
		int count=0;
		
		for(int i=0; i<(input1.length()-word.length()+1);i++) {
			if(word.equals(input1.substring(i, i+word.length())))
				count++;
		}
		
		//total count of words in string
		System.out.println(count);
	}

}
