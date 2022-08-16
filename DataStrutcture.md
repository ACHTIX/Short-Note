# สารบัญเนื้อหาสรุป

## 1. Introduction Data Structure :bookmark_tabs: ##
## 2. Structure & Pointer :closed_book: ##
## 3. Function & Recursion :green_book: ##
## 4. Linked List :orange_book: ##
## 5. Stack :notebook: ## 
## 6. Queue :notebook_with_decorative_cover: ##
## 7. Linear & Hashing :ledger: ##
## 8. Graphs :blue_book: ##
## 9. Trees :label: ##

# Introduction Data Structure :books:

การโปรแกรมในภาษาคอมพิวเตอร์ มีสิ่งสำคัญอยู่สองอย่างคือ
1. Algorithms : ลำดับขั้นตอนในการทำงานของโปรแกรมเพื่อแก้ปัญหา
2. Data Structure : การจัดเก็บข้อมูลในหน่วยความจำ(Memory)เพื่อที่จะนำมาใช้ใน`Algorithm`ได้อย่างมีประสิทร์ภาพ

***Data Structure***
ในการจัดเก็บข้อมูลของData Structureนั้นจะเป็นการจัดเก็บข้อมูลไว้เป็นกลุ่มที่มีความเชื่อมโยงกันไว้ด้วยกัน 
จะเป็น`ข้อมูลประเภท/ โครงสร้าง`เดียวกันหรือต่างกันก็ได้ *เพื่อที่จะสะดวกในการนำมาใช้และเพื่อให้เกิดประสิทธิภาพสูงสุด*

**ประโยชน์ของData Structure ในการสร้างAlgorithms**
- นำโครงสร้างข้อมูลที่มีอยู่แล้วมาประยุกต์ใช้ในการแก้ปัญหา
- เพิ่มประสิทธิภาพในการเเขียนโปรแกรม
- สามารถนำโครงสร้างข้อมูลในรูปแบบต่างๆมาประยุกต์ใช้ให้เหมาะสมกับอัลกอริทึมนั้นๆได้อย่างเหมาะสม

## Type of Data Structure :page_with_curl:

1. Basic Data Type
   - Primtive Data Type
   - Structure Data Type
   - Pointer

2. Abstract Data Type
   - Linear Data Structure
   - Non - Linear Data Structure

## Basic Data Structure :page_with_curl:

### Primtive Data Type :pencil2:

