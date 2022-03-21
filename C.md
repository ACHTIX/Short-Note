# สารบัญเนื้อหาสรุป

## 1. Introduction :bookmark_tabs: ##
## 2. Types , Operators and Expression :closed_book: ##
## 3. Control - Flow :green_book: ##
## 4. Function :orange_book: ##
## 5. Array :notebook: ## 
## 6. Structures & Unions :notebook_with_decorative_cover: ##
## 7. Pointers & Dynamic Memory Allocation :ledger: ##
## 8. characters & string :blue_book: ##
## 9. linked list :orange_book: ##
## 10. File handling in C :notebook: ## 
## 11. Example of Function in C :label: ##



> # Introduction :books:

`#include <stdio.h>` 

`#define STARTNUMBER 2`

`int main()`

`{`

`int x;`  

`}`

- คำสั่ง #include <ชื่อชุดคำสั่งในภาษาซี> จะเป็นคำสั่งที่อยู่บนสุดของโค้ด ใส่คำสั่งนี้เพื่อที่จะได้ใช้ฟังก์ชังก์ชั่นของคำสั่งต่างๆ 
:triangular_flag_on_post: Example : `printf() , putf()`

- คำสั่ง #define KEYWORD Number เป็นคำสั่งที่ใช้ในการแทนค่า 
:triangular_flag_on_post: Example : `#define STARTNUMBER 2` หมายถึง STARTNUMBER มีค่าเป็น2 
ถ้าหากต้องการเปลี่ยนค่าSTARTNUMBER ก็สามารถมาเปลี่ยนที่คำสั่งได้เลย ค่าของคำว่าSTARTNUMBERก็จะเปลี่ยนเหมือนกันทั้งBlockของโค้ดนั้น

_*นิยมตั้งชื่อเป็นตัวพิมพ์ใหญ๋_

- คำสั่ง Variable type main() เป็นคำสั่งที่ระบุว่าโค้ดนี่เป็นโค้ดหลัก ต้องมีไม่งั้นจะคอมไพไม่ผ่าน ขึ้นError

## ตัวแปร  Variable ##

- คำสั่งในการประกาศตัวแปร จะต้องระบุชนิดของตัวแปรตามด้วยชื่อ ต้องมีการประกาศตัวแปรก่อนใช้เสมอ 

**การตั้งชื่อตัวแปร**
```
1. ในชื่อตัวแปรสามารถมีได้ทั้งอักขระและตัวเลข แต่ต้องนำอักขระไว้ตัวแรก ไม่สามารถใช้ตัวเลขเป็ฯตัวเเรกได้

2. เครื่องหมาย "_" นับเป็นอักขระ นิยมใช้ในการเว้นวรรคในชื่อของตัวแปรเพื่อให้เข้าใจง่ายขึ้น
      
3. สำหรับตัวพิมพ์ใหญ่และพิมพ์เล็กในอักขระภาษาอังกฤษ ถือว่าต่างกัน เหมือนในตารางascii 
      
4. ห้ามตั้งชื่อตัวแปรให้เหมือนกับคีย์เวิร์คในภาษาซี เช่น if else int float long char
```
:triangular_flag_on_post: Example : snake_case , CamelCase , camelCase

**การประกาศตัวแปร**

- การประกาศแบบระบุประเภทข้อมูล

:round_pushpin: ` int lower, upper, step; char c, line[1000]; `

- การประกาศตัวแปรแบบกำหนดค่าข้อมูลตอนประกาศตัวแปร

:round_pushpin: ` int lower = 10, upper = 30; `

- การประกาศตัวแปรที่ระบุค่าตัวแปรด้วยนิพจน์

:round_pushpin: ` char c = 'A' + 1; `

- การประกาศตัวแปรให้เป็นค่าคงที่ โดยใช้คำสั่ง `const` เพื่อไม่ให้ค่าที่กำหนดตอนประกาศตัวแปรไม่สามารถเปลี่ยนแปลงได้ ตลอดการทำงานของโปรแกรม

:round_pushpin: ` const int step = 20; `

**สิ่งที่ต้องรู้**
      
- ทุกคำสั่งในภาษาซี จะต้องมีเครื่องหมาย " ; " เมื่อจบคำสั่งในแต่ละบรรทัด เช่น

`printf("Hello world");`

`putf("Bye world");`

- เครื่องหมาย " { } " หมายถึงขอบเขตของโค้ดนั้น หรือ Blockในโค้ดนั้น

- เครื่องหมาย " /* ข้อความ */ " เครื่องหมายคอมเม้นต์ในภาษาซี

> # Types , Operators and Expression :books:

## Data Types & Sizes :page_with_curl:

