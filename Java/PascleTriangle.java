import java.util.*;
public class PascleTriangle
{
    public List<List<Integer>> generate(int num)
    {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> row, prev = null;
        for(int i=0; i<num; ++i)
        {
            row = new ArrayList<Integer>();
            for(int j=0; j<=i;++j)
            {
                if(j==0||j==i)// Imp Check Point
                {
                    row.add(1);
                }
                else
                {
                    row.add(prev.get(j-1)+prev.get(j));
                }
                
            }
            prev = row;
            res.add(row);
        }
        return res;
    }
}