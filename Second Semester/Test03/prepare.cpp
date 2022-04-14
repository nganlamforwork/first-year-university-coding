#include <iostream>
#include <fstream>
using namespace std;

struct NODE{
    string name = "";
    double square = 0;
    int people = 0;
    NODE* next = nullptr;
};
struct City{
    NODE* head = nullptr;
    NODE* tail = nullptr;
};
void printList(int **A, int s)
{
    for (int i=0;i<s;i++){
        for (int j=0;j<s;j++)
            cout<<A[i][j]<<' ';
        cout<<'\n';
    }
}
int** createSumMatrix(int **A, int s)
{
    int **ans = new int*[s];
    for (int i=0;i<s;i++)
        ans[i]=new int[s];
    for (int i=0;i<s;i++)
        for (int j=0;j<s;j++)
            ans[i][j]=A[i][j]+A[i][j+s]+A[i+s][j]+A[i+s][j+s];
    return ans;
}
int count1(int n, int m, int max)
{
    if (n==0) return 1;
    if (n<m) return 0;
    int sum=0;
    for (int i=m;i<=max;i++)
        sum+=count1(n-i,m,i);
    return sum;
}

NODE* createNode(string name, double square, int people)
{
    NODE* p = new NODE;
    p->name=name;
    p->square=square;
    p->people=people;
    p->next=nullptr;
    return p;
}
void addTail(City &city, string name, double square, int people)
{
    NODE* p=createNode(name,square,people);
    if (city.head==nullptr){
        city.head=city.tail=p;
        return;
    }
    city.tail->next=p;
    city.tail=p;
}
City readFile()
{
    ifstream in("Cities.txt");

    City city;

    string name;
    double square;
    int people;

    while (!in.eof()){
        getline(in,name,','); in.ignore();
        in>>square; in.ignore();
        in>>people; in.ignore();

        addTail(city,name,square,people);
    }
    in.close();
    return city;
}

void printCities(City C)
{
    NODE* p = C.head;
    while (p!=nullptr){
        cout<<p->name<<'\n';
        p=p->next;
    }
}

void removeCity (City C, int X)
{
    NODE* curGreater=nullptr;

    NODE* p=C.head;
    if (C.head==nullptr) return;
    if (C.head->people>X) curGreater=C.head;

    while (p!=nullptr && p->next!=nullptr){
        if (p->next->people>X)
            curGreater=p;
        p=p->next;
    }

    NODE* tmp=curGreater->next;
    curGreater->next=curGreater->next->next;
    delete tmp;
}
int main()
{
//    int n=2;
//    int **a = new int*[2*n];
//    for (int i=0;i<2*n;i++)
//        a[i]=new int[2*n];
//
//    for (int i=0;i<2*n;i++)
//        for (int j=0;j<2*n;j++)
//            cin>>a[i][j];
//
//    int **ans = createSumMatrix(a,n);
//    printList(ans,n);
//    cout<<count1(6,1,6);
    City city = readFile();
    removeCity(city,1191380);
    printCities(city);
    return 0;
}