![f8b1b4707cd00bf208706eb38997f7c2](https://user-images.githubusercontent.com/86911299/181749121-3a0aae06-ae9e-41b6-90b4-81fbf8fc2c6a.jpg)

***การแปลงเลขฐาน และการบวกลบเลขฐาน***

[ระบบเลขฐาน.pdf](https://github.com/ACHTIX/Project/files/9219516/default.pdf)

#### Binary number representation

1. Unsigned representation

ชุดข้อมูลของเลขฐานสองที่ไม่ได้กำหนดเครื่องหมาย มีทั้งหมด 0 - 256 หรือ 2^8

2. signed magnitude representation

ชุดข้อมูลที่มีเครื่องหมายสในการระบุว่าชุดข้อมูลนั้นๆเป็นบวกหรือลบ โดย`sign bit`นั้นคือตัวหน้าสุด 
ถ้าเป็น 0 = บวก  , 1 = ลบ และ`magnitude`ขนาดของบิตตัวเลขจะอยู่หลังบิตระบุเครื่องหมาย

```
0 0 0 0 0 1 1 0 = 6

1 0 0 0 0 1 1 0 = -6
```

3. 1's complement system

สามารถสลับบิตได้เลย เช่น 0 => 1 , 1 => 0

4. 2' complement system

ในการแปลงค่าให้เป็น2' complement นำค่าที่คำนวนเป็น 1' complementมาบวก1

Overflow : ข้อมูลล้นหรือข้อมูลเกิน เกิดในกรณีที่ตัวเลขที่มีขนาดใหญ่กว่าความจุของหน่วยความจำ 

Underflow : ข้อมูลน้อยเกินกว่าที่จะเก็บในหน่วยความจำจนไม่สามารถนำไปเก็บในหน่วยความจำ

Real Number : จำนวนจริงเป็นเลขทศนิยมfloating point จัดเก็บในรูปแบบเลขฐานสองแบบเดียวกับInteger 
`Normalized` การเขียนเลขฐานต่างๆ ได้ทั้งฐานสอง ฐานสิบ และอื่นๆ ให้อยู่ในรูปแบบของเลขยกกำลัง 
เช่น 1.52 x 10^15 = 152,000,000 1.1011 x 2^5 = 110110

**ในการใช้หน่วยความจำเก็บจำนวนจริง**
- Float : จะเก็บในรูปแบบ`Single precision` โดยจะใช้พื้นที่ในหน่วยความจำขนาด32บิต
- Double : จะเก็บในรูปแบบ`double precision` โดยจะใช้พื้นที่ในหน่วยความจำขนาด64บิต
ในการจัดเก็บจะแบ่งเป็น3ส่วน
1. Sign bit [s] : บิตเครื่องหมายถ้าเป็น 0 จะหมายถึงค่านั้นมีค่าบวก 1 จะหมายถึงค่านั้นมีค่าเป็นลบ 
2. Mantissa : จะใช้เก็บตัวเลขที่อยู่หลังจุดทศนิยม
3. Exponent : จะใช้เก็บตัวเลขที่เป็นเลขยกกำลัง โดยการเก็บ จะต้องนำค่ายกกำลังที่คำนวนได้ + ค่าbias(127)
 
Boolean : บูลีนเป็นข้อมูลที่มีค่าเป็นจริง`true` หรือเป็นเท็จ`false`ในภาษาซีก่อนจะใช้ต้องเรียก ` #include <stdbool.v> `
โดยค่าบูลีนส่วนใหญ่จะใช้กับ if-else statement

## Array :page_with_curl:

Array : เป็นโครงสร้างข้อมูลที่เก็บข้อมูลเป็นชุดๆในหน่วยความจำ ชนิดข้อมูลในชุดการจัดเก็บของอาเรย์จะต้องเป็นข้อมูลชนิดเดียวกัน 
และในการเข้าถึงข้อมูลจะต้องใช้การอ้างถึง`Index`ซึ่งจะเริ่มจากศูนย์ ไปถึงจำนวนn-1ของขนาดอาเรย์ทั้งหมด

### One dimensional arry :pencil2:

![images (1)](https://user-images.githubusercontent.com/86911299/181930013-96f90920-8a6d-424e-b729-46683a067db7.png)

จะจัดเก็บในลักษณะที่เป็นแถมต่อเนืองเรียงกัน ขนาดจะขึ้นอยู่กับindexของarray เช่น int num[10] = มีตำแหน่งindexตั้งแต่0 - 9
เราสามารถกำหนดค่าในแต่ละตำแหน่งได้ หรือถ้าหากไม่ได้กำหนดตัวcomplilerจะกำหนดค่า0 - 9ให้แทน

- ขอบเขตของอาร์เรย์ 1 มิติ : ช่วงขอบเขตล่างสุด(Lower Bound) [L] , ช่วงขอบเขตบนสุด(Upper Bound) [U] 
```
สูตรการคำนวนหาตำแหน่งaddressในหน่วยความจำ 
Location(Data[1]) = ตำแหน่งเริ่มต้น[ฺBase] + เนื้อที่หน่วยความจำ[w] * (ตำแหน่งที่ต้องการ[i] - ขอบเขตล่างสุด[L])
```
### Two dimensional arry :pencil2:

![อาร์เรย์สองมิติ+(Two+Dimension+Array)](https://user-images.githubusercontent.com/86911299/181931542-ec7bdc5e-bac7-472c-96e0-12f8abc6f301.jpg)

โครงสร้างข้อมูลในรูปแบบสองมิติที่จัดเก็บข้อมูลแบบตารางสองทางจะเรียงตามแนวแถว(Row) และแนวหลัก(Column)
ในการจัดเก็บสามารถทำได้สองแบบจะต้องใช้กับภาษา`ฟอร์ทราน`
R = จำนวนแถวของแถวลำดับ
i = ตำแหน่งของแถวในอาร์เรย์
j = ตำแหน่งของคอลัมน์ในอาร์เรย์

1. การจัดเก็บแบบการเรียงแถวเป็นหลัก(Row Major Order)
```
Loc(K[i , j]) = Base + w [C * (i - LR) + (j - LC)]
```

2. การจัดเก็บแบบการเรียงคอลัมน์ป็นหลัก(Column Major Order)
```
Loc(K[i , j]) = Base + w [R * (i - UR) + (j - UC)]
```

- ขอบเขตของอาร์เรย์ 2 มิติ : ช่วงขอบเขตล่างสุดของแถว(Lower Bound) [LR] , ช่วงขอบเขตบนสุดของแถว(Upper Bound) [UR]  
ช่วงขอบเขตล่างสุดของคอลัมน์(Lower Bound) [LC] , ช่วงขอบเขตบนสุดของคอลัมน์(Upper Bound) [UC]  
```
ArrayName[LR : UR : LC : UC]
สูตรการคำนวนหาตำแหน่งaddressในหน่วยความจำ 
จำนวนสมาชิก = (UR - LR + 1) * (UC - LC + 1) 
```

**การประกาศอาร์เรย์สองมิติ**
```
datatype arrayName[row size][colum size]
```

### Three dimensional arry :pencil2:

การนำอาร์เรย์สองมิติมาเรียงซ้อนกันจากที่อาร์เรย์สองมิติมีแถว(Row) คอลัมน์(Column)ในอาร์เรย์สามมิติจะมี`ความลึก(Page)`เพิ่มขึ้นมา
```
ArrayName[LR : UR : LC : UC : LP : LP]
สูตรการคำนวนหาตำแหน่งaddressในหน่วยความจำ 
จำนวนสมาชิก = (UR - LR + 1) * (UC - LC + 1) * (UP - LP + 1) 
```


**การประกาศอาร์เรย์สามมิติ**
```
datatype arrayName[row size][colum size][page size]
```


## String :page_with_curl:

String : ชุดของข้อมูลตัวอักขระ จะเก็บข้อมูลนี้ในชนิดของchar / character โดย1อักขระจะถูกเก็บใน1indexและในindexสุดท้ายจะต้องเป็น`null , \0`
แต่ถ้าหากเรากำหนดขนาดไม่พอสำหรับnull โปรแกรมจะตัดStringตัวสุดท้ายออกและนำnullมาแทน หรือจะรันในชุดข้อมูลอื่นจนกว่าจะเจอ ถึงหยุดการทำงาน

### Input & Output :pencil2:

- Input : จะใช้ฟังก์ชันในการรับค่าตัวแปรscanf() , gets()
1. scanf("%s" , variable) ในการใช้ฟังก์ชันนี้จะไม่สามารถใช้space barระหว่างการป้อนข้อมูล
2. gets(char *variable) ในการใช้ฟังก์ชันนี้จะหยุดรับข้อมูลก็ต่อเมื่อกดปุ่มenter และสามารถใช้space bar

- Output : จะใช้ฟังก์ชันในการแสดงผลลัพท์ของค่าตัวแปรที่ดำเนินการเสร็จแล้วprintf() , puts()
1. prinf("%s" , variable)
2. puts(char *varible)

### Declare String :pencil2:

สามารถประกาศและกำหนดค่าเริ่มต้นstringได้
`char variable[][] = {{"Computer"} , {"cs231"} , {"Kaset"}}`

### Function `#include <string.h>` :pencil2:

String manipulation : การประมวลผลสายอักขระสามารถนำมาใช้ในการจัดการข้อมูลอักขระได้ ทั้งการนับความยาว การเปรียบเทียบ การนำมาต่อกัน

#### strcmp()

นำสตริงสองตัวมาต่อกัน 
- var1 < var2 : ได้ผลลัพท์น้อยกว่าศูนย์ 
- var1 > var2 : ได้ผลลัพท์มากกว่าศูนย์
- var1 = var2 : ได้ผลลัพท์เท่ากัน
และผลลัพท์ที่ได้จะส่งกลับมาในรูปแบบจำนวนเต็ม

```
int strcmp(char *var1 , char *var2);
```

#### strcpy()

ฟังก์ชันนี้จะเป็นการคัดลอกข้อมูลจากสตริงนึงไปยังอีกสตริงนึก โดยตัวที่เป็นหลักต้องมีขนาดมากกว่าหรือเท่ากัน
ในการคัดลอกสตริงจะคัดลอกทีละตัวจนกว่าจะ\0ก็จะหยุดคัดลอก และไม่คัดลอก\0ไปด้วย
dest = ตัวแปรปลายทาง src = ตัวแปรต้นทาง

```
char * strcpy(char *dest , char * src);
```

#### strlen()

นับความยาวของสตริง และไม่นับ\0

```
int strlen(str);
```

#### strcat()

นำสตริงสองชุดมาเชื่อมต่อกันผลลัพท์ที่จะได้ตัวสตริงจะมีความยาวเท่ากับสตริงสองชุดมาต่อกัน
dest = ตัวแปรปลายทางที่เก็บผลลัพท์จากการเชื่อมต่อกัน src = ตัวแปรต้นทางนำสตริงไปเชื่อมต่อกัน

```
char *strcat(char *dest , char *src);
```

#### strncpy()

ฟังก์ชันนี้จะเป็นการคัดลอกข้อมูลจากสตริงนึงไปยังอีกสตริงนึง โดยตัวที่เป็นหลักต้องมีขนาดมากกว่าหรือเท่ากัน
ในการคัดลอกสตริงจะคัดลอกทีละตัวจนกว่าจะ\0ก็จะหยุดคัดลอก และไม่คัดลอก\0ไปด้วย และ`สามารถระบุความยาวที่สุด`
dest = ตัวแปรปลายทาง src = ตัวแปรต้นทาง size_t maxlen = ตัวแปรที่ระบุความยาวของสตริง

```
char * strcpy(char *dest , char * src , size_t maxlen);
```

# Structure & Pointer :books:

## Structure :page_with_curl:

โครงสร้างข้อมูลแบบstructure การกำหนดข้อมูลชนิดใหม่ขึ้นมา โดยจะรวมชนิดข้อมูลพื้นฐานไว้ จะเป็นข้อมูลชนิดเดียวกันหรือต่างชนิดกันก้ได้
แต่ในชุดข้อมูลต้องมีความเชือมโยงกันหรือเกี่ยวข้องกัน และในโครงสร้างข้อมูลแบบstructureจะมี
`record / struct`จะเก็บข้อมูลต่างกันในชุดโครงสร้างเดียวกัน เช่น ในโครงสร้างข้อมูลที่เก็บข้อมูลรายชื่อรหัสของนิสิต
record จะเก็บเป็นรายบุคคล หลายๆบุคคลรวมกัน

![296620498_732730577832963_5535013250790364011_n](https://user-images.githubusercontent.com/86911299/182015142-3af3ae68-2714-4f00-bfd7-ff7a7f676e2f.jpg)

### การกำหนดตัวแปรชนิดโครงสร้าง :pencil2:

```
struct struct_name{
   type field1;
   type field2;
   .
   .
   .
   type fieldn;
};
```


ในการกำหนดค่าให้กับตัวแปรต่างๆในโครงสร้างข้อมูลที่กำหนด

```
struct struct_name field;
```

หรือจะกำหนดตัวแปรไปพร้อมกับการกำหนดโครงสร้างข้อมูลเลยก็ได้

```
struct struct_name{
   type field1;
   type field2;
   .
   .
   .
   type fieldn;
}field_name;
```

ในการกำหนดค่าในตัวแปรชนิดโครงสร้างข้อมูลโดยใช้เครื่องหมาย[.]

```
ชื่อตัวแปรงโครงสร้าง.ชื่อสมาชิกในโครงสร้าง;
```

### input & output :pencil2:

- ในการรับinputหรือการกำหนดค่าชนิดข้อมูลอื่นๆที่ไม่ใช่stringจะสามารถใช้เครื่องหมาย[=]
- การรับinputเป็นStringจะไม่สามารถกำหนดค่าโดยใช้เครื่องหมาย[=]จะต้องใช้ฟังก์ชัน`strcpy() , gets() , scanf()`
- ในการแสดงผลของoutput สำหรับในภาษาซีจะสามารถใช้`printf()`

### Array + Structure :pencil2:

![296228690_457215412939774_8479325969192878050_n](https://user-images.githubusercontent.com/86911299/182020162-b96a0a95-5fa0-4ef7-916f-479fcd76ec62.jpg)

ในการนำโครงสร้างข้อมูลแบบStructureมาใช้กับarrayจะทำให้ข้อมูลในรูปบบสตริงหรือข้อความรายบุคคลใช้งานได้สะดวกและง่ายดายมากขึั้น
ในชุดข้อมูลนั้นๆจำเป็นต้องมีความเกี่ยวข้องและเชื่อมโยงกันด้วย

```
struct struct_name{
   type field1;
   type field2;
   .
   .
   .
   type fieldn;
}field_name;

struct struct_name[];
```
![295931890_1159458858260109_3350104657265853866_n](https://user-images.githubusercontent.com/86911299/182020267-d40b5001-e848-420c-9a86-2edb1c698442.jpg)

### Nest Structure :pencil2:

โครงสร้างซ้อนโครงสร้าง เหมือนการจัดเก็บโครงสร้างข้อมูลย่อยไว้ในโครงสร้างข้อมูลกล่องใหญ่ๆ

![296088847_600511421432714_1120103785893153271_n](https://user-images.githubusercontent.com/86911299/182020362-5796b5b9-ff60-4e25-a4ea-4e9988e86f81.jpg)

## Pointer :page_with_curl:

Pointer : เป็นชนิดข้อมูลที่มีความเร็วในการทำงานสูง ทำให้การเขียนภาษาซีมีความยืดหยุ่น 
แต่การที่จะใช้ชนิดข้อมูลพอยเตอร์จะมีความซับซ้อนค่อนข้างสูง แต่ก็ทำให้การใช้ข้อมูลชนิดพอยเตอร์เป็นจุดเด่นในภาษาซี

### Declaration Pointer :pencil2:

ในการประกาศตัวแปรพอยเตอร์เราจะกำหนดชื่อตัวแปรใช้แทนข้อมูลและจองพื้นที่ในการอ้างอิงถึงตัวแปร
สามารถกำหนดชนิดของตัวแปรพอยเตอร์เป็นตัวชี้ไปยังตัวแปรชนิดอื่นๆได้

**ในการจองพื้นที่ต้อง`address`ส่วนใหญ่จะถูกเก็บเป็นเลขฐาน16เพราะข้อมูลมีขนาดยาวมาก**

```
type *variable_name;

int i; จะจองพื้นทั้งหมด4 byteตามชนิดของตัวแปรint และใช้ชื่อตัวแปรiเพื่ออ้างอิงถึงตัวแปร
int *p; ตัวแปรประเภทพอยเตอร์ จะใช้เครื่องหมาย[*]
i = 10; ตัวกำหนดค่าให้ตัวแปรi
p = &i; pเป็นตัวแปรที่เก็บaddress จะใช้เครื่องหมาย[&]
```

### การแสดงค่าAddress :pencil2:

ในการแสดงค่าaddress จะใช้ฟังก์ชันprintfโดยใช้`%p , %u`
%p = แสดงตำแหน่งของaddressที่เป็นเลขฐาน16
%u = แสดงตำแหน่งของaddressที่เป็นเลขฐาน10

### Pointerซ้อนPointer :pencil2:

ในการประกาศพอยเตอร์ซ้อนพอยเตอร์จะใช้เครื่องหมาย[*]สองตัวซ้อนกันเพื่อแสดงถึงพอยเตอร์ซ้อนพอยเตอร์

```
type **variable_name;
```

### Pointer Vs. Array :pencil2:

ในการใช้ตัวแปรชนิดพอยเตอร์สามารถใช้ควบคู่ไปกับตัวแปรชนิดอาร์เรย์ได้ โดยกำหนดตัวแปรคล้ายๆกับการประกาศทั่วไป
เพียงแต่เราสามารถเรียกค่าaddressของindexในarrayได้ เช่น varptr = &a[0]; ตัวแปรvarptr = จะเก็บค่าaddressของตัวแปรa ตำแหน่งที่0

**การบวกลบจำนวนเต็มกับพอยเตอร์**
- ค่าของพอยเตอร์จะไม่เพิ่มหรือลดลงตามตัวเลขจำนวนนั้น
- ค่าของaddressจะเพิ่มหรือลดลงตามมจำนวนนั้นคูณกับขนาดของตัวแปรที่ถูกชี้อยู่

```
int v[5];
int *vPtr;
vPtr += 2; => vPtr = vPtr + (2 * 4) 
```
2 = จะขึ้นอยู่กับการเขียนโปรแกรม 
4 = ขนาดของตัวแปร 

## Pointer Vs. Structure :page_with_curl:

เราสามารถใช้งานสมาชิกของตัวแปรได้สองวิธี
1. ใช้เครื่องหมาย[.]ในการเข้าถึงข้อมูล`struct_name.field_name`
2. ใช้เครื่องหมาย[->]ในการเข้าถึงข้อมูล ในกรณีที่ตัวแปรเป็นพอยเตอร์ไปปยังตัวแปรของโครงสร้าง`pointer_name->field_name`

## การกำหนดประเภทข้อมูลที่ผู้ใช้กำหนดเอง :page_with_curl:

`typedef` การนิยามประเภทของข้อมูล เราสามารถประกาศตัวแปรในรูปแบบของประเภทข้อมูลด้วยคำใหม่ได้
โดยคำที่นิยามใหม่จะใช้แทนชนิดข้อมูลต่างๆเช่น int float double

```
typedef type new_type;
```

# Function & Recursion :books:

## Function :page_with_curl:

Function : ฟังก์ชันคือชุดคำสั่งในการทำงาน จะสามารถเรียกใช้ได้ง่าย และผู้ใช้ไม่จำเป็นต้องรู้รายละเอียดของระบบการทำงานทั้งหมดก็ได้
เพียงแค่รู้วิธีการใช้งานและผลลัพธ์ก็ได้ สำหรับฟังก์ชันสามารถเขียนให้โปรแกรมมีการทำงานที่ซับซ้อนได้ แบ่งเป็นสองประเภท

- Standard library function : ฟังก์ชันไลบรารีมาตรฐานจะสามารถเรียกใช้โดยคำ `#include <directives>`
Directives แทนกลุ่มของฟังก์ชันในแต่ละแบบ เช่น stdio.h , conio.h , string.h math.h และฟังก์ชันมาตรจะมีการทำงานในรูปแบบเฉพาะงานพื้นฐานจึงทำให้ต้องสร้างรูปแบบเฉพาะขึ้นมา

- User Defined function : ในการทำงานรูปแบบเฉพาะทางจะต้องสร้างขึ้นมาเอง 
โดยมีข้อกำหนดการเขียน 
1. สร้างฟังก์ชันก่อนที่จะสร้างmain
2. สร้างmainก่อนที่จะสร้างฟังก์ชัน จึงต้องใช้การประกาศ`function prototype`

![296036084_1224997751610870_8499602511448098384_n](https://user-images.githubusercontent.com/86911299/182026084-4c9a5dce-5c7a-475b-9a8e-5c7720a1d34f.jpg)

### function prototype :pencil2:
```
type function_name(type1, type2, ... ,typen);
```

![295666468_750512639548786_9030175358266972520_n](https://user-images.githubusercontent.com/86911299/182026217-5b623cc7-f0f8-44c1-9f89-f7a84c2e1625.jpg)
![295684891_366139085668058_4540643205752000105_n](https://user-images.githubusercontent.com/86911299/182026219-4fe1670f-ed93-443d-a41e-b9809ad271a6.jpg)
![296243188_448037197199260_8719984754030229176_n](https://user-images.githubusercontent.com/86911299/182026220-cac8ba57-f730-40f4-abdf-c6773e7d0925.jpg)
![296575014_487901123144684_443353130266227159_n](https://user-images.githubusercontent.com/86911299/182026224-04391ab8-2dfb-4722-bf36-44f7fc78164c.jpg)

### Global :pencil2:

ตัวแปรที่ฟังก์ชันใดก็สามารถเรียกใช้ได้โดยการประกาศตัวแปรต่อจาก`preprocessor directive` ใช้ได้ทั้งในmainและฟังก์ชันที่ประกาศ

### Local :pencil2:

ตัวแปรที่สามารถใช้ได้เฉพาะภายในฟังก์ชันที่ประกาศตัวแปรนั้นๆ

### Pass by value :pencil2:

ส่งค่าเข้ามาในฟังก์ชัน โปรแกรมมันประกาศตัวแปรใหม่ แล้วก็ copy ค่ากำหนดให้กับมันเฉยๆเท่านั้น

### Pass by reference :pencil2:

เปลี่ยนค่าในฟังก์ชันแล้วตัวแปรจริงๆก็เปลี่ยนค่าตาม จะมีการนำpointerเข้ามาใช้ด้วย 
เพราะ pointerเหมือนการร่างไว้ก่อน สามารถแก้ไขค่าของตัวแปรที่มันชี้อยู่ได้โดยใช้ค่าที่เคยร่างไว้แล้ว

## Recursion :page_with_curl:

Recursion : การเวียนเกิด วนกลับไปเรียกตัวแปรเดิมซ้ำๆ แตกต่างจากลูปตรงที่ถ้าราเป็นลูปจะใช้forในการวนข้อมูลแต่ถ้าเป็นrecursionจะใช้if-elseแล้วreturnค่าตัวแปรเดิมแทน

การทำงานของRecursionมี 2 ขั้นตอน
1. Base step : จะบอกถึงกรณีที่จะจบการวน เป็นตัวหยุด และถ้าไม่มีการเรียกซ้ำแล้วจะคืนค่า
2. Induction / Recursion Step : เรียกตัวเองซ้ำๆจนกว่าจะเข้าไปเจอbase step

### Linear Recursion :pencil2:

Linear Recursion : การเรียกตัวเองแบบเส้นตรง คล้ายๆstack

```
int fr(int n){
   if (n <= 0)
      return 0;
   else
      return fr(n-1) + n;
}
```
n = 0 , 1 , 2 , 3 , ...

=> 1 , 1 + 2 , 1 + 2 + 3 : n - 1

=> f(n) = f(n-1) + n

### Binary Recursion :pencil2:

Binary Recursion : มีการเรียกตัวเอง 2 ครั้ง 
1. basic step : f0 = 0 , f1 = 1
2. Induction : Fn = F(n - 1) + F(n - 2)

```
int fibonacci(int n){
   if(n == 1)
      return 0;
   else if(n == 2)
      return 1;
   else
      return fibonacci(n-1) + fibonacci(n-2);
}
```

Fn = Fn - 1 + Fn - 2 [F0 = 0 , F1 = 1]

Topdown

![4041ddaa-fccc-49b7-b2ad-320a49df75fb](https://user-images.githubusercontent.com/86911299/184830990-79a3050f-f93e-496b-8bca-031076129139.png)

Fibonacci

![fibonacci-sequence](https://user-images.githubusercontent.com/86911299/184831798-db74f306-88cc-4bfc-8503-85bb46692358.png)

### Multiple Recursion :pencil2:

Multiple Recursion : เรียกซ้ำมากกว่า 2 ครั้ง ใช้กรณีสลับตัวอักษร

```
       => m = 0 ; n + 1
A(m,n) => m > 0 , n = 0 ; A(m - 1 , 1)
       => m > 0 , n > 0 ; A(m - 1, A(m, n - 1))
```

### Tail Recursion :pencil2:

Tail Recursion : การทำงานจะจบที่ตัวสุดท้ายเมื่อมีการเรียกจะส่งคำตอบให้เลบ + ไม่เปลืองพื้นที่
```
int ft(int n, int sum){
   if (n <= 0)
      return sum;
   else
      return ft(n-1, n + sum);
}
```

# Linked List :books:

Linked List : เป็นโครงสร้างข้อมูลที่เก็บcollections of data สามารถเก็บข้อมูลได้ทุกชนิดเหมือนกับarray
แต่ต่างกันตรงที่ข้อดีของarrayคือเข้าถึงข้อมูลได้ง่ายและรวดเร็วโดยใช้เครื่องหมาย`[i]`i = `index`ตำแหน่งของสมาชิกในชุดข้อมูล 
และข้อเสียของarrayจะมีการกำหนดขนาดตายตัว ในการเพิ่มสมาชิกใหม่เข้าในชุดข้อมูลต้องทำการย้ายสมาชิกเดิมที่มีอยู่จำนวนมาก
และในarrayจะต้องมีการจองพื้นที่ในหน่วยความจำติดกันเป็น`{}`
ส่วน`Linked List`สามารถจัดเรียงกันตามpointerได้โดยเป็นสายข้อมูลที่เชื่อมโยงกันผ่านpointer 
และในสายข้อมูลจะสามารถเพิ่ม,ตัดและแทรกชุดข้อมูลออกในแต่ละส่วนได้อีกด้วย
ในlinked listสามารถใช้เนื้อที่ในการเก็บข้อมูลได้อย่างมีประสิทธิภาพหากเรา
`ไม่ทราบจำนวนขนาดที่แน่นอน`ต่างจากarrayที่จำเป็นต้องกำหนดขนาดของข้อมูล 
และยังสร้างสมาชิกใหม่ขึ้นมาเพื่อเพิ่มการเก็บข้อมูลได้เรื่อยๆตามที่ต้องการา

***Linked List***
1. Pointer : มีไว้สำหรับชี้สมาชิกต่างๆในlinked list
2. Information : ข้อมูลที่เป็นในLinked list จะไม่เป็นบล็อกติดกัน ไม่จำเป็นต้องเรียงกัน

## Insert Item :page_with_curl:

![298795666_348536850691181_2645159197647934475_n](https://user-images.githubusercontent.com/86911299/184817818-047e94da-a0ef-40cd-9275-756e6c138180.jpg)

ในการแทรกสมาชิกเข้าไปเพิ่มในชุดข้อมูลสามารถทำได้โดยใช้พอยเตอร์ของสมาชิกตัวใหม่ชี้ไปที่สมาชิกเดิมที่อยู่ถัดไปจากสมาชิกตัวใหม่
แล้วย้ายพอยเตอร์ของสมาชิกใหม่ที่ต้องการต่อท้ายไปชี้ที่สมาชิกใหม่

## Deleted Item :page_with_curl:

![298795666_348536850691181_2645159197647934475_n](https://user-images.githubusercontent.com/86911299/184818771-087d72f9-fbdd-4a3d-9b04-9db940369eb3.jpg)

ในการลบสมาชิกที่อยู่ในชุดข้อมูลของLinked List 
จะสามารถทำได้โดยใช้พอยเตอร์ของสมาชิกที่อยู่ก่อนหน้าสมาชิกที่ต้องการจะลบช้
ไปที่สมาชิกตัวก่อนหน้าตัวที่ต้องการจะลบแทน และทำการคืนค่าพื้นในหน่วยความจำด้วยคำสั่ง`free()`

## การสร้างและการจัดการ :page_with_curl:

### Node Structure :pencil2:

1. ส่วนข้อมูล : จำนวนเต็ม ทศนิยม หรือโครงสร้างข้อมูลอื่นๆ

2. ส่วนพอยน์เตอร์ : ชี้ที่ยังสมาชิกตัวถัดไป

```
struct node{
   int item;
   struct node *next;
}

typedef struct node node_t;

typedeef struct nd{
   struct item data;
   struct nd *next:
}node;
```
### Head of Linked List :pencil2:

1. Length : ความยาวของlinked list

2. First : พอยน์เตอร์ที่ชี้ไปยังสมาชิกตัวแรก

![298585155_749811699606709_5432365789617221257_n](https://user-images.githubusercontent.com/86911299/184825734-b92d680a-9ef7-441c-80e7-03ea58c716cf.jpg)

3. Last : พอยน์เตอร์ที่ชี้ไปยังสมาชินตัวสุดท้าย

![299239829_1487015201757144_2104117563990773107_n](https://user-images.githubusercontent.com/86911299/184825740-8599db0a-6ec1-4a5b-beeb-69eabdf04cbd.jpg)


## Heap :page_with_curl:

Heap : (dynamic storage) พื้นที่ของหน่วยความจำในคอมพิวเตอร์ที่จะถูกจัดสรรด้วยCPU
โดยพื้นที่ในHeapส่วนใหญ่จะเป็นพื้นที่ว่าง
ในการจองหน่วยความจำแบบheapสามารถใช้ได้สองคำสั่งคือ`malloc(),calloc()`
และเมื่อไม่ต้องการจะใช้หรือใช้พื้นที่ในหน่วยความจำเสร็จแล้วก็จะต้องใช้คำสั่ง`free()`เพื่อยกเลิกการจอง 
แต่ถ้าหากไม่ได้ทำการคืนพื้นที่จะทำให้เกิด`memory leak`ทำให้พื้นที่บนหน่วยความจำของheapยังถูกเก็บไว้เป็นข้อมูลขยะ

### malloc() :pencil2:

เป็นฟังก์ชันที่จะทำหน้าที่ในการจัดสรรหน่วยความจำให้บล็อก และคืนค่ากลับให้พอยน์เตอร์ที่ชี้ไปยังบล็อกของหน่วยความจำใหม่ 
หรือคืนค่าเป็นNullถ้ามีเนื้อที่ในหน่วยความจำไม่พอ

**จะต้องใช้ `#include <stdlib.h>`**

```
ptr = (castType*) malloc(size);

ptr = (float*) malloc(100 * sizeof(float));
```

### free() :pencil2:

เป็นฟังก์ชันที่ใช้ในการคืนพื้นที่ในหน่วยความจำที่เคยจองไว้

**จะต้องใช้ `#include <stdlib.h>`**

```
free(ptr);
```

## Singly Linked List : SLL :page_with_curl:

![download](https://user-images.githubusercontent.com/86911299/184826487-79f8fd5d-94b3-43e0-8bfb-5606c3317330.png)

### Ordinary Singly Linked List : OLL :pencil2:

![Singly-Linked-List1](https://user-images.githubusercontent.com/86911299/184827107-74eff284-7929-4479-a685-fd8218d9173c.png)

### Circular Singly Linked List : CLL :pencil2:

![Circular-Linked-List](https://user-images.githubusercontent.com/86911299/184827080-abb70e87-e318-48f9-9edc-95cc719efd64.png)

## Doubly Linked List : DLL :page_with_curl:

![DLL1](https://user-images.githubusercontent.com/86911299/184826823-202fe4f3-936f-4846-beec-21e8eace4d25.png)

### Ordinary Doubly Linked List : ODLL :pencil2:

![Doubly-Linked-List](https://user-images.githubusercontent.com/86911299/184827517-86db7f27-1a30-4212-ac58-4f6f48402bce.png)

### Circular Doubly Linked List : CDLL :pencil2:

![Doubly-Circular-Linked-List](https://user-images.githubusercontent.com/86911299/184827499-9c71e017-0025-43ae-a81b-1b8299feb03f.png)

# Stack [LIFO : Last In First Out]:books:

![1_r4Bfo3rrFprzFM2zbgzZXA](https://user-images.githubusercontent.com/86911299/184838076-619c38e5-196e-437d-8fc4-c06364136a51.jpeg)

Stack [LIFO : Last In First Out] : เป็นลักษณะข้อมูลที่เก็บแบบวางซ้อนทับกัน
แบบวางหลังแต่ได้ออกก่อน วางก่อนได้ออกทีหลัง ข้อมูลแรกอยู่ล่างสุด ข้อมูลสุดท้ายอยู่ด้านบน ใช้การจัดลำดับการทำงาน และการเรียกใช้ฟังก์ชัน
ในภาษาซี จะใช้กลไกในการตรวจวง{} ใช้นิพจน์ `A + (B / (C - D)) * E`

## Implementation Stack :page_with_curl:

1. Array Implementation 

2. Linked List Implementation 

## Array representation of Stack :page_with_curl:

จำนวนข้อมูลสูงสุดของStack คือ N (ขนาดของArray) ตัวแปรบนสุดแทนจำนวนของข้อมูลที่มีอยู่ในstack

![298570946_639402354458042_6549412223160864892_n](https://user-images.githubusercontent.com/86911299/184840055-57c8d7ca-891d-4a04-b3d9-32673b4bfecb.jpg)

## Operation Stack :page_with_curl:

![Push-and-Pop-operation-on-Stack](https://user-images.githubusercontent.com/86911299/184840905-16d650cd-d907-4133-ba88-3f4d618b6054.png)

### Push Stack :pencil2:

- เป็นOperation สำหรับนำข้อมูลลงในStack

### Pop Stack :pencil2:

- เป็นOperation สำหรับนำข้อมูลออกจากStack

### Example Stack = 4 :pencil2:

![298862949_753881685886328_785999869958107209_n](https://user-images.githubusercontent.com/86911299/184841236-7e3976f4-ecfa-460c-9051-89f75791a00f.jpg)

## นิพจน์คณิตศาสตร์ :page_with_curl:

### Infix :pencil2:

- นิพจน์ที่เครื่องหมายดำเนินการ(Operator)`อยู่ระหว่าง`ตัวดำเนินการ(Operands) เช่น A + B - C

### Postfix :pencil2:

- นิพจน์ที่เครื่องหมายดำเนินการ(Operator)`อยู่หน้า`ตัวดำเนินการ(Operands) เช่น - + A B C

### Prefix :pencil2:

- นิพจน์เครื่องหมายดำเนินการ(Operator)`อยู่หลัง`ตัวดำเนินการ(Operands) เช่น A B + C -

### การแปลงนิพจน์infixให้เป็นPostfix :pencil2:

ลำดับความสำคัญของOperator(Precedence)
- เครื่องหมายยกกำลังมีความสำคัญมากกว่าเครื่องหมายคูณและหาร
- เครื่องหมายคูณและหารมีความสำคัญมากกว่าเครื่องหมายบวกและลบ

*ข้อเสีย : ทำให้คอมไพเลอร์ยุ่งยาก*

```
AB+ => A+B
AB- => A-B
AB* => A*B
```

### อัลกอริทึมการแปลงนิพจน์infixให้เป็นPostfix :pencil2:

1. ถ้าข้อมูลเข้าจะเป็นตัวถูกดำเนินการ(Operand)ให้นำออกไปเป็นผลลัพธ์
2. ถ้าข้อมูลเข้าเป็นตัวดำเนินการ(Operator)
   - ถ้าstackว่าง : ให้push operatorลงในstack
   - ถ้าstackไม่ว่าง : ให้เปรียบเทียบOperatorที่เข้ามากับOperatorที่อยู่ในตำแหน่งTop 
      ถ้าOperatorที่เข้ามามีความสำสัญมากกว่าOperatorที่ตำแหน่งtopจะ`push`ลงในstack
      ถ้าOperatorที่เข้ามามีความสำสัญน้อยกว่าหรือเท่ากับOperatorที่ตำแหน่งtopจะ`pop`ออกไปเป็นoutput
3. ถ้าข้อมูลเข้าเป็นวงเล็บเปฺิดให้`push`
4. ถ้าข้อมูลเข้าเป็นวงเล็บปิดให้`pop` ไปเป็นoutputจนกว่าจะเจอวงเล็บเปิด
5. ถ้าข้อมูลเข้าหมดแล้ว ให้`pop`ข้อมูลออกจากstackไปเป็นoutputจนกว่าstackจะว่าง

## ฺBalancing Symbol :page_with_curl:

Balancing Symbol : การตรวจสอบอักขระสมดุล
1. อ่านอักขระทีละตัว
   - อักขระเปิด เช่น { [ ( `Push`
   - อักขระปิด เช่น } ] ) `Pop` 
   *ถ้าบนtopไม่เป็นคู่กันจะเป็นerror*
2. ถ้าอ่ากอักขระหมดแล้วแต่ยังไม่เป็นStackว่างจะแสดงผลเป็นerror

# Queue [FIFO : First in First Out]:books:

โครงสร้างข้อมูลที่เรียงต่อกันเป็นแถวเมื่อมีสมาชิกใหม่จะเข้าไปต่อด้านหลัง และเมื่อสมาชิกจะออกจากคิวจะต้องออกจากด้านหน้า มีตัวชี้ 2 ตัวคือfront และ rearสำหรับการใส่ข้อมูลเข้าและนำข้อมูลออก

![Queue-Data-Structures-1024x1024](https://user-images.githubusercontent.com/86911299/184851552-bc82360f-245c-4da4-857f-7962da5fbd4a.png)

## Enqueue :page_with_curl:

- ก่อนที่จะเพิ่มข้อมูลเข้าไปต้องตรวจสอบก่อนว่าคิวเต็มหรือไม่ `rear = MAXQUEUE`
ถ้าคิดเต็ม ต้องแสดงคำเตือนออกมา แต่ถ้าไม่เต็มให้ทำการเพิ่มข้อมูลเข้าไปในคิวและ
เพิ่มค่าrearทีละ 1 ก่อนจะนำสมาชิกเข้าไปใหม่ทุกครั้ง ทำอย่างงี้ไปเรื่อยๆจนกว่าคิวจะเต็ม

![298920167_1131368240791919_7914888336747977101_n](https://user-images.githubusercontent.com/86911299/184852798-c4aeef27-987c-4e3b-9951-5a1cdd40779c.jpg)

```
addQ(int data){
   if(rear == MAXQUEUE - 1){
      printf("\n Queue is full");
      return;
   }
   else{
      rear++
      arr[rear] = data;
      if(front == -1)
         front ==0;
   }
}
```

## Dequeue :page_with_curl:

- ก่อนจะทำการDequeueเพื่อนำข้อมูลออกจากตำแหน่งfrontจะต้องตรวจสอบก่อนว่าคิวว่างหรือไม่ `front = rear = -1` 
ถ้าคิวว่างให้แสดงคำเตือนแต่ถ้าไม่ว่างให้แสดงข้อมูลที่มีอยู่ในคิวและทำการนำข้อมูลที่ตำแหน่งที่fronชี้อยู่ออกจากคิวและเพ่ิมค่าfrontขึ้นทีละ1ทุกครั้งที่นำข้อมูลออกจากคิว 
จนกว่า`front = rear => front = -1 , rear = -1`

![299050831_1032110824095093_23930857974328291_n](https://user-images.githubusercontent.com/86911299/184852793-9ed1bd61-c8d7-427c-83a0-4836a16c46fb.jpg)

```
delQ(){
   int data:
   if(front == -1){
      printf("\nQueue is Empty");
      return NULL;
   }
   data = arr[front];
   if(front == rear)
      front = rear = -1;
   else
      front ++;
   return data;
}
```

## Circular Queue :page_with_curl:

- เพื่อใช้ในการแก้ปัญหาในกรณีที่ยังมีพื้นที่เหลือในการเก็บข้อมูล และคิววงกลมสามารถกลับไปใช้พื้นที่ด้านหน้าได้ในกรณีที่ใช้พื้นที่มาถึงปลายสุดของคิวแล้ว

![Circular-Queue-using-Array-in-C](https://user-images.githubusercontent.com/86911299/184858240-98e873c0-798d-47d3-ab7e-859bf7692c87.png)

### Enqueue :pencil2:

![298264243_1488687288243237_5188102707214588922_n](https://user-images.githubusercontent.com/86911299/184858573-ccb4fb2c-8fb8-4c07-8bf6-4e3bd6fb3b9a.jpg)

```
addq ( int item ) {
   if (( rear == MAX -1 && front == 0 ) || ( rear + 1 == front )){       
      printf ( "\nQueue is full" );
      return; 
   }
   if ( rear == MAX - 1 ) 
      rear = 0 ;//เมื่อต้องการเพิ่มข้อมูลเข้าไปอีกให้กำหนดrearไปชี้ที่จุดเริ่มต้นใหม่
   else
      rear++ ;
   arr[rear] = item ;  
   if ( front == -1 ) 
   front = 0 ;
}
```

### Dequeue :pencil2:

![298927866_1490070031405711_5288499801700022641_n](https://user-images.githubusercontent.com/86911299/184858562-13546142-fc2c-4456-9f3a-c57c82e2ae41.jpg)

```
delq( ) {
   int data ;
   if ( front == -1 ) {
      printf ( "\nQueue is Empty" ) ;
         return NULL ; 
   }
   else {
      data = arr[front] ;
      if ( front == rear ) 
      front = rear = -1 ;//ลบคิวที่เหลือเพียงตัวเดียว
   else {
      if ( front == MAX - 1 )
      front = 0 ;//ลบคิวที่ช่องความจำสุดท้าย กำหนดให้front วนไปชี้ที่จุดเริ่มต้นใหม่
   else
      front++ ; 
   }
}
return data ;}
```

### Priority Queue :pencil2:

Priority Queue : คิวลำดับความสำคัญ หรือ แถวคอยเชิงบุริมภาพทำให้เราสามารถประยุกต์ใช้คิวได้ดีขึ้น
เนื่องจากเพิ่มการให้ความสำคัญของสมาชิกที่แตกต่างกัน ส่งผลให้เราสามารถจัดเรียงคิวได้ใหม่ให้เหมาะสมกับการทำงานได้
เราใช้คิวลำดับความสำคัญในการจัดการทำงานการตรวจนับ

Queue : ข้อมูลที่เข้ามาก่อนจะสิทะิ์ออกก่อน(First in First Out : FIFO) มีบางครั้งที่ต้องยกให้สมาชิกบางประเภทได้ทำงานก่อนทั้งที่มาทีหลัง เช่นการให้คิวงานที่เล็กกว่าทำงานก่อน หรือการที่ให้สิทธิพิเศษ

# Linear & Hashing :books:

## Sequential Search :page_with_curl:

### Complexity of Algorithims :pencil2:

### Average Case :pencil2:

### Rate of growth : Big O notation :pencil2:

## Binary Search :page_with_curl:

## Hashing Function :page_with_curl:

### Mod :pencil2:

### Mid-Square :pencil2:

### Folding :pencil2:

### Open Addressing :pencil2:

### Double Hashing :pencil2:

### Chaining :pencil2:

# Graphs :books:

# Trees :books: