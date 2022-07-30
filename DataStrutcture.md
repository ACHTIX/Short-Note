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

- จำนวเต็มบวก : 

- จำนวนเต็มลบ : 


4. 2' complement system



#### Overflow

Overflow : ข้อมูลล้นหรือข้อมูลเกิน เกิดในกรณีที่ตัวเลขที่มีขนาดใหญ่กว่าความจุของหน่วยความจำ 

#### Underflow

Underflow : ข้อมูลน้อยเกินกว่าที่จะเก็บในหน่วยความจำจนไม่สามารถนำไปเก็บในหน่วยความจำ

#### Real Number

Real Number : จำนวนจริงเป็นเลขทศนิยมfloating point จัดเก็บในรูปแบบเลขฐานสองแบบเดียวกับInteger 
`Normalized` การเขียนเลขฐานต่างๆ ได้ทั้งฐานสอง ฐานสิบ และอื่นๆ ให้อยู่ในรูปแบบของเลขยกกำลัง 
เช่น 1.52 x 10^15 = 152,000,000 1.1011 x 2^5 = 110110

**ในการใช้หน่วยความจำเก็บจำนวนจริง**
- Float : จะเก็บในรูปแบบ`Single precision` โดยจะใช้พื้นที่ในหน่วยความจำขนาด32บิต
- Double : จะเก็บในรูปแบบ`double precision` โดยจะใช้พื้นที่ในหน่วยความจำขนาด64บิต

* 

* Mantissa

* Exponent

#### Boolean

#### Relational Operator

## Array :page_with_curl:

### One dimensional arry :pencil2:

### Two dimensional arry :pencil2:

### Multidimensional arry :pencil2:

## String :page_with_curl:

### Input & Output :pencil2:

### Declare String :pencil2:

### String manipulation :pencil2:

### Function `#include <string.h>` :pencil2:

#### strcmp()

#### strcpy()

#### strlen()

#### strcat()

#### strncpy()

# Structure & Pointer :books:

## Structure :page_with_curl:

### :pencil2:

## Pointer :page_with_curl:

### :pencil2:


# Function & Recursion :books:

# Linked List :books:

# Stack :books:

# Queue :books:

# Linear & Hashing :books:

# Graphs :books:

# Trees :books: