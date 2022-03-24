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

## Constructors :page_with_curl:

`Constructor or ตัวสร้างวัตถุ` มีลักษณะคล้ายกับเมมเบอร์ฟันก์ชัน โดยคอนสตรักเตอร์จะมีหน้าที่คือการสร้างวัตถุ เตรียมวัตถุให้พร้อมใช้งาน และช่วยกำหนดค่าเริ่มต้นให้ดาต้าเมมเบอร์ หรือประมวลผลคำสั่งที่จำเป็นตอนสร้างวัตถุ
เช่น การตรวจสอบช่วงของค่าเริ่มต้น เชื่อมต่อคลาส

**สิ่งที่ต้องรู้**

- การตั้งชื่อคอนสตรักเตอร์จะต้องตั้งชื่อเดียวกับชื่อคลาส
- คอนสตรักเตอร์จะไม่มีการประกาศtypeของตัวผลลัพท์
- รับค่าผ่านทางพารามิเตอร์หรือไม่รับก็ได้
- จะถูกเรียกตอนสร้างวัตถุแค่1ครั้งต่อ1วัตถุเท่านั้น

#### การนิยามคอนสตรักเตอร์ :pencil2:

:desktop_computer: Example :

```
class ชื่อคลาส
{
    ชื่อคลาส(พารามิเตอร์)
    {
        //คำสั่งที่กำหนดค่าเริ่มต้นให้ดาต้าเมมเบอร์ หรือ สร้าง+เตรียมวัตถุให้พร้อมใช้งาน
    }
}
```

#### ข้อดีของการใช้คอนสตรักเตอร์ในการกำหนดค่าเริ่มต้นให้ดาต้าเมมเบอร์ 

1. ทำให้คำสั่งสั้นและกระชับกว่า
2. ช่วยตรวจสอบช่วงของค่าเริ่มต้นหรือการเรียกใช้เมมเบอร์ฟันก์ชันที่จำเป็น ตอนสร้าง+เตรียมวัตถุให้พร้อมใช้งาน *ตรวจสอบว่าค่าเริ่มต้นไม่ใช่ค่าลบ แต่ถ้าเป็นค่าลบจะต้องเปลี่ยนให้เป็นค่า0แทน* **ทำให้โปรแกรมถูกต้องและปลอดภัย**

เช่น การเขียนโปรแกรมสำหรับบัญชีธนาคาร

:desktop_computer: Example Code :

```
class BankAccount
{
    public:

        //----data member----
        int number;
        double balance;

        //----constructor----
        BankAccount(int n, double b) 
        {
            number = n;
            balance = b;
            //----เปลี่ยนค่าลบเป็นศูนย์----
            if (b < 0)
                balance = 0;
        }

        //----member fuctions----
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

3. ช่วยบังคับการกำหนดค่าดาต้าเมมเบอร์ที่จำเป็นต้องผ่านพารามิเตอร์ของคอนสตรักเตอร์
*เพราะถ้าหากเราไม่ได้กำหนดค่าเริ่มต้นไว้ ตัวคอมไพล์เลอร์จะไม่เตือน จึงอาจทำให้ลืมกำหนดค่าที่จำเป็นได้ แต่ถ้ากำหนดค่าคอนสตรักเตอร์คอมไพล์เลอร์จะเตือนให้เรากกำหนดค่าเริ่มต้น

### Overload :pencil2:

`constructor overload` ในนึงคลาสจะมีคอนสตรักเตอร์หลายตัว ในแต่ละตัวจะต้องรับพารามิเตอร์เข้ามาต่างกัน และต้องมีอย่างน้อยหนึ่งพารามิเตอร์ที่มีประเภอข้อมูลต่างกัน
คล้ายกับการOver load function
สามารถใช้คอนสตรักเตอร์หลายตัว ถ้าไม่กำหนดค่าให้กับดาต้าเมมเบอร์ ตัวคอนสตรักเตอร์จะกำหนดค่าปริยายให้กับตัวแปรนั้นๆ *ทำให้โปรแกรมมีความยืดหยุ่นมากขึ้น*

:desktop_computer: Example Code :

```
class BankAccount
{
    public:

