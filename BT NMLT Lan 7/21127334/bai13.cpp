#include <iostream>
#include <fstream>

using namespace std;
int sumMatrix(char input[])
{
    ifstream in;
    in.open(input);

    int n,m,x, sum=0;

    in>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            in>>x;
            sum+=x;
        }
    return sum;
}
int main()
{
    cout << sumMatrix("input.txt");
    return 0;
}
