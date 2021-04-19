#include <iostream>
#define MAX 107
#define NOT_CONNECTED -1

int distance[MAX][MAX];
int nodesCount;

void Initialize1(){
    for (int i=0;i<MAX;++i){
        for (int j=0;j<MAX;++j){
            distance[i][j]=NOT_CONNECTED;
        }
        distance[i][i]=0;
    }
}



// 1) Метод сортування : вставками (для матрицi)

void InsertSort(double **a, int s1, int s2) {
 
 
    int tmp = 1;
 
    for (int o = 1; o <=s1; o++) {
 
        for (int i = 1; i <=s2; i++) {
            for (int j = i; j >1 && a[o][j - 1] > a[o][j]; j--) {
                //swap(a[o][j - 1], a[o][j]);
                tmp = a[o][j - 1];
                a[o][j - 1] = a[o][j];
                a[o][j] = tmp;
            }
        }
    }
}
void SortArr(double **a, int s1, int s2) {
 
    int j = s2;
    int tmp = 0;
 
    for (int l = 1; l <= s1*s2; l++) {
        InsertSort(a, s1, s2);
 
        for (int i = 1; i <=s1; i++) {
 
            if (i < s1 - 1) {
                if ((a[i][j - 1] > a[i + 1][0])) {
                    tmp = a[i][j - 1];
                    a[i][j - 1] = a[i + 1][0];
                    a[i + 1][0] = tmp;
                    //swap(a[i][j - 1], a[i + 1][0]);
                }
            }
        }
    }
}

// 1) Метод сортування : вставками
void Sort(int* arr,int n){
    for(int i=1;i<n;i++){
        for(int j=i; j>0 && arr[j-1]>arr[j];j--){
            int tmp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=tmp;
        }
    }
    
}

void showSort(double **ss,int num){
    int* max = new int[MAX];
    int j=0;
    for(int i=1;i<=nodesCount;i++){
        max[j]=ss[i][nodesCount];
        j++;
    }
    Sort(max,j);
    for(int m =0; m<nodesCount;m++){
        for(int i=1;i<=nodesCount;i++){
            for(int j=1;j<=nodesCount;j++){
                       if(max[m]==distance[i][j]){
                        std::cout<<"("<<i<<","<<j<<")"<<std::endl;
                           
                }
            }
        }
    }
}



// 1)Вивести вершини графу, відсортовані за кількістю вихідних ребер.
void taskFirst(){
    scanf("%d", &nodesCount);
    int m;
    scanf("%d", &m);
    int d = m;
    int i =0;
    int a,b,c{0};
    while(m!=0){
        bool tmp = true;
        std::cin>>a>>b;
        while(tmp){
        std::cin>>c;
        if(c <=m ){
            tmp = false;
        }
         else{
             std::cout<<"Error"<<std::endl;
             tmp = true;
         }
        }
        distance[a][b]=c;
        i++;
        m=m-1;
    }
    double **ss = new double*[MAX];
    for (int i = 1; i <=nodesCount; i++)
            ss[i] = new double[nodesCount];
    
    for(int i=1;i<=nodesCount;i++){
        for(int j=1;j<=nodesCount;j++){
            ss[i][j]=distance[i][j];
        }
    }
    SortArr(ss,nodesCount,nodesCount);
    showSort(ss, d);

    for (int i = 0; i < nodesCount; i++)
           delete[] ss[i];
       delete[] ss;

}



// 2) Метод сортування : бульбашкою
int* bubbleSort( int* arr,int size){
    int temp;
     for (int i = 0; i < size - 1; i++) {
         for (int j = 0; j < size - i - 1; j++) {
             if (arr[j] > arr[j + 1]) {
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
             }
         }
     }
    return arr;
}
// 2) Вивести вершини графу, відсортовані за сумою довжин вихідних ребер.
void taskSecond(){
    scanf("%d", &nodesCount);
    int m;
    scanf("%d", &m);
    int a,b,c{0},sum{0},num{0},i{0};
    int *arr;
    while(m!=0){
        bool tmp = true;
        std::cin>>a>>b;
        while(tmp){
        std::cin>>c;
        if(c <=m ){
            tmp = false;
        }
         else{
             std::cout<<"Error"<<std::endl;
             tmp = true;
         }
        }
         sum =0;
        while(c!=0){
            num=0;
            std::cin>>num;
            sum+=num;
            c--;
        }
        std::cout<<"sum : "<<sum<<std::endl;
        distance[a][b]=sum;
        arr[i]=sum;
        i++;
        m=m-1;
    }
    bubbleSort(arr,nodesCount);
    for(int m =0; m<nodesCount;m++){
        for(int i=1;i<=nodesCount;i++){
            for(int j=1;j<=nodesCount;j++){
                       if(arr[m]==distance[i][j]){
                        std::cout<<"("<<i<<","<<j<<")"<<std::endl;
                           
                }
            }
        }
    }
    
}


