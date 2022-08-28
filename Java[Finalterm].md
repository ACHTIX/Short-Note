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

Serial Object : 

Chaining stream : 

Serial Version ID : 

### ObjectInputStream :pencil2:

1. FileInputStream : 

2. ObjectInputStream : 

3. readObject : 

4. cast object : 

5. close : 

### ObjectOutputStream :pencil2:

1. FileOutputStream : 

2. ObjectOutputStream : 

3. writeObject : 

4. close : 

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

# Interface , Abstract Classes , Polymorphism :books:

# Collections :books:

# Unit Testing and jUnit :books:

# Object-Oriented Design Principles :books:

# Composition :books:

# Design Patterns :books:

# Error Code :books:
