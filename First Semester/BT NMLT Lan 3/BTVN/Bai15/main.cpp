#include <iostream>

using namespace std;

int main()
{
    float theMin=99999999, theMax=0;
    float h;
    while (1){
        cout<<"Nhap vao chieu cao: ";
        cin>>h;
        if (h==0) break;
        theMin=min(theMin,h);
        theMax=max(theMax,h);
    }
    if (theMin==99999999) theMin=0;
    cout<<"Chieu cao cua hoc sinh dung dau danh sach: "<<theMin<<" (m)\n";
    cout<<"Chieu cao cua hoc sinh dung cuoi danh sach: "<<theMax<<" (m)\n";
    return 0;
}