// 3) Метод сортування : перемiшуванням
int* movingSort(int* arr,int size){
    int buff;
        int control=size;
        int left = 0;
        int right = size - 1;
        do {
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i + 1]) {
                    buff = arr[i];
                     arr[i] = arr[i + 1];
                    arr[i + 1] = buff;
                    control=i;
                }
            }
            right=control;
            for (int i = right; i > left; i--) {
                if (arr[i] < arr[i - 1]) {
                    buff = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = buff;
                    control=i;
                }
            }
            left=control;
        } while (left < right);
    return arr;
}

/* 3) Вивести вершини графу, відсортовані за функцією від координат. Функція
передається в якості аргументу.*/
void taskThird(){
    scanf("%d", &nodesCount);
    int m;
    scanf("%d", &m);
    
    int a,b,c{0},i{0};
    int arr[nodesCount];
    while(m!=0){
        std::cin>>a>>b;
        c = a+b;
        distance[a][b]=c;
        arr[i]=c;
        i++;
        m=m-1;
    }
    movingSort(arr, nodesCount);
    for(int m =0; m<nodesCount;m++){
        for(int i=1;i<=nodesCount;i++){
            for(int j=1;j<=nodesCount;j++){
                       if(arr[m]==distance[i][j] && arr[m]==i+j){
                        std::cout<<"("<<i<<","<<j<<")"<<std::endl;
                           
                }
            }
        }
    }
    
}


// 4) Метод сортування : швидке
int* QuickSort (int Array[], /* масив для сортування */
        unsigned int N, /* розмір масиву */
        int L, /* ліва межа сортування */
        int R) /* права межа сортування */
{
    int iter = L ,
        jter = R ;
    
    int middle = (R+L)/2 ;
    
    int x = Array [middle] ;
    int w ;
    
    do
    {
        while (Array[iter]<x)
        { iter ++ ; }
 
        while (x<Array[jter])
        { jter -- ; }
 
        if (iter<=jter)
        {
           w = Array [iter];
           Array [iter] = Array [jter] ;
           Array [jter] = w ;
           
           iter ++ ;
           jter -- ;
        }
    }
    while (iter<jter) ;
    
    if (L<jter)
    { QuickSort (Array, N, L, jter) ; }
    
    if (iter<R)
    { QuickSort (Array, N, iter, R) ; }
    return Array;
}

// 4) Вивести ребра графу, відсортовані за довжиною.
void taskForth(){
    scanf("%d", &nodesCount);
    int m;
    scanf("%d", &m);
    int a,b,c{0},sum{0},num{0},i{0};
    int *arr;
    while(m!=0){
        bool tmp = true;
        std::cin>>a>>b;
        while(tmp){
        std::cin>>c;
        if(c <=m ){
            tmp = false;
        }
         else{
             std::cout<<"Error"<<std::endl;
             tmp = true;
         }
        }
        distance[a][b]=c;
         sum =0;
        while(c!=0){
            num=0;
            std::cin>>num;
            arr[i]=num;
            i++;
            c--;
        }
        m=m-1;
    }
    QuickSort(arr, nodesCount, 0, nodesCount-1);
    for (int i =0; i<nodesCount; i++)
      { std::cout << arr[i] << " " ; }
      std::cout << std::endl ;
}
// 5) Метод сортування : Злиттям

void merge(int* arr,int l,int r){
    if (r == l)
    return;
    if ((r-l)==1) {
    if (arr[r] < arr[l])
    std::swap(arr[r], arr[l]);
    return;
    }
    int m = (r + l) / 2;
    merge(arr,l, m);
    merge(arr,m + 1, r);
    int buf[nodesCount];
    int xl = l;
    int xr = m + 1;
    int cur = 0;
    while (r-l + 1 != cur) {
    if (xl > m)
    buf[cur++] = arr[xr++];
    else if (xr > r)
    buf[cur++] = arr[xl++];
    else if (arr[xl] > arr[xr])
    buf[cur++] = arr[xr++];
    else buf[cur++] = arr[xl++];

    }
    for (int i = 0; i < cur; i++)
    arr[i + l] = buf[i];
}
/*
  5)
 Вивести ребра графу, відсортовані за за функцією від координат середини ребра.
 Функція передається в якості аргументу.
 */

