#include <stdio.h>

int main ()
{
    int Table[999][6]= {0};
    int i=0,j=0,num_table =1,num_reserve=0,rol=0;
    int ro,co;
//input
    scanf("%i",&num_table);
    if (num_table == 0)
    {
      printf ("ERROR");
    }
    else if (num_table <= 0)
    {
      printf ("ERROR");
    }
    else if (num_table >= 40)
    {
      printf ("ERROR!");
    }
    else
    {
    scanf("%d",&num_reserve);
    if((num_table%6)==0)
        rol=num_table/6;
    else
        rol=(num_table/6)+1;
    for(int y=0;y<=(rol);y++)
    {
        for(int x=0;x<6;x++)
            {
                Table[y][x]=1;
                i=i+1;
                if(num_table==i){
                  break;  
                }
                
            }
    }
    i=0;
    while(i<num_reserve)
	    {
	     scanf("%i %i",&ro,&co);
	     if(ro>rol||co>6)
	     {
	         printf("%i %i Out of range!",ro,co);
	     }
	     else
	     {
	         if(Table[ro-1][co-1]==1)
	         {
	             Table[ro-1][co-1]=2;
	             i++;
	         }else if(Table[ro-1][co-1]==2)
	         {
	            printf("%i %i Is Reserve",ro,co);
	         }else{
	             printf("%i %i Out of range!",ro,co);
	         }
	         
	     }
	     
	    }
    }
    for(int y=0;y<(rol);y++)
    {
        for(int x=0;x<6;x++)
            {
                if(Table[y][x]==1)
                printf("x");
                if(Table[y][x]==2)
                printf("s");
                if(Table[y][x]==0)
                break;
            }
            printf("\n");
    }

  return 0;
}