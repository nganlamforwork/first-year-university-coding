#include <iostream>
#include <fstream>

using namespace std;
int printSource(char input[])
{
    ifstream in;

	in.open(input);

	string line;

	while(!in.eof()){
		getline(in,line);
		cout<<line<<'\n';
	}
	in.close();
}
int main()
{
    char input[]="bai04.cpp";
    printSource(input);
    return 0;
}