![This is an image](https://www.startertutorials.com/blog/wp-content/uploads/2016/04/data-types-sizes-in-c.png)

## Constants :page_with_curl:

หมายถึงค่าที่ไม่สามารถเปลี่ยนได้ตลอดการทำงาน มีหลายประเภทเช่น ค่าคงที่จำนวนเต็ม , ค่าคงที่จำนวนจริง , ค่าคงที่ของอักษร , ค่าคงที่สตริง ฯลฯ

### integer Constants :pencil2:

```
an integer constant 
a long constant [l , L]
unsigned constants [u , U]
insigned long constants [ul , UL]
```
:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main(void)
{
	int const i = 10;
	int j = 20;

	printf("ptr: %d\n", *ptr);

	*ptr = 100;	

	ptr = &j;		
	printf("ptr: %d\n", *ptr);

	return 0;
}
```

:printer: Output
```
error: assignment of read-only location ‘*ptr’
```

### Float Constants :pencil2:

```
double constants
float constants [f , F]
long double constants [l , L] 
```
:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    const float PI = 3.14;
    int r = 2;
    double result = 2 * PI * r;
    printf("Area of the circle is %f", result );
    return 0;
}
```

:printer: Output
```
Area of the circle is 12.560000
```

### Binary , Octal , Hexadecimal Constants :pencil2:

**- Binary**

ค่าคงที่ของเลขฐานสอง ใช้สัญลักษณ์แทนเป็น [ 0b , 0B ]

:triangular_flag_on_post: Example : 0b011010 , 0B110100

**- Octal**

ค่าคงที่ของเลขฐานแปด ใช้สัญลักษณ์แทนเป็น [ 0 ]

:triangular_flag_on_post: Example : 0342 

**- Hexadecimal**

ค่าคงที่ของเลขฐานสิบหก ใช้สัญลักษณ์แทนเป็น [ 0x 0X ]

:triangular_flag_on_post: Example : 0x189 , 0X123

### Character Constants :pencil2:

ค่าคงที่ของตัวอักษร จะใช้เครื่องหมาย [' '] (single quote) 

:triangular_flag_on_post: Example : 'A' , 'b' , 'c'

**Escape Sequences**

| symbol  |         meaning        |
| ------  | ---------------------- |
|  `\a`   | alert(bell) character  |
|  `\b`   |        backspace       |
|  `\f`   |        formfeed        |
|  `\n`   |        nexline         |
|  `\r`   |    carriage return     |
|  `\t`   |     horizontal tab     |
|  `\v`   |      vertical tab      |
|  `\\`   |       backslash        |
|  `\?`   |     question mark      |
|  `\'`   |      single quote      |
|  `\"`   |      double quote      |
| `\000`  |      octal number      |
| `\xhh`  |   hexadecimal number   |

### Srting Constants :pencil2:

ค่าคงที่ของตัวอักษร จะใช้เครื่องหมาย [" "] (double quote) 

[ "" ] เป็น empty string หรือสตริงว่าง

:triangular_flag_on_post: Example : "empty string" 

## Arithmetic Operators :page_with_curl:

| Operator |             Meaning of Operator            |
| -------- | ------------------------------------------ |
|    +	   |           addition or unary plus           |
|    -	   |         subtraction or unary minus         |
|    *     |              multiplication                |
|    /     |                 division                   |
|    %     | remainder after division (modulo division) |

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a = 9,b = 4, c;
    
    c = a+b;
    printf("a+b = %d \n",c);
    c = a-b;
    printf("a-b = %d \n",c);
    c = a*b;
    printf("a*b = %d \n",c);
    c = a/b;
    printf("a/b = %d \n",c);
    c = a%b;
    printf("Remainder when a divided by b = %d \n",c);
    
    return 0;
}
```

:printer: Output

```
a+b = 13
a-b = 5
a*b = 36
a/b = 2
Remainder when a divided by b=1
```

## Relational Operators :page_with_curl:

| Operator |     Meaning of Operator    |           Example            |
| -------- | -------------------------- | ---------------------------- |
|    ==    |          Equal to          |   5 == 3 is evaluated to 0   |
|    >     |        Greater than        |   5 > 3 is evaluated to 1    |
|    <     |          Less than         |   5 < 3 is evaluated to 0    |
|    !=    |        Not equal to        |   5 != 3 is evaluated to 1   |
|    >=    |  Greater than or equal to	|   5 >= 3 is evaluated to 1   |
|    <=    |   Less than or equal to    |   5 <= 3 is evaluated to 0   |

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a = 5, b = 5, c = 10;

    printf("%d == %d is %d \n", a, b, a == b);
    printf("%d == %d is %d \n", a, c, a == c);
    printf("%d > %d is %d \n", a, b, a > b);
    printf("%d > %d is %d \n", a, c, a > c);
    printf("%d < %d is %d \n", a, b, a < b);
    printf("%d < %d is %d \n", a, c, a < c);
    printf("%d != %d is %d \n", a, b, a != b);
    printf("%d != %d is %d \n", a, c, a != c);
    printf("%d >= %d is %d \n", a, b, a >= b);
    printf("%d >= %d is %d \n", a, c, a >= c);
    printf("%d <= %d is %d \n", a, b, a <= b);
    printf("%d <= %d is %d \n", a, c, a <= c);

    return 0;
}
```

:printer: Output

```
5 == 5 is 1
5 == 10 is 0
5 > 5 is 0
5 > 10 is 0
5 < 5 is 0
5 < 10 is 1
5 != 5 is 0
5 != 10 is 1
5 >= 5 is 1
5 >= 10 is 0
5 <= 5 is 1
5 <= 10 is 1 
```

## Logical Operators :pencil2:

| Operator |   Meaning   |
| -------- | ----------- |
|    &&	   | Logical AND.| 
|    ||	   | Logical OR. |
|    !	   | Logical NOT.| 

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a = 5, b = 5, c = 10, result;

    result = (a == b) && (c > b);
    printf("(a == b) && (c > b) is %d \n", result);

    result = (a == b) && (c < b);
    printf("(a == b) && (c < b) is %d \n", result);

    result = (a == b) || (c < b);
    printf("(a == b) || (c < b) is %d \n", result);

    result = (a != b) || (c < b);
    printf("(a != b) || (c < b) is %d \n", result);

    result = !(a != b);
    printf("!(a != b) is %d \n", result);

    result = !(a == b);
    printf("!(a == b) is %d \n", result);

    return 0;
}
```
:printer: Output

```
(a == b) && (c > b) is 1 
(a == b) && (c < b) is 0 
(a == b) || (c < b) is 1 
(a != b) || (c < b) is 0 
!(a != b) is 1 
!(a == b) is 0 
```

## Comma Operators :pencil2:

เครื่องหมาย [ , ] ใช้ในการคั่นระหว่างนิพจน์

:triangular_flag_on_post: Example :

`int a, c = 5, d;`

```
if
    a = 1 , printf("kasetsart university") , b = 2;
```

## Increment and Decrement Operators :page_with_curl:

- Increment [n++ , ++n]

- Decrement [n-- , --n]

- ความแตกต่างของตำแหน่งเครื่อง 

:triangular_flag_on_post: Example : 

- ++x = 1 -> ++x = 2 #x = 2

- x++ = 1 -> x++ = 1 #x = 2

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a = 10, b = 100;
    float c = 10.5, d = 100.5;

    printf("++a = %d \n", ++a);
    printf("--b = %d \n", --b);
    printf("++c = %f \n", ++c);
    printf("--d = %f \n", --d);

    return 0;
}
```

:printer: Output

```
++a = 11
--b = 99
++c = 11.500000
--d = 99.500000
```

## Bitwise Operators :page_with_curl:

| Operators	|  Meaning of operators  |
| --------- | ---------------------- |
|     &	    |      Bitwise AND       |
|     |	    |      Bitwise OR        |
|     ^	    |  Bitwise exclusive OR  |
|     ~	    |   Bitwise complement   |
|    <<     |      Shift left        |
|    >>	    |      Shift right       |

## Assignment Operators :page_with_curl:

| Operator | Example | Same as |
| -------- | ------- | ------- |
|     =    |  a = b  |  a = b  |
|    +=    |  a += b | a = a+b |
|    -=    | a -= b	 | a = a-b |
|    *=    |  a *= b | a = a*b |
|    /=    | a /= b	 | a = a/b |
|    %=    | a %= b	 | a = a%b |

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a = 5, c;

    c = a;      // c is 5
    printf("c = %d\n", c);
    c += a;     // c is 10 
    printf("c = %d\n", c);
    c -= a;     // c is 5
    printf("c = %d\n", c);
    c *= a;     // c is 25
    printf("c = %d\n", c);
    c /= a;     // c is 5
    printf("c = %d\n", c);
    c %= a;     // c = 0
    printf("c = %d\n", c);

    return 0;
}
```

:printer: Output

```
c = 5 
c = 10 
c = 5 
c = 25 
c = 5 
c = 0
```

> # Control - Flow :books:

## If :page_with_curl:

```
if (test expression) 
{
   // code
}
```

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/working-c-if-statement.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // true if number is less than 0
    if (number < 0) {
        printf("You entered %d.\n", number);
    }

    printf("The if statement is easy.");

    return 0;
}
```
:printer: Output 1

```
Enter an integer: -2
You entered -2.
The if statement is easy.
```

:printer: Output 2

```
Enter an integer: 5
The if statement is easy.
```

## If - Else :page_with_curl:

```
if (test expression) {
    // run code if test expression is true
}
else {
    // run code if test expression is false
}
```

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/how-if-else-works-c-programming.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() 
{
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    /* True if the remainder is 0 */
    if  (number%2 == 0) {
        printf("%d is an even integer.",number);
    }
    else {
        printf("%d is an odd integer.",number);
    }

    return 0;
}
```

:printer: Output

```
Enter an integer: 7
7 is an odd integer.
```

## Else - If :page_with_curl:

```
if (test expression1) {
   // statement(s)
}
else if(test expression2) {
   // statement(s)
}
else if (test expression3) {
   // statement(s)
}
.
.
else {
   // statement(s)
}
```

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
    int number1, number2;
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);

    //checks if the two integers are equal.
    if(number1 == number2) {
        printf("Result: %d = %d",number1,number2);
    }

    //checks if number1 is greater than number2.
    else if (number1 > number2) {
        printf("Result: %d > %d", number1, number2);
    }

    //checks if both test expressions are false
    else {
        printf("Result: %d < %d",number1, number2);
    }

    return 0;
}
```

:printer: Output

```
Enter two integers: 12
23
Result: 12 < 23
```

## Switch :page_with_curl:

```
switch (expression)
​{
    case constant1:
      // statements
      break;

    case constant2:
      // statements
      break;
    .
    .
    .
    default:
      // default statements
}
```

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/flowchart-switch-statement.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
    char operation;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operation);
    printf("Enter two operands: ");
    scanf("%lf %lf",&n1, &n2);

    switch(operation)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}
```

:printer: Output

```
Enter an operator (+, -, *, /): -
Enter two operands: 32.5
12.4
32.5 - 12.4 = 20.1
```

## While [Loops] :page_with_curl:

```
while (testExpression) 
{
  // the body of the loop 
}
```

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/c-while-loop_0.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
  int i = 1;
    
  while (i <= 5) {
    printf("%d\n", i);
    ++i;
  }

  return 0;
}
```

:printer: Output

```
1
2
3
4
5
```

## Do - While [Loops] :page_with_curl:

```
do 
{
  // the body of the loop
}
while (testExpression);
```

![This is an image]()

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
  double number, sum = 0;

  // the body of the loop is executed at least once
  do {
    printf("Enter a number: ");
    scanf("%lf", &number);
    sum += number;
  }
  while(number != 0.0);

  printf("Sum = %.2lf",sum);

  return 0;
}
```

:printer: Output

```
Enter a number: 1.5
Enter a number: 2.4
Enter a number: -3.4
Enter a number: 4.2
Enter a number: 0
Sum = 4.70
```

## For [Loops] :page_with_curl:

```
for (initializationStatement; testExpression; updateStatement)
{
    // statements inside the body of loop
}
```

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/c-for-loop.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
  int i;

  for (i = 1; i < 11; ++i)
  {
    printf("%d ", i);
  }
  return 0;
}
```

:printer: Output

```
1 2 3 4 5 6 7 8 9 10
```

## Break :page_with_curl:

คำสั่ง `break;` ใช้เมื่อต้องการจะหยุดการวนลูป ของfor loop , while loop เป็นต้น

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/c-break-statement-works.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
   int i;
   double number, sum = 0.0;

   for (i = 1; i <= 10; ++i) {
      printf("Enter n%d: ", i);
      scanf("%lf", &number);

      // if the user enters a negative number, break the loop
      if (number < 0.0) {
         break;
      }

      sum += number; // sum = sum + number;
   }

   printf("Sum = %.2lf", sum);

   return 0;
}
```

:printer: Output

```
Enter n1: 2.4
Enter n2: 4.5
Enter n3: 3.4
Enter n4: -3
Sum = 10.30
```

## Continue :page_with_curl:

คำสั่ง `continue;` ใช้เมื่อต้องการจะบังคับให้ลูปนั้นๆวนลูปซ้ำขึ้นมาใหม่ ของ while loop , do-while loop แต่ในกรณีของfor loopเมื่อลูปกำลังทำงานให้นิพจน์ที่สาม แล้วย้อนกลับมาทำงานในนิพจน์ที่สอง 

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/c-continue-statement-works.jpg)

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
   int i;
   double number, sum = 0.0;

   for (i = 1; i <= 10; ++i) {
      printf("Enter a n%d: ", i);
      scanf("%lf", &number);

      if (number < 0.0) {
         continue;
      }

      sum += number; // sum = sum + number;
   }

   printf("Sum = %.2lf", sum);

   return 0;
}
```

:printer: Output

```
Enter n1: 1.1
Enter n2: 2.2
Enter n3: 5.5
Enter n4: 4.4
Enter n5: -3.4
Enter n6: -45.5
Enter n7: 34.5
Enter n8: -4.2
Enter n9: -1000
Enter n10: 12
Sum = 59.70
```

## Sleep :page_with_curl:

คำสั่ง `sleep(n);` ใช้เมื่อต้องการจะทำให้การทำำงานของลูปช้าลง อยู่ในชุดคำสั่ง `#include <unitd.h>`

*n = จำนวนวินาทีที่ต้องการจะให้ลูปนั้นๆช้าลง*

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <unistd.h>`

```
int main()
{
    int x;

    for (x = 0; x < 5; x++)
    {
        printf("x = %d\n" , x);
        sleep(1);
    }
}
```

:printer: Output

```
x = 0
 **1 sec**
x = 1
 **1 sec**
x = 2
 **1 sec**
x = 3
 **1 sec**
x = 4
 **1 sec**
```

> # Function :books:

`#include <stdio.h>`

```
void functionName()
{
    //Block of Code
}

int main()
{
    //Block of Code

    functionName();
    
    //Block of Code
}
```

![This is an image]()

**สิ่งที่ต้องรู้**

`void` หมายถึง ไม่มีการคืนค่าใดๆ กลับออกไปจากฟังก์ชั่น และไม่มีการรับค่าใดๆ เข้ามาในฟังก์ชั่น

## Function Defintion :page_with_curl:

```
returnType functionName(type1 argument1, type2 argument2, ...)
{
    //body of the function

    return (expression);   
}
```

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int checkTriple(int a, int b, int c)
{
    if ((a*a)+(b*b)==(c*c)) return 1;
    else return 0;
}

int main()
{
    int n = 0, i = 0, t = 0;
    int a, b, c, y;

    scanf("%d", &n);
    for (a = 1; a < n; a++){
        for (b = a+1; b < n - a;b++){
            c = n - a - b;
            if (checkTriple(a,b,c) == 1){
                printf("(%d, %d, %d)", a, b, c);
                return 1;
            }
        }
    }
    printf("No triple found.");

}
```

## Function Prototypes :page_with_curl:

```
returnType functionName(type1 argument1, type2 argument2, ...);
```


:desktop_computer: Example Code :

`#include <stdio.h>`

```
int ADD_AB(int A, int B); // Prototype
int main()
{
    int A=2, B=7, C;
    C = ADD_AB(A,B); // Function Call

    printf("Answer is %d",C);

    return(0);
}

int ADD_AB(int A, int B) // Add_AB Function
{
    int x;
    x = A+B;

    return(x);
}
```

:printer: Output

```
9
```

## Recursion :page_with_curl:

```
void recurse()
{
    ... .. ...
    recurse();
    ... .. ...
}

int main()
{
    ... .. ...
    recurse();
    ... .. ...
}
```

![This is an image]()

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int sum(int n);

int main() {
    int number, result;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    result = sum(number);

    printf("sum = %d", result);
    return 0;
}

int sum(int n) {
    if (n != 0)
        // sum() function calls itself
        return n + sum(n-1); 
    else
        return n;
}
```

:printer: Output

```
Enter a positive integer:3
sum = 6
```

## Scope Rules :page_with_curl:

## Local Variable :page_with_curl:

ตัวแปรชนิดโลคอล (Local Variable) ถูกสร้างขึ้นภายในฟังก์ชัน การเปลี่ยนแปลงจะมีผลภายในฟังก์ชันเท่านั้น หากมีชื่อซ้ ากับ Global variable จะถือว่าเป็นคนละตัวแปรกัน ตัวแปรประเภทนี้ เมื่อโปรแกรมออกจากฟังก์ชันจะถูกทำลาย

:desktop_computer: Example Code :

`#include <stdio.h>`

```
void new_value()
{
    int x; // x is Local Variable of new_value()
    x = 100;
}

int main()
{
    int x = 59; // x is Local Variable of main()
    printf("x = %d\n", x);

    new_value();
    printf("x = %d\n", x);
    
    return(0);
}
```

:printer: Output

```
x = 59
x = 59
```

## Global Variable :page_with_curl:

ตัวแปรชนิดโกลบอล (Global Variable) เป็นตัวแปรที่ประกาศไว้นอกฟังก์ชัน อยู่ส่วนหัวโปรแกรม สามารถใช้ได้ทุกที่ ทุกฟังก์ชันในโปรแกรม

:desktop_computer: Example Code :

`#include <stdio.h>`

```
void display();

int n = 5;  // global variable

int main()
{
    ++n;     
    display();
    return 0;
}

void display()
{
    ++n;   
    printf("n = %d", n);
}
```

:printer: Output

```
n = 7
```

## Random Number Generator :page_with_curl:

### rand() :pencil2:

`rand()` เป็นฟังก์ชันที่ใช้สุ่มเลข

**ในการจะใช้คำสั่งเกี่ยวกับการสุ่ม จะต้องใช้ #include <stdlib.h>**

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main(void)
{
 
    for(int i = 0; i<5; i++)
        printf(" %d ", rand());
   
    return 0;
}
```

:printer: Output

```
453 1276 3425 89
```

### srand() :pencil2:

`srand()` ฟังก์ชัน srand ใช้กำหนด random seed ให้กับการทำงานของฟังก์ชัน rand ในกรณีนี้ เราสร้าง rand seed ด้วยการเรียกใช้งานฟังก์ชัน time(NULL) เพื่อรับเอาค่าเวลาปัจจุบันมาทำเป็นค่าของ random seed เนื่องจากเวลานั้นจะเปลี่ยนแปลงไปในการรันโปรแกรมแต่ละครั้ง ดังนั้นจึงทำให้ตัวเลขที่สุ่มออกมาไม่ซ้ำกัน

**ในการจะใช้คำสั่งเกี่ยวกับเวลา จะต้องใช้ #include <time.h>**

`#include <stdio.h>`
`#include <stdlib.h>`
`#include <time.h>`

```
int main()
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        printf("%d ", rand());
    }
    return 0;
}
```

:printer: Output 1

```
10680 25517 30576 2481 29439
```

:printer: Output 2

```
10739 22380 24451 9637 18493
```

:printer: Output 3

```
10791 30515 15366 1434 19687
```

> # Array :books:

![This is an image](https://cdn.programiz.com/sites/tutorial2program/files/c-arrays.jpg)

อาร์เรย์ คือ ตัวแปรที่เก็บข้อมูลเป็นชุดข้อมูล โดยข้อมูลของอาเรย์จะเก็บในรูปแบบของลำดับข้อมูล โดยข้อมูลนั้นจะต้องเป็นประเภทเดียวกัน

**การประกาศตัวแปรอาร์เรย์**

`type name[size];`

:desktop_computer: Example Code :

การประกาศตัวแปรอาร์เรย์

`int n[5];`

การกำหนดค่าให้ตัวแปรแต่ละindex ถ้าไม่กำหนดค่าให้indexนั้นๆจะมีค่าเป็น0

```
int n1 = 5;
int n2 = 10;
int n3 = 20;
int n4 = 30;
int n5 = 50;
```

`int n[5] = {5, 10, 20, 30, 50};`

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int n[8] = {5, 10, 15, 20, 25, 30, 35, 40};

    printf("n[2] = %d\n", n[2]);
    printf("n[3] = %d\n", n[3]);

    n[2] = 99;
    printf("n[2] = %d\n", n[2]);
    return 0;
}
```

:printer: Output

```
n[2] = 15
n[3] = 20
n[2] = 99
```

## Arrays with for-loop :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int n[8] = {5, 10, 15, 20, 25, 30, 35, 40};

    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d, ", n[i]);
    }

    printf("\n");

    for (i = 7; i >= 0; i--)
    {
        printf("%d, ", n[i]);
    }
    return 0;
}
```

