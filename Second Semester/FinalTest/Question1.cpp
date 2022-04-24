#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
char* replaceStr(char* src, char* sub, char* rep)
{
    char* ans = new char;
    strcpy(ans, "\0");
    char* pos = new char;
    while (strstr(src, sub) != NULL) {
        pos = strstr(src, sub);             //Tìm vị trí của sub string trong src
        strncat(ans, src, pos - src);       //Copy tất cả ký tự phía trước pos
        src = pos + strlen(sub);            //Cập nhật src từ vị trí sau sub vừa tìm được
        strcat(ans, rep);                   //Nối rep vào (thay thế sub = rep)
    }
    strcat(ans, src);
    cout << ans << '\n';
    return ans;
}
int main()
{
    char src[] = "brown fox and brown cat";
    char sub[] = "brown";
    char rep[] = "red";
    char* ans = replaceStr(src, sub, rep);
    cout << ans;
    return 0;
}

#endif