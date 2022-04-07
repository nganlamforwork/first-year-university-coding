#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
struct People{
    string name;
    int height,weight;
};
void printPeople(People people[], int &n)
{
    n=0;
    ifstream inp("people.txt");
    string s, tmpHeight, tmpWeight;
    while (!inp.eof()){
        getline(inp,s);
        stringstream ss(s);
        getline(ss,people[n].name,'-');
        getline(ss,tmpHeight,'-');
        getline(ss,tmpWeight,'-');

        people[n].height = atoi(tmpHeight.c_str());
        people[n].weight = atoi(tmpWeight.c_str());

        ++n;
    }
    --n;
    for (int i=0;i<n;i++)
        cout<<people[i].height<<'-'<<people[i].name<<'-'<<people[i].weight<<'\n';
    inp.close();
}
string getLastName(string x)
{
    stringstream ss(x);
    string ans;
    while (ss>>ans);
    return ans;
}
void Swap(People &x, People &y)
{
    People tmp=x;
    x=y;
    y=tmp;
}
void sortPeople(People people[],int n)
{
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (people[j].height>people[i].height)
                Swap(people[j],people[i]);
            else
                if (people[j].height==people[i].height && getLastName(people[j].name)>getLastName(people[i].name))
                    Swap(people[j],people[i]);
    for (int i=0;i<n;i++)
        cout<<people[i].height<<'-'<<people[i].name<<'-'<<people[i].weight<<'\n';
}
void calculateWeight(People people[], int n, int&nLess, int&nMore, int*&less, int*&more)
{
    for (int i=0;i<n;i++)
        if (people[i].weight>90)
            more[nMore++]=people[i].weight;
        else if (people[i].weight<60)
            less[nLess++]=people[i].weight;
}
int main()
{
    People people[10001];
    int* less, * more;
    less = new int [10001];
    more = new int [10001];
    int n=0,nLess=0, nMore=0;

    printPeople(people,n);
    cout<<"----\n";

    sortPeople(people,n);
    cout<<"----\n";

    calculateWeight(people,n,nLess,nMore,less,more);
    for (int i=0;i<nLess;i++)
        cout<<less[i]<<' ';
    cout<<"\n----\n";
    for (int i=0;i<nMore;i++)
        cout<<more[i]<<' ';
    return 0;
}
