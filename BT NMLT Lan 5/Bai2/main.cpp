#include <iostream>
#include <string>
#include <string.h>

using namespace std;
void reverseCharArray(string a){
    for (int i=(int)a.size()-1;i>=0;i--)
        cout<<a[i];
}
int checkSymmetricArray(string a){
    for (int i=0;i<=((int)a.size()-1)/2;i++)
        if (a[i]!=a[a.size()-1-i]) return 0;
    return 1;
}
int countOccurrencesChar(string a, char c){
    int cnt=0;
    for (int i=0;i<(int)a.size();i++)
        if (a[i]==c) cnt++;
    return cnt;
}
int findMostFrequentChar(string a, char &chr){

}
void insertCharAtPosition(string str, char chr, int pos){
    //str.insert(pos,chr);
    str+=str[str.size()-1];
    for (int i=str.size()-2;i>pos;i--)
        str[i]=str[i-1];
    str[pos]=chr;
    cout<<str;
}
int main()
{
    int n;
    string ch;
    cin>>ch;
    insertCharAtPosition(ch,'*',4);
    return 0;
}
