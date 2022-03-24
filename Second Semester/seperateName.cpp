#include <iostream>
#include <ctime>
#include <string>
#include <string.h>

using namespace std;
void input(char a[10][1000], int &n, const int SIZE)
{
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++)
        cin.getline(a[i],SIZE);
}
void output(char a[10][1000], const int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<'\n';
}
void solution1(char a[1000])
{
    int cnt = 0;
    while (a[strlen(a)-1]!=' '){
        char tmp=a[strlen(a)-1];

        //Shift Right
        for (int i=strlen(a)-1;i>0;i--)
            a[i]=a[i-1];

        a[0]=tmp;
        ++cnt;
    }

    char *tmp = new char[strlen(a)];
    strcpy(tmp,a+cnt);
    *(a+cnt)=' ';
    *(a+cnt+1)='\0';
    strcat(a,tmp);
}
void solution2(char a[1000])
{
    int i = strlen(a)-1, cnt=0;
    while (a[i]!=' ')
        --i,++cnt;
    char *firstName = new char[strlen(a)];
    strcpy(firstName,a+i+1);
    strcat(firstName," ");
    *(a+i)='\0';
    strcat(firstName,a);

    char *tmp = new char[strlen(a)];
    strcpy(tmp,a);
    strcpy(a,firstName);
    strcpy(firstName,tmp);
}
void sortArr(char a[10][1000],int n)
{
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (strcmp(a[i],a[j])>0){
                char *tmp = new char[strlen(a[i])];
                strcpy(tmp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],tmp);
            }
}
int main()
{
    char a[10][1000];
    int SIZE = 1000;
    int n;
    input(a,n,SIZE);
    for (int i=0;i<n;i++)
        solution2(a[i]);
    sortArr(a,n);
    output(a,n);
    return 0;
}
