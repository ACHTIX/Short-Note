#include <stdio.h>
#include <stdlib.h>

#define NAME 190

type namepototype();

int main()
{
    char name[];
    int name = 10;
    float name = 11;
    type name = 10 , num = 19;

    return var / num;

}

type namepototype()
{
    int result = 1, i;
    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void scanf();
{
    int number;    
    printf("enter a number:");    

    scanf("%d",&number);    
    printf("cube of number is:%d ",number*number*number);    
    
    return 0;  
}

//atoi() ฟังก์ชันที่เปลี่ยนค่า string ให้เป็นตัวเลขจำนวนเต็ม (integer) ที่สามารถนำไปคำนวณได้
//atof() ฟังก์ชันที่ใช้เปลี่ยนค่า string ให้เป็นตัวเลขจำนวนทศนิยม (floating point) ที่สามารถนำไปคำนวณได้

void main()
{
    char hour_str[4], min_str[3];
    int hour, min;

    printf("Enter hour: ");
    fgets(hour_str, 4, stdin);

    printf("Enter minute: ");
    gets(min_str);

    hour = atoi(hour_str);
    min = atoi(min_str);
    if (hour < 24 && min <= 60) {
        printf("Time is %02d:%02d", hour, min);
    }
}

//atoll ฟังก์ชันที่เปลี่ยนค่า input ให้เป็น long long
long long gcd(long long n, long long m){
  if(m==0){
    return n;
  }
  return gcd(m,n%m);
}

int main(){
  char sn[15],sm[15];
  fgets(sn,15,stdin);
  fgets(sm,15,stdin);
  long long n = atoll(sn);
  long long m = atoll(sm);
  if (n<m){
    int tmp = n;
    n=m;
    m=tmp;
  }
  long long Gcd =gcd(n,m);
  printf("GCD: %lld\n",Gcd);
  printf("LCM: %lld\n",(n*m)/Gcd);
}

//if-else
if ( x == 0 && y == 0)
        printf("Center");
    
    else if ( x > 0 && y == 0 )
        printf("East");
    
    else if ( x < 0 && y == 0 )
        printf("West");

    else if ( x == 0 && y > 0)
        printf("North");

    else if ( x == 0 && y < 0)
        printf("South");

    else if ( x > 0 && y > 0 )
        printf("North-east");
    
    else if ( x < 0 && y > 0 )
        printf("North-west");
    
    else if ( x < 0 && y < 0 )
        printf("South-west");
    
    else if ( x > 0 && y < 0 )
        printf("South-east");
    return 0;
}

//while
void main()
{
     char i[5];
     int num;

     fgets(i , 5 , stdin);

     num = atoi(i);
     while(num >= 0)
     {
          printf("%d\n" , num);
          num--;
     }
}

//atof() ฟังก์ชันที่ใช้เปลี่ยนค่า string ให้เป็นตัวเลขจำนวนทศนิยม (floating point) ที่สามารถนำไปคำนวณได้

#include<stdio.h>

int main(){
    float input, value, result;
    char operator;
    printf("Initial Value: ");
    scanf("%f", &value);
    result = value;
    while(1){
        printf("\nOperator: ");
        scanf("%s", &operator);
        if(operator == '+' || operator == '-' || operator == '*' || operator == '/' ){
            printf("Input Value: ");
            scanf("%f", &input);
            if(operator == '+'){
                result += input;
                printf("Present Value is %.4f\n", result);
            }else if(operator == '-'){
                result -= input;
                printf("Present Value is %.4f\n", result);
            }else if(operator == '*'){
                result *= input;
                printf("Present Value is %.4f\n", result);
            }else if(operator == '/'){
                result /= input;
                printf("Present Value is %.4f\n", result);
            }
        }else{
            break;
        }
    }
    printf("\n");
    printf("Finish Calculation. Final Value is %.4f", result);
}

int a=4, b=3, c, d, e;
float f=2,g=5, h, i, j, k;

c = f/b*f;                 /* c = 1 */
h = a++/(float)b;          /* h = 1.33 */
j = (float)c/h--;          /* j = 0.75 */
d = b*h/c;                 /* d = 1 */
i = d*f+h--;               /* i = 2.33 */
e = a*d++/i;               /* e = 2 */
k = (int)i*d/(float)a;     /* k = 0.80 */

int a=5, b=2;

1. a++%b>>2        /* Ans1 = 0 */
2. a|b+3           /* Ans2 = 5 */
3. (b<<1)*a        /* Ans3 = 20 */
4. a+(7&b)         /* Ans4 = 7 */
5. --a*b%3<<2      /* Ans5 = 8 */
6. (a+5*b>>1)<<2   /* Ans6 = 28 */

int x=1, y=0, z=32;
 float i=65;
 char a='A', b='a';

1. (b==a+z)&&(x>y)        /*Ans1 = t */
2. (y==z)&&(!y)           /*Ans2 = f */
3. (a/4==i/4)||(!z)       /*Ans3 = f */
4. (z>=y)&&(a!=65)        /*Ans4 = f */
5. (x*y)||(x)&&(z%5)      /*Ans5 = t */
6. (b<i)||(z/2)           /*Ans6 = t */

int a[10] = {0, 1}, *ptr;
int  k;
ptr  =  a+2;
for(k=2; k<10; k++)
    a[k] = a[k-1]+a[k-2];

*ptr = 1

*(ptr+1) = 2

ptr = FFE8

ptr[3] = 5

ptr[-1] = 1

&a[4] = FFF0

*(ptr+2) = 3

ptr+3 = FFF4

&ptr[3] = FFF4

ptr[5] = 13

int i, j=12;
int *pi, *pj=&j;
*pj = j+3;
i = *pj+7;
pi = pj;
*pi = i+j;

&i = FF04

&j = FF00

pj = FF00

*pj = 37

i = 22

pi = FF00

*pi = 37

pi+2 = FF08

*pi+2 = 39

*pi+*pj = 
74

เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำ ที่ทำการเก็บตัวแปรชนิด int ขนาด 20 integers โดยหน่วยความจำดังกล่าวถูกชี้โดย pointer A
A=(int*)malloc(20*sizeof(int))

เขียนประโยคคำสั่งเพื่อทำการจองพื้นที่หน่วยความจำ ที่ทำการเก็บตัวแปรชนิด int ขนาด 40 byte โดยกำหนดให้ค่าเป็น 0 ของหน่วยความจำที่ชี้โดย pointer B
B=(int*)calloc(10,sizeof(int))

ให้ทำการลดพื้นที่การจองในข้อ 1 เป็น 10 intergers
A=realloc(A,10*sizeof(int))

ให้ทำการเพิ่มพื้นที่การจองในข้อ 2 เป็น 15 intergers
B=realloc(B,15*sizeof(int))

float **ptr;
int i,m,n;
ptr=(float**)malloc(m*sizeof(float*));
for(i=0;i<m;i++)
    ptr[i]=(float*)malloc(n*sizeof(float));
/* Do something with ptr */
for(i=0;i<m;i++)
free(ptr[i]);
free(ptr);