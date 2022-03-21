# สารบัญเนื้อหาสรุป

## 1. Introduction :bookmark_tabs: ##
## 2. Class & Object :closed_book: ##
## 3. Constructors, Access modifiers :green_book: ##
## 4. Composition :orange_book: ##
## 5. Inheritance :notebook: ##

# Introduction :books:

## history :page_with_curl:

ภาษาCPP / C++ เป็นภาษาที่วิวัฒนาการมาจาก ภาษาC โดยภาษาCPP / C++ จะสามารถใช้เขียนโปรแกรมได้ทั้งเชิงโครงสร้าง และเชิงวัตถุ ภาษาCPP / C++ถูกสร้างขึ้นโดยคุณเบียเนอ สเดราสดร็อบ (Bjarne Stroustrup) ในปีค.ศ. 1985 / ปีพ.ศ. 2582
โดยการพฒันาการโปรแกรมทั้ง 2 สาย
1. ภาษาระดับต่ำ (Low Level Language) ในตอนแรกภาษาระดับต่ำจะสามารถทำงานได้เร็วกว่า แต่คนทั่วไปเข้าใจยาก เช่น *Assembly* 
หลังจากนั้นจึงมีการพฒันามาเป็น*ภาษาซี* ซึ่งภาษาซีนั้น ถูกสร้างมาเพื่อให้คนทั่วไปเข้าใจง่ายขึ้นและยังคงความเร็วไว้อยู่

2. ภาษาระดับสูง (High Level Language) ในตอนแรกภาษาระดับสูงคนทั่วไปสามารอ่านแล้วเข้าใจง่ายกว่าภาษาระดับต่ำแต่จะมีความเฉพาะเจาะจงมาก เช่น *fortran* [ใช้ในทางวิทยาศาสตร์] , *COBOL* [ใช้ในทางธุรกิจ] ในปัจจุบันเช่น ธนาคารบางที่ก็ยังใช้ภาษานี้อยู่ 
หลังจากนั้นจึงมีการพฒันาเป็น*Simula* [เป็นภาษาที่นเป็นต้นกำเนิดของภาษาโปรแกรมเชิงวัตถุ] ถูกสร้างมาเพื่อให้สามารถนำภาษานี้ไปใช้ได้ในหลายสาขา และเข้าใจง่ายขึ้น

**ดังนั้น*ภาษาCPP* จึงมีต้นกำเนิดมาจากการรวมกันของ*ภาษาC* และ * *ภาษาSimula***
ภาษาCPP จึงเป็นการต่อยอดจากภาษาซีโดยมีการนำเรื่องของคลาสและวัตถุเข้ามาเป็นหลัก 
และจากภาษาSimulaโดยสามารถใช้กับสาขาใดๆก็ได้มีความ ทั่วไป เข้าใจง่ายมากขึ้น และมีความรวดเร็วในการทำงาน 

## format code :page_with_curl:

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
int main()
{
    //การประกาศตัวแปร เหมือนภาษาซี//
    int a , b;

    //การรับค่า//
    cin >> a;
    cin >> b;
    //หรือรับค่าแบบบรรทัดเดียว//
    //`cin >> a , b;`//

    int total = a + b;

    cout << "HELLO WORLD" << endl;
    cout << "Total = " << total << endl;
}
```

:keyboard: Input

```
4
5
```

:printer: Output

```
HELLO WORLD
Total = 9
```

### using namespace :pencil2:

การใช้*using namespace* โดยปกติแล้วภาษาCPPการเขียนโปรแกรมในการ cout หรือ cin ฯลฯ จะต้องเขียนโค้ดแบบนี้
`std::cout << "HELLO WORLD" << std::endl;`
จะสังเกตุเห็นได้ว่าหน้าcout , endlจะต้องมี*std::* ดังนั้นเราจึงใช้คำว่า*using namespace*เข้ามาช่วยเพื่อลดความยาวและความยาวของโค้ดลงนั้นเอง

### How to compiler CPP :pencil2:

การคอมไพล์
`g++ ตามด้วยชื่อไฟล์`

การรันโปรแกรม
`a.out or ./a.out`

การคอมไพล์ และรันโปรแกรม
`g++ ชื่อไฟล์ -o คำที่จะใช้แทน a.out`

## Example code :page_with_curl:

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
class Rectangle { // user-defined type
public:
	int width;  // int is a primitive type
	int length;

	int area() {
		return width * length;
	}

	int perimeter() {
		return 2 * (width + length);
	}

	void change_size(int d) {
		width += d;
		length += d;
	}
};
```

