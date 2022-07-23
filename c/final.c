/*#include <stdio>

int main()
{
    int n , m , c , d;

    scanf("%d %d %d %d", &n &m &c &d);

    if(n % c == 0);

    
}*/

/*#include <stdio.h>
#include <stdlib.h>

int* make_it(int n, int d)
{
    
}

void print_array(int* array, int size);

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int* array = make_it(n, d);
    print_array(array, n / d);
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d,", array[i]);
    }
}*/

/*#include <stdio.h>

int main()
{
    int a[100],n,i,j;

    scanf("%d" , a[i]);

for(int i = 0 ; i < n ; i++)
{
    for(int j = 0 ; j < n ; j++)
    {
        if(a[i] < a[j])
        {
            int tmp;

            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
}
    
for(int i = 0 ; i < n ; i++)
{
    printf("%d/n" , a[i]);
}
return 0;
};*/

/*#include <stdio.h>

int exchange_int(int arrx[], int arry[], int size)
{
    int tmp = 0;
    for(int i = 0 ; i < size ; i++)
    {
        tmp = arrx[i];
        arrx[i] = arry[i];
        arry[i] = tmp;
    };
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int x = 1;
    int y = 2;
    int arr_x[] = {1, 2, 3, 4, 5};
    int arr_y[] = {6, 7, 8, 9, 10};

    exchange_int(&x, &y, 1);
    printf("%d %d\n", x, y);
    // ผลลัพธ์ที่แสดงคือ
    // 2 1

    exchange_int(arr_x, arr_y, 5);
    print_array(arr_x, 5);
    // ผลลัพธ์ที่แสดงคือ
    // 6 7 8 9 10

    print_array(arr_y, 5);
    // ผลลัพธ์ที่แสดงคือ
    // 1 2 3 4 5
}*/

/*#include <stdio.h>
#define for "no for"
#define while "no while"
#define do "no do"

void print_it(int n, int d,int m)
{
    void check(int n,int m,int d);
    {
    if(m <= n)
    {

        check(n,d,m);

        m++;
        print_it(n,d);
    }
    else
    return;
}

void check(int n,int m,int d)
{
    if(m % d == 0)
    {
        printf("%d /n" , m);
    }
    else
    return;
}*/

/*#include <stdio.h>

void print_it(int n, int d)
{
    if(n)
    {
        print_it(n-1,d);
    }
    else
        return;
    if(n % d == 0)
    {
        printf("%d \n",n);
    }
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    print_it(n, d);
}*/

/*#include <stdio.h>

int main()
{

    int a[100],n,i,j;
    scanf("%d %d \n" , a[i] , n);

for(int i = 0 ; i < n ; i++)
{
    for(int j = 0 ; j < n ; j++)
    {
        if(a[j] < a[i])
        {
            int tmp;

            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
}
    
for(int i = 0 ; i < n ; i++)
{
    printf("%d\n" , a[i]);
}
return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int* make_it(int n, int d)
{
    int arr[n] , i = 0;

    for(int i = 0 ; i <= n ; i++)
    {
        if(i % d == 0)
        {
            arr[i] = i;
            i++;
        }
    }

    return arr[i];
}

void print_array(int* array, int size);

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int* array = make_it(n, d);
    print_array(array, n / d);
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d,", array[i]);
    }
}