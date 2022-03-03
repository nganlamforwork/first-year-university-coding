#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int  insert2thLine(char input[])
{
    ifstream in;

	in.open(input);

	string line,second;
	int cnt=0;

	while(!in.eof()){
		getline(in,line);
		++cnt;
		if (cnt==2) second=line;
		cout<<line<<'\n';
		if (cnt%2==0) cout<<second<<'\n';
	}
	in.close();
}
int main()
{
    char input[]="input.txt";
     insert2thLine(input);
    return 0;
}