```
int main() {

	Rectangle r;
	cout << "Enter width: ";
	cin >> r.width;

	cout << "Enter length: ";
	cin >> r.length;

	cout << "Area: " << r.area() << endl;
	cout << "Perimeter: " << r.perimeter() << endl;

	r.change_size(1);
	cout << r.width << ", " << r.length << endl;
}
```

:keyboard: Input

```
Enter width: 20
Enter length: 40
```

:printer: Output

```
Area: 800
Perimeter: 120
21, 41
```

# Class & Object :books:

คลาส จะช่วยจัดระเบียบข้อมูลและคำสั่งในเป็นส่วนๆ โดยรวบรวมตัวแปรและฟันก์ชันข้อมูลและฟังก์ชันที่บรรจุคำสั่งการประมวลผลที่เกี่ยวข้องกัน มาอยู๋ในคลาสเดียวกัน
และเมื่อต้องการใช้คลาสต้องสร้างวัตถุขึ้นมาก่อน ดังนั้นคลาสจะเป็นเหมือนแม่พิมพ์ของวัตถุ จะสร้างวัตถุได้จะต้องขึ้นอยู่กับคลาส ต้องมีความสอดคล้องกัน และเรียกใช้ฟันก์ชันของกันและกัน

เช่น 
- คลาสของนักเรียน จะมีวัตถุเป็น ชื่อ และ คะแนน
- คลาสของบัญชีธนาคาร จะมีวัตถุเป็น เลขบัญชี ,  เงินคงเหลือ , การถอนเงิน , การฝากเงิน

`private:` 
สมาชิกประเภทนี้สามารถเข้าถึงได้โดยคลาสและออบเจ็คเดียวกัน และนี่เป็นค่าเริ่มต้นเมื่อเราปล่อยให้ว่าง
`protected:`
สมาชิกประเภทนี้สามารถเข้าถึงได้ในคลาสเดียวกัน (friends) และ extended classes
`public:`
สมาชิกประเภทนี้สามารถเข้าถึงได้ทุกส่วนของโปรแกรม

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
class Circle
{
private:
    int r;
public:
    void setRadius(int n)
    {
        r = n;
    };
    float area(void)
    {
        return 3.14 * r * r;
    };
    float girth(void)
    {
        return 3.14 * 2 * r;
    };
} cir1;
```

```
int main ()
{
    int n;
    cout << "Enter circle radius: ";
    cin >> n;
    cir1.setRadius(n);
    cout << "Area " << cir1.area() << endl;
    cout << "Girth " << cir1.girth() << endl;
    return 0;
}
```

:keyboard: Input

```
code
```

:printer: Output

```
code
```

## Class :page_with_curl:

`Class` เป็นuser - defined type นิยมตั้งชื่อคลาสเป็นคำนานตรงกับบริบทของการใช้งานและต้องสร้าง object ได้หลายๆวัตถุ
- *instance* มีความหมายเดียว *object* ในการโปรแกรมวัตถุ

คลาสและวัตถุประกอบด้วย 2 ส่วน ดังนี้
 1. data เรียก data member คุณลักษณะของวัตถุ เช่น ความกว้าง ความยาว 
    [ชื่ออื่น : attribute, property, member, instance variable]
 2. function เรียกว่า member function การทำงานของวัตถุ
    [ชื่ออื่น : method, operation, behavior] 

### การจัดแบ่งโปรแกรม :pencil2:

1. Class
    - Data Member
    - Member Function
2. Object

:desktop_computer: Example :

1. Class : หนังสือ (Book)
    - Data Member : ชื่อหนังสือ , ชื่อผู้แต่ง , สำนักพิมพ์ , ราคา
    - Member Function : ยืมหนังสือ (Borrow) , คืนหนังสือ (BringBack)
2. Object : 
    - C Programming , โดยคุณเดนนิส , ราคา 290
    - C++ , โดยคุณเบียเนอ , ราคา 400

## Object :page_with_curl:

`Object` หรือ `instance`*Object - Oriented Programming* วัตถุสร้างเพื่อการนำไปใช้ในคลาส 
เพื่อเข้าถึงและใช้งานข้อมูลในตัวแปรกบัฟันก์ชันภายใน เหมือนกับข้อมูลที่ผลิตจากคลาส

วัตถุ เป็นได้ทั้งรูปธรรมแบบจับต้องได้ เช่น นักเรียน สินค้า รถ และนามธรรมแบบจับต้องไม่ได้ เช่น บัญชีธนาคาร ความเห็น

**คลาสถือเป็นประเภทข้อมูลแบบหนึ่ง ส่วนวัตถุเป็นข้อมูลประเภทคลาส**

### การสร้างObject :pencil2:

การสร้างวัตถุจะสร้างโดยเหมือนกับการประกาศตัวแปร 
ชื่อคลาส ชื่อวัตถุในคลาส;

:desktop_computer: Example :

```
BankAccount scb_account;
BankAccount tmb_account;

