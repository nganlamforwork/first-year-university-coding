#include <iostream>

using namespace std;

int main()
{
    int year, year1, month;

    cout << "Nhap vao mot nam: ";
    cin>>year1;

    if ((year1%4==0 && year1%100!=0) || year1%400==0)
        cout<<"Nam nhuan!\n";
    else cout<<"Khong la nam nhuan!\n";

    cout<<"Nhap vao mot thang va mot nam: ";
    cin>>month>>year;
    if (month==2){
        if ((year%4==0 && year%100!=0) || year%400==0)
            cout<<"Thang "<<month<<" nam "<<year<<" co 29 ngay";
        else cout<<"Thang "<<month<<" nam "<<year<<" co 28 ngay";
    }
    else
        switch (month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                cout<<"Thang "<<month<<" nam "<<year<<" co 31 ngay";
                break;
            }
            default:
                cout<<"Thang "<<month<<" nam "<<year<<" co 30 ngay";
        }
    return 0;
}
