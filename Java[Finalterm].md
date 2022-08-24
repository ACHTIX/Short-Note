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

### BufferedWriter [เขียนทับ] :pencil2:

### PrintWriter + BufferWriter [เขียนทับ] :pencil2:

### [เขียนต่อท้ายไฟล์] :pencil2:

## Scanner :page_with_curl:

## Reading / Writing odjects with serialzation :page_with_curl:

## Comment :page_with_curl:

# Exception Handling :books:

# Interface , Abstract Classes , Polymorphism :books:

# Collections :books:

# Unit Testing and jUnit :books:

# Object-Oriented Design Principles :books:

# Composition :books:

# Design Patterns :books:

# Error Code :books:
