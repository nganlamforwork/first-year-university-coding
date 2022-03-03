#include <iostream>

using namespace std;

int main()
{
    cout<<"BANG MA ASCII\n";
    cout<<"26 chu cai hoa:\n";
    for (int i=0;i<26;i++){
        char s='A'+i;
        int index=s;
        cout<<s<<": "<<index<<'\n';
    }
    cout<<"26 chu cai thuong:\n";
    for (int i=0;i<26;i++){
        char s='a'+i;
        int index=s;
        cout<<s<<": "<<index<<'\n';
    }
    return 0;
}