:printer: Output

```
5, 10, 15, 20, 25, 30, 35, 40,
40, 35, 30, 25, 20, 15, 10, 5
```

## Two-dimensional array :page_with_curl:

โครงสร้างข้อมูลที่มีการจัดเก็บข้อมูลแบบตารางสองทาง ข้อมูลมีการจัดเรียงกันตามแนวแถว (Row)และ แนวหลัก (Column)การอ้างถึงข้อมูลต้องระบุตำแหน่งแถวและตำแหน่งหลักที่ข้อมูลนั้นอยู่

![This is an image](https://sites.google.com/site/pmtcitajmon/home/hnwy-thi-2-khorngsrang-khxmul-baeb-xarrey-array/array8.png?attredirects=0)

**การประกาศตัวแปรอาร์เรย์แบบสองมิติ**

`Variable type Name [n][n]`

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int a[3][3] =
    {
        {35, 6, 1},
        {4, 5, 16},
        {9, 7, 92}
    };

    int i, j;
    for (i = 0; i <3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d, ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
```

:printer: Output

```
35, 6, 1,
4, 5, 16,
9, 7, 92,
```

> # Structures & Unions :books:

โครงสร้างข้อมูล (structure) คือกลุ่มของตัวแปรที่สามารถสร้างและเก็บไว้ในตัวแปรเดียวที่เรียกว่า data structure ในภาษา C เราสามารถสร้างและออกแบบโครงสร้างข้อมูลของเราได้ตามที่ต้องการ โดยโครงสร้างข้อมูลจะมีสมาชิกที่เป็นตัวแปร (members) และฟังก์ชันได้ในเวลาเดียวกัน

**การประกาศ Structures**

```
struct struct_name
{
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
} object_names;
```

:desktop_computer: Example Code :

`#include <stdio.h>`

```
struct person
{
    char name[20];
    int age;
    float money;
};

/*สร้างโครงสร้างข้อมูลชื่อว่า person โดยมีสมาชิก 3 ตัว โดยเป็นตัวแปรที่เก็บข้อมูลประเภทต่างๆ ที่เป็น name, age และ money สำหรับสมาชิกของโครงสร้างข้อมูล*/

int main()
{
    struct person student, teacher;

    strcpy(student.name, "Marcus");
    student.age = 18;
    student.money = 10.25;

    strcpy(teacher.name, "James");
    teacher.age = 20;
    teacher.money = 49.5;

    printf("%s has age %d and money %.2f usd\n", student.name, student.age, student.money);
    printf("%s has age %d and money %.2f usd\n", teacher.name, teacher.age, teacher.money);

    return 0;
}
```

:printer: Output

```
Marcus has age 18 and money 10.25 usd
James has age 20 and money 49.50 usd
```

## Structures with Array :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
struct point
{
    int x;
    int y;
};

int main()
{
    const int TOTAL_POINT = 4;

    struct point p[TOTAL_POINT];
    p[0].x = 1;
    p[0].y = 2;
    p[1].x = -3;
    p[1].y = -5;
    p[2].x = 4;
    p[2].y = 8;
    p[3].x = 0;
    p[3].y = -1;

    printf("There are %d steps for robot to walk.\n", TOTAL_POINT);

    int i = 0;
    for (i = 0; i < TOTAL_POINT; i++)
    {
        printf("Step %d: walk to point %d, %d\n", i, p[i].x, p[i].y);
    }

    return 0;
}
```

:printer: Output

```
There are 4 steps for robot to walk.
Step 0: walk to point 1, 2
Step 1: walk to point -3, -5
Step 2: walk to point 4, 8
Step 3: walk to point 0, -1
```

## Union :page_with_curl:

ยูเนียน คือ ข้อมูลแบบหนึ่งที่สามารถกำหนดให้ตัวแปรต่างชนิดกัน ใช้เนื้อที่ในหน่วยความจำของเครื่องร่วมกันได้ ทำให้การใช้เนื้อที่ภายในหน่วยความจำลดลง

```
union   {
      int  a;
      float  b;
      char c;
}  ShareArea;
```

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

``` 
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        

   printf( "Memory size occupied by data : %d\n", sizeof(data));

   return 0;
}
```

:printer: Output

```
Memory size occupied by data : 20
```
### การเข้าถึงข้อมูลในยูเนียน :pencil2:

`member access operator (.)`

การเข้าถึงของสมาชิกจะถูกเข้ารหัสเป็นช่วงเวลาระหว่างชื่อตัวแปรของ ยูเนี่ยน และสมาชิก ยูเนี่ยน ที่เราต้องการเข้าถึง คุณจะใช้คีย์เวิร์ด union เพื่อกำหนดตัวแปรของประเภทยูเนี่ยน

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```
union Data {
   int i;
   float f;
   char str[20];
};
 
int main( ) {

   union Data data;        

   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

   return 0;
}
```

:printer: Output

```
data.i : 1917853763
data.f : 4122360580327794860452759994368.000000
data.str : C Programming
```

### Enumeratiom :pencil2:

เพื่อกําหนดประเภทของข้อมูลที่ตนเองสร้างขึ้นได้ โดยข้อมูลประเภทนี้จะมีสมาชิกจํานวนจํากัดซึ่งเป็นค่าคงที่

```
enum <name> {constant 1 , constant 2 , … , constant n};
enum months {MON, TUE, WED, THU, FRI, SAT, SUN};
enum months {JAN = 1, FEB, MAR, APR, MAY ,JUN ,JUL, AUG, SEP, OCT, NOV, DEC};
```

:desktop_computer: Example Code :

`#include <stdio.h>`

```
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card;

int main() 
{
    card = club;
	printf("Size of enum variable = %d bytes", sizeof(card));	
	return 0;
}
```

:printer: Output

```
Size of enum variable = 4 bytes
```

### bit field :pencil2:

การเก็บค่าเป็น bit ใน structure นั้นสมาชิกตัวนั้นจะมีชื่อว่า bit field มีประโยชน์ตรงที่จะประหยัดพื้นที่ในการเก็บค่า มักนิยมมากใช้กับค่า Boolean ซึ่งมีค่าเพียงแค่ True (1) , False (0) เท่านั้น ทำงานกับตัวดำเนินการบิตไวส์ (bitwise Operator)

```
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status;
```

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```
/* define simple structure */
struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status2;
 
int main( ) {
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
   return 0;
}
```

:printer: Output

```
Memory size occupied by status1 : 8
Memory size occupied by status2 : 4
```

#### การประกาศbit field

```
struct {
   type [member_name] : width ;
};
```

1. type ชนิดข้อมูลจำนวนเต็มที่กำหนดวิธีตีความค่าของบิตฟิลด์ ชนิดข้อมูลอาจเป็น int, signed int, หรือ unsigned int.
2. member_name ชื่อของบิตฟิลด์
3. width จำนวนบิตในฟิลด์บิต ความกว้างต้องน้อยกว่าหรือเท่ากับความกว้างบิตของประเภทที่ระบุ

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```
struct {
   unsigned int age : 3;
} Age;

int main( ) {

   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );

   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );

   Age.age = 8;
   printf( "Age.age : %d\n", Age.age );

   return 0;
}
```

:printer: Output

```
Sizeof( Age ) : 4
Age.age : 4
Age.age : 7
Age.age : 0
```

> # Pointers & Dynamic Memory Allocation :books:

พอนย์เตอร์ (pointer) คือตัวแปรที่เก็บค่าของที่อยู่ของข้อมูลของตัวแปร การใช้พอนย์เตอร์จะทำให้เราสามารถเข้าถึงข้อมูลได้โดยตรงโดยใช้ที่อยู่ของหน่วยความจำ แทนที่จะใช้ชื่อของตัวแปร

**พอนย์เตอร์มีประโยนช์สำหรับ low-level programming เช่นการเขียนโปรแกรมในภาษา C**

- Address-of operator [ & ]
- Dereference operator [ * ]
- Declaration operator [ * ]

## Address-of operator :page_with_curl:

สัญลักษณ์ ampersand [ & ] หน้าตัวแปรนั้นจะทำให้เราได้รับค่าที่อยู่ของตัวแปรในหน่วยความจำ ที่อยู่นี้สามารถได้รับมาได้ในตอนที่โปรแกรมรันเท่านั้น ซึ่งมันจะบอกว่าตัวแปรที่เก็บอยู่ที่ตำแหน่งไหนของหน่วยความจำ

`&Variable;`

:desktop_computer: Example Code :

```
int myVariable = 8;
printf("%d", &myVariable);
```

:printer: Output

```
1367
```

## Dereference operator :page_with_curl:

เครื่องหมาย star [ * ] หน้าตัวแปรพอยน์เตอร์เพื่อเข้าถึงข้อมูลในที่อยู่ของพอยน์เตอร์

`*myPointer`

:desktop_computer: Example Code :

```
int myVariable = 8;
int *myPointer = &myVariable; // ประกาศตัวแปรพอนย์เตอร์
printf("%d", *myPointer); // เข้าถึงข้อมูลของตัวแปรพอนย์เตอร์
```

### Declaration :pencil2:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int number = 10;
    float money = 34.8;

    int *p1 = &number;
    float *p2;
    p2 = &money;

    printf("p1 address = %x\n", p1);
    printf("p1 value = %d\n", *p1);
    printf("p2 address = %x\n", p2);
    printf("p2 value = %f\n", *p2);
    return 0;
}
```

:printer: Output

```
p1 address = 28ff04
p1 value = 10
p2 address = 28ff00
p2 value = 34.799999
```

## Pointers & Arrays :page_with_curl:

การนำพอยเตอร์มาใช้ร่วมกับอาร์เรย์ มีประโยชน์เนื่องจากสามารถนำข้อมูลนั้นมาเก็บแบบชุดอันดับ และเรียงต่อกันได้

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    int number[5] = {10, 20, 30, 40, 50};
    int *myPointer = &number;
    printf("first -> %d\n", *myPointer);
    myPointer++;
    printf("go next -> %d\n", *myPointer);
    myPointer += 3;
    printf("go next 3 -> %d\n", *myPointer);
    myPointer--;
    printf("go back -> %d\n", *myPointer);
    return 0;
}
```

