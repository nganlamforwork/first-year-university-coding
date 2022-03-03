#include <iostream>
#include <fstream>

using namespace std;
bool checkPrime(int x){
    if (x<2) return 0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return 0;
    return 1;
}
int countPrimes(char input[])
{
    ifstream in;

	in.open(input);

	int n,cnt=0;
	while (in>>n){
        if (n%2==1&&checkPrime(n))
            cnt++;
	}

	in.close();

	return cnt;
}
int main()
{
    char input[]="output.txt";
    cout<<countPrimes(input);
    return 0;
}
