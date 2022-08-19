# สารบัญเนื้อหาสรุป

## 1. Introduction of Java :bookmark_tabs: ##
## 2. Conversions & Controls :closed_book: ##
## 3. Introduction of Object & Class :green_book: ##
## 4. Method & Constructor :orange_book: ##
## 5. String :notebook: ## 
## 6. Array :notebook_with_decorative_cover: ##
## 7. Introduction to Inheritance :ledger: ##
## 8. Error Code :bangbang:

# Introduction of Java :books:

## History of Java :page_with_curl:

ภาษา Java เป็นภาษาโปรแกรมเชิงวัตถุที่พัฒนาขึ้นโดย  `“James Gosling”`   และทีมวิศวกรของเขาซึ่งบริษัท `Sun Microsystems` ต้องการนำภาษาจาวา`มาใช้แทนภาษา C++`  ชื่อของ “Java” มาจากชื่อกาแฟที่ทีมวิศวกรของ Sun ดื่มตอนที่ร่วมกันพัฒนาภาษา Java ขึ้นมา

Java  ถูกคิดค้นและสร้างโดย บริษัท Sun Microsystems ซึ่งเป็นบริษัทผู้ขายระบบ Unix ที่มีชื่อว่า `Solaris` ซึ่ง`จุดเด่นของภาษา Java` อยู่ที่ผู้เขียนโปรแกรมสามารถใช้หลักการของ `Object-Oriented Programmin` มาพัฒนาโปรแกรมของตนด้วย Java ได้ พัฒนาขึ้นโดยทีมวิจัยได้มีการพัฒนามาจากโครงการที่ต้องการพัฒนาระบบซอฟต์แวร์ เพื่อควบคุมเครื่องใช้ไฟฟ้าขนาดเล็กภายในบ้านชื่อเดิมคือภาษา `Oak` ต่อมาเปลี่ยนชื่อเป็นภาษา `Java`"

*วัตถุประสงค์เดิม คือ ของ จาวาคือใช้สำหรับการเขียนโปรแกรมเพื่อฝังตัวในอุปกรณ์อิเล็กทรอนิกส์*

*ภาษาสำหรับเขียนโปรแกรม (Application Programming) ซึ่งเป็นลักษณะของโปรแกรมเชิงวัตถุ (Object Oriented Programming) ซึ่งสามารถใช้งานบนเว็บได้ด้วย*

**`ผู้คิดต้นแบบ` คือ James Gosling และคณะ จากบริษัท Sun Microsystems**

**`วัตถุประสงค์เดิม` คือ ของ จาวาคือใช้สำหรับการเขียนโปรแกรมเพื่อฝังตัวในอุปกรณ์อิเล็กทรอนิกส์**

**`ผล` คือ ภาษาสำหรับเขียนโปรแกรม (Application Programming) ซึ่งเป็นลักษณะของโปรแกรมเชิงวัตถุ (Object Oriented Programming) ซึ่งสามารถใช้งานบนเว็บได้ด้วย**

