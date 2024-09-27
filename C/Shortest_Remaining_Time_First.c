#include<stdio.h>
#include<string.h>

int main()
{
	int n,bt[100],at[100],ct[100],st[100],rt[100],tat[100],wt[100],p[100];
	int i,j,btr[100],comp[100];
	float avg_tat,avg_wt,avg_rt,s_tat=0.0,s_wt=0.0,s_rt=0.0,s_it=0.0;
	memset(comp,0,sizeof(comp));
	printf("SHORTEST REMAINING TIME FIRST\n");
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("....Enter the arrival time and brust time of each process....");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the at and bt of process %d =",(i+1));
		scanf("%d\n %d",&at[i],&bt[i]);
		p[i]=i+1;
		btr[i]=bt[i];
	}
	int c_t=0,completed=0,prev=0;
	while(completed != n)
	{
		int idx=-1,mn = 10000000;
        for(int i = 0; i < n; i++)
		{
			if(at[i] <= c_t && comp[i] == 0)
			{
				if(btr[i] < mn)
				{
					mn = btr[i];
                    idx = i;
            	}
                if(btr[i] == mn)
				{
                    if(at[i] < at[idx])
					{
                        mn = btr[i];
                        idx = i;
                    }
                }
            }
        }
        if(idx<n && idx>=0)
		{
            if(btr[idx] == bt[idx])
			{
                st[idx] = c_t;
                s_it += st[idx] - prev;
            }
            btr[idx] -= 1;
            c_t++;
            prev = c_t;

            if(btr[idx] == 0)
			{
                ct[idx] = c_t;
            	tat[idx] = ct[idx] - at[idx];
            	wt[idx] = tat[idx] - bt[idx];
            	rt[idx] = st[idx] - at[idx];

        		s_tat += tat[idx];
        		s_wt += wt[idx];
            	s_rt += rt[idx];
              		
            	comp[idx] = 1;
            	completed++;
            }
        }
        else
		{
            c_t++;
        }
    }

	float m;
	m=n;
	avg_tat=s_tat/m;
	avg_wt=s_wt/m;
	avg_rt=s_rt/m;
	printf("Process	a_t	b_t	s_t	c_t	t_a_t	w_t	r_t\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%d	%d	%d\n",p[i],at[i],bt[i],st[i],ct[i],tat[i],wt[i],rt[i]);
	}
	printf("\nAverage TAT is %f\n",avg_tat);
	printf("\nAverage WT is %f\n",avg_wt);
	printf("\nAverage RT is %f\n",avg_rt);
	return 0;
}