        //----data member----
        int number;
        double balance;

        //----constructor----
        BankAccount(int n, double b) 
        {
            number = n;
            balance = b;
        }

        //----overload----
        BankAccount(int n)
        {
            number = n;
            balance = 0;
        }

        BankAccount(int n, string l)
        {
            number = n;
            name = l;
        }

        //----member fuctions----
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



### Default Constructor :pencil2:

`Default Constructor` คือคอนสตรักเตอร์ที่ไม่รับพารามิเตอร์ คอมไพล์เลอร์จะสร้างคอนสตรักเตอร์แบบปริยายให้โดยอัตโนมัติ 
*หากเราประกาศคอนสตรักเตอร์ที่มีพารามิเตอร์แล้วจะสร้างวัตถุแบบไม่ใส่พารามิเตอร์ไม่ได้*

class Rational
{
    public:
        int numerator;
        int denomtnator;

        //----default constructor----
        rational()
        {
            numerator = 0;
            denominator = 1;
        } 
}

### Constructor รับพารามิเตอร์เพียงหนึ่งค่า :pencil2:

ในภาษาCPPสามารถใช้คอนสตรักเตอร์ที่รับพารามิเตอร์แค่หนึ่งค่าเท่านั้น 
ถ้าหากค่าในพารามิเตอร์ไม่ตรงกับประเภทของพารามิเตอร์ที่กำหนดไว้ 
เช่น `int x = 4.5; => [4.5 => 4]`

ถ้าหากไม่ต้องการให้มีการเปลี่ยนแปลงค่าจะต้องใช้คำสั่ง `explicit`

:desktop_computer: Example Code :

```
class BankAccount
{
    public:

        //----data member----
        int number;
        double balance;

        //----constructor----
        explicit BankAccount(int n, double b) 
        {
            number = n;
            balance = 0;
        }

        BankAccount(int n, double b)
        {
            number = n;
            balance = b;
        }

        //----member fuctions----
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

**ถ้าหากเรารันผลเมื่อป้องกันการแปลงของมูลด้วย `explicit`**

:abacus: Compiler

![275377247_344318621081259_5742022368687562599_n](https://user-images.githubusercontent.com/86911299/159618315-7da781e7-10f1-47b3-ab75-2817de293c40.jpg)


### Member Initilizer :pencil2:

การใช้Member Initilizerมาช่วยในการกำหนดค่าเริ่มต้นให้กับดาต้าเมมเบอร์แบบกระชับขึ้น
**โดยใช้ : หลังพารามิเตอร์ ตามด้วยชื่อตัวแปรดาต้าเมมเบอร์(ส่งค่ากลับ)**

:desktop_computer: Example :

`BankAccount(int n, double b) : number(n) , balance(b) {}`

- หากมีตัวแปรดาต้าเมมเบอร์ที่ไม่จำเป็นต้องรับพารามิเตอร์และต้องการกำหนดค่าปริยายให้ และสามารถส่งค่าปริยายใน()ของดาต้าเมมเบอร์ได้ด้วย

:desktop_computer: Example :

`explicit BankAccount(int n, double b) : number(n) , balance(b) {}`

- Member Initilizer ยังช่วยให้การoverload constructionกระชับขึ้น โดยระบุค่าพารามิเตอร์ต่อท้าย (รับค่าหรือไม่รับค่าก็ได้)

:desktop_computer: Example :

`explicit BankAccount(int n, double b = 0) : number(n) , balance(b) {}`

- Member Initilizer สามาระประมวลผลคำสั่งอื่นที่จำเป็นเพื่อเตรียมวัตถุให้พร้อมใช้งานด้วย

:desktop_computer: Example :

```
explicit BankAccount(int n, double b = 0) : number(n) , balance(b) 
{
    if (b < 0)
        balance = 0;
}
```

## Access Modifier / Access Spercifier :page_with_curl:

`Access Modifier / Access Spercifier` คือการควบคุมการเข้าถึงข้อมูลที่ไม่ต้องการจะเปิดเผย หรือเป็นข้อมูลที่อยู๋ในรูปแบบเฉพาะเจาะจง ทำให้ข้อมูลเหล่านี้มีความปลอดภัยมากขึ้น ต้องได้รับการอนุญาติก่อนที่จะเข้าถึง การอ่านและแก้ไขข้อมูล

ในการควบคุมการเข้าถึงดาต้าเมมเบอร์ คอนสตรักเตอร์ เมมเบอร์ฟังก์ชัน มีการควบคุมทั้งหมด 3 ระดับ

1. private (ส่วนตัว) ไม่สามารถเข้าถึงได้โดยตรง ต้องเป็นวัตถุของคลาสที่ประกาศ ดาต้าเมมเบอร์ คอนสตรักเตอร์ เมมเบอร์ฟังก์ชันเดียวกันเท่านั้นถึงจะเข้าถึงได้
2. public (สาธารณะ) สามารถเข้าถึงดาต้าเมมเบอร์ คอนสตรักเตอร์ เมมเบอร์ฟังก์ชันของคลาสและฟังก์ชันอื่นๆได้โดยตรง
3. protected (ถูกป้องกัน) สามารถเข้าถึงได้แค่คลาสหรือสมาชิกได้ภายในคลาสย่อยและคลาสเดียวกันเท่านั้น 

|  Modifiers  |	 Class  | 	Package  | 	Sub class   |  World  |
|-------------|---------|------------|--------------|---------|
|   public	  |   Yes   |     Yes    | 	    Yes     |  	Yes   |
|  protected  |   Yes   |     Yes	 |      Yes	    |   No    |
| no modifier |   Yes   |	  Yes    |    	No      |  	No    |
|   private   |   Yes   |     No     |    	No      |  	No    |

### การเลือกใช้Access Modifier / Access Spercifier :pencil2:

- Data member ควรระบุด้วย Private
- Constructor & Member function ควรระบุด้วย Public

:desktop_computer: Example Code :

```
class BankAccount
{
    private:

        //----data member----
        int number;
        double balance;
    
    public:

        //----constructor----
        BankAccount(int n, double b) 
        {
            number = n;
            balance = b;
            //----เปลี่ยนค่าลบเป็นศูนย์----
            if (b < 0)
                balance = 0;
        }

        //----member fuctions----
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

:keyboard: Input

```
BankAccount scb_account(1,1000);
scb_account.balance = -500;
```

:abacus: Compiler 

![275656047_5320609314637725_167369951244698904_n](https://user-images.githubusercontent.com/86911299/159625347-b44967b5-945a-4e7a-abec-7e738c0815f7.jpg)


**เนืองจากดาต้าเมมเบอร์เป็นPrivateจึงไม่สามารถอ่านค่าได้ผ่านคำสั่งโดยตรง ดังนั้นเราต้องสร้างฟังก์ชันเพิ่มเพื่อช่วยในการเข้าถึง นั้นคือ`getter` `setter`**

### getter & setter + Tostring() :pencil2:

`getter & setter` ใช้ในการอ่านและกำหนดค่าให้กับดาต้าเมมเบอร์ที่เป็นprivate
- getter : มีหน้าที่คืนค่าให้กับดาต้าเมมเบอร์ 
- setter : มีหน้าที่กำหนดค่าตรงๆจากค่าที่รับเข้ามาผ่านพารามิเตอร์ หรือตรวจสอบเงื่อนไข

**การเรียกใช้**

ใช้คำว่า `get` , `set` และตามด้วยชื่อดาต้าเมมเบอร์ 

`Tostring()` ใช้ในการคืนค่าสตริงในรูปแบบที่กำหนด ทำให้การพิมพ์ค่าวัตถุสั้นและกระชับขึ้น ด้วยการสร้างตัวแปรสตริง s มาเก็บข้อความ โดยใช้ `+` เป็นตัวนำมาต่อกับสตริงตัวอื่นได้
เช่น number , balance ไม่ใช่ข้อมูลประเภทสตริง จึงต้องแปลงให้เป็นสตริงก่อนโดยใช้ฟังก์ชัน `to_string()`

:desktop_computer: Example :

```
Getชื่อดาต้าเมมเบอร์()

setชื่อดาต้าเมมเบอร์()
```

:desktop_computer: Example Code :

`#include <iostream>`
`using namespace std;`

```
//--ไม่ควรใช้cin coutใช้ในclass--
class Student
{
    private:
        //----data member----
        string name;
        int midterm_score, final_score;
    
    public:
        //----constructor----
        explicit Student(string n) : name(n), midterm_score(0), final_score(0)
        {
            //----member function----
            int TotalScore()
            {
                return midterm_score + final_score;
            }
            
            //----getter & setter----
            string GetName() const
            {
                return name;
            }

            void SetName(string n)
            {
                name = n;
            }

            int GetMidtermScore() const
            {
                return midterm_score;
            }

            void SetMidtermScore(int score)
            {
                if (score > 0) midterm_score = score;
            }

            int GetFinalScore() const
            {
                return final_score;
            }

            void SetFinalScore(int score)
            {
                if (score > 0) final_score = score;
            }

            //----ToString----
            string ToString() const
            {
                string s = "BankAccount No. " + ToString(number) + " has balance " + to_string(balance);
                return s;
            }
        };

int main()
{
    Student kwan("Kwan");
    kwan.SetMidtermScore(9);
    kwan.SetFinalScore(7);

    cout << kwan.GetName() << " 's total score = " << kwan.TotalScore() << endl;
}
```

:printer: Output

```
kwan 's total score = 16
```

## Handle & Copy :page_with_curl:

### Handle :pencil2:

่`Handle` วิธีที่เราจะเข้าถึงและใช้งานวัตถุ ในภาษาCPPมี3อย่าง

1. Object Name : ชื่อหลังการประกาศประเภทข้อมูลคลาส สามารถใช้เรียกใช้ดาต้าเมมเบอร์และเมมเบอร์ฟังก์ชันด้วย (.) dot operator

:desktop_computer: Example :

```
BankAccount scb_account(1, 500);
scb_account.Deposit(100);
```

:framed_picture: diagram

![275327689_1293641438128534_8028501839545828854_n](https://user-images.githubusercontent.com/86911299/159632201-cb22d9a8-9971-4729-8c1d-05f402f9f0e7.jpg)

2. Object Reference : ชื่อเล่นของวัตถุ สามารถใช้เหมือนกับชื่อวัตถุ ใช้ (&) ampersand

:desktop_computer: Example :

```
BankAccount &saving = scb_account;
```

:framed_picture: diagram

![275800624_735113260811741_466129116407426650_n](https://user-images.githubusercontent.com/86911299/159632565-cfaeb39d-b395-4bc3-b1b0-212109434a0b.jpg)

:desktop_computer: Example Code :

```
int main()
{
    BankAccount scb_account(1, 500);
    scb_account.Deposit(100);

    BankAccount &saving = scb_account;
    saving.Deposit(100);

    cout << "name: " << scb_account.ToString() << endl;
    cout << "name: " << saving.ToString() << endl;
}
```

:printer: Output

```
name: BankAccount No. 1 has balance 700
ref: BankAccount No. 1 has balance 700
```

:framed_picture: diagram

![275320939_973358816640466_7994180185766671885_n](https://user-images.githubusercontent.com/86911299/159633025-8497c3fb-d837-42c4-8ca6-716531d89c4f.jpg)


3. Object Pointer : เก็บที่อยู่ของหน่วยความจำของวัตถุ *เหมือนกับpointerในภาษาC* (*) 


:desktop_computer: Example :

```
BankAccount *current_account = &scb_account;
```

:framed_picture: diagram

![275459655_1185007978704422_8683598015873174732_n](https://user-images.githubusercontent.com/86911299/159634145-edbc894c-45ff-4754-b802-021eec2a78cc.jpg)

**การย้ายพอยน์เตอร์**

:desktop_computer: Example Code :

```
int main()
{
    BankAccount tmb_account(2, 2000);
    BankAccount *my_account = &tmb_account;

    cout << my_account -> ToString() << endl;
    
    BankAccount ktb_account(3, 3000);
    my_account = & ktb_account;

    cout << my_account -> ToString() << endl;
}
```

:printer: Output

```
BankAccount No. 2 has balance 2000
BankAccount No. 3 has balance 3000
```

:framed_picture: diagram

![277017399_390070265901065_7784751333035033661_n](https://user-images.githubusercontent.com/86911299/159634813-ea7e0247-7c45-4446-9d2f-e7ab95f0310d.jpg)

![275543361_512245186943721_2358706942344427796_n](https://user-images.githubusercontent.com/86911299/159634850-21e6a9a6-663e-4092-a599-5c49e89aab36.jpg)


### Copy :pencil2:

`copy` การสร้างวัตถุใหม่ขึ้นที่มีค่าดาต้าเมมเบอร์เท่าเดิม ใช้เครื่องหมาย (=) ในการคัดลอกค่า 
*ระวังการใช้เครื่องหมาย*

:desktop_computer: Example :

```
BankAcccount account_copy = tmb_account;
```

:framed_picture: diagram


![275608346_388138013064788_4953026859186243364_n](https://user-images.githubusercontent.com/86911299/159648257-770825bb-d62b-4109-b1d3-35943d566b56.jpg)

## การสร้างobject ด้วย new :page_with_curl:

การควบคุมการจัดสรรหน่วยความจำ เหมือนกับ`malloc` , `free` คือการจองพื้นที่ในหน่วยความจำ และการคืนพื้นที่ในหน่วยความจำ

`new` ใช้ในการจองพื้นที่ในหน่วยความจำ เมื่อสร้างวัตถุของคลาส โดยพอยน์เตอร์ในการเก็บที่อยู่ของหน่วยความจำของวัตถุ

:desktop_computer: Example :

```
BankAccount *bkk_account = new BankAccount(4, 800);
```

:framed_picture: diagram

![275242470_543074867406903_8036412089218108519_n](https://user-images.githubusercontent.com/86911299/159649739-d0dcc556-4a47-448f-ab8f-b7a989eac613.jpg)

`delete` ใช้ในการคืนพื้นที่ในหน่วยความจำ และเราสามารถคืนหน่วยความจำจากพอยน์เตอร์ใดพอยน์เตอร์หนึ่งก็พอ

:desktop_computer: Example :

```
delete bkk_account;
```

## Pointer this :page_with_curl:

`this` เป็นพอยน์เตอร์พิเศษที่ใช้อ้างถึงวัตถุที่กำลังทำงานอยู่

**ประโยชน์**

1. เพื่อแยกแยะตัวแปรของดาต้าเมมเบอร์ออกจากพารามิเตอร์ได้ง่ายขึ้น เมื่อตัวแปรมีชื่อเดียวกัน การใช้งานthisจจใช้เงินคล้ายกับhandle 
สามารถใช้thisเรียกดาต้าเมมเบอร์ ทำให้รู้ว่าตัวแปรนี้เป็นดาต้าเมมเบอร์ ไม่ใช่พารามิเตอร์

`this -> ชื่อตัวแปรของดาต้าเมมเบอร์ = ชื่อตัวแปรพารามิเตอร์`

:desktop_computer: Example :

```
BankAccount(int number, double balance)
{
    this -> number = number;
    this -> balance = balance;
}

void SetName(string name)
{
    this -> name = name;
}
```

2. ใช้ส่งวัตถุไปเป็นพารามิเตอร์ของฟังก์ชันในคลาสอื่น
3. คืนค่าเป็นวัตถุของคลาสนี้

**ข้อ2-3 จะได้ใช้ตอนโปรแกรมมีขนาดใหญ่ขึ้น**

## Destructor :page_with_curl:

`Destructor or ตัวทำลายวัตถุ` โดยอัตโนมัตเดสตรักเตอร์จะถูกเรียกเพียงครั้งเดียวต่อหนึ่งวัตถุ เมื่อออกจากเขตการทำงาน หรือการคืนพื้นที่ในหน่วยความจำ โดยใช้คำสั่ง `delete` หรือการปิดการใช้ทรัพยากรต่างๆ
เช่น การปิดไฟล์

*ไม่จำเป็นต้องประกาศ หากเราไม่ต้องการคือค่าหรือปิดการใช้งาน*

### การนิยามเดสตรักเตอร์ :pencil2:

**ใช้เครื่องหมาย (~)หน้าชื่อคลาส**

:desktop_computer: Example :

```
class ชื่อคลาส
{
    ~ชื่อคลาส()
    {
        //คำสั่งที่ใช้ในการคืนพื้นที่หน่วยความจำ หรือปิดการใช้งานต่างๆ
    }
}
```

### การประกาศ :pencil2:

```
class BankAccount
{
    private:

        //----data member----
        int number;
        double balance;
    
    public:

        //----destructor----
        BankAccount(int number) 
        {
            this -> number = number;
            this -> balance = 0;

            cout << "Constructor " << number << endl;
        }

        ~BankAccount()
        {
            cout << "Destructor " << number << endl;
        }

        //----member fuctions----
        void Deposit(double amount)
        {
            balance += amount;
        }

        void Withdraw(double amount)
        {
            balance -= amount;
        }
};

int main()
{
    BankAccount a(1);
    BankAccount b(2);

    cout << "----------" << endl;
}
```

:printer: Output

```
Constructor 1
Constructor 2
----------
Destructor 1
Destructor 2
```

### การทำงาน :pencil2:

:desktop_computer: Example Code :

```
void func()
{
    BankAccount c(3);
}

int main()
{
    BankAccount a(1);
    cout << "********" << endl;
    func();
    
    cout << "********" << endl;
    BankAccount b(2);
}
```


:printer: Output

```
Constructor 1
********
Constructor 3
Destructor 3
********
Constructor 2
Destructor 2
Destructor 1
```

# Composition :books:

`composition การประกอบบกัน` คือการนำวัตถุของคลาสอื่นมาใช้ในดาต้าเมมเบอร์ของคลาสเรา ในความสัมพันะืที่เราประกาศดาต้าเมมเบอร์ให้เป้นคลาส
จะทำให้เกิดการประกอบกัน ความสัมพันธ์นี้จะเรียกว่า "การมี หรือ Has-A"
**วัตถุหนึ่งวัตถุอื่นเป้นดาต้าเมมเบอร์**
ในการเขียนโปรแกรมเชิงวัตถุสิ่งที่สำคัญที่สุดคือความสัมพันธ์ระหว่างคลาสกับวัตถุ ดังนั้นการประกอบกันจึงจำเป็นต้องใช้บ่อยในภาษาCPP

### Class without & with composition :pencil2:

#### without
                                                             
:desktop_computer: Example Code :

```
class Vector
{
    private:
        double start_x, start_y
        double end_x, end_y
    
    public:
        Vector()
        {
            start_x = 0;
            start_y = 0;
            end_x = 0;
            end_y = 0;
        }

        Vector(double sx, double sy, double ex, double ey);
        {
            start_x = sx;
            start_y = sy;
            end_x = ex;
            end_y = ey;
        }

        //----Accessor----
        Vector Add (Vector v2) const
        {
            Vector v3;
            v3.start_x = start_x + v2.start_x;
            v3.start_y = start_y + v2.start_y;
            v3.end_x = end_x + v2.end_x;
            v3.end_y = end_y +v2.end_y;
            return v3.;
        }


        //----Tostring----
        string ToString() const
        {
            string s = "(" + to_string(start_x) + "," + to_string(start_y) + ")" + "--->" + "(" + to_string(end_x) + "," + to_string(end_y)")";
            return s;
        }
}
```

#### with

:desktop_computer: Example Code :

```

class point 
{
    private:
        double x;
        double y;
    
    public:
        Point()
        {
            x = 0;
            y = 0;
        }

        Point(double x, double y)
        {
            this -> x = x;
            this -> y = y;
        }

        Point Add(Point other)
        {
            double new_x = x + other.x;
            double new_y = y + other.y;
            Point p(new_x, new_y);
            return p;
        }

        string ToString() const 
        {
            return "(" + to_string(x) + "," + to_string(y) + ")";
        }
}
```

### Class with composition and pointer :pencil2:

## แผนภาพ UML (Unified Modeling Language) :page_with_curl:ฃ

คลาสของpoint

:framed_picture: diagram

 ![275514746_752257325948377_2922808605939526561_n](https://user-images.githubusercontent.com/86911299/159839951-c54d3be7-17bc-4d0b-8ea2-54042ee931a2.jpg)

ความสัมพันธ์ระหว่างคลาสของvectorและคลาสของpoint

:framed_picture: diagram

![276052703_444582830777473_5076697073790255598_n](https://user-images.githubusercontent.com/86911299/159840050-9a1806d4-cc64-4b5e-a93d-5510c59fa0fe.jpg)

ึคุณลักษณะในpoint

:framed_picture: diagram

![275861031_4713674575408916_5271255705286304291_n](https://user-images.githubusercontent.com/86911299/159840099-f7a5639b-ae0f-4afe-bb17-32a44831c820.jpg)

รายละเอียดของทั้งสองคลาส

:framed_picture: diagram


![275616955_3133522090262888_6760653193978452198_n](https://user-images.githubusercontent.com/86911299/159840444-b5645848-b691-4ee0-88a4-1dc3398858c1.jpg)

![275786387_1327993967700204_8455664130512317095_n](https://user-images.githubusercontent.com/86911299/159840452-cba0a838-9662-41de-90b3-9ff2a0117a15.jpg)

ตัวอย่าง

:framed_picture: diagram

![275477426_1424421758015409_5239379440372181978_n](https://user-images.githubusercontent.com/86911299/159840266-21a9543a-80b8-4e9c-8c86-99f15c8bd7ae.jpg)

## Header files & Include Guard :page_with_curl:

`Header files`แบบ Class Definition ใน Header Flie
*ไม่ควรใช้ "using namespace"ในไฟล์ .h*

**ความแตกต่างของไฟล์ .h &d .cpp**

ไฟล์นามสกุล .h ไว้เก็บโครงสร้างของคลาสที่ต้องการสร้างขึ้นมา เป็นการกำหนดโดยภาพรวมว่าภายในคลาสเรานั้นจะประกอบด้วยฟังก์ชัน ตัวแปรอะไรบ้าง มีแต่โครงสร้างอย่างเดียว ทำงานไม่ได้ 
ไฟล์นามสกุล .cpp ไว้เขียนโค้ดทำงานเพื่อให้คลาสที่ได้มาสามารถใช้งานได้จริง โดยเราต้องยึดตามโครงสร้างที่กำหนดไว้ใน .h

`Include guard` เป็นคำสั่งที่ใช้เพื่อช่วยป้องกันการเรียกใช้ #include ไฟล์.h ซ้ำซ้อน

:desktop_computer: Example Code :ฃ

```
#include <iostream>
#include "point.h"
//----ในvector.hมีการเรียกใช้#include "point.h"แล้ว ดังนั้นคอมไพล์เลอร์จะเป็น error----
#include "vector.h"
```

:framed_picture: diagram


![275786387_533974528371671_9159988784841220232_n](https://user-images.githubusercontent.com/86911299/159844416-fe005cee-3cee-43d4-9e10-e69a45ffa400.jpg)

### Example Code :pencil2:

:desktop_computer: Example Code .h :

`#include <string>`
`#ifndef POINT_H`
`#define POINT_H`

```
class Point {
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    // p3 = this + p2
    // this: (1,1) 
    // p2:   (10,10)
    // p3:   (11,11)
    Point *Add(Point *other) {
        int new_x = this->x + other->x;
        int new_y = this->y + other->y;
        Point *p3 = new Point(new_x, new_y);
        return p3;
    }
    std::string ToString() const {
        return "(" + std::to_string(x) + ","
                   + std::to_string(y) + ")";
    }
};

#endif
```

:desktop_computer: Example Code .h:

// include guard
`#ifndef VECTOR_H`
`#define VECTOR_H`

```
class Vector {
private:
    // (x1,y1) ----> (x2,y2)
    Point *start;   // double start_x, start_y;
    Point *end;     // double end_x, end_y;
public:
    Vector(Point *start, Point *end) {
        this->start = start;
        this->end = end;
    }
     // v3 = this + v2
    // this: (1,1) ---> (3,3)
    // v2:   (10,10) ---> (20,20)
    // v3:   (11,11) ---> (23,23)
    Vector *Add(Vector *v2) {
        Point *new_start = start->Add(v2->start);
        Point *new_end = end->Add(v2->end);
        Vector *v3 = new Vector(new_start, new_end);
        return v3;
    }
    std::string ToString() {
        return start->ToString() + "-->" + end->ToString();
    }
};
#endif
```

:desktop_computer: Example Code main.cpp:

`#include <iostream>`
`#include <cmath>`
`#include "point.h"`
`#include "vector.h"`
`using namespace std;`

```
// ---------------------------------
//  we must compile all .cpp file
// ---------------------------------

int main() {
    Point *p1 = new Point(1,1);
    Point *p2 = new Point(3,3);
    Point *pAdd = p1->Add(p2);

    Vector *v1 = new Vector(p1,p2);

    cout << "p1: " << p1->ToString() << endl;
    cout << "p2: " << p2->ToString() << endl;
    cout << "pAdd: " << pAdd->ToString() << endl;

    cout << "v1: " << v1->ToString() << endl;

    Point *p3 = new Point(10,10);
    Point *p4 = new Point(20,20);

    Vector *v2 = new Vector(p3,p4);

    Vector *v3 = v1->Add(v2);

    cout << "v2: " << v2->ToString() << endl;
    cout << "v3: " << v3->ToString() << endl;

}
```

## Conditional inclusions :page_with_curl:

- Header File or Standard files: จะเรียกไลบรารี่หรือ header file มักจะเป็นเก็บอยู่ในไฟล์ไลบรารี่ของเครื่องเรา โดยไฟล์เหล่านี้จะที่เก็บฟังก์ชันหรือค่าตัวแปรมาใช้ร่วมกับโปรแกรมที่เขียนโดยที่พบเห็นได้ปกติคือ

`#include <stdio.h>`

- user defined files: ส่วนนี้มักจะเป็น header file ที่นักพัฒนาเขียนมาในการใช้งาน เพื่อลดความซับซ้อนในโปรแกรม และเพื่อให้ง่ายต่อการเรียกใช้ฟังก์ชันหรือตัวแปรซ้ำ ๆ โดยการเรียกใช้ผู้เรียนอาจเคยพบเจอมาบ้างในรูป

`#include "filename"`

`Conditional inclusions`

#Ifdef <-- ถ้า เปิดเงื่อนไขถ้าเป็น 1 จะทำงานในเงื่อนไขนี้
#ifndef <-- ถ้า-ไม่ ถ้าเงื่อนไขไม่เป็น 1 เป็น 0 จะทำงานในเงื่อนไขนี้ 
#elif <-- เงื่อนไขอื่นอันนี้ก็ทำงานในกรณีเป็น 1
#else <-- ถ้าไม่มีเงื่อนไขอื่นๆแล้วจะทำในส่วนนี้
#endif <-- ใช้ปิดเงื่อนไข

```
#ifdef (KL25_PLATFORM) && !(MSP_PLOATFORM)
    kl25_initial();
#elif (MSP_PLOATFORM) && !(KL25_PLATFORM)
    msp_initial();
#else
    #error "Please specific one platform target"
#endif
```

# Inheritance :books:

## Base class & Derived class :page_with_curl:      

### Inheritance with data member & member function :pencil2:

## benefits of inheritance :page_with_curl:

### example code without inheritance:pencil2:

### example code with inheritance :pencil2:

## customization member function :page_with_curl:

### redefine :pencil2:

### override :pencil2:

## bind varable :page_with_curl:

### Static binding :pencil2:

### Dynamic binding :pencil2:

## Ploymorphism (ภาวะพหุสัณฐาน) :page_with_curl:

