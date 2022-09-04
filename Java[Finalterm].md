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


## Unchecked Exception :page_with_curl:

Unchecked Exception : เป็นsubclass[RuntimeException] เป็นข้อผิดพลาดที่เกิดจากการเขียนโปรแกรมของตัวโปรแกรมเมอร์เอง 
[`ไม่ต้อง`ส่งต่อ(declare) `ไม่ต้อง`ดักจับ(try - catch)] เช่น 
- NullPointerException : ไม่ได้เช็คNUll 
- IndexOutOfBoundsException : ไม่ได้เช็คขอบเขต/index
- IllegalArgumentException : ใช้argumentผิดประเภท
- ArithmeticException : ไม่ได้เช็คค่าศูนย์ก่อน เช่น มีค่าศูนย์มาหาร

# Interface , Abstract Classes , Polymorphism :books:

# Collections :books:

# Unit Testing and jUnit :books:

# Object-Oriented Design Principles :books:

# Composition :books:

# Design Patterns :books:

# Error Code :books:
