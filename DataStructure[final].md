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

![300458377_773615790516572_5383199367535091922_n](https://user-images.githubusercontent.com/86911299/187029447-40e502d3-767f-425e-8f1f-b5cb737398ec.jpg)

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

# Graphs Traversals :books:

# Trees :books:

# Tree Traversals :books:

# Binary Tree :books:

# Binary Search Trees :books:

# Balanced Binary Search Trees :books:

# Disjoint-set Data Structure :books:
