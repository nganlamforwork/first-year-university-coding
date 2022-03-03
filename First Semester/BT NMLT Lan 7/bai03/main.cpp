#include <iostream>
#include <fstream>

using namespace std;
int countAverageChar(char input[])
{
    ifstream in;

	in.open(input);

	string line;
	int sum=0,cnt=0;

	while(!in.eof()){
		getline(in,line);
		sum+=line.size();
		++cnt;
	}
	double ans = (double) sum/cnt;
	cout<<ans;

	in.close();
}
int main()
{
    char input[]="input.txt";
    countAverageChar(input);
    return 0;
}
