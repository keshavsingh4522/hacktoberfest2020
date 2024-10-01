/***************************
*  Bhoopesh Maurya         *
***************************/
//supports alphabet,numbers,and #%*
//you can do it using switch instead of while :)

import java.util.*;
 public class Name{
public static void main (String[]args){
Scanner scan=new Scanner(System.in);
System.out.print("Enter your Name: ");
String name=scan.nextLine();
System.out.println();
int x=0;
if (name==null ||name.length()==0){
   System.out.println("Plz enter something ") ;
}
else {
String name1 = name.toUpperCase();
System.out.println("Nb of characters ="+name.length()+":P \n\n");
System.out.println("+=-+=-+=-+=-+=-+=-+=-+=-");
System.out.println("HELLO |");
System.out.println("      |");
System.out.println("     \\ /");
System.out.println("     \\|/");
System.out.println("      '\n");

while(x<name1.length()){
if (name1.charAt(x)==' '){
    System.out.println("\n\n\n");
}
else if (name1.charAt(x)=='A'){

System.out.println("\t   A");
System.out.println("\t  A A");
System.out.println("\t AAAAA");
System.out.println("\t A   A");
System.out.println("\t A   A\n");
}
else if (name1.charAt(x)=='B'){

System.out.println("\t BBBBB");
System.out.println("\t B   B ");
System.out.println("\t BBBB");
System.out.println("\t B   B");
System.out.println("\t BBBBB \n");
}
else if (name1.charAt(x)=='C'){

System.out.println("\t CCCCC");
System.out.println("\t C    ");
System.out.println("\t C    ");
System.out.println("\t C   ");
System.out.println("\t CCCCC\n");
}
else if (name1.charAt(x)=='D'){

System.out.println("\t DDDDD  ");
System.out.println("\t D   D");
System.out.println("\t D   D");
System.out.println("\t D   D");
System.out.println("\t DDDDD\n");    
} 
else if (name1.charAt(x)=='E'){

System.out.println("\t EEEEE  ");
System.out.println("\t E");
System.out.println("\t EEEEE ");
System.out.println("\t E");
System.out.println("\t EEEEE\n");    
} 
else if (name1.charAt(x)=='F'){

System.out.println("\t FFFFF  ");
System.out.println("\t F   ");
System.out.println("\t FFF");
System.out.println("\t F  ");
System.out.println("\t F\n");    
} 
else if (name1.charAt(x)=='G'){

System.out.println("\t GGGGG");
System.out.println("\t G ");
System.out.println("\t G GGG");
System.out.println("\t G   G");
System.out.println("\t GGGGG\n");
} 
else if (name1.charAt(x)=='H'){

System.out.println("\t H   H");
System.out.println("\t H   H");
System.out.println("\t HHHHH");
System.out.println("\t H   H");
System.out.println("\t H   H\n");
} 
else if (name1.charAt(x)=='I'){

System.out.println("\t IIIII");
System.out.println("\t   I");
System.out.println("\t   I");
System.out.println("\t   I");
System.out.println("\t IIIII\n");    
} 
else if (name1.charAt(x)=='J'){

System.out.println("\t  JJJJ");
System.out.println("\t     J");
System.out.println("\t   JJJ");
System.out.println("\t  J  J");
System.out.println("\t  JJJJ\n") ;  
} 
else if (name1.charAt(x)=='K'){

System.out.println("\t K  K");
System.out.println("\t K K");
System.out.println("\t KK");
System.out.println("\t K K" );
System.out.println("\t K  K\n");
} 
else if (name1.charAt(x)=='L'){

System.out.println("\t L");
System.out.println("\t L");
System.out.println("\t L");
System.out.println("\t L");
System.out.println("\t LLLLL\n");
}
else if (name1.charAt(x)=='M'){

System.out.println("\t M   M");
System.out.println("\t MM MM");
System.out.println("\t M M M");
System.out.println("\t M   M");
System.out.println("\t M   M\n");
}  
else if (name1.charAt(x)=='N'){

System.out.println("\t N   N");
System.out.println("\t NN  N");
System.out.println("\t N N N");
System.out.println("\t N  NN");
System.out.println("\t N   N\n");
} 
else if (name1.charAt(x)=='O'){

System.out.println("\t OOOOO");
System.out.println("\t O   O");
System.out.println("\t O   O");
System.out.println("\t O   O");
System.out.println("\t OOOOO\n");
} 
else if (name1.charAt(x)=='P'){

System.out.println("\t PPPPP");
System.out.println("\t P   P");
System.out.println("\t PPPPP");
System.out.println("\t P");
System.out.println("\t P\n");
} 
else if (name1.charAt(x)=='Q'){

System.out.println("\t QQQQQ");
System.out.println("\t Q   Q");
System.out.println("\t Q Q Q");
System.out.println("\t QQQQQ");
System.out.println("\t     QQ\n");
} 
else if (name1.charAt(x)=='R'){

System.out.println("\t RRRRR");
System.out.println("\t R   R");
System.out.println("\t RRRR");
System.out.println("\t R  R");
System.out.println("\t R   R\n");
} 
else if (name1.charAt(x)=='S'){

System.out.println("\t SSSSS");
System.out.println("\t S");
System.out.println("\t SSSSS");
System.out.println("\t     S");
System.out.println("\t SSSSS\n");    
} 
else if (name1.charAt(x)=='T'){

System.out.println("\t TTTTT");
System.out.println("\t   T");
System.out.println("\t   T");
System.out.println("\t   T");
System.out.println("\t   T\n");
} 
else if (name1.charAt(x)=='U'){

System.out.println("\t U   U");
System.out.println("\t U   U");
System.out.println("\t U   U");
System.out.println("\t U   U");
System.out.println("\t UUUUU\n");
} 
else if (name1.charAt(x)=='V'){

System.out.println("\t V     V");
System.out.println("\t  V   V");
System.out.println("\t   V V");
System.out.println("\t    V \n");    
 } 
else if (name1.charAt(x)=='W'){

System.out.println("\t W     W");
System.out.println("\t W     W");
System.out.println("\t W  W  W");
System.out.println("\t W W W W");
System.out.println("\t WW   WW\n");
} 
else if (name1.charAt(x)=='X'){

System.out.println("\t X   X");
System.out.println("\t  X X");
System.out.println("\t   X");
System.out.println("\t  X X");
System.out.println("\t X   X\n");    
} 
else if (name1.charAt(x)=='Y'){

System.out.println("\t Y   Y");
System.out.println("\t  Y Y");
System.out.println("\t   Y");
System.out.println("\t   Y");
System.out.println("\t   Y \n");
} 
else if (name1.charAt(x)=='Z'){

System.out.println("\t ZZZZZ");
System.out.println("\t    Z");
System.out.println("\t   Z");
System.out.println("\t  Z");
System.out.println("\t ZZZZZ\n");    
} 
else if (name1.charAt(x)=='*'){
System.out.println("\t    * ");
System.out.println("\t    *");
System.out.println("\t *******");
System.out.println("\t   * * ");
System.out.println("\t  *   *\n");
}
else if (name1.charAt(x)=='%'){
System.out.println("\t   %%   %");
System.out.println("\t  %%   %");
System.out.println("\t      %");
System.out.println("\t     %   %%");
System.out.println("\t    %   %%\n");
}
else if (name1.charAt(x)=='#'){
System.out.println("\t    #   #");
System.out.println("\t  ########"); 
System.out.println("\t   #   #");
System.out.println("\t ########");
System.out.println("\t  #   #\n");
}
else if(name1.charAt(x)=='0'){
System.out.println("\t 0000");
System.out.println("\t 0  0");
System.out.println("\t 0  0");
System.out.println("\t 0  0");
System.out.println("\t 0000\n");  
     
}
else if(name1.charAt(x)=='1'){
    System.out.println("\t    1");
    System.out.println("\t   11");
    System.out.println("\t  1 1");
    System.out.println("\t    1");
    System.out.println("\t    1\n"); 

}
else if(name1.charAt(x)=='2'){
    System.out.println("\t 2222");
    System.out.println("\t    2");
    System.out.println("\t 2222");
    System.out.println("\t 2   ");
    System.out.println("\t 2222\n");
}
else if(name1.charAt(x)=='3'){
    System.out.println("\t 3333");
    System.out.println("\t    3");
    System.out.println("\t  333");
    System.out.println("\t    3");
    System.out.println("\t 3333\n");
}
else if(name1.charAt(x)=='4'){
    System.out.println("\t    4");
    System.out.println("\t  4 4");
    System.out.println("\t 44444 ");
    System.out.println("\t    4");
    System.out.println("\t    4\n");
}
else if(name1.charAt(x)=='5'){
    System.out.println("\t 5555");
    System.out.println("\t 5");
    System.out.println("\t 5555" );
    System.out.println("\t    5");
    System.out.println("\t 5555\n");
}
else if(name1.charAt(x)=='6'){
    System.out.println("\t 6666");
    System.out.println("\t 6");
    System.out.println("\t 6666");
    System.out.println("\t 6  6");
    System.out.println("\t 6666\n");
}
else if(name1.charAt(x)=='7'){
    System.out.println("\t 7777");
    System.out.println("\t    7");
    System.out.println("\t   7");
    System.out.println("\t  7");
    System.out.println("\t 7\n");
}
else if(name1.charAt(x)=='8'){
    System.out.println("\t 8888");
    System.out.println("\t 8  8");
    System.out.println("\t 8888 ");
    System.out.println("\t 8  8");
    System.out.println("\t 8888\n");
}
else if(name1.charAt(x)=='9'){
    System.out.println("\t 9999");
    System.out.println("\t 9  9");
    System.out.println("\t 9999");
    System.out.println("\t    9");
    System.out.println("\t 9999\n");
}
else System.out.println("unsupported character \n\n");

x++;
}
System.out.println("+=-+=-+=-+=-+=-+=-+=-+=-");
}
 }
 }

 
