#include <iostream>
#include <fstream>

using namespace std;
int writeListOddNumbers(int n, char output[])
{
    ofstream out;

	out.open(output);

	for (int i=1;i<=n;i++){
        int x=i;
        int sum=0;
        while (x>0){
            sum+=x%10;
            x/=10;
        }
        if (sum%2==0) out<<i<<'\n';
	}
	out.close();
}
int main()
{
    char output[]="output.txt";
    int n;
    cin>>n;
    writeListOddNumbers(n,output);
    return 0;
}
