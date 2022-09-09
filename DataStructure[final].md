# สารบัญเนื้อหาสรุป

## 1. Graphs  :bookmark_tabs: ##
## 2. Graphs Traversals :closed_book: ##
## 3. Trees :green_book: ##
## 4. Tree Traversals :orange_book: ##
## 5. Binary Tree :notebook: ## 
## 6. Binary Search Trees :notebook_with_decorative_cover: ##
## 7. Balanced Binary Search Trees :ledger: ##
## 8. Disjoint-set Data Structure :blue_book: ##
## 9. Terminology :label: ##


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

![305177351_803390500677349_8518480040172322500_n](https://user-images.githubusercontent.com/86911299/188323414-f65f48c3-ecce-44e7-841f-4d43f8f2dd4b.jpg)

## Basic Operations on Graphs Using Adjacency-Matrix :page_with_curl:

![image](https://user-images.githubusercontent.com/86911299/187135342-209f61f8-b67b-49b8-bdf1-85dd64f89e96.png)

### createGraph(n) :pencil2:

:desktop_computer: Example Code :

```
// Create the graph using adjacency-matrix representation
int** createGraph(const int n) { //จำนวนพื้นที่ของnode
    // Return 2D array of size n*n
    int** adjMatrix = malloc(sizeof(int*)*n);//จองพื้นที่ตามขนาดของ2D Array โดยใช้double pointer
    
    for (int i=0; i<n; i++) {
        adjMatrix[i] = malloc(sizeof(int)*n);

        for (int j=0; j<n; j++)
            adjMatrix[i][j] = 0;//กำหนดค่าdefaultให้เป็น0
    }
    return adjMatrix;
}
```

:framed_picture: diagram

![300836374_1109609323283736_4046407995333340541_n](https://user-images.githubusercontent.com/86911299/187141847-b2b6e01b-de41-4af4-bf14-c23562928d5d.jpg)

### addEdge(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// adjacency-matrix representation
void addEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
}
```

:framed_picture: diagram

![300720510_1276204856528364_8237072635620139358_n](https://user-images.githubusercontent.com/86911299/187141737-3a2b6317-c615-45e7-ad66-3918352f2afb.jpg)

### printGraph(G) :pencil2:

:desktop_computer: Example Code :

```
// Print the adjacency-matrix representation of the graph
void printGraph(int** adjMatrix, int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}
```

:bulb:

=> แสดงผลคล้ายกับ2D - Array

### deleteGraph(G) :pencil2:

:desktop_computer: Example Code :

```
// Delete the adjacency-matrix representation of the graph
void deleteGraph(int** adjMatrix, int n){
    for (int i=0; i<n; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}
```

### removeEdge(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// Remove the existing edge from the graph using adjacency-matrix representation
void removeEdge(int** adjMatrix, int u, int v) {
    adjMatrix[u][v] = 0;
}
```

:framed_picture: diagram

![301549816_663379831296190_4752734775629991891_n](https://user-images.githubusercontent.com/86911299/187142358-6996e43b-5672-442d-b965-e3f859b3fafa.jpg)

### addVertex(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Add the new vertex to the graph using adjacency-matrix representation
int** addVertex(int** adjMatrix, int *n, int u) {
int** adjMatrix_new =createGraph(u+1);
    
    for (int i=0; i<*n; i++) {
        for (int j=0; j<*n; j++)
            if(adjMatrix[i][j] == 1)
                adjMatrix_new[i][j] = 1;
    }
    
    deleteGraph(adjMatrix, *n);
    *n = u+1;
    return adjMatrix_new;
}
```

:framed_picture: diagram

![294917300_2315748295230545_409730532456031221_n](https://user-images.githubusercontent.com/86911299/187144711-b6ae569f-63a7-47df-8c33-400735100a9e.jpg)

### removeVertex(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Remove the existing vertex from the graph using adjacency-matrix representation
int** removeVertex(int** adjMatrix, int* n, int u)
{
    for (int i=0; i<*n; i++)
        for (int j=u; j<*n-1; j++)
            adjMatrix[i][j] = adjMatrix[i][j+1];

    for (int i=0; i<*n; i++)
        for (int j=u; j<*n-1; j++)
            adjMatrix[j][i] = adjMatrix[j+1][i];
    
    int** adjMatrix_new = createGraph(*n-1);
    for (int i=0; i<*n-1; i++)
        for (int j=0; j<*n-1; j++)
            adjMatrix_new[i][j] = adjMatrix[i][j];
    deleteGraph(adjMatrix, *n);
    (*n)--;
    return adjMatrix_new;
}
```

:framed_picture: diagram

![301368622_768510967697405_4969233872286942043_n](https://user-images.githubusercontent.com/86911299/187145211-10088122-de3a-4c75-9798-1b189e0067ec.jpg)

### isAdjacent(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// Check whether the two vertices are adjacent using adjacency-matrix representation
int isAdjacent(int** adjMatrix, int u, int v) {
    if(adjMatrix[u][v] == 1)
        return 1;
    else
        return 0;
}
```

:bulb:

=> ตรวจสอบว่าในกราฟNode U มีEdge ที่เชื่อมไปยังNode Vมั้ย

### inDegree(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Report the in-degree of the vertex using adjacency-matrix representation
int inDegree(int** adjMatrix, const int n, int u) {
    int in_deg = 0;
    for(int i=0; i<n; i++) {
        if(adjMatrix[i][u])
    }
    
    in_deg++;
    return in_deg;
}
```

:bulb:

=> นับinDegreeในเมทริกซ์

### outDegree(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Report the out-degree of the vertex using adjacency-matrix representation
int outDegree(int** adjMatrix, const int n, int u) {
    int out_deg = 0;
    for(int i=0; i<n; i++) {
        if(adjMatrix[u][i])
    }
    out_deg++;
    return out_deg;
}
```

:bulb:

=> นับoutDegreeในเมทริกซ์


## Basic Operations on Graphs Using Adjacency-List :page_with_curl:

![7 undirected-graph-and-its-adjacency-list](https://user-images.githubusercontent.com/86911299/187135617-b17b5607-5441-468b-82a4-795464377974.png)

### createGraph(n) :pencil2:

:desktop_computer: Example Code :

```
// Create the graph using adjacency-list representation
struct Node** createGraph(int n){
    // Return array of n lists (vectors)
    struct Node** adjList = malloc(sizeof(struct Node*)*n);
    for(int i=0; i<n; i++)
        adjList[i] = NULL;
    return adjList;
}
```

```
// Implementation of singly linked list
struct Node
{
    int adj_vertex;
    struct Node* next;
};
```

:framed_picture: diagram

![301200206_489249379682056_7696652362514550766_n](https://user-images.githubusercontent.com/86911299/187148708-a62fe917-bd2c-412a-860b-0d92165eab6b.jpg)

### addEdge(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// Add the edge to the graph using adjacency-list representation
void addEdge(struct Node** adjList, int u, int v)
{
    struct Node* node = adjList[u];
    if(node == NULL) {
        node = malloc(sizeof(struct Node));
        node->adj_vertex = v;
        node->next = NULL;
        adjList[u] = node;
    } 
    else {
        while(node->next != NULL)
            node =  node->next;
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->adj_vertex = v;
        new_node->next = NULL;
        node->next = new_node;
    }
}
```

:framed_picture: diagram

![301274456_1186954785196390_2905611500274096353_n](https://user-images.githubusercontent.com/86911299/187148977-dcf74354-097d-40bd-9193-103859f311a1.jpg)

### printGraph(G) :pencil2:

:desktop_computer: Example Code :

```
// Print the adjacency list representation of the graph
void printGraph(struct Node** adjList, int n)
{
    for (int u = 0; u < n; u++) {
        printf("[%d] head: ", u);
        struct Node* node = adjList[u];
        while(node) {
            printf("-> %d ", node->adj_vertex);
            node = node->next;
        }
        printf("-> NULL \n");
    }
}
```

:bulb:

=> แสดงผลเป็นarray list

### deleteGraph(G) :pencil2:

:desktop_computer: Example Code :

```
// Delete the adjacency list representation of the graph
void deleteGraph(struct Node** adjList, int n) {
    for (int u=0; u<n; u++) {
        struct Node* node = adjList[u];
        while(node != NULL) {
            struct Node* next_node = node->next;
            free(node);
            node = next_node;
        }
    }
    free(adjList);
}
```

:framed_picture: diagram

![300829472_2313725308802164_5524816136474978476_n](https://user-images.githubusercontent.com/86911299/187149509-d5c9dc0a-ecdd-47c8-9d81-551af2f03c01.jpg)

### removeEdge(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// Remove the existing edge from the graph usingadjacency-list representation
void removeEdge(struct Node** adjList, int u, int v) {
struct Node* node = adjList[u];
    if(node->adj_vertex == v) {
        adjList[u] = node->next;
        free(node);
    } 
    else {
        struct Node* prev_node = node;
        node = node->next;
        while(node->adj_vertex != v) {
            prev_node = node;
            node = node->next;
        }
        prev_node->next = node->next;
        free(node);
    }
}
```

:framed_picture: diagram

![301607906_442516194495765_7860557699702989996_n](https://user-images.githubusercontent.com/86911299/187151270-1794b949-5375-49ba-b8b6-af9d68a094a8.jpg)

### addVertex(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Add the new vertex to the graph graph using adjacency-list representation
struct Node** addVertex(struct Node** adjList, int *n, int u) {
struct Node** new_adjList = createGraph(u+1);
    for (int i=0; i<*n; i++) {
        new_adjList[i] = adjList[i];
        adjList[i] = NULL;
    }
    deleteGraph(adjList, *n);
    *n = u+1;
    return new_adjList;
}
```

:framed_picture: diagram

![301680506_1117037112219415_454473982634628465_n](https://user-images.githubusercontent.com/86911299/187152869-fd9a7e82-73da-4721-bd90-1f84d62f00aa.jpg)

### removeVertex(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Remove the existing vertex from the graph using adjacency-list representation
void removeVertex(struct Node** adjList, int *n, int u) {
    for(int v=0; v<*n; v++) {
        if(isAdjacent(adjList, v, u) == 1)
            removeEdge(adjList, u, v);
    }
    struct Node* node = adjList[u];
    while(node != NULL) {
        struct Node* next_node = node->next;
        free(node);
        node = next_node;
    }
    adjList[u] = NULL;
    if(u < *n-1)
        return;
    (*n)--;
}
```

:framed_picture: diagram

### isAdjacent(G , u , v) :pencil2:

:desktop_computer: Example Code :

```
// Check whether the two vertices are adjacent using adjacency-list representation
int isAdjacent(struct Node** adjList, int u, int v) {
    struct Node* node = adjList[u];
    int ret = 0;
    while(node != NULL) {
        if(node->adj_vertex == v)
            ret = 1;
        node = node->next;
    }
    return ret;
}
```

:bulb:

=> ตรวจสอบว่าในกราฟNode U มีEdge ที่เชื่อมไปยังNode Vมั้ย

### inDegree(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Report the in-degree of the vertex using adjacency-list representation
int inDegree(struct Node** adjList, int n, int u) {
int in_deg = 0;
    for(int i=0; i<n; i++) {
        struct Node* node = adjList[i];
        while(node) {
            if(node->adj_vertex == u)
                in_deg++;
            node = node->next;
        }
    }
    return in_deg;
}
```

:bulb:

=> นับinDegreeในลิส

### outDegree(G , u) :pencil2:

:desktop_computer: Example Code :

```
// Report the out-degree of the vertex using adjacency-list representation
int outDegree(struct Node** adjList, int n, int u) {
    struct Node* node = adjList[u];
    int out_deg = 0;
    while(node != NULL) {
        out_deg++;
        node = node->next;
    }
    return out_deg;
}
```

:bulb:

=> นับoutDegreeในลิส

## Adjacency-Matrix & Adjacency-List in CPP :page_with_curl:

![302328131_1120577528815248_9019764535738993268_n](https://user-images.githubusercontent.com/86911299/188323588-da47bdb8-3f6a-4e8a-b6c1-50bcd6133fee.jpg)

![301455089_1345123036314085_932035562219758730_n](https://user-images.githubusercontent.com/86911299/188323589-4047dfb3-e65d-46b4-8b37-e5c2947d49d2.jpg)

:desktop_computer: Example Code :

![302560553_1150196838865764_4975264800420144007_n](https://user-images.githubusercontent.com/86911299/188323832-2c6ed0f1-5944-401b-8584-aae7a4abb3de.jpg)

![303255338_827748288391768_9127950023376358735_n](https://user-images.githubusercontent.com/86911299/188323836-322b8a63-4d8b-49d1-9130-957a8fa13fa5.jpg)

![304059857_1459198041174552_4688866610571582193_n](https://user-images.githubusercontent.com/86911299/188323842-8ec5534c-130b-4945-b09f-2e99598de945.jpg)

![302636711_5429665437109682_5275908758022646124_n](https://user-images.githubusercontent.com/86911299/188323848-6bcee792-218f-45a0-8569-64f9ee3dd16f.jpg)

![302375727_487716366121246_2271269586617616449_n](https://user-images.githubusercontent.com/86911299/188323850-f8064bd4-aca8-45a9-acb9-a78890932771.jpg)

![304823820_3877283555728938_4066792446327116423_n](https://user-images.githubusercontent.com/86911299/188323853-6d63b3ff-fd96-49ba-b0eb-a61a5219a941.jpg)

![302387436_498103735654993_8847219171281872507_n](https://user-images.githubusercontent.com/86911299/188323855-7b706d10-653e-4a85-b101-7f58624d6497.jpg)

![301921379_527286325827029_5199123822761162371_n](https://user-images.githubusercontent.com/86911299/188323862-f92fb219-12b3-4e01-8d7d-41c02ceec897.jpg)

![302451466_2337451356409482_4544541740599774547_n](https://user-images.githubusercontent.com/86911299/188323865-4bdfcf82-b59c-4541-9b99-95145546c90c.jpg)


# Graphs Traversals :books:

https://www.tamemo.com/post/26/project-solution-tree-searching-dfs-bfs-step-by-step/

## Terminology About Graphs :page_with_curl:

- Path : [เส้นทาง] การเชื่อมต่อ ต่อเนื่องการระหว่าง Node กับ Edge สลับกัน โดยที่ จะมีจุดเริ่มต้นเป็นEdge จบที่Node และ Edgeระหว่างNodeไม่สามารถสลับกันได้ ต้องเป็น—Edge—>Node—Edge—>Node

- Cycle : [วงจร] จะมีEdgeในเส้นทางอย่างน้อย1Edge และจะเริ่มต้นที่Node(A) โดยที่ต้องกลับมาจบที่Node(A)

- Path's length : [ระยะ/ความยาวของเส้นทาง] จำนวนของจุดในเส้นทาง-1 / จำนวนเส้นเชื่อม

- Connected graph : [กราฟที่มีการเชื่อมต่อกันทุกๆจุดตัด] กราฟที่ทุกจุดมีเส้นทางเดินที่สามารถเดินทางไปถึงกันได้

- Connected components : [ส่วนประกอดของกราฟที่มีการเชื่อมต่อ] 

### Graphs Traversals :pencil2:

- Traverse : ไปท่องเที่ยวแบบไม่ซ้ำที่กัน 

- Graph traversal : การท่องไปในกราฟที่ประจุดเยี่ยมชมคือNode และเส้นทางคือEdges

### Maze Exploration :pencil2:

:framed_picture: Maze Exploration Motivation 

![305371341_896990881268283_4656080646892464186_n](https://user-images.githubusercontent.com/86911299/189430553-cd858901-da9d-4e53-adcc-ba3a8b5b02e9.jpg)

:framed_picture: Maze Exploration Problem 

![305182374_798147724548720_2596956639497721890_n](https://user-images.githubusercontent.com/86911299/189430742-3329d40d-c9d1-47ce-a46e-a0cf87ce46d8.jpg)

### Tremaux's Algorithm :pencil2:

Tremaux Algorithm : การเอาเชือกมาผูกกับตัวเอง และหลักที่จุดเริ่มต้นละเดินไปเรื่อยๆ จนกว่าจะครบทุกทาง โดยการทำสัญลักษณ์ไว้ 
ละเชือกสามารถพาเรากลับมาที่จุดเริ่มต้นละเดินไปอีกเส้นทางที่ไม่ซ้ำกันได้อีกครั้ง 
1. เลือกเส้นทางละเดินไป ทำสัญลักษณ์ไว้  ที่ intersection , passage
2. ถ้าไปต่อได้ให้ไปต่อเรื่อนๆละทำสัญลักษณ์ไว้ 
3. ถ้าไม่ไป หรือdead end ให้ย้อนกลับมาหาเส้นทางใหม่ จนกว่าจะครบทุกpath

:framed_picture: Tremaux's Algorithm

![305885105_3213938818849460_3053376877236656895_n](https://user-images.githubusercontent.com/86911299/189430788-865abb6a-0c29-4193-b807-083c5a226b01.jpg)

## Depth-First Search/Traversal [DFS] :page_with_curl:

Depth first search [DFS] : การค้นหาแบบลึกก่อน เป็นการค้นหาที่กําหนดทิศทางจากรูปของโครงสร้างข้อมูล ที่เริ่มต้นจากโหนดที่อยู่บนสุด 
แล้วเดินลงมาให้ลึกที่สุด เมื่อถึงโหนดล่างสุด(Terminal node) ให้ย้อนขึ้นมาที่จุดสูงสุด หาโหนดที่ยังไม่ได้ไป แล้วเริ่มเดินลงจนถึงโหนดลึกสุดอีก 
ทําสลับไปเรื่อยจนพบโหนดที่ต้องการหาหรือสํารวจครบทุกโหนดแล้ว การค้นหาแบบลึกก่อนจะมีลําดับการเดิน ตามโหนดดังตัวเลขที่กํากับไว้ในแต่ละโหนด.

### Undirected graph :pencil2:

:framed_picture: Example

![1_eyqACQAziXkSuMNmMeTa6A](https://user-images.githubusercontent.com/86911299/189434623-a498d6ee-829e-4d08-8c74-e2562ec29d12.png)

```
DFS-init(s, adjList):
    visited = {}
    DFS-visit(s, adjList, visited)
```

```
DFS-visit(s, adjList, visited):
    visited = visited U {s}
    for v in adjList[s]:
        if v not in visited:
            DFS-visit(v, adjList, visited)
```

```
DFS-explore(V, adjList):
    visited = {}
    for s in V:
        if s not in visited:
            DFS-visit(s, adjList, visited)
```

### DFS's Complexity :pencil2:

![305166529_637552407929442_3353291991800212249_n](https://user-images.githubusercontent.com/86911299/189430928-cc5373cc-f043-4801-86e8-75ea9b7abee5.jpg)

### DFS Implementation In CPP :pencil2:

:desktop_computer: Example Code :

```
// C++ program to print DFS traversal from a given vertex in a given graph
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a undirected graph using adjacency list representation
class Graph{
    int V; 
    // No. of vertices

    list<int> *adj; 
    // Pointer to an array containing adjacency lists

    void DFSVisit(int s, bool visited[]); 
    // A recursive function used by DFS

public:
    Graph(int V); 
    // Constructor
    
    void addEdge(int v, int w); 
    // Function to add an edge to graph
    
    void DFSInit(int s); 
    // DFS traversal of the vertices reachable from s
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
    // Add w to v’s list

    adj[w].push_back(v); 
    // Add v to w’s list
}

void Graph::DFSVisit(int s, bool visited[])
{
    // Mark the current node as visited and print it
    visited[s] = true;
    cout << s << " ";

    // Recurse for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFSVisit(*i, visited);
}

// DFS traversal of the vertices reachable from v
void Graph::DFSInit(int s){
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to print DFS traversal
    DFSVisit(s, visited);
}
```

:keyboard: Main

```
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFSInit(2);
    return 0;
}
```

:printer: Output

```
Following is Depth First Traversal (startingfrom vertex 2)
2 0 1 3
```

:bulb: 

=>

## Breath-First Search/Traversal [BFS] :page_with_curl:

Breadth-first search [BFS] : เป็นขั้นตอนการหาข้อมูลทั้งหมด ที่โหนดบนสุดของกราฟและทำการสำรวจโหนดของเพื่อนบ้าน 
เป็นการกําหนดทิศทางการค้นหาแบบทีละระดับของโครงสร้างข้อมูล 

- โดยเริ่มจาก(ระดับที่ 0) แล้วลงมาระดับที่ 1 จากซ้ายไปขวา เมื่อเสร็จระดับที่ 1 ไประดับที่ 2จากซ้ายไปขวาเช่นกัน 
ทําไปเรื่อยๆจนพบโหนดที่ต้องการตาม ลําดับการเดินทางของโหนดเป็นไปตามหมายเลขที่กํากับไว้บนโหนด

### Undirected graph :pencil2:

:framed_picture: Example

![305767698_1539323129854123_8453918063843371850_n](https://user-images.githubusercontent.com/86911299/189431524-24456110-7f26-4631-a983-483e5e309ebd.jpg)

```
BFS-visit(s, adjList, visited = {}):
    visited = visited U {s}
    L0 = {s}
    i = 0

    while Li is not empty:
        Li+1 = {}
        for each u in Li:
            for each v in adjList[u]:
                if v is not in visited:
                    visited = visited U {v}
                Li+1 = Li+1 U {v}
        i = i+1
```

```
BFS-explore(V, adjList):
    visited = {}
    for each s in V:
        if s not in visited:
            BFS-visit(s, adjList, visited)
```

:framed_picture: Example

![305351946_638023474538690_3859810982605578959_n](https://user-images.githubusercontent.com/86911299/189431245-e672a8a4-726b-4b31-8375-5d222ea6fb57.jpg)

### BFS's Complexity :pencil2:

![305079078_392675029611438_7130839251589605808_n](https://user-images.githubusercontent.com/86911299/189430938-432042e2-1d16-4b61-8767-b42e7bd90466.jpg)

### BFS Implementation In CPP :pencil2:

:desktop_computer: Example Code :

```
// C++ program to print BFS traversal from a given vertex in a given graph
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a undirected graph using adjacency list representation
class Graph{
    int V; 
    // No. of vertices
    
    list<int> *adj; 
    // Pointer to an array containing adjacency lists

public:
    Graph(int V); 
    // Constructor
    
    void addEdge(int v, int w); 
    // Function to add an edge to graph

    void BFSVisit(int s); 
    // BFS traversal of the vertices reachable from s
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); 
    // Add w to v’s list
    
    adj[w].push_back(v); 
    // Add v to w’s list
}


// BFS traversal of the vertices reachable from s
void Graph::BFSVisit(int s){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent vertices of a vertex u
    list<int>::iterator i;
    int u;

    while(!queue.empty()){
        // Dequeue a vertex from queue and print it
        u = queue.front();
        cout << u << endl;
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex u. If a adjacent has not been visited, then mark it visited and enqueue it
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
```


:keyboard: Main

```
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    cout << "Following is Breath-First Traversal (starting from vertex 0) \n";
    g.BFSVisit(0);
    return 0;
}
```

:printer: Output

```
Following is Breath-First Traversal (starting from vertex 0)
0
1
2
3
```

:bulb:

=>


### BFS's Properties :pencil2:

![304843285_557983376110206_8745328850935854464_n](https://user-images.githubusercontent.com/86911299/189431366-4bc45a55-72ff-4409-abca-d695ef7a97d8.jpg)

## Application :page_with_curl:

- Test whether there is a path from one vertex to another

:bulb: Because

=>

- Test whether a graph is connected

:bulb: Because

=>

- Test whether a graph has a cycle

:bulb: Because

=>

![302177417_572313191245872_5283596151075159324_n](https://user-images.githubusercontent.com/86911299/188324640-b7082699-f50b-48a6-89b7-bf629070509c.jpg)

![304309029_3249804065287716_1981574995862492039_n](https://user-images.githubusercontent.com/86911299/188324645-11a66fae-f41b-43ca-9d38-0a4e28fab9d7.jpg)

![304191992_489229662601005_1928407008652570236_n](https://user-images.githubusercontent.com/86911299/188324647-a1415ed6-3c9e-4f00-9a28-80940828a7ee.jpg)

# Trees :books:

Trees : ต้นไม้ที่ไม่มีวงจร / ไม่มีnodeเดิมที่เคยเชื่อมกันแล้ววนกลับมาเชื่อมกันอีก `non-linear`
Tree เป็นโครงสร้างข้อมูลที่สามารถสร้าง`algorithms`ที่รันได้เร็วกว่าโครงสร้างข้อมูลแบบ`linear` ; ไม่สามารถที่จะใช้การลำดับชั้นของข้อมูลได้
    เช่น GUI , database , websites , etc

*Terminology of Tree*

- hierarchical : เป็บการเรียงลำดับชั้นว่าnodeไหนมาก่อนหรือมาหลัก `จะมีก็ต่อเมื่อต้นไม้มีroot`

- above : บน สูงกว่า

- below : ล่าง ต่ำกว่า

- Parent : พ่อ แม่ ผู้ปกครอง

- Child / Children : ลูก

- Ancestor : ปู่ ย่า ตา ย่า บรรพบุรุษ

- Descendant : ทายาท

- Siblings : พี่ น้อง [same Parent]

## Free Trees :page_with_curl:

:framed_picture: Tree

![640px-Tree_graph svg](https://user-images.githubusercontent.com/86911299/189417431-088c1c7c-64c2-47ed-a218-d4f7867548d5.png)

Free Trees / Tree : `Connected Undirected graph ; no cycle` ไม่มีลำดับชั้น [Hierarchical] เพราะไม่มี root
สามารถใช้โครงสร้างสำหรับกราฟได้ เช่น adjency-matrix , adjency-list

### Linked Structure :pencil2:

:framed_picture: Linked Structure for General Trees

![303024281_596815575495329_3331920471558427297_n](https://user-images.githubusercontent.com/86911299/189418278-34644150-a226-45a9-acef-2003531ff52e.jpg)

## Rooted Trees :page_with_curl:

Rooted Trees : ต้นไม้ที่กำหนด`root`มาด้วยซึ่งrootเนี่ยก็จะเป็นnodeแต่มีความพิเศษมากกว่าnodeอื่นๆ [Distinguished] ; จะnodeที่ไม่มี parent

- Root : จะอยู่บนสุด หรือถ้าnodeนั้นๆเป็นrootแต่ไม่อยู่บนสุดของกราฟก็สามารถปรับให้อยู่บนสุดได้ 
ดังนั้น เมื่อรู้ว่าต้นไม้ของเรามีรากอยู่ที่ไหนก็จะเกิดลำดับชั้นขึ้น 

### Rooted Tree Terminology :pencil2:

:framed_picture: Rooted Tree

![304980343_476216744150921_4536461395199997503_n](https://user-images.githubusercontent.com/86911299/189420818-1e441e2e-8f6a-4308-bb9e-01756e5a9221.jpg)

- Ancestor : เส้นทางที่จะเดินทางจาก `root => x_Node` 
    => x_Node = 9 ; Ancestor's X = 7 , 3 , 8 , 5 , 9 [r to x]

- Descendant : ถ้า y_Node Ancestor's X ; จะทำให้x_Nodeเป็นDescendantของy_Node
    => y_Node = 8 ; Descendant's Y = 8 , 6 , 5 , 9

*ทุกNodeจะเป็น Ancestor & Descendant ของตัวมันเอง*

- Subtree rooted at x : ถ้ากำหนดNodeใดๆในต้นไม้เป็นroot จะเกิดเป็นต้นไม้ย่อยอยู่ในต้นไม้ทั้งหมด
    => Subtree rooted at 4 ; ในต้นไม้ย่อยของรากที่4 มีNode = 11 , 2

- Parent : Node / Rootที่มีNodeต่อมาจากNodeของตัวเอง
- Child / Children : Node ที่มีRoot หรือ Nodeก่อนหน้า
- Siblings : same Parent
    => 3 Parent's 12 , 8
    => 12 Child's 3
    => 8 Child's 3
    => 12 , 8 are Sibling

- Leaf / External Node : Node ที่ไม่มี child
    => Leaf / External Node = 1 ,6 , 9 , 10 , 11 , 2

- Internal Node : Node ที่มี child
    => Internal Node = 7 , 3 , 4 , 12 , 8 , 5

- degree : จำนวนchildrenของnodeนั้นๆ 
    => 3_Node = 2 degree ; 8 , 12

- depth : ระยะห่างของNodeนั้นๆ ไปสู่Root 
    => 9_Node = depth 4
    => 4_Node = depth 1

- level : ทุกNodeที่อยู่ในdepthเดียวกัน
    => level 2 = 8 , 12 , 11 , 2 

- height : ความสูงของต้นไม้จะนับจากNodeไปจนถึงLeafที่อยู่ต่ำสุด ; ระยะความสูงของต้นไม้จะเท่ากับdepthที่ห่างจากrootที่สุด
    => height = 4

### Linked Structure :pencil2:

### Basic Operation [Create] :pencil2:

## Ordered Trees :page_with_curl:

:framed_picture: Ordered Trees

![305460783_606495461180205_4159149470554621444_n](https://user-images.githubusercontent.com/86911299/189425163-cad0dff2-6dcc-4ca4-96e4-3b768403ea61.jpg)

Ordered Trees : ต้นไม้ที่มีลำดับชั้นในแนวราบ จะต้องมีลำดับของลูก เช่น ถ้าเป็นFamily Tree จะต้องเรียงลำดับของลูกคนโต คนกลาง คนเล็ก ...

### Basic Operation [createRoot(r,T)] :pencil2:

### Basic Operation [createNode(u,p,T)] :pencil2:

### Basic Operation [getParent(u,T)] :pencil2:

### Basic Operation [getChild(u,k,T)] :pencil2:

### Basic Operation [isRoot(u,T)] :pencil2:

### Basic Operation [isExternal(u,T)] :pencil2:

### Basic Operation [depth(u,T)] :pencil2:

### Basic Operation [height(T)] :pencil2:

### Complexity of Operations :pencil2:

# Tree Traversals :books:

## Preorder Traversal :page_with_curl:

### Pseudicode (Root , Left , Right) :pencil2:

## Postorder Traversal :page_with_curl:

### Pseudicode (Root , Left , Right) :pencil2:

# Binary Tree :books:

# Binary Search Trees :books:

# Balanced Binary Search Trees :books:

# Disjoint-set Data Structure :books:

# Terminology about Graphs :books:

## Basic Graph Terminology [01] :page_with_curl:

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