//แบบย่อ//
Student nam, fon, ton;
```

## ข้อมูลและฟันก์ชันของวัตถุ :page_with_curl:

### ข้อมูลของวัตถุ :pencil2:

`Data Member` หรือ `Instance Variable`คือคุณลักษณะ อัตลักษณ์ หรือสถานะของวัตถุ ที่ขึ้นอยู่กับการทำงานของโปรแกรมว่าต้องการใช้ทำอะไร
เช่น รายชื่อ สีของปากกา ยอดเงินคงเหลือในบัญชี

**การเรียกใช้**

```
ชื่อวัตถุ.ชื่อตัวแปรของdata member 
//ใช้(.) dot operatorในเรียกใช้data member//
```

:desktop_computer: Example Code :

```
Student Kwan;
Kwan.name = "Kwan";
cout << Kwan.name << endl;
```

:desktop_computer: Example Code :

```
int main()
{
    BankAccount scb_account;
    scb_account.number = 1;
    scb_account.balance = 1000;

    BankAccount tmb_account;
    tmb_account.number = 2;
    tmb_account.balance = 2000;

    cout << scb.balance << endl;
    cout << tmb.balance << endl;
}
```

:printer: Output

```
1000
2000
```

### ฟันก์ชันของวัตถุ :pencil2: 

`Member Function` คือพฤติกรรมของวัตถุ เป็นกระบวนการที่จะเกิดขึ้นในฟันก์ชัน 
เช่น การาฝากหรือถอนเงิน การยืนหรือคืนหนังสือ การหาพื้นที่สี่เหลี่ยม

- เป็นการจัดแบ่งคำสั่งของโปรแกรมนำมากระจายไว้ในคลาส เพื่อให้คลาสอื่นๆหรือฟันก์ชันอื่นๆสามารถเรียกใช้งานได้ และแบ่งหน้าที่การทำงานชัดเจนตามกระบวนการทำงาน

ฟันก์ชันประกอบด้วย 2 ส่วนหลักๆ
1. ส่วนหัวของฟังก์ชัน : ระบุลักษณะของแต่ละฟันก์ชัน
    1. ชื่อฟันก์ชัน : เป็นกระบวนการ การกระทำของ หน้าที่ที่วัตถุของคลาสนั้นทำได้
    2. รายการของพารามิเตอร์ : ประกอบด้วยประเภท , ชื่อของพารามิเตอร์ที่จะรับเข้ามา **ถ้าไม่รับพารามิเตอร์ ไม่จำเป็นต้องมีก็ได้**
    3. ประเภทของข้อมูลผลลัพท์ : ประเภทของค่าที่จะส่งกลับมา จะเป็นประเภทข้อมูลใดก็ได้ หรือไม่คืนค่าแล้วใช้ voidก็ได้
2. ส่วนตัวของฟันก์ชัน : บรรจุคำสั่งและalgorithm ไว้ในเครื่องหมายปีกกา {} และส่วนใหญ่จะใช้ในการประมวลผลdata member โดยอาจจะมีแค่การคืนค่า `return a;` **กำหนดค่าหรือเปลี่ยนแปลงค่าในdata memberได้**

:desktop_computer: Example Code :

```
class BankAccount
{
    public:
        int number;
        double balance;

        void Deposit(double amount)
        {
            balance += amount;
        }
        void Withdraw(double amount)
        {
            balance -= amount;
        }
}
```

**การเรียกใช้**

```
ชื่อวัตถุ.ชื่อmember function(รายการพารามิเตอร์);
//ใช้(.) dot operatorในเรียกใช้member function//
```

:desktop_computer: Example Code :

```
scb_account.Deosit(100);
tmb_account.Withdraw(50);

cout << "Kwan" << Kwan.TotalScore << endl;
cout << "Fon" << Fon.TotalScore << endl;
```

#### สามารถเรียกใช้Data Memberของคลาสนั้นๆได้โดยตรง

#### Member Function ภายในคลาสใช้ Data Memberร่วมกัน

- data memberจะทำงานอยู่ตลอดอายุการทำงานของวัตถุ โดยจะเปลี่ยนอยู่ตลอดขึ้นอยู่กับmember function ซึงจะเรียกdata memberไปทำการคำนวนหรือหาค่าต่างๆโดยจะใช้data member ร่วมกัน

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
int main()
{
    BankAccount scb_account;
    scb_account.number = 1;
    scb_account.balance = 1000;

    //ใช้data memberตัวเดียวกันนั้นก็คือ "scb_account.balance"//
    scb_account.Deposit(2000);
    cout << scb_account.balance << endl;

    scb_account.Withdraw(500);
    cout << scb_account.balance << endl;
}
```

:printer: Output

```
3000
2500
```

#### Member Function จะกระทำต่อวัตถุที่ถูกเรียกเท่านั้น

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
int main()
{
    BankAccount scb_account;
    scb_account.number = 1;
    scb_account.balance = 1000;

    BankAccount tmb_account;
    tmb_account.number = 2;
    tmb_account.balance = 2000;

    scd_account.Deposit(100);
    tmb_account.Withdraw(50);

    //เรียกใช้data memberแค่ "scb_account.balance , tmb_account.balance"//
    cout << "SCB: " << scb_account.balance << endl;
    cout << "TMB: " << tmb_account.balance << endl;
}
```

:printer: Output

```
SCB: 1100
TMB: 1950
```

### ทำความเข้าใจ :pencil2:

![275532029_1003337930534587_3710101625310200153_n](https://user-images.githubusercontent.com/86911299/159249706-1af5e039-3106-4239-90e6-b293375e9215.jpg)


## Type of parameter :page_with_curl:

วัตถุที่เรียกmember functionนั้นถือเป็นพารามิเตอร์ประเภทของฟังก์ชัน 
พารามิเตอร์ที่ส่งผ่านไปให้เมมเบอร์ฟังก์ชันแบ่งได้ 2 ประเภท

1. Explicit Parameter : ระบุได้ชัดเจนอยู่ภายในรายการพารามิเตอร์ของเมมเบอร์ฟังก์ชัน
2. Implicit Parameter : หมายถึงพารามิเตอร์แฝง หรือโดยนัย ไม่ได้ระบุอย่างชัดเจน แฝงมากับการเรียกใช้เมมเบอร์ฟังก์ชัน 
ในการโปรแกรมเชิงวัตถุ คือ วัตถุที่เรียกเมมเบอร์ฟังก์ชัน

:desktop_computer: Example Code :

```
scb_account.Deposit(100);
//implicit         //explicit
```

**คำสั่งมีลักษณะเหมือนประโยคบอกเล่า**
- ชื่อวัตถุ = ประธาน
- ชื่อเมมเบอร์ = กริยา
- explicit = กรรม
*ประกาศคลาสกับวัตถุ ให้เป็นคำนาน
*ประกาศชื่อคลาสกับชื่อฟังก์ชัน ให้เป็นกริยา

## Type of member function :page_with_curl:

1. Accessor : เข้าถึงข้อมูลเพื่อไปอ่าน คำนวน คืนค่า 
*โดยที่จะไม่มีการเปลี่ยนแปลงค่าในดาต้าเมมเบอร์เลย* 

:desktop_computer: Example Code :

```
double Area()
{
    return width * length;
}
```

`const` ระบุด้วยคีย์เวิร์ดนี้หลังจากการประกาศหัวของฟังก์ชันแล้ว จะไม่สามารถเปลี่ยนแปลงค่าดาต้าเมมเบอร์ได้ 
*หากมีการเปลี่ยนแปลงจะทำให้คอมไพล์ไม่ผ่าน*

2. Mutator : กำหนดหรือเปลี่ยนแปลงค่าในดาต้าเมมเบอร์ 
*ถือว่าเป็นฟังก์ชันที่ไม่ค่อยปลอดภัย*

:desktop_computer: Example Code :

```
void Deposit(double amount)
{
    balance = balance - amount;
}

void Withdraw(double amount)
{
    balance = balance - amount;
}
```

## Overload :page_with_curl:

`Overload`ในภาษาCPPอนุญาติให้คลาสนึงมีฟังก์ชันชื่อเดียวกันได้หลายฟังก์ชัน แต่ต้องรับพารามิเตอร์ต่างกัน แบ่งออกเป็น 2 กรณี

1. จำนวนพารามิเตอร์ต่างกัน
2. มีอย่างน้อยหนึ่งพารามิเตอร์ที่มีประเภทข้อมูลต่างกัน

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
class Rectangle
{
    public:
        double width;
        double length;
        
        double Area() const
        {
            return width * length;
        }

        double Perimeter() const
        {
            return 2 * (width + length);
        }

        //Overload
        void ChangeSize(int a)
        {
            width += a;
            length += a;
        }

        void ChangeSize(int dw, int dl)
        {
            width += dw;
            length += dl;
        }

        void ChangeSize(int a1, double a2)
        {
            width += a1;
            length += a2;
        }
}
```

## การตั้งชื่อคลาส ตัวแปร ฟันก์ชัน :page_with_curl:

### Class :pencil2:

ตั้งชื่อในลักษณะของ หลังอูฐ(CamelCase)
*นิยมใช้คำนามเป็นเอกพจน์*
ขึ้นตัวชื่อด้วยอักษรตัวใหญ่ใช้อักษรตัวใหญ่ในการขั้นระหว่างคำ 
เช่น Book BankAccount ChessBoard

### Variable :pencil2:

ตั้งชื่อในลักษณะของ งูเลื้อย(snake_case) 
*นิยมใช้คำนามเป็นเอกพจน์หรือพหุพจน์ก็ได้*
ขึ้นตัวชื่อด้วยอักษรตัวเล็ก ใช้ (_) ในการขั้นระหว่างคำ 
เช่น book bank_account chess_board

**บางองค์กรใหญ่ๆ เช่น google bitcoin มักจะใส่ (_) ต่อท้ายชื่อด้วย**

### Member function :pencil2:

ตั้งชื่อในลักษณะของ หลังอูฐ(CamelCase)
*นิยมใช้คำกริยา*
ขึ้นตัวชื่อด้วยอักษรตัวใหญ่ใช้อักษรตัวใหญ่ในการขั้นระหว่างคำ 
เช่น Book() BankAccount() ChessBoard()

# Constructors, Access modifiers :books:



# Composition :books:



# Inheritance :books:
