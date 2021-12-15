#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int delete2FirstChars(char input[])
{
    ifstream in;

	in.open(input);

	string line;

	while(!in.eof()){
		getline(in,line);
		line.erase(0,2);
		cout<<line<<'\n';
	}
	in.close();
}
int main()
{
    char input[]="input.txt";
    delete2FirstChars(input);
    return 0;
}