int  middleOfVector(int x1, int x2){
    int num=0;
    num = (x1+x2)/2;
    return num;
}

void taskFifth(){
    scanf("%d", &nodesCount);
    int m;
    scanf("%d", &m);
    int a,b,c{0},arr1[nodesCount];
    int i =0;
    int arr[nodesCount];
    while(m!=0){
        bool tmp = true;
        std::cin>>a>>b;
        arr1[i]=a;
        i++;
        while(tmp){
        std::cin>>c;
        if(c <=m && c==1 ){
            tmp = false;
        }
         else{
             std::cout<<"Error"<<std::endl;
             tmp = true;
         }
        }
        distance[a][b]=c;
        m=m-1;
    }
    for(int i =0;i<nodesCount;i++){
        arr[i]=middleOfVector(arr1[i], arr1[i+1]);
    }
    merge(arr,0, nodesCount-1);
    for(int i =0;i<nodesCount;i++){
        std::cout<<arr[i]<<" ";
    }
}
// 6) метод сортування : Шелла
void shellSort(int *arr, int size){
    for(int s=size/2; s>0; s/=2){
        for(int i=0; i<size; i++){
            for(int j=i+s; j<size; j+=s){
                if(arr[i] > arr[j]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}

// 6) Вивести всі цикли довжини три, відсортовані за площею трикутника.




int vectorLong(int x,int y){
    int num = sqrt(pow(x,2)+pow(y,2));
    return num;
}

int square(int a,int b,int c){
    int P;
    int S;
    P = (a + b + c) / 2.0;
        S = sqrt(P * (P - a) * (P - b) * (P - c));
    return S;
}


const int NE = 8, NV = 5;
int g[NE][2] = { { 0,1 },{ 1,2 },{ 2,3 },{ 3,0 },{ 4,0 },{ 1,4 },{ 4,2 },{ 3,4 } },
p[NE][2] = { { 0,0 }, { 0,0 }, { 0,0 }, {0,0}, {0,0}, {0,0}, {0,0} };

int color[NV] = {0,0,0,0,0};
int from = 0, n = 0, k = 0;
int* arr;
void dfs(int v)
{
    int count=0;
    int num[10];
    int s =0;
    n++;
    static int to;
    color[v] = 1;
    for (int i = 0; i < NE; i++)
    {
        if (g[i][0] == v)
        {
            to = g[i][1];
            if (color[to] == 0)
            {
                p[n][0] = g[i][0]; p[n][1] = g[i][1];
                from = v;
                dfs(to);
                while (p[n][1] != v)
                    n--;
                n++;
            }
            else if (color[to] == 1 && p[n-2][0]==to)
            {
 
                p[n][0] = g[i][0]; p[n][1] = g[i][1];
                k = n;
                while (p[k][0] != to)
                {
                   std:: cout << p[k][0]<< '-' << p[k][1] << ' ';
                    num[s]=p[k][0];
                    s++;
                    num[s]=p[k][1];
                    s++;
                    k--;
                }
               std:: cout << p[k][0] << '-' << p[k][1] << ' ' << std::endl;
                num[s]=p[k][0];
                s++;
                num[s]=p[k][1];
                s++;
                count++;
            }
        }
       
    }
    if (v == 0) color[v] = 2;
    else
        if (color[from] == 1)
          color[v] = 0;
       else color[v] = 2;
    if(count==1){
        int sq=0;
        sq= square(vectorLong(num[0], num[1]), vectorLong(num[2], num[3]), vectorLong(num[4], num[5]));
           std::cout<<"Ploshad : "<<sq<<std::endl;
    }
    std::cout<<std::endl;
 
}



void taskSixth(){
    for (int i = 0; i < NV; i++)
            if (color[i] == 0)
               dfs(i);
       std:: cout <<std::   endl;
}


int main(){
   // Initialize1();
    //taskFirst();
   // taskSecond();
    //taskThird();
    //taskForth();
   // taskFifth();
   taskSixth();
    
   
    return 0;
}
