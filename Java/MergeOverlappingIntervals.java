/*Given a collection of intervals, merge all overlapping intervals.
For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.*/

import java.io.*;
import java.util.*;
class Interval
{
    int start;
    int end;
    Interval(int start, int end)
    {
        this.start=start;
        this.end=end;
    }
}
public class Merge_overlapping
{
    public ArrayList<Interval> merge(ArrayList<Interval> intervals)
    {
        ArrayList<Interval> ans=new ArrayList<>();
        Collections.sort(intervals,(Interval a,Interval b)->a.start-b.start);
        int start=intervals.get(0).start;
        int end=intervals.get(0).end;
        for(int i=1;i<intervals.size();i++)
        {
            if(Math.max(start,intervals.get(i).start)<=Math.min(end,intervals.get(i).end))
                end=Math.max(end, intervals.get(i).end);
            else
            {
                ans.add(new Interval(start,end));
                start=intervals.get(i).start;
                end=intervals.get(i).end;
            }
         }
        ans.add(new Interval(start,end));
        Collections.sort(ans,(Interval a,Interval b)->a.start-b.start);
        return ans;
    }
    public static void main(String[] args)throws IOException
    {
        //Scanner sc=new Scanner(System.in);
        ArrayList<Interval> inter=new ArrayList<>();
        int s[]={1,2,8,15};
        int e[]={3,6,10,18};
        for(int i=0;i<4;i++)
        {
            inter.add(new Interval(s[i],e[i]));
        }
        Merge_overlapping ob=new Merge_overlapping();
        ArrayList<Interval> inter1=ob.merge(inter);
        for(int i=0;i<inter1.size();i++)
        {
            System.out.println(inter1.get(i).start+","+inter1.get(i).end);
        }
    }
}

