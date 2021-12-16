#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> a;
int sortListName(char input[])
{
    ifstream in;
    in.open(input);

    int n;
    string name;

    in>>n;
    for (int i=1;i<=n;i++){
        in>>name;
        a.push_back(name);
    }
    sort(a.begin(),a.end());
    cout<<"Danh sach ten thi sinh sau khi sap xep la:\n";
    for (int i=0;i<n;i++)
        cout<<a[i]<<'\n';

}
int main()
{
    sortListName("input.txt");
    return 0;
}
