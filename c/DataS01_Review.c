#include <stdio.h>

int main ()
{
  float score[999][2]= {0};
  char name[999][30] = {0};
  int n=0,b;
  float a;
//input
  scanf("%d",&n);
  if (n == 0)
    {
      printf ("No reviews found");
    }
  else if (n <= 0)
    {
      printf ("ERROR");
    }
  else
    {
      for (int i = 0; i < n; i++)
     {
     scanf ("%f %s",&score[i][0], name[i]);
     score[i][1]=i;
     }
    }
// sorting
     for (int i = 0; i < n; ++i) 
        {
            
            for (int j = i + 1; j < n; ++j) 
            {
                if (score[i][0] < score[j][0]) 
                {
                    a = score[i][0];
                    score[i][0] = score[j][0];
                    score[j][0] = a;
                    b=score[i][1];
                    score[i][1]=score[j][1];
                    score[j][1] = b;
                }
            }
            
        }
    
// output
    int ans=0;
    for(int i = 0; i < n; i++)
     {   
         ans=score[i][1];
         printf ("%.2f %s (id:%.f)\n",score[i][0], name[ans],score[i][1]+1);
     }
  return 0;
}