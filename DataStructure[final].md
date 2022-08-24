# สารบัญเนื้อหาสรุป

## 1. Graphs  :bookmark_tabs: ##
## 2. Graphs Traversals :closed_book: ##
## 3. Trees :green_book: ##
## 4. Tree Traversals :orange_book: ##
## 5. Binary Tree :notebook: ## 
## 6. Binary Search Trees :notebook_with_decorative_cover: ##
## 7. Balanced Binary Search Trees :ledger: ##
## 8. Disjoint-set Data Structure :blue_book: ##
## 9.  :label: ##


# Graphs :books:

Graphs : กราฟในโครงสร้างของข้อมูลนั้นจะเป็นในส่วนของ `List` ที่ไม่มีลำดับขั้นตอน `Non-linear` ในกราฟจะประกอบด้วยสองเซตดังนี้
1. จุดตัด `[Vertices / Nodes]` **สร้างจุดตัดก่อนแล้วตามด้วยเส้นเชื่อม** 
2. เส้นเชื่อม `[Edges / arcs]`

![300003168_947944703266520_6188458677050875491_n](https://user-images.githubusercontent.com/86911299/186433232-5f09f18b-a12f-42eb-a3f2-4c766198f0ec.jpg)

Set of Node

```
V = {0 , 1 , 2 , 3 , 4}
```

Set of Edges

```
E = {{0 , 1} , {0 , 4} , {1 , 2} , {1 , 3} , {2 , 3} , {3 , 4}}
//ในเซตของedgesจะหมายถึง node A ---> node B [ถ้าเป็นundirectedตำแหน่ง/ลำดับไม่มีผลต่อกราฟ แต่directedมีผล]
```

![300443725_395356386042817_7510432234889318436_n](https://user-images.githubusercontent.com/86911299/186435646-8a3a467e-7dc4-4f3f-979a-8171a2d00f93.jpg)

- Undirectied Graph : กราฟที่มีเชื่อมไม่ระบุทิศทาง ประกาศดังนี้ได้เลย `{0 , 1} => 0----1`
*ถ้ามีแค่หนึ่งเส้นเชื่อมที่ระบุทิศทางจะถือเป็น Directied Graph*

![300088801_2871021996540101_1294893420576660579_n](https://user-images.githubusercontent.com/86911299/186435714-4bd3232a-7493-472e-b72b-52a863682d6c.jpg)

- Directied Graph : กราฟที่มีเชื่อมระบุทิศทางเข้าและออก `Outgoing/Incoming` ในการประกาศต่างกัน เช่น 
`(2 , 3) => 2 ----> 3` , `(5 , 4) => 4 <---- 5 `

*Undirected graph เหมือนเป็นsib classของDirected graph*

## Basic Graph Terminology :page_with_curl:

ศัพท์เฉพาะทางขั้นพื้นฐานที่จะใช้ในเรื่องของกราฟ จะแบ่งออกเป็นสองกลุ่ม 
1. Undirected + Directed : ใช้ได้กับทั้งกราฟที่กำหนดทิศทางและไม่กำหนด 
2. Directed ONLY : ใช้ได้แค่กับกราฟที่กำหนดทิศทาง 

### Undirected + Directed :pencil2:

:framed_picture: For Example : 

![300185822_597711345226108_4250708952962243063_n](https://user-images.githubusercontent.com/86911299/186439014-081b432c-607f-4af1-bc8e-712e374a5689.jpg)

- End-Vertices / Endpoints : หมายถึงปลายของเส้นเชื่อม จะประกอบไปด้วยจุดตัดสองจุด 

:desktop_computer: Example :

```
{b , d} = Endpoints of E1
{d , f} = Endpoints of E2
```

- Adjacent : หมายถึงเส้นเชื่อมที่มีEndpointsเดียวกัน/เชื่อมถึงกัน/ใกล้กัน

:desktop_computer: Example :

```
'a' adjacent {b} , {c} 
'f' adjacent {b} , {d}
```

- Incident : หมายถึงจุดตัดที่แยกย่อยออกมา กลายเป็นเชื่อมสองเส้นที่มีจุดตัดเดียวกัน1จุด

:desktop_computer: Example :

```
'a' adjacent {{a , b} | {a , c}} 
'f' adjacent {{f , b} | {f , d}}
```

- Degree : หมายถึงจำนวนเส้นเชื่อมที่ออกหรือเข้า[ขึ้นอยู่กับประเภทกราฟ] จากหนึ่งจุดตัด 

:desktop_computer: Example :

```
deg(c) = 2
deg(b) = 3
```

### Directed ONLY :pencil2:

:framed_picture: For Example : 

![299681051_480916236820305_1962670974590185217_n](https://user-images.githubusercontent.com/86911299/186442076-2986dd70-9223-4daa-996c-9032027650e3.jpg)

- Origin / Source [destination of the edge]

1. Outgoing Edges : หมายถึงเส้นเชื่อมที่มีหัวลูกศรชี้ออกจากจุดตัด

:desktop_computer: Example :

```
E1 , E2 <--Outgoing Edges-- d
```

2. Ingoing Edges : หมายถึงเส้นเชื่อมที่มีหัวลูกศรชี้เข้าไปทางจุดตัด

:desktop_computer: Example :

```
E1 --Ingoing Edges--> b
E2 --Ingoing Edges--> f
```

- Degree : หมายถึงจำนวนเส้นเชื่อมที่ออกหรือเข้า[ขึ้นอยู่กับประเภทกราฟ] จากหนึ่งจุดตัด *กราฟที่ระบุทิศทางDirected*

1. In-degree : จำนวนของเส้นเชื่อมที่ชี้เข้าไปในจุดตัด

:desktop_computer: Example :

```
indeg(b) = 3
indeg(a) = 0
```

2. Out-degree : จำนวนเส้นเชื่อมที่ชี้ออกมาจากจุดตัด

:desktop_computer: Example :

```
outdeg(d) = 2
outdeg(b) = 0
```

## Graph Applications :page_with_curl:

Graph Applications : การนำกราฟไปในใช้งานจริง 

- Road Network [GPS] : สร้างกราฟจากแผนที่เพื่อระบุเส้นทางที่ต้องการจะไป
- Social Network [Instagram] : สร้างกราฟจากการติดตาม/ผู้ติดตาม เป็นเครือข่ายในการติดต่อระหว่างคนนึงสู่อีกคน หรือหลายๆคน
- Flight Network [Airport] : สร้างกราฟจากเส้นทางกาารเดินทางระหว่างประเทศในแต่ละประเทศแต่ละสนามบิน

## Graph Representations :page_with_curl:

Graph Representations : การใช้กราฟในการแทนหรือแสดงภาพให้ออกมาในรูปแบบปกติหรือธรรมดาที่สุด จะมีสองแบบ 

1. Adjacency Matrix : เมทริกซ์เก็บความใกล้เคียงในรูปแบบ`2D - Array`
2. Adjacency List : ลิสเก็บความใกล้เคียงในรูปแบบ`Array + List`

**n = จำนวนของnodeในกราฟ , m = จำนวนของedgeในกราฟ**

### Adjacency Matrix :pencil2:

Adjacency Matrix : เมทริกซ์เก็บความใกล้เคียงในรูปแบบ`2D - Array` ที่มีขนาด n * n 

![300573405_375947004718713_193758497409480006_n](https://user-images.githubusercontent.com/86911299/186447382-8e2944a7-640b-4b06-a3c2-b59bb0910455.jpg)
![299927107_607314724281759_5159757099193883666_n](https://user-images.githubusercontent.com/86911299/186447394-bc621ea5-21ad-461c-b27c-a26f03194b76.jpg)

1 = ถ้าข้อมูลในเมทริกซ์ตำแหน่งนั้นมีค่าเป็น1แสดงว่ามีเส้นเชื่อม
0 = ถ้าข้อมูลในเมทริกซ์ตำแหน่งนั้นมีค่าเป็น0แสดงว่าไม่มีเส้นเชื่อม

### Adjacency List :pencil2:

Adjacency List : ลิสเก็บความใกล้เคียงในรูปแบบ`Array + List` arrayจะเก็บข้อมูลของnodes listจะเก็บข้อมูลของedges

![299764047_1305283883628286_1915968610184735763_n](https://user-images.githubusercontent.com/86911299/186448259-c593212f-1b28-467e-af39-c34c38e192ba.jpg)
![300850195_1445639709247860_5957118997924408247_n](https://user-images.githubusercontent.com/86911299/186448280-ce643a88-cd00-4f28-8b4b-c373984daf46.jpg)

~ ขั้นตอนการสร้าง ~
1. สร้างarrayตามจำนวนจุดตัดของกราฟ 
2. ดูในแต่ละจุดตัดว่ามีเส้นเชื่อมที่เป็น`Outgoing`อยู่ตรงไหนบ้าง และกำหนดลงในlist
3. สุดท้ายจบทุกlistด้วยnull/สายดิน หรือถ้าจุดตัดนั้นๆไม่มีเส้นเชื่อมที่เป็น`Outgoing`เลยให้ใส่nullได้เลย

## Basic Operations on Graphs :page_with_curl:

~ ขั้นตอนการปฎิบัติบนกราฟ ~
1. สร้างกราฟ
2. เพิ่มเส้นเชื่อมลงในกราฟ
3. แสดงกราฟออกมา

:desktop_computer: Example Code :

`#include <stdio.h>`
`#include <stdlib.h>`

```
//ฟังก์ชันในการสร้างกราฟ
int** createGraph(const int n){
    //คืนค่า2D-arrayในขนานn*n + จองพื้นที่ในหน่วยความจำ
    int** adjMatrix = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        adjMatrix[i] = malloc(sizeof(int)*n);
        for(int j = 0; j< n ; j++)
            adjMatrix[i][j] = 0 ;
    }
    return adjMatrix;
}

//ฟังก์ชันที่เพิ่มเส้นเชื่อมแบบระบุทิศทาง
void addEdge(int** adjMatrix, int u,int v){
    adjMatrix[u][v] = 1;
}

//ฟังก์ชันที่แสดง`Adjacency Matrix`
void printGraph(int** adjMatrix,int n){
    for (int i = 0 ; i<n ;i++){
        for (int j= 0; j < n; j++){
            printf("%d",adjMatrix[i][j]);
        }
        printf("\n");
    }
}

//main program
int main(){
    int n= 5;
    int** adjMatrix = createGraph(n);

    //Vertex numbers should be from 0 to 4
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,3);
    addEdge(adjMatrix,1,4);
    addEdge(adjMatrix,2,0);
    addEdge(adjMatrix,2,3);
    addEdge(adjMatrix,3,4);
    printGraph(adjMatrix,n);
    return 0 ;
}
```

:printer: Output

```
01010
00001
10010
00001
00000
```

# Graphs Traversals :books:

# Trees :books:

# Tree Traversals :books:

# Binary Tree :books:

# Binary Search Trees :books:

# Balanced Binary Search Trees :books:

# Disjoint-set Data Structure :books:
