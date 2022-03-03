#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void inputString(char C[100])
{
    cin>>C;
}
void printString(char C[100])
{
    cout<<C;
}
bool isPalindrome(char C[100])
{
    int n = strlen(C);
    for (int i=0;i<=n/2;i++)
        if (C[i]!=C[n-i-1])
            return 0;
    return 1;
}
int countCapital(char C[100])
{
    int n = strlen(C);
    int ans = 0;
    for (int i=0;i<n;i++)
        if (C[i]>='A'&&C[i]<='Z')
            ans++;
    return ans;
}
int countAppearance(char C[100], char c)
{
    int n = strlen(C);
    int ans = 0;
    for (int i=0;i<n;i++)
        ans+=(C[i]==c);
    return ans;
}
int countWord(char C[100])
{

}
int main()
{
    cout<<isPalindrome("LA8L");
    return 0;
}