:printer: Output

```
first -> 10
go next -> 20
go next 3 -> 50
go back -> 40
```

## Expression & Pointer Arithmetic :page_with_curl:

การดำเนินการทางคณิตศาสตร์กับพอยน์เตอร์เหมือนกับตัวแปรได้ แต่สำหรับพอยน์เตอร์แล้วจะเป็นการทำงานกับที่อยู่ของหน่วยความจำแทน

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int *p1 = &foo;
p1 += 1000; 
p1++;     

// work with arrays
int a[400];
int *p2 = &a;
p2 += 399;
*p2 = 1234;
```

:printer: Output 1

```
1367
```

:printer: Output 2

```
2367
```

:printer: Output 3

```
2368
```

## Dynamic Memory Allocation :page_with_curl:

การจองพื้นที่หน่วยความจำ (Memory Allocation) แบบ Dynamic เป็นการจองหน่อยความจำ ที่อนุญาตให้เพิ่มหรือคืนหน่วยความจำคืนระบบ ณ ขณะที่โปรแกรมรันอยู่ได้

`malloc()` เป็นการจองพื้นที่ในหน่วยความจำเป็นจำนวนbyte

`free()` เป็นการคืนพื้นที่ให้หน่วยึวามจำ

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main() {
  int n, i, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));
 
  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }

  printf("Enter elements: ");
  for(i = 0; i < n; ++i) {
    scanf("%d", ptr + i);
    sum += *(ptr + i);
  }

  printf("Sum = %d", sum);
  
  // deallocating the memory
  free(ptr);

  return 0;
}
```

:keyboard: Input

```
Enter number of elements:
=> 3
```

:keyboard: Input

```
Enter elements:
=> 100
=> 20
=> 36
```

:printer: Output

```
Enter number of elements: 3
Enter elements: 100
20
36
Sum = 156
```

# Characters & String & Memory Functions :books:

## Characters :page_with_curl:

### Character Handling Library <ctype.h>

`int isalnum(int c)`
This function checks whether the passed character is alphanumeric.
เป็นฟังก์ชันที่ใช้ตรวจสอบว่าข้อมูลที่เก็บไว้ในตัวแปรint cเป็นตัวอักษรหรือตัวเลข(letter or digit)
ถ้าข้อมูลที่เก็บไว้เป็นตัวอักษรหรือตัวเลขก็จะส่งค่ากลับที่เป็นจำนวนเต็มที่มีค่าไม่เท่ากับศูนย์มายังฟังก์ชัน
ถ้าข้อมูลที่เก็บไว้ในตัวแปรchไม่ได้เก็บตัวอักษรหรือตัวเลขก็จะส่งค่ากลับมามีค่าเป็นศูนย์มายังฟังก์ชัน