![299162436_1222830978553583_6472355237211507967_n](https://user-images.githubusercontent.com/86911299/185520479-d8598ac9-dbd7-45f8-8ce3-74dcd358ccdc.jpg)

![299598916_768699617794704_4652662362583479882_n](https://user-images.githubusercontent.com/86911299/185520602-5a02e5f8-99bc-49c8-b8b9-094f64ed5491.jpg)

## Advantage of Java :page_with_curl:

- ภาษา Java เป็นภาษาที่สนับสนุนการเขียนโปรแกรมเชิงวัตถุแบบสมบูรณ์ ซึ่งเหมาะสำหรับพัฒนาระบบที่มีความซับซ้อน การพัฒนาโปรแกรมแบบวัตถุจะช่วยให้เราสามารถใช้คำหรือชื่อ ต่าง ๆ ที่มีอยู่ในระบบงานนั้นมาใช้ในการออกแบบโปรแกรมได้ ทำให้เข้าใจได้ง่ายขึ้น

- โปรแกรมที่เขียนขึ้นโดยใช้ภาษา Java จะมีความสามารถทำงานได้ในระบบปฏิบัติการที่แตกต่างกัน ไม่จำเป็นต้องดัดแปลงแก้ไขโปรแกรม เช่น หากเขียนโปรแกรมบนเครื่อง Sun โปรแกรมนั้นก็สามารถถูก compile และ run บนเครื่องพีซีธรรมดาได้

- ภาษาจาวามีการตรวจสอบข้อผิดพลาดทั้งตอน compile time และ runtime ทำให้ลดข้อผิดพลาดที่อาจเกิดขึ้นในโปรแกรม และช่วยให้ debug โปรแกรมได้ง่าย

- ภาษาจาวามีความซับซ้อนน้อยกว่าภาษา C++ เมื่อเปรียบเทียบ code ของโปรแกรมที่เขียนขึ้นโดยภาษา Java กับ C++ พบว่า โปรแกรมที่เขียนโดยภาษา Java จะมีจำนวน code น้อยกว่าโปรแกรมที่เขียนโดยภาษา C++ ทำให้ใช้งานได้ง่ายกว่าและลดความผิดพลาดได้มากขึ้น

- ภาษาจาวาถูกออกแบบมาให้มีความปลอดภัยสูงตั้งแต่แรก ทำให้โปรแกรมที่เขียนขึ้นด้วยจาวามีความปลอดภัยมากกว่าโปรแกรมที่เขียนขึ้น ด้วยภาษาอื่น เพราะ Java มี security ทั้ง low level และ high level ได้แก่ electronic signature, public and private key management, access control และ certificates

- มี IDE, application server, และ library ต่าง ๆ มากมายสำหรับจาวาที่เราสามารถใช้งานได้โดยไม่ต้องเสียค่าใช้จ่าย ทำให้เราสามารถลดค่าใช้จ่ายที่ต้องเสียไปกับการซื้อ tool และ s/w ต่าง ๆ

## Disadvantage of Java :page_with_curl:

- ทำงานได้ช้ากว่า native code (โปรแกรมที่ compile ให้อยู่ในรูปของภาษาเครื่อง) หรือโปรแกรมที่เขียนขึ้นด้วยภาษาอื่น อย่างเช่น C หรือ C++ ทั้งนี้ก็เพราะว่าโปรแกรมที่เขียนขึ้นด้วยภาษาจาวาจะถูกแปลงเป็นภาษากลาง ก่อน แล้วเมื่อโปรแกรมทำงานคำสั่งของภาษากลางนี้จะถูกเปลี่ยนเป็นภาษาเครื่องอีก ทีหนึ่ง ทีล่ะคำสั่ง (หรือกลุ่มของคำสั่ง) ณ runtime ทำให้ทำงานช้ากว่า native code ซึ่งอยู่ในรูปของภาษาเครื่องแล้วตั้งแต่ compile โปรแกรมที่ต้องการความเร็วในการทำงานจึงไม่นิยมเขียนด้วยจาวา

- Tool ที่มีในการใช้พัฒนาโปรแกรมจาวามักไม่ค่อยเก่ง ทำให้หลายอย่างโปรแกรมเมอร์จะต้องเป็นคนทำเอง ทำให้ต้องเสียเวลาทำงานในส่วนที่ tool ทำไม่ได้ ถ้าเราดู tool ของ MS จะใช้งานได้ง่ายกว่า และพัฒนาได้เร็วกว่า (แต่เราต้องซื้อ tool ของ MS และก็ต้องรันบน platform ของ MS)

## Timeline :page_with_curl:

ปี 1991 :hourglass:

ได้ทำการวิจัยเพื่อพัฒนาซอฟต์แวร์ที่ใช้ควบคุมอุปกรณ์เล็กทรอนิคขนาดเล็ก ซึ่งได้ผลลัพธ์ที่สำคัญคือ ภาษาโอ๊ค (Oak)

ปี 1993 :hourglass:

ภาษาโอ๊คได้ถูกปรับปรุงใหม่เพื่อใช้ในการสร้างเว็บแอพพลิเคชั่น (web application) พร้อมกับสร้างเว็บเบราว์เซอร์ (web browser) ที่รองรับ ชื่อว่าเว็บรันเนอร์ (WebRunner)

ปี 1995 :hourglass:

- บริษัทซันได้เปิดตัวภาษาจาวา (Java) (ภาษาโอ๊คเดิม) พร้อมกับเว็บเบราว์เซอร์ ที่รองรับภาษานี้ ชื่อว่า ฮอตจาวา (HotJava) (WebRunner เดิม)

- ได้รับการสนับสนุนจากบริษัทใหญ่ทั้งเน็ตสเคบ (Netscape), ไมโครซอฟต์ (Microsoft), และ ไอบีเอ็ม (IBM)

- บริษัทซันได้เริ่มแจกจ่าย Java development Kit (JDK) ซึ่งเป็นชุดพัฒนาโปรแกรมภาษาจาวาในอินเตอร์เน็ต

# Conversions & Controls :books:

## Conversion Contexts :page_with_curl:

![298284317_606298197673731_8900526157071660415_n](https://user-images.githubusercontent.com/86911299/185533821-b88eae3d-e199-4440-869d-d0b1d2c3147f.jpg)

### Assignment Contexts :pencil2:

Assignment Contexts : เป็นการแทนค่าหรือกำหนดค่าให้ตัวแปลต่างๆ

:desktop_computer: Example Code :

```
double num = 1;
```

### Strict Invocation Contexts :pencil2:

Strict Invocation Contexts : เป็นการแปลงอย่าง`เข้มงวด`โดยใช้รูปแบบของพารามิเตอร์จาก`constructor / method` 


:desktop_computer: Example Code :

```
Math.sqrt(4);
```

### Loose Invocation Contexts :pencil2:

Loose Invocation Contexts : เป็นการแปลงที่คล้ายๆกับStrict Invocation Contextsแต่จะ`ไม่ได้เข้มงวดเท่า`
และใช้ในรูปแบบเดียวกันคือใช้รูปแบบของพารามิเตอร์จาก`constructor / method`แต่ในการแปลงรูปแบบนี้จะไม่เหมาะสมในการประกาศ 

**เนืองจากในการประกาศ`Declartion`ของ Invocation Contexts นั้นจะมีเฉพาะใน `Strict` Invocation Contexts เท่านั้น**

### String Contexts :pencil2:

String Contexts : เป็นการแปลงข้อมูลชนิดต่างๆให้เป็นในชนิดของ`String`เพื่อที่จะแสดงค่าออกมาหรือprintออกมา 

:desktop_computer: Example Code :

```
System.out.printIn("______");
```

### Casting Contexts :pencil2:

Casting Contexts : เป็นการแสดงค่าของการแปลงชนิดข้อมูลต่างๆโดย`cast operator`

![java-type-cast-operator](https://user-images.githubusercontent.com/86911299/185536103-195e8790-4f5a-4faa-8d84-32fbc0e79db9.png)

### Numeric Contexts :pencil2:

Numeric Contexts : เป็นการแปลงหรือชนิดของข้อมูลต่างๆด้วยกันคำนวณโดย`numeric operator`

![operators](https://user-images.githubusercontent.com/86911299/185536181-ca364606-736c-472b-b199-2527051bec64.png)

*อาจจะเป็น Widening (Sub Type -> Super Type)*


:desktop_computer: Example Code :

```
public class Test {
    public static void main(String[] args) {
        int i = (int)12.5f; 
        // Narrowing {Super Type[float] -> Sub Type[int]} & casting conversion (int)
        
        System.out.println("(int)12.5f==" + i);
        // String conversion (5.4) of i's int value [แปลงจากค่าintมาเป็นstringและแสดงผลลัพท์]
        
        float f = i;
        // Widening {Sub Type[int] -> Super Type[float]} & assignment conversion (f = i)
        
        System.out.println("after float widening: " + f);
        // String conversion of f's float value [fที่มีค่าเป็นiที่มีชนิดตอนแรกเป็นintแต่เมื่อแปลงแล้วค่าiนั้นจะกลายเป็นstringและค่าfก็เช่นกัน]
        
        System.out.print(f); 
        // String conversion of f's float value [แปลงจากค่าintมาเป็นstringและแสดงผลลัพท์]
        
        f = f * i;
        // Widening {Sub Type[int] -> Super Type[float]} & numeric conversion
        // Numeric promotion of i's value -->float [* เครื่องหมายคูณ]
        // After promotion, the operation is float*float
        
        System.out.println("*" + i + "==" + f); 
        // Two string conversions of i and f:
        
        double d = Math.sin(f);
        // Widening & invocation conversion
        // Conversion of f's value -->double, needed because the method Math.sin accepts only a double argument 
        
        System.out.println("Math.sin(" + f + ")==" + d);
        // Two string conversions of f and d:
    } 
}
```

:printer: Output

```
(int)12.5f==12
after float widening: 12.0
12.0*12==144.0 Math.sin(144.0)==-0.49102159389846934
```

## Primitive to Primitive :page_with_curl:

![299086930_373419591633980_4144069758796985945_n](https://user-images.githubusercontent.com/86911299/185538366-f05d1d8a-003f-48ec-b26c-fc97726722af.jpg)

**Combines Widening + Narrowing `byte --> char`**

:desktop_computer: Example Code :

```
public static void main(String[] args) {
    byte b = 65;
    char c = (char)b; 
    System.out.println(c); 
}
```

### Widening primitive Conversion :pencil2:

Sub Type[] -> Super Type[]

- byte --> short, int, long, float, or double
- char --> int, long, float, or double
- int --> long, float, or double
- long --> float or double
- float --> double

`int > float , long > float , long > double`

### Narrowing primitive Conversion :pencil2:

Super Type[] -> Sub Type[]

- short --> byte or char
- char --> byte or short
- int --> byte, short, or char
- long --> byte, short, char, or int
- float --> byte, short, char, int, or long
- double --> byte, short, char, int, long, or float

`double > float`

## Variables Reference Type :page_with_curl:

- Class Types : Null / reference to class T or subclass T

- Interface Type : Null / reference to implements of interface [อุปกรณ์ที่ใช้ในการเชือมต่อระหว่างคลาส]

- Object Type : Null / reference to object , class(object) , array

1. The Class "Object" : สำหรับภาษาจาวาแล้วเป็นภาษาที่ใช้การโปรแกรมเชิงวัตถุ และคลาส โดยคลาสที่เป็นคลาสใหญ่สุดหรือsuper classนั้นคือคลาสที่ชื่อว่า"object" 
สำหรับคลาสและอาร์เรย์ทั้งหมดจะได้รับการรับทอดmethodsจากคลาสobjectมา 

```
clone() 
equals() 
finalize()
getClass()
hashCode()
toString()
```

2. The Class "String" : คลาสสตริงเป็นคลาสของตัวอักษรที่เป็น`reference` ในการสร้างสตริงตัวใหม่สามารถใช้คำสั่ง`new` และการ"___"+"___"
บวกแต่ละครั้งคือการสร้างobjectใหม่เลยไม่ใช่การต่อกับตัวเดิม จะสร้างaddressใหม่อีกตัวเพิ่มตามเครื่องหมายบวก

### Kinds of Variables :pencil2:

- Class : การประกาศตัวแปรจะสามารถใช้`static` , `final` , `public` ในตอนประกาศตัวแปรตอนประกาศคลาสได้เลย
- Instance : จะต่างจากคลาสตรงที่ไม่มีstatic
- Array Components : เป็นตัวแปรที่ยังไม่ต้องมีชื่อหรือกำหนดค่าเริ่มต้นก็ได้
- Methods Parameters :
- Constructor Parameters :
- Lambda Parameters :
- Exception Parameters
- Local Variables :

## Reference to Reference :page_with_curl:

### Widening Reference Conversion :pencil2:

Sub Type[] -> Super Type[]

### Narrowing Reference Conversion :pencil2:

Super Type[] -> Sub Type[]

## Primitive to Reference :page_with_curl:

Primitive : ค่าจริงๆของวัตถุนั้นๆ
Reference : ค่าของที่อยู่/address

### Boxing Conversion :pencil2:

![299598918_749114892991538_1373334838019852936_n](https://user-images.githubusercontent.com/86911299/185545920-ab3932c5-682c-4c71-bed4-9fade5515374.jpg)

:desktop_computer: Example Code :

```
public static void main(String[] args) { 
    int x = 1;
    Integer objx = x; //boxing conversion 
    System.out.println("x = " + x); 
    System.out.println("objx = " + objx);
}
```

### Unboxing Conversion :pencil2:

![299298895_631057405234161_3427333686059000332_n](https://user-images.githubusercontent.com/86911299/185546245-86edf7a8-066a-4bda-b7c9-ab64067513c4.jpg)

:desktop_computer: Example Code :

```
public static void main(String[] args) { 
    int x = 1;
    Integer objx = x; //boxing conversion 
    System.out.println("x = " + x); 
    System.out.println("objx = " + objx);
    int y = objx; //unboxing conversion
    System.out.println("y = " + y); 
}
```

### String Conversion :pencil2:

:desktop_computer: Example Code :

```
@Override
    public String toString() {
        return name + " [" + stamp + " point]";
    }
```

## Java Control Statements :page_with_curl:

### If Statements :pencil2:

![If-statement-GeeksforGeeks1](https://user-images.githubusercontent.com/86911299/185546653-ee9d98d5-ef17-482e-8c64-32dde931a44c.jpg)

Declarations : 

```
if(condition) 
{
   // Statements to execute if
   // condition is true
}
```

:desktop_computer: Example Code :

```
class IfDemo {
    public static void main(String args[])
    {
        int i = 10;
 
        if (i < 15)
            System.out.println("10 is less than 15");
 
        // This statement will be executed
        // as if considers one statement by default
        System.out.println("Outside if-block");
    }
}
```


:printer: Output

```
10 is less than 15
Outside if-block
```

### If-Else Statements :pencil2:

![If-else-statement-GeeksforGeeks1](https://user-images.githubusercontent.com/86911299/185546724-6090ed95-eccd-4fc4-889f-1648ca0d14b7.jpg)

Declarations : 

```
if (condition)
    {
    // Executes this block if
    // condition is true
    }
    else
    {
    // Executes this block if
    // condition is false
}
```

:desktop_computer: Example Code :

```
class IfElseDemo {
    public static void main(String args[])
    {
        int i = 20;
 
        if (i < 15)
            System.out.println("i is smaller than 15");
        else
            System.out.println("i is greater than 15");
 
        System.out.println("Outside if-else block");
    }
}
```


:printer: Output

```
i is greater than 15
Outside if-else block
```

### if-else-if Statements :pencil2:

![If-else-if-ladder-GeeksforGeeks-1](https://user-images.githubusercontent.com/86911299/185547338-be60797e-5a24-4249-87f5-0981952d81fd.jpg)

Declarations : 

```
if (condition)
    statement 1;
else if (condition)
    statement 2;
.
.
else
    statement;
```

:desktop_computer: Example Code :

```
// Java program to illustrate if-else-if ladder

import java.io.*;

class GFG {
	public static void main(String[] args)
	{
		// initializing expression
		int i = 20;

		// condition 1
		if (i == 10)
			System.out.println("i is 10\n");

		// condition 2
		else if (i == 15)
			System.out.println("i is 15\n");

		// condition 3
		else if (i == 20)
			System.out.println("i is 20\n");

		else
			System.out.println("i is not present\n");

		System.out.println("Outside if-else-if");
	}
}
```


:printer: Output

```
i is 20
Outside if-else-if
```

### Switch Statements :pencil2:

![java-switch-case-flow-diagram](https://user-images.githubusercontent.com/86911299/185547904-c10d7759-e31e-4457-a802-ed54517edac3.jpg)

```
switch (expression)
{
  case value1:
    statement1;
    break;
  case value2:
    statement2;
    break;
  .
  .
  case valueN:
    statementN;
    break;
  default:
    statementDefault;
}
```

### While & Do-While Loop :pencil2:

![While-Loop-GeeksforGeeks](https://user-images.githubusercontent.com/86911299/185548187-9e3a5537-5170-47dd-b53f-11a70a982244.jpg)

![do-while-Loop-GeeksforGeeks2](https://user-images.githubusercontent.com/86911299/185548219-77e3cf93-f6bd-4f1b-ad90-2e081cc75fce.jpg)

### For Loop :pencil2:

![For-Loop](https://user-images.githubusercontent.com/86911299/185548296-384b7d04-7398-4741-9f5b-3f8e0e4dddce.jpg)

#### Break / Continue

![break](https://user-images.githubusercontent.com/86911299/185548406-345055b2-31e5-4a5e-a87f-1f7a4e06e256.png)

![j1-660x615](https://user-images.githubusercontent.com/86911299/185548414-22bf5b0a-f546-4ccb-b4ee-768b94dbc4f9.png)

### Mathematical Methods :pencil2:

![300250298_628513015242603_3034174869324541614_n](https://user-images.githubusercontent.com/86911299/185548880-098e0fcd-77b5-4df9-8480-3335e99cd7ed.jpg)

### Conditional Operator :pencil2:

![Conditional-or-Ternary-Operator-__-in-Java](https://user-images.githubusercontent.com/86911299/185549008-5ea40fe0-a7bb-4a16-ab47-17063a3086da.jpg)

# Introduction of Object & Class :books:

## Object :page_with_curl:

Object : เป็นค่าคงที่ของคลาส

### "new" :pencil2:

### Referencing :pencil2:

## Class :page_with_curl:

### Declarations :pencil2:

### Member :pencil2:

## Field :page_with_curl:

### Declarations :pencil2:

### Default Values :pencil2:

## Acces Modifiers :page_with_curl:

## Encasulation :page_with_curl:

# Method & Constructor :books:

## Method :page_with_curl:

### Method Declarations :pencil2:

### Method Signature :pencil2:

### Method Body :pencil2:

### Method Formal Parameters :pencil2:

### Method Pass by Value :pencil2:

### Method Pass by Reference :pencil2:

### Overloading Method :pencil2:

### "static" :pencil2:

### "final" :pencil2:

## Constructor :page_with_curl:

### Constructor Declarations :pencil2:

### Constructor Invocations :pencil2:

### Constructor Signature :pencil2:

### Constructor Modifiers :pencil2:

### Overloading Constructor :pencil2:

### Default Constructor :pencil2:

### Constructor Body :pencil2:

### "this" :pencil2:

# String :books:

## Manipulation String :page_with_curl:

## String Concatenation :page_with_curl:

## Conversion [int - double] :page_with_curl:

## String Function :page_with_curl:

### replace() :pencil2:

### replaceFirst() :pencil2:

### replaceAll() :pencil2:

### split() :pencil2:


# Array :books:

## Component / Element of Array :page_with_curl:

## Array Types :page_with_curl:

## Array Declaration :page_with_curl:

### with object creation :pencil2:

### Initialized Values :pencil2:

### Accessing Values :pencil2:

## Looping through Array :page_with_curl:

## Convert Array to ArrayList :page_with_curl:

## 2D Array :page_with_curl:

## Copying Array of Primitives :page_with_curl:

## Copying Array of Reference Types :page_with_curl:

## Collection :page_with_curl:

## Wrapper Classes :page_with_curl:

## HashSet :page_with_curl:

## HashMap :page_with_curl:

## TreeMap :page_with_curl:

## Array Fuction :page_with_curl:

### toString() :pencil2:

### Arrays.sort() :pencil2:

### Arrays.binarySearch() :pencil2:

### Arrays.equals() :pencil2:

### intArrList.add() :pencil2:

### intArrList.get() :pencil2:

### intArrList.set() :pencil2:

### intArrList.size() :pencil2:

### intArrList.indexOf() :pencil2:

### intArrList.contains() :pencil2:

### intArrList.clear() :pencil2:

### intArrList.remove() :pencil2:

### intArrList.add() :pencil2:

### intArrList.addAll() :pencil2:

# Introduction to Inheritance :books:

## Inherited Instance Varible :page_with_curl:

## Inherited Instance Method :page_with_curl:

## UML [Unified Modeling Language] Diagram :page_with_curl:

## "super" :page_with_curl:

## Inherited & Constructor Chaining :page_with_curl:

## Constructor Chaining Back to The Class Object :page_with_curl:

## Overriding Method :page_with_curl:


# Error Code :books:

:desktop_computer: Example Code :

```
//----อธิบาย----
code
//----อธิบาย----
code
```

:keyboard: Input

```
code
```

:printer: Output

```
code
```

:bulb: Error Because

=>
