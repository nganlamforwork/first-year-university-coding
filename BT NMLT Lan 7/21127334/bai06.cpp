#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int deleteEmptyLines(char input[])
{
    ifstream in;

	in.open(input);

	string line;

	while(!in.eof()){
		getline(in,line);
		if(line.size()!=0) cout<<line<<'\n';
	}
	in.close();
}
int main()
{
    char input[]="input.txt";
    deleteEmptyLines(input);
    return 0;
}