=> {{ a b c d e f g h i j k l m n o p q r s t u v w x y z } , {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z } , { 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f }}

`int isalpha(int c)`
This function checks whether the passed character is alphabetic.
เป็นฟังก์ชันที่ใช้ตรวจสอบว่าข้อมูลที่เก็บไว้ในตัวแปรint cเป็นตัวอักษร(letter)หรือไม่  
ถ้าใช่ฟังก์ชันนี้จะให้ค่าส่งกลับเป็นเลขจำนวนเต็มที่ไม่เท่ากับศูนย์ 
ถ้าไม่ใช่ฟังก์ชันนี้จะให้ค่าส่งกลับมาเป็นเลขศูนย์(0)
=> {{ a b c d e f g h i j k l m n o p q r s t u v w x y z } , {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z }}

`int iscntrl(int c)`
This function checks whether the passed character is control character.

=>In ASCII, these characters have octal codes 000 through 037, and 177 (DEL).

`int isdigit(int c)`
This function checks whether the passed character is decimal digit.
=> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.

`int isgraph(int c)`
This function checks whether the passed character has graphical representation using locale.
=> This is a set of Alphanumeric characters and Punctuation characters.

`int islower(int c)`
This function checks whether the passed character is lowercase letter.
=> { a b c d e f g h i j k l m n o p q r s t u v w x y z }

`int isprint(int c)`
This function checks whether the passed character is printable.
=> This is a set of Alphanumeric characters, Punctuation characters and Space characters.

`int ispunct(int c)`
This function checks whether the passed character is a punctuation character.
=> This is a set of ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~

`int isspace(int c)`
This function checks whether the passed character is white-space.
=> This is a set of tab, newline, vertical tab, form feed, carriage return, and space.

`int isupper(int c)`
This function checks whether the passed character is an uppercase letter.
=> {A B C D E F G H I J K L M N O P Q R S T U V W X Y Z } 

`int isxdigit(int c)`
This function checks whether the passed character is a hexadecimal digit.
=> { 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f }

`int tolower(int c)`
This function converts uppercase letters to lowercase.

`int toupper(int c)`
This function converts lowercase letters to uppercase.

## string :page_with_curl:

### scaning string  :pencil2:

```
//เก็บข้อมูลได้19ตัว อีก1มีค่าเป็นNULL
char string[20];
//รับค่าเข้ามามีขนาดไม่เกิน19 และเก็บค่านั้นในstring
scanf("%19", strinf);
```

### printing strinf :pencil2:

```
//เเสดงค่าของstringและขึ้นบรรทัดใหม่
printf("%s\n", string);
```

### String conversion from <stdlib.h> :pencil2:

- `double strtod(const char *nPtr, char **endPtr);`
        สตริงจะถูกแปลงเป็นความแม่นยำสองจำนวนจุดลอยตัว
        ฟังก์ชั่นนี้จะส่งกลับแม่นยำสองจำนวนจุดลอยตัวแปลงหากมีการดำเนินการที่มีประสิทธิภาพในการแปลงไม่มีก็จะส่งกลับศูนย์ (0.0)

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char str[30] = "2030300 This is test";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%s|", ptr);

   return(0);
}
```

:printer: Output

```
The number(unsigned long integer) is 2030300
String part is | This is test|
```

-  `long int strtol(const char *str, char **endptr, int base);`
        สตริงจะถูกแปลงเป็นจำนวนเต็มยาว การอ้างอิงไปยังวัตถุชนิด char *และค่าถูกกำหนดโดยค่าฟังก์ชั่นใน STR หลังจากตัวอักษรถัดไป endptr ฟังก์ชั่นนี้จะส่งกลับจำนวนเต็มยาวแปลงหากมีการดำเนินการที่มีประสิทธิภาพในการแปลงใดก็จะส่งกลับค่าเป็นศูนย์

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char str[30] = "2030300 This is test";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%s|", ptr);

   return(0);
}
```

:printer: Output

```
The number(unsigned long integer) is 2030300
String part is | This is test|
```

- `unsigned long int strtoul(const char *str, char **endptr, int base);`
        สตริงจะถูกแปลงเป็นจำนวนเต็มยาวที่ไม่ได้รับการรับรองการอ้างอิงไปยังวัตถุชนิด char * และค่าถูกกำหนดโดยค่าฟังก์ชั่นใน STR หลังจากตัวอักษรถัดไป endptr ฟังก์ชั่นนี้จะส่งกลับจำนวนเต็มยาวแปลงหากมีการดำเนินการที่มีประสิทธิภาพในการแปลงใดก็จะส่งกลับค่าเป็นศูนย์

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char str[30] = "2030300 This is test";
   char *ptr;
   long ret;

   ret = strtoul(str, &ptr, 10);
   printf("The number(unsigned long integer) is %lu\n", ret);
   printf("String part is |%s|", ptr);

   return(0);
}
```

:printer: Output

```
The number(unsigned long integer) is 2030300
String part is | This is test|
```

### string Manipulation in <string.h> :pencil2:

- `char *strcp(char *s1, cont char *s2);`
        เป็นฟังก์ชันในการคัดลอกสตริง แต่ในฟังก์ชันที่ 2 สามารถกำหนดความยาวของสตริงที่ต้องการจะคัดลอกได้strcpy ฟังก์ชัน  strcpy เป็นฟังก์ชันในการคัดลอกสตริงพื้นฐาน การทำงาน คือ จะทำการคัดลอกสตริงต้นทั้งหมด ซึ่งจะรวมไปถึง Null Character ด้วย ไปใส่ในสตริงปลายทาง โดยการประกาศฟังก์ชัน strcpy

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main()
{
    char name[] = "Mateo";
    char another_name[10];

    strcpy(another_name, name);

    printf("name: %s\n", name);
    printf("another_name: %s\n", another_name);
    return 0;
}
```

:printer: Output

```
name: Mateo
another_name: Mateo
```

- `char *strcat(char *s1, cont char *s2);`
        การเชื่อมต่อ String คือการนำสอง String มาเชื่อมต่อกันเพื่อให้ได้ String ใหม่ ในภาษา C เราสามารถใช้ฟังก์ชัน strcat เพื่อเชื่อมต่อสอง String เข้าด้วยกันได้ นี่เป็นตัวอย่างการใช้งาน

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```
int main()
{
    char sitename[] = "marcuscode";
    char tld[] = ".com";

    strcat(sitename, tld);
    printf("%s", sitename);
    return 0;
}
```

