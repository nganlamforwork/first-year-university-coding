#include <iostream>

using namespace std;

int main()
{
    bool checkYear, check;
    int day, month, year, preDay, preMonth, preYear;

    cout<<"Ngay = ";
    cin>>day;
    cout<<"Thang = ";
    cin>>month;
    cout<<"Nam = ";
    cin>>year;

    if ((year%4==0 && year%100!=0) || year%400==0) checkYear=1;
    else checkYear=0;

    if (month==2){
        check = (checkYear) ? (day>=1 && day<=29) : (day>=1 && day<=28);
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
                    if (day>=1 && day<=31) check=1;
                    else check=0;
                    break;
                }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                if (day>=1 && day<=30) check=1;
                else check=0;
                break;
            }
            default: check=0;
        }

    if (!check) cout<<"Ngay thang ban nhap khong hop le";
    else {
        preMonth=month; preYear=year;
        preDay=day-1;
        if (preDay==0) {
            preMonth=month-1;
            switch (month){
                case 5: case 7: case 10: case 12:{
                    preDay=30;
                    break;
                }
                case 1: case 2: case 4: case 6:  case 8: case 9: case 11: {
                    preDay=31;
                    break;
                }
                case 3:{
                    if (checkYear) preDay=29;
                    else preDay=28;
                    break;
                }
            }
        }
        if (preMonth==0) {
            preYear=year-1;
            preMonth=12;
        }
        cout<<"Ngay truoc do la ngay "<<preDay<<" thang "<<preMonth<<" nam "<<preYear;
    }
    return 0;
}
