#include <iostream>

using namespace std;

int main()
{
    int one, two, ans;
    char x;

    cout<<"Toan hang 1: ";
    cin>>one;
    cout<<"Toan hang 2: ";
    cin>>two;
    cout<<"Toan tu: ";
    cin>>x;

    switch (x){
        case '+':{
            ans=one+two;
            break;
        }
        case '-':{
            ans=one-two;
            break;
        }
        case '*':{
            ans=one*two;
            break;
        }
        case '/':{
            ans=one/two;
            break;
        }
        case '%':{
            ans=one%two;
            break;
        }
    }
    cout<<"Ket qua la: "<<ans;
    return 0;
}