:printer: Output

```
marcuscode.com
```

- `int strcmp (const char * str1, const char * str2);`
        ฟังก์ชันรับค่าเป็น String สองตัวที่ต้องการเปรียบเทีียบกัน และมันส่งค่ากลับเป็นจำนวนเต็ม สามารถใช้งานฟังก์ชัน strcmp เพื่อตรวจสอบว่า String มีค่าเท่ากัน น้อยกว่า หรือมากกว่าได้

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```
int main()
{
    char username[] = "Mateo";
    if (strcmp(username, "Mateo") == 0) {
        printf("Equal");
    } else {
        printf("Not equal");
    }
    return 0;
}
```

:printer: Output

```
Equal
```

**strncp() , strncat() , strcmp() กำหนดเป็นNขนาด**

## memory functions :page_with_curl:

- `void *memcpy(void *dest, const void * src, size_t n);`


:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}
```

:printer: Output

```
Before memcpy dest = Heloooo!!
After memcpy dest = http://www.tutorialspoint.com
```

- `void *memmove(void *str1, const void *str2, size_t n);`


:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}
```

:printer: Output

```
Before memmove dest = oldstring, src = newstring
After memmove dest = newstring, src = newstring
```

- `int memcmp(const void *str1, const void *str2, size_t n);`

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}
```

:printer: Output

```
str2 is less than str1
```

- `void *memchr(const void *str, int c, size_t n);`

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
```

:printer: Output
```
String after |.| is - |.tutorialspoint.com|
```

- `void *memset(void *str, int c, size_t n);`

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
int main () {
   char str[50];

   strcpy(str,"This is string.h library function");
   puts(str);

   memset(str,'$',7);
   puts(str);
   
   return(0);
}
```

:printer: Output

```
This is string.h library function
$$$$$$$ string.h library function
```

# linked list :book: 

## with structure :page_with_curl:

## การสร้าง :page_with_curl:

## การเข้าถึงข้อมูล :page_with_curl:

## การลบข้อมูล :page_with_curl:

## การเพิ่มข้อมูล :page_with_curl:

## Doubly Linked List :page_with_curl:

## Circular Linked List :page_with_curl:

# File handling in C :book: 

## Open File :page_with_curl:

## Plain Text Portable PixMap File Format(PPM) :page_with_curl:

## Binary Portable PixMap File Format (PPM) :page_with_curl:

## ImageMagic :page_with_curl:

## Floyd - Steinberg Algorithm :page_with_curl:

> # Example of Function in C :books:

## printf() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int myFactorial(int);

int main()
{
    int myNumber = 5;
    printf("%d face is %d", myNumber, myFactorial(myNumber));
    return 0;
}

int myFactorial(int n)
{
    int result = 1, i;
    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
```

:printer: Output

```
5 face is 120
```

## puts() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    char Mystr[] = "C and C++";
     
    puts(Mystr);
     
    return 0;
}
```

:printer: Output

```
C and C++
```

## getchar() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <conio.h>`
`#include <ctype.h>`  

```
int main()    
{  
    char ch;   
    printf (" Enter a character ( If we want to exit press #) \n");  
    while (ch != '#') 
    {  
        ch = getchar();   
        printf (" \n We have entered the character : ");  
        putchar (ch); // print a single character  
        printf ("\n");  
        }     
        return 0;  
}  
```

:keyboard: Input

```
Enter a character ( If we want to exit.. press #)
=> B
```

:printer: Output

```
We have entered the character: B
We have entered the character:
```

## gets() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <string.h>`

```    
int main()
{    
    char name[50];    
    printf("Enter your name: ");    
    
    gets(name); 
    printf("Your name is: ");    
    puts(name);   
    
    return 0;    
}    
```

:keyboard: Input

```
Enter your name:
=> Tipsukanya Norrasing
```

:printer: Output

```
Enter your name: Tipsukanya Norrasing
Your name is: Tipsukanya Norrasing
```

## putchar() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{
    char ch = '1';
  
    for (ch = '1'; ch <= '9'; ch++)
        putchar(ch);
  
    return (0);
}
```

:printer: Output

```
123456789
```

## sizeof() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main() {
int a = 16;
   printf("Size of variable a : %d\n",sizeof(a));
   printf("Size of int data type : %d\n",sizeof(int));
   printf("Size of char data type : %d\n",sizeof(char));
   printf("Size of float data type : %d\n",sizeof(float));
   printf("Size of double data type : %d\n",sizeof(double));
   return 0;
}
```

:printer: Output

```
Size of variable a : 4
Size of int data type : 4
Size of char data type : 1
Size of float data type : 4
Size of double data type : 8
```

## scanf() :page_with_curl:

:desktop_computer: Example Code :

`#include <stdio.h>`

```
int main()
{    
    int number;    
    printf("enter a number:");    

    scanf("%d",&number);    
    printf("cube of number is:%d ",number*number*number);    
    
    return 0;  
}    
```

:keyboard: Input

```
enter a number:
=> 5
```

:printer: Output

```
enter a number:5
cube of number is:125
```

***Reference***

Visit https://sites.google.com/ku.th/01418113

Visit https://www.programiz.com/c-programming/c-keywords-identifier

Visit http://marcuscode.com/lang/c?fbclid=IwAR2SLkJO4mruEWRB7eoTRu1Vw6LAa9rF89G0dm8c2p-aNyD9w9K3KT7ild8

Visit https://piravit-chenpittaya.medium.com/c-pointer-%E0%B8%84%E0%B8%B7%E0%B8%AD%E0%B8%AD%E0%B8%B0%E0%B9%84%E0%B8%A3-%E0%B8%89%E0%B8%9A%E0%B8%B1%E0%B8%9A%E0%B9%80%E0%B8%94%E0%B9%87%E0%B8%81%E0%B8%A1%E0%B8%AB%E0%B8%B2%E0%B8%A5%E0%B8%B1%E0%B8%A2-f852a0974b41 

Visit file:///C:/Users/ASUS/Downloads/The-C-Programming-Language-by-Brian-W.-Kernighan-Dennis-M.-Ritchie-z-lib.org%20(2).pdf

Visit https://www.geeksforgeeks.org/c-programming-language/

Visit https://www.javatpoint.com/c-programming-language-tutorial

![This is an image](https://imgur.com/DUKOwBH.jpg)
