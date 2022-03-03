#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int insert7thLine(char input[])
{
    ifstream in;

	in.open(input);

	string line;
	int cnt=0;

	while(!in.eof()){
		getline(in,line);
		++cnt;
		cout<<line<<'\n';
		if (cnt==7) cout<<'\n';
	}
	in.close();
}
int main()
{
    char input[]="input.txt";
    insert7thLine(input);
    return 0;
}
