public class trappingw {
public static void value(int hight[]){
    //calculate left max boundary
    int n=hight.length-1;
    int leftmax[] =new int[n];
    leftmax[0]=hight[0];
    for(int i=0;i<n;i++){
        leftmax[i]=Math.max(hight[i],leftmax[i-1]);
    }


    //calculate right max boundary
    int rightmax[]= new int[n];
    rightmax[n-1]=hight[n-1];
    for(int i=n-2;i>0;i--){
        rightmax[i]=Math.max(hight[i],rightmax[i+1]);
    }

    //loop{
        int trappedw=0;
        for(int i=0;i<n;i++){
            //water level minval
            int waterlevel=Math.min(rightmax[i], leftmax[i]);
            //trapping water}
            trappedw+=waterlevel-hight[i];
        }
        System.out.print(trappedw);



}
    public static void main(String[] args){
       int hight[]={4,2,0,6,3,2,5};
       value(hight);       
    }
}    
