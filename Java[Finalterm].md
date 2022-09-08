# สารบัญเนื้อหาสรุป

## 1. Input/Output [IO] :bookmark_tabs: ##
## 2. Exception Handling :closed_book: ##
## 3. Interface , Abstract Classes , Polymorphism :green_book: ##
## 4. Collections :orange_book: ##
## 5. Unit Testing and jUnit :notebook: ## 
## 6. Object-Oriented Design Principles :notebook_with_decorative_cover: ##
## 7. Composition :ledger: ##
## 8. Design Patterns :blue_book: ##
## 9. Error Code :label: ##


# Input/Output [IO] :books:

IO (Input/Output) : เป็นlibraryนึงซึ่งอยู่ในpackage(java.io) ทำหน้าที่รับส่งข้อมูลทางหน้าจอและผ่านทางnetwork อ่านเขียนไฟล์ในฐานข้อมูลต่างๆ

**ในรูปแบบ`Stream` [เป็นรูปแบบของข้อมูลที่เป็นสายอักขระหรือข้อมูล] จะเป็นข้อมูลปกติหรือbinaryก็ได้**

![300436883_602469404655980_7264082446855232016_n](https://user-images.githubusercontent.com/86911299/186454127-56f25c6c-67a1-475d-b1e6-e204a6b226c6.jpg)

:framed_picture: For Example : 

- System.out : ส่งข้อมูลไปที่หน้าจอ ผลลัพท์จะเป็นสีดำปกติ
- System.err : ส่งคำเตือนerrorไปที่หน้าจอแต่ผลลัพท์จะเป็นสีดำปกติ
- System.in : รับข้อมูลinput

:pushpin: https://docs.oracle.com/en/java/javase/11/docs/api/

Input : จะเป็นsub classของ`InputStream` / `Reader`
Output : จะเป็นsub classของ`OutputStream` / `Writer`

**`InputStream` / `Reader` + `OutputStream` / `Writer` = ทั้งสี่classนี้เป็น`abstract class`ของทุกๆIO [read() , write()]**

## InputStream/OutputStream :page_with_curl:

InputStream/OutputStream : อ่านเขียนเป็น`byte` เหมาะกับการอ่านเขียน image , music , binary data

- FileInputStream/FileOutputStream : `File`
- DataInputStream/DataOutputStream : `Data`
- ObjectInputStream/ObjectOutputStream : `Object` 

### read() [InputStream] :pencil2:

:desktop_computer: Example Code :

```
System.out.print("Enter characters: ");
    try {
        int inChar = System.in.read();//อ่านทีละbyteและรับค่ามาเป็นint
        char a = (char) inChar; //`casting contexts`จากintเป็นchar
        System.out.println("You entered: " + a);//a = charและแสดงผลลัพท์
    }
    catch (IOException e){
        System.err.println("Error reading from user");
    }
```

:keyboard: Input 01

```
Enter characters: 'a'
```

:printer: Output 01

```
Enter characters: 'a'
You entered: a
```

:keyboard: Input 02

```
Enter characters: 'chat'
```

:printer: Output 02

```
Enter characters: 'chat'
You entered: c
```

:bulb:

=> เนืองจากรับได้ทีละbyteจึงทำให้ระบบรับมาแค่'c'และนำไปcastingแค่ค่าเดียว


## Reader :page_with_curl:

Reader/Writer : อ่านเขียนเป็น`Unicode Characters [2 byte]` เหมาะกับtext

- FileReader/FileWriter : `File`
- BufferedReader/BufferedWriter : อ่านได้เป็นบรรทัดไม่ใช่แค่charทำงานเร็ว + คล้ายwrapper class
- PrintWriter : `println()` ช่วยในการเขียนข้อมูลชนิดสตริงในไฟล์

### readLine() [BufferedReader] :pencil2:

:desktop_computer: Example Code :

```
System.out.print("Enter characters: ");
    try {
        InputStreamReader inReader = new InputStreamReader(System.in); //Conversion InputStream/OutputStream to Reader/Writer
        BufferedReader buffer = new BufferedReader(inReader); //เอาBufferedReaderมาครอบไว้เพื่อที่จะได้อ่านได้ทีละบรรทัดแทนการอ่านทีละbyte
        
        String line = buffer.readLine(); //คำสั่งที่ใช้ในการสั่งให้อ่านเป็นบรรทัด
        System.out.println("You entered: " + line);
    }
    catch (IOException e){
        System.err.println("Error reading from user");
}
```

:keyboard: Input 01

```
Enter characters: "Hello java"
```

:printer: Output 01

```
Enter characters: "Hello java"
You entered: Hello java
```

:bulb:

=> ต้องแปลงInputStreamเป็นReaderก่อนที่จะใช้BufferReader 

### อ่านจากไฟล์ ".txt" [BufferedReader] :pencil2:

:desktop_computer: Example Code :

```
String filename = "hello.txt";//ประกาศนอกtryเนืองจากcatchจะได้เข้าถึงได้ด้วย
    try {
        FileReader fileReader = new FileReader(filename);//ไม่ต้องแปลงเพราะว่าเป็นreaderอยู่แล้ว
        BufferedReader buffer = new BufferedReader(fileReader);
        
        System.out.println("Open file:");
        String line = buffer.readLine();
                       
        while (line != null) {//'null'ไม่ใช้stringใช้!=ได้
            System.out.println("-----> " + line);
            line = buffer.readLine();
        } 
    }
    catch (FileNotFoundException e){//Sub class [error : ถ้าหาไฟล์ไม่เจอ]
        System.err.println("Cannot read file "+filename);
    }
    catch (IOException e){//Super class [error : ไม่สามารถอ่านไฟล์ได้]
        System.err.println("Error reading from file");
}
```


:keyboard: Input [hello.txt]

```
hello
world
```

:printer: Output

```
Open file:
-----> hello
-----> world
```

:bulb: 

=> ควร`catch (FileNotFoundException e)`แยกกรณีที่อาจเกิดข้อผิดพลาดได้ และต้องมีลำดับความสำคัญในการเรียงลำดับด้วยsuper classอยู่ล่างสุดsub classจะอยู่ด้านบน

=> ในการสร้างไฟล์".txt" สามารถสร้างไว้ในsrcได้เลยหรือจะสร้างข้างนอกก็ได้ แต่ต้องระบุaddress เช่น "/User/Desktop/hello.txt"

### Integer.parselnt(String) :pencil2:

อ่านnumberจากไฟล์ ".txt" [BufferedReader]

:desktop_computer: Example Code :

```
String filename = "number.txt";
    try {
        FileReader fileReader = new FileReader(filename);
        BufferedReader buffer = new BufferedReader(fileReader);
        
        int sum = 0;
        String line = null;

        while ((line = buffer.readLine()) != null) {//อ่านและกำหนดค่า
            int num = Integer.parseInt(line);//แปลงstringเป็นint
            sum += num;
        }
        
        System.out.println("Total: " + sum);
    }
    catch (FileNotFoundException e){
        System.err.println("Cannot read file "+filename);
    }
    catch (IOException e){
        System.err.println("Error reading from file");
}
```

### อ่านหลายๆค่าจากไฟล์ :pencil2:
:desktop_computer: Example Code :

`#include <  >`

```
String filename = "restaurant.txt";
List<Restaurant> restaurants = new ArrayList<Restaurant>();

try {
    FileReader fileReader = new FileReader(filename);
    BufferedReader buffer = new BufferedReader(fileReader);
    
    String line = null;//ตรวจสอบ
    while ((line = buffer.readLine()) != null) {
       String[] data = line.split(",");//แยกค่าในไฟล์ผ่าน"__" ได้ข้อมูลเป็นarray
       String name = data[0].trim();//.trim() เอาwhite spaceหน้า,หลังออก
       String type = data[1].trim();
       String area = data[2].trim();
       int rating = Integer.parseInt(data[3].trim());
       
       Restaurant r = new Restaurant(name, type, area);
       r.setRating(rating);
       restaurants.add(r);
    } 
}
catch (FileNotFoundException e){
    System.err.println("Cannot read file "+filename);
}
catch (IOException e){
    System.err.println("Error reading from file");
}
```

:keyboard: Input [restaurant.txt]

```
After you , Desseart , Phahonyoyhin 5
```

### Conversion InputStream/OutputStream to Reader/Writer :pencil2:

#### วนลูปอ่านทางหน้าจอ

:desktop_computer: Example Code :

```
try {
    InputStreamReader inReader = new InputStreamReader(System.in);
    BufferedReader buffer = new BufferedReader(inReader);
    
    System.out.println("Enter lines:");
    String line = buffer.readLine();
    
    while (!line.equals("bye")) { //จบลูปด้วยคำว่า"__" + ควรใช้ [.equals()]
        System.out.println("-----> " + line);
        line = buffer.readLine();
    }   
}
catch (IOException e){
    System.err.println("Error reading from user");
}
```

:keyboard: Input

```
Enter lines :
"Hello"
-----> Hello
"Java"
-----> Java
"bye"
```

:printer: Output

```
Enter lines :
"Hello"
-----> Hello
"Java"
-----> Java
"bye"
```

:bulb: 

=> ในการเทียบstringควรใช้ [.equals()] สามารถใช้ [!=] ได้ก็ต่อเมื่อstring นั้นเป็นStatic

## Writer :page_with_curl:

Reader/Writer : อ่านเขียนเป็น`Unicode Characters [2 byte]` เหมาะกับtext

- FileReader/FileWriter : `File`
- BufferedReader/BufferedWriter : อ่านได้เป็นบรรทัดไม่ใช่แค่charทำงานเร็ว + คล้ายwrapper class
- PrintWriter : `println()` ช่วยในการเขียนข้อมูลชนิดสตริงในไฟล์

### PrintWriter [เขียนทับ] :pencil2:

:desktop_computer: Example Code :

```
FileWriter fileWriter = null;
try {
    // read from user
    InputStreamReader inReader = new InputStreamReader(System.in);
    BufferedReader buffer = new BufferedReader(inReader);
    
    // write to file
    fileWriter = new FileWriter("from-user.txt"); //สร้างไฟล์ใหม่หรือเขียนทับไฟล์เดิมขึ้นอยู่กับแต่ในกรณี 
    PrintWriter out = new PrintWriter(fileWriter); //ในการใช้`FileWriter`จะยุ่งยากเลยต้องนำ`PrintWriter`มาครอบไว้เพื่อให้สะดวกในการใช้มากขึ้น
    
    System.out.println("Input text to file:");
    String line = buffer.readLine(); //ใช้อ่านไฟล์
    
    while (!line.equals("bye")) {
       out.println("-----> " + line); //ปริ้นผลลัพท์โดยตรงจาก`PrintWriter`เลยไม่จำเป็นต้องใช้`System.out`ก็ได้
       line = buffer.readLine();
    }
    out.flush(); //คำสั่งในการเขียนข้อมูลลงดิส/ไฟล์ ถ้าไม่ใช้คำสั่งนี่ข้อมูลจะอยู่แค่ในหน่วยความจำ
}
catch (IOException e){
    System.err.println("Error reading from user");
}
finally {
    .... close file ....
}
```

:keyboard: Input text to file

```
cat
dog
bat
bye
```

:printer: Output

```
-----> cat
-----> dog
-----> bat
```

:bulb:

=> PrintWriter [เขียนทับ] : ใช้คลาสPrintWriterสะดวกเหมือนการใช้System.out.println()

=> ถ้าเราเขียนใส่ไฟล์ในรอบแรกจะเป็นการ`สร้างไฟล์ใหม่` 
แต่ถ้ามีไฟล์อยู่แล้วจะเป็นการ`เขียนไฟล์ทับ` ส่วนไฟล์ที่เขียนในตอนแรกก็จะหายไป มีไฟล์ใหม่ขึ้นมาแทน 

=> PrintWriter : สามารถปริ้นข้อมูลชนิดไหนก็ได้ แม้กะทั้ง objectก็ปริ้นได้

:desktop_computer: Example Code :

```
// write to file
FileWriter fileWriter = new FileWriter("any-type.txt");
PrintWriter out = new PrintWriter(new BufferedWriter(fileWriter));
out.println("hello");
out.println(5.67);
out.println(new Restaurant("After You", "Dessert", "Phahonyothin"));
out.close();
```

### BufferedWriter [เขียนทับ] :pencil2:

:desktop_computer: Example Code :

```
FileWriter fileWriter = null;
try {
    // read from user
    InputStreamReader inReader = new InputStreamReader(System.in);
    BufferedReader buffer = new BufferedReader(inReader);
    
    // write to file
    fileWriter = new FileWriter("from-user.txt");
    BufferedWriter out = new BufferedWriter(fileWriter);
    
    System.out.println("Input text to file:");
    String line = buffer.readLine();
    
    while (!line.equals("bye")) {
        out.write("-----> " + line);
        out.newLine();
        line = buffer.readLine();
    }
    out.flush();
}
catch (IOException e){
    System.err.println("Error reading from user");
}
finally {
    .... close file ....
}
```

:bulb:

=> BufferedWriter [เขียนทับ] : เมื่อใช้คลาสนี้BufferedWriterจะทำให้การทำงานมีความรวดเร็วยิ่งขึ้น 

=> newline() : ควรใช้คำสั่งnewline()ในการขึ้นบรรทัดใหม่

=> BufferedWriter : ไม่มีการใช้คำสั่งprintlnเหมือนกับPrintWrite แต่จะใช้คำสั่ง.write() มาปริ้นผลลัพท์แทน

### PrintWriter + BufferWriter [เขียนทับ] :pencil2:

:desktop_computer: Example Code :

```
FileWriter fileWriter = null;
try {
    // read from user
    InputStreamReader inReader = new InputStreamReader(System.in);
    BufferedReader buffer = new BufferedReader(inReader);
    
    // write to file
    fileWriter = new FileWriter("from-user.txt");
    PrintWriter out = new PrintWriter(new BufferedWriter(fileWriter));
    
    System.out.println("Input text to file:");
    String line = buffer.readLine();
    
    while (!line.equals("bye")) {
        out.println("-----> " + line);
        line = buffer.readLine();
    }
    out.flush();
}
catch (IOException e){
    System.err.println("Error reading from user");
}
finally {
    .... close file ....
}
```

:bulb:

=> ใช้คลาสPrintWriter + BufferedWriter : ถ้าใช้สองคำสั่งนี้พร้อมการจะสะดวกและรวดเร็วกว่า


### [เขียนต่อท้ายไฟล์] :pencil2:


:desktop_computer: Example Code :

```
FileWriter fileWriter = null;
try {
    // read from user
    InputStreamReader inReader = new InputStreamReader(System.in);
    BufferedReader buffer = new BufferedReader(inReader);
    
    // write to file
    fileWriter = new FileWriter("from-user.txt" , true);
    PrintWriter out = new PrintWriter(new BufferedWriter(fileWriter));
    
    System.out.println("Input text to file:");
    String line = buffer.readLine();
    
    while (!line.equals("bye")) {
        out.println("-----> " + line);
        line = buffer.readLine();
    }
    out.flush();
}
catch (IOException e){
    System.err.println("Error reading from user");
}
finally {
    .... close file ....
}
```

:bulb:

=> fileWriter = new FileWriter("from-user.txt" , true);

=> ในการเขียนไฟล์ต่อจากไฟล์เดิมสามารถเพิ่มparameterในFileWriter constructor



## .close() :page_with_curl:

:desktop_computer: Example Code :

```
finally {
    try {
       if (buffer != null) // อาจจะต้องใช้nullตรวจสอบก่อน
           buffer.close();
    } catch (IOException e) {
        System.err.println("Error closing files");
    } 
}
```

:bulb:

=> จะต้องใส่คำสั่งปิดไฟล์ทุกกครั้งถ้าไม่ทำไฟล์บางส่วนอาจจะหายไปได้

## Scanner :page_with_curl:

Scanner : ใช้อ่านข้อมูล สามารถแยกข้อมูลจากการด้วย `Whitespace` เป็นคลาสที่มีความสะดวกแต่ช้า และยังมีข้อยกเว้นหลายอย่างทำให้ผิดพลาดง่าย

:desktop_computer: Example Code :

```
Scanner scanner = new Scanner(System.in);
String symbol = scanner.next();
String line = scanner.nextLine();
int symbol = scanner.nextInt();
double amount = scanner.nextDouble();
```

:bulb:

=> .next() : จะรับชนิดข้อมูลเป็นคำหรืออื่นๆ

=> .nextLine() : จะรับชนิดข้อมูลเป็นบรรทัด

=> .nextInt() : จะรับชนิดข้อมูลเป็นint

=> .nextDouble() : จะรับชนิดข้อมูลเป็นdouble

## Reading / Writing odjects with serialzation :page_with_curl:

![301471336_583161989957097_3606114597016279115_n](https://user-images.githubusercontent.com/86911299/187132525-5ee491a2-fd7d-44f5-b87d-efa0351d0a8f.jpg)

Serial Object : การแปลงobjectที่อยู่ในheap อยู่ในรูปแบบ`serialized object` เป็นinstance varlables เหมือนการเอาลมออกจากวัตถุต่างๆ

![301700316_834807664569283_2420264551288135383_n](https://user-images.githubusercontent.com/86911299/187132477-4ca90dcd-f896-40c8-8aa8-183f283d365f.jpg)

Chaining stream :

![301404282_371294915204580_1753864049247489344_n](https://user-images.githubusercontent.com/86911299/187132240-48c5bef4-ce75-4e02-81bb-4c99eccd8bcd.jpg)

Serial Version ID : ถ้าโค้ดในคลาสของobjectเปลี่ยน หรือมีการเพิ่มเติมแก้ไข จะเกิด`Error : Invalid Class`
มาจากเวอชั่นคลาสไม่ตรงกันถ้าต้องการจะแก้ไข่ จะต้องแน่ใจแล้วว่าการแก้ไขนั้นไม่มีผลกระทบต่อโค้ดเดิม  

Sol. ระบุ Serial Version ID ไปในโค้ดอยู่ในไฟล์ระบุเป็นhardcode [Serial Version ID จาวาจะเก็บคลาสไว้ในobjectที่ถูกserialized]
วิธีตรวจสอบว่าตรงกันมั้ย ก็ต่อเมื่อdeserialized 


:desktop_computer: Example Code :

```
static final long serialVersionUID = -6849794470754667710L;
```

### ObjectInputStream :pencil2:

1. FileInputStream : 

:desktop_computer: Example Code :

```
FileInputStream fileStream = new FileInputStream("MyGame.ser");
```

2. ObjectInputStream : 

:desktop_computer: Example Code :

```
ObjectInputStream name = new ObjectInputStream(fileStream);
```

3. readObject : 

:desktop_computer: Example Code :

```
Object one = name.readObject();
```

4. cast object : 

:desktop_computer: Example Code :

```
GameCharacter name = (GameCharacter) one;
```

5. close : 

:desktop_computer: Example Code :

```
name.close();
```

### ObjectOutputStream :pencil2:

1. FileOutputStream : 

:desktop_computer: Example Code :

```
FileOutputStream fileStream = new FileOutputStream("MyGame.ser");
```

2. ObjectOutputStream : 

:desktop_computer: Example Code :

```
ObjectOutpurStream name = new ObjectOutputStream(fileStream);
```

3. writeObject : 

:desktop_computer: Example Code :

```
name.writeObject(characterOne);
```

4. close : 

:desktop_computer: Example Code :

```
name.close();
```

## Comment :page_with_curl:

### inline comment :pencil2:

```
// comment
```

=> ใช้หลังโค้ดหรือเหนือโค้ดก็ได้

### block comment :pencil2:

```
/* comment */
```

=> จะต้องใช้คู่กัน ถ้าไม่จับคู่กับจะerror

### documentation comment :pencil2:

![javadoc-1024x533](https://user-images.githubusercontent.com/86911299/187074355-25ddefb1-e2a4-41d1-bdbc-df115f909526.png)

- class : @author = ผู้เขียน , @since = version

```
/**
* MyClass description
* @author Usa Sammapun
* @since 1.1
*/
public class MyClass {
```

- method , consturctor : @param , @return , @exception 

```
/**
* อธิบายเมธอท myMeth 
*
* @param param1 อธิบาย parameter แรกสั้นๆ
* @param param2 อธิบาย parameter ที่ 2 ส้ันๆ
* @return อธิบายค่าที่ return ส้ันๆ
* @throws ExceptionClassName อธิบายสาเหตุที่ทําให้เกิดการโยน exception 
*/
public int myMeth(int param1, int param2) throws ExceptionClassName {
```

- variable : อยู่เหนือตัวแปร

```
**
* อธิบายตัวแปร myVar 
*/
protected int myVar;
```

# Exception Handling :books:

Exception : เป็นกลไกของจาวาในการแจ้งเตือน`ERROR`แบบเฉพาะเจาะจงมายิ่งขึ้น เข้าใจง่าย ช่วยให้โปรแกรมเมอร์สามารถจัดการกับ`ERROR`ให้ตามต้องการ 
และเป็นคลาสหนึ่งใน`Java Libiary`ที่เราสามารถสร้างobjectของคลาสExceptionได้ และเป็นObjectชนิดนึงที่พิเศษมากเพราะสามารถ
`throw`[แจ้งError,ส่งต่อError] `try / catch` [จัดการกับError] ซึ่งสามารถpass control ไปให้callerที่รู้ว่าต้องจัดการยังไง
ในคลาสExceptionนี้จะมีsubclass เช่น IOException RuntimeException ClassCastException IllegalArrgumentException 

 ![302429801_437202058375924_2112388091397634434_n](https://user-images.githubusercontent.com/86911299/188262937-0b51b6f2-39de-4f6e-9358-8198e882cf62.jpg)

Reporting : รายงานข้อมูลError ที่เฉพาะเจาะจง จะบอกได้เลยว่าเกิดจากอะไร เกิดขึ้นที่บรรทัดไหน คลาสไหน  

Recovery : ช่วยบอกให้รู้วิธีการแก้ไขกับErrorนั้นๆ ว่าต้องจัดการยังไง จะแสดงผลลัพท์ให้รูปแบบที่เข้าใจง่าย คนทั่วไปหรือผู้ใช้เข้าใจได้เลย ไม่ใช่แบบ`Stack Trace` ซึ่งแบบนี้จะเยอะ เข้าใจยาก และนอกจากจะแสดงผลลัพท์ที่เข้าใจง่ายแล้วยังสามารถบอกวิธีแก้ไขให้ตรงจุดอีกด้วย

Error Type :

- Syntax Error : ส่วนใหญ่แล้วIDE / IntelliJ จะช่วยตรวจสอบละบอกวิธีแก้ไขในขณะที่กำลังสร้างโค้ดเลย 
- Runtime Error : ใช้Try / Catchในการแก้ปัญหา
- Logic Error : ใช้unit testing

System Error : เป็นErrorที่**ร้ายแรง ไม่ค่อยเกิดขึ้น ไม่สามารถควบคุมได้** ไม่ควรจัดการเองควร`throwโดยJVM`แต่ต้องแจ้งผู้ใช้ ไม่ต้องdeclare/handle เช่น OutOfMemoryError

Exception class : มีหลายคลาสมีให้เลือกหลายแบบควรเลือกให้เหมาะสมกับการใช้งาน แต่ถ้าหากไม่มีสามารถสร้างขึ้นมาเองได้จากการ`extends จาก exception class / subclass`

## Checked Exception :page_with_curl:

Checked Excption : เป็นsubclassของException[แต่ไม่ใช่RuntimeException] เป็นข้อพิดพลาดที่เกิดจาดเหตุสุดวิสัยที่เกิดขึ้นได้เสมอ ไม่สามารถควบคุมได้
เช่น ไม่สามารถอ่านไฟล์ได้ ฐานข้อมูลมีปัญหา หน่วยความจำเต็ม เน็ตหลุด ไฟดับ เกิดได้จากทั้งภายในและภายนอก เช่น FileNotFoundException , IOException 
SQLException , ParseException `ต้องส่งต่อ(declare) throwsไปให้caller` `ดักจับ(try - catch)exception` 

### แจ้งerror :pencil2:

:desktop_computer: Example Code:

```
if(balance < amount)
    throw new InsufficientFundException("Error Message");
```

:bulb:

=> ใช้`throw`เมื่อต้องการแจ้งข้อผิดพลาด สามารถใช้ได้ทั้ง method , constructor

=> ในการใช้throwจะต้องสร้างobjectใหม่ด้วยจึงต้องใช้คู่กับ `throw new`


:desktop_computer: Example Code checked Exception:

```
public void withdraw(double amount) throws InsufficientFundException{
    if(balance < amount)
        throw new InsufficientFundException("Error Message");
    balance = balance - amount;
}
```

:bulb:

=> ใช้`throws` ถ้าหากเป็นchecked exception และต้องdeclareตรงmethod signatureด้วยไม่งั้นจะเกิดerror

=> ถ้าในบรรทัด [throw new InsufficientFundException("Error Message");] เกิดการthrow exception บรรทัดต่อๆไปในmethodนี้จะไม่ทำงาน

:desktop_computer: Example Code Unchecked Exception:

```
public Student(String name, String birthday) {
    if (!isDateFormatCorrect(birthday))
        throw new IllegalArgumentException("Birthday is incorrect");
    this.name = name;
    this.birthday = birthday;
}
```

:bulb:

=> เนืองจากIllegalArgumentExceptionนี้เป็น`Uncheck Exception`เราไม่ต้องdeclare

### ส่งต่อ / ดักจับ :pencil2:

- Declare :  
- Handle : 

### ส่งต่อExceptionต่อด้วยการDelacre :pencil2:

### ดักจับException :pencil2:

### declare + ดักจับ :pencil2:

## Unchecked Exception :page_with_curl:

Unchecked Exception : เป็นsubclass[RuntimeException] เป็นข้อผิดพลาดที่เกิดจากการเขียนโปรแกรมของตัวโปรแกรมเมอร์เอง 
[`ไม่ต้อง`ส่งต่อ(declare) `ไม่ต้อง`ดักจับ(try - catch)] เช่น 
- NullPointerException : ไม่ได้เช็คNUll 
- IndexOutOfBoundsException : ไม่ได้เช็คขอบเขต/index
- IllegalArgumentException : ใช้argumentผิดประเภท
- ArithmeticException : ไม่ได้เช็คค่าศูนย์ก่อน เช่น มีค่าศูนย์มาหาร

### Catch with Unchecked Exception :pencil2:

## Try / Catch :page_with_curl:

### Try with multiple catch :pencil2:

### ลำดับของCatch :pencil2:

### Try with multiple catch :pencil2:

### RethrowingException :pencil2:

## Throwable :page_with_curl:

### String getMessage() :pencil2:

### void printStrackTrace() :pencil2:

### String toString() :pencil2:

## Create Exception :page_with_curl:

## Finally clause :page_with_curl:

### Finally with catch :pencil2:

### System.exit() :pencil2:

### Example Finally Code :pencil2:

## Extra :page_with_curl:

# Collections :books:

Collection : เป็นกลุ่มของข้อมูลคล้ายกัน เช่น Array , List , Set เรียกสิ่งที่อยู่ในCollection `elements`

https://docs.oracle.com/javase/tutorial/collections/intro/?fbclid=IwAR3tnStR9vQMM4YzmSf0kyqMAtTHN9iGg4KwMEs390vX5V9DL40O2qZpoCM

Java Collection : เป็นInterfaceที่มีหลาย `method Specification`

- เพิ่ม สิ่งของเข้าไปในCollection 
    `boolean add(E o)`

- หา สิ่งของว่าอยู่ที่ไหนในCollection
    `boolean contains(Object o)` ใช้ผ่านMethod [.equal()] 

- ลบ สิ่งของที่อยู๋ในCollection
    `boolean remove(Object o)`

- ลูป ประมวลผล / ดำเนิดการ ___ กับสิ่งของ `ทุกชิ้น` ในCollection
    `int size()`

```
for(type element : Collection) 
    ประมวลผลelement;
```

การประมวลผลของCollection : สามารถใช้loopได้ทั้งหมดสองแบบ

    1. for loop : ใช้เมื่อต้องการเข้าถึง `Index` ในการทำงานและใช้กับCollectionที่มี `.get()`

    :desktop_computer: Example Code :

    ```
    for (int i = 0; i < studentList.size(); i++)
       System.out.println(studentList.get(i).getName());
    ```

    2. for-each loop : ใช้เมื่อCollectionที่มี `.set() , .get()`

    :desktop_computer: Example Code :

    ```
    for (Student student : studentList)
       System.out.println(student.getName());
    ```

ลักษณะของCollection
1. Element 
    => `ซ้ำได้` ถ้ามีข้อมูลหรือสิ่งของซ้ำกันจะเก็บทุกข้อมูลจะไม่มีข้อมูลไหนหายไปจนกว่าจะ `Remove`
        List , MultiSet

    => `ซ้ำไม่ได้` ถ้ามีข้อมูลหรือสิ่งของซ้ำกันจะเก็บให้เหลือเพียงแค่ชิ้นเดียว 
        Set , SortedSet

2. Index
    => `ผ่านได้` เข้าถึงelementผ่านindexได้ จะเก็บแบบใส่ข้อมูลก่อนจะอยู่ก่อน 
        List , SortedSet
            
    Note : จะเข้าถึงข้อมูลในรูปแบบ *Random Access* แต่เวลาเก็บข้อมูลจะแตกต่างกันออกไปตามประเภท 
        เช่น Array-List จะเก็บแบบArray , Linked-List จะเก็บแบบDoubly Linked-List

    => `ผ่านไม่ได้` เข้าถึงelementผ่านindexไม่ได้ จะเก็บแบบปนกัน เหมือนเวลาเก็บของเล่นใส่กล่อง จะไม่เรียงกัน
        MUltiSet , Set

![305395403_608000120700945_7802270997801150979_n](https://user-images.githubusercontent.com/86911299/189147738-08772dc3-abc2-4e85-9347-49a6d4c29718.jpg)

## Generic types :page_with_curl:

`Collection<E> , List<E> , Set<E> , Map<K , V>` : E เป็นชนิดของobject ในCollectionนึงควรจะมีแค่ 1 elementเท่านั้น
เพื่อที่เราจะได้ประกาศว่าCollectionนั้นๆ เก็บObjectชนิดไหนอยู่เวลาจะคืนค่าสามารถreturnได้เลย ไม่ต้องcast 

![305356782_1123386631590607_2095269272473667358_n](https://user-images.githubusercontent.com/86911299/189151318-58b4ace7-1d4c-4677-b72b-37c8e30d22e3.jpg)

Collection with Primitive type จะต้องใช้ `wrapper class`ทำได้สองแบบ

1. ใช้`Wrapper`ตลอด

```
List<Integer> a = new ArrayList<Integer>(); a.add(new Integer(30));
a.add(new Integer(11));
a.add(new Integer(20));
Integer iObj = a.get(2);
int i = iObj.intValue();
```

2. ประกาศชนิดเป็นwrapper ใช้เป็น`Prmitive`

```
List<Integer> a = new ArrayList<Integer>(); a.add(30);
a.add(11);
a.add(20);
int i = a.get(2);
```

## [List<E>] :page_with_curl:

### Array-List :pencil2:

Array-List : คล้ายกับArrayต่างกันตรงที่Array-Listจะขยายขนาดให้โดยอัตโนมัติเมื่อเต็ม แต่Arrayสามารถเพิ่มขีดจำกัดของArrayได้

=> เข้าถึงข้อมูลแบบ`Random Access` เร็วมาก เพราะว่าArray-Listจะเป็นการ`implement`ที่ระบุว่าจะเข้าถึงข้อมูลแบบRandom Access(Generally constant)

=> `insert` ช้ามาก เพราะถ้าต้องการเพิ่มข้อมูลไปในระหว่างArray จะต้องเลื่อนข้อมูลในindexไปที่indexถัดไปเรื่อยๆ 

### การใช้ArrayList<E> :pencil2:

#### การสร้างList + เพิ่มElement

:desktop_computer: Example Code :

```
ArrayList<Student> stdList = new ArrayList<Student>();
//สร้างList

Student s1 = new Student("First");
Student s2 = new Student("Second");
Student s3 = new Student("Third");
//สร้างelement

stdList.add(s1);
stdList.add(s2);
stdList.add(s3);
//เพิ่มelementเข้าไปในlist
```

#### contains()

:desktop_computer: Example Code :

```
System.out.println("------ Check for elements using contains()");
System.out.println(stdList.contains(s1));
System.out.println(stdList.contains(new Student("First")));
```

:printer: Output

```
true
false
```

:bulb:

=> .contain() เรียกใช้Method .equal() ; จะตรวจสอบจากObjectเลย การ`new`เป็นการสร้างobjectใหม่จึงทำให้แสดงผลเป็นfalse

=> ใช้`@Override`เปลี่ยนให้ตรวจสอบค่าแทน .equal() [สามารถgenerateได้เลย] 

#### get(index)

:desktop_computer: Example Code :

```
System.out.println("------ Access a list using get(index)");
for (int i = 0; i < stdList.size(); i++) {
Student student = stdList.get(i);
String name = student.getName();
System.out.println("Name: "+name);
```

:bulb:

=> get(i) i = index ในList<E> มีmethodในการเข้าถึงข้อมูล

#### for-each loop

:desktop_computer: Example Code :

```
System.out.println("------ Access a list using for-each loop");
for (Student student : stdSet) {
   String name = student.getName();
   System.out.println("Name: "+name);
}
```

### Linked-List :pencil2:

Linked-List : เป็นโครงสร้างข้อมูลที่ไม่จำกัดขนาด

=> เข้าถึงข้อมูลแบบ`Random Access` ช้ามาก เพราะในการเก็บข้อมูลจะใช้`Pointer , Node` ; เข้าถึงตั้งแต่ Head_Node . . . End_Node
    จะช้ามาเพราะถ้าจะเข้าถึง index[38] = 0 , 1 , ... , 36 , 37
    - Linked-List ไม่มีimplement random access 
    - [Double Linked-List] มีการimplement random access ; จะสามารถเข้าถึง Head , Endได้เร้วกว่า

=> `insert` เร็วมาก เพราะว่าใช้pointerในการinsert

**ความเร็วในการเข้าถึง LinkedList < Doubly Linked-List < ArrayList**

## [Set<E>] :page_with_curl:

Set<E> ; class HashSet : elementห้ามซ้ำกัน และจะไม่เรียงกันตามindex

subtype => HashSet : เป็นคลาสที่ใช้`hash codes` [ใช้ในการเก็บหรือตรวจสอบว่าเป็นคลาสเดียวกันมั้ย] ในการเข้าถึงelement *รวดเร็ว + ไม่เรียงกัน*
        => TreeSet : คล้ายๆกัน แต่สามารถเรียงข้อมูล`sort` 
            `TreeSet(Comprator <? super E> comprator)` / `Comparable`

        :desktop_computer: Example Code :
        
        ```
        Set<String> s = new HashSet<String>();
        s.add(“Hello”);
        boolean b = s.contains(“Hello”);
        ```

**Set ไม่มี Get(index)**

### HashSet :pencil2:

#### การสร้างSet + เพิ่มElement

:desktop_computer: Example Code :

```
HashSet<Student> stdSet = new HashSet<Student>();
//สร้างList

Student s1 = new Student("First");
Student s2 = new Student("Second");
Student s3 = new Student("Third");
//สร้างelement

stdSet.add(s1);
stdSet.add(s2);
stdSet.add(s3);
//เพิ่มelementเข้าไปในset
```

#### contains()

:desktop_computer: Example Code :

```
System.out.println("------ Check for elements using contains()");
System.out.println(stdSet.contains(s1));
System.out.println(stdSet.contains(new Student("First")));
```

:printer: Output

```
true
false
```

:bulb:

=> .contain() เรียกใช้Method .equal() ; จะตรวจสอบจากObjectเลย การ`new`เป็นการสร้างobjectใหม่จึงทำให้แสดงผลเป็นfalse

=> ใช้`@Override`เปลี่ยนให้ตรวจสอบค่าแทน .equal() [สามารถgenerateได้เลย] 

#### for-each loop

:desktop_computer: Example Code :

```
System.out.println("------ Access a list using for-each loop");
for (Student student : stdSet) {
   String name = student.getName();
   System.out.println("Name: "+name);
}
```

:bulb:

=> ข้อมูลที่แสดงผลหลังจากรันแล้วจะ`ไม่เรียง`

## [Map<K,V>]:page_with_curl:

Map<K,V> ; K = key , V = value เป็นโครงสร้างที่มีelementเป็นคู่ key-value จะทำให้มีประสิทธิภาพในการเข้าถึงข้อมูลมากถ้า `รู้ค่าkey`
คล้ายกับIndex's Array-Listต่างกันตรงที่Map จะเป็นข้อมูลชนิดใดก็ได้

Map เป็นinterfaceสำหรับgeneric type key , value
- V get(Object key) : คืนค่าvalue + key แต่ถ้าไม่มีจะ return null;
- V put(K key , V value) : เก็บค่าvalueไว้ในkey ถ้ามีkeyอยู่แล้วจะใช้keyเดิม เปลี่ยนแค่ค่าvalue ถ้าไม่มีจะ return null; 

ถ้าเราต้องการที่จะประมวลผลทั้งMap เราสามารถออกจากMap ได้ 2 ทาง
1. `Set<K> keySet()` : return set's key ทุกอันใน Map
2. `Collection<V> values` : return group's value ทุกอันใน Map

### HashMap :pencil2:

#### การสร้าง Map ด้วย key/value และเพิ่ม element เข้า map

:desktop_computer: Example Code :

```
HashMap<String, Student> stdMap = new HashMap<String, Student>();
//สร้างMap ด้วยkey/value

Student s1 = new Student("First", 1);
Student s2 = new Student("Second", 2);
Student s3 = new Student("Third", 3);
//สร้างelement

stdMap.put("First", s1);
stdMap.put("Second", s2);
stdMap.put("Third", s3);
//เพิ่มelementเข้าไปในMap .put()เหมือน.add()
```

#### การใช้เมธอด containsKey(), containsValue()

:desktop_computer: Example Code :

```
System.out.println("------ Check using containsKey/Value()");
System.out.println(stdMap.containsKey("First"));
System.out.println(stdMap.containsValue(s1));
System.out.println(stdMap.containsValue(new Student("First", 1)));
```

:printer: Output

```
true
true
false
```

:bulb: 

=> .contain() เรียกใช้Method .equal() ; จะตรวจสอบจากObjectเลย การ`new`เป็นการสร้างobjectใหม่จึงทำให้แสดงผลเป็นfalse

=> ใช้`@Override`เปลี่ยนให้ตรวจสอบค่าแทน .equal() [สามารถgenerateได้เลย] 

#### การค้นหา/เข้าถึงข้อมูลเมื่อรู้ key : ใช้ get(key)

:desktop_computer: Example Code :

```
System.out.println("------ Access a map with known key");
Student myStd = stdMap.get("Second");
System.out.println("Name: "+myStd.getName()+" Year: "+myStd.getYear());
```

#### การวนลูปของ map ผ่าน key : ใช้ keySet()

:desktop_computer: Example Code :

```
System.out.println("------ Looping a map using keys with keySet() method");
Set<String> keys = stdMap.keySet();
for (String name : keys) { //เข้าถึงข้อมูลทุกชิ้นในMap
   Student student = stdMap.get(name);
   System.out.println("Name: "+student.getName()+" Year: "+student.getYear());
}
```

:bulb: 

=> ต้องการkeySet + Value

#### การวนลูปของ map : ใช้ values()

:desktop_computer: Example Code :

```
System.out.println("------ Looping a map using values with values() method");
Collection<Student> values = stdMap.values();
    for (Student student : values) {
          System.out.println("Name: " + student.getName() + " Year: " + student.getYear());
}
```

:bulb: 

=> ต้องการkeySet + Value

=> values = return collection

## Implementation :page_with_curl:

![306040747_606162140906002_8407473119290121113_n](https://user-images.githubusercontent.com/86911299/189171436-a945eeb2-eade-44e3-9411-56862e17390c.jpg)

## Hashtable VS. Vector :page_with_curl:

![304858711_3148235365420996_9212496275751526900_n](https://user-images.githubusercontent.com/86911299/189171459-82d9fe74-dba3-44e7-b1ea-d34969dee9d9.jpg)

# Interface , Abstract Classes , Polymorphism :books:

# Unit Testing and jUnit :books:

# Object-Oriented Design Principles :books:

# Composition :books:

# Design Patterns :books:

# Error Code :books:
