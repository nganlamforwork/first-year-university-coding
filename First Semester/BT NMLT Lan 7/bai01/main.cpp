#include <iostream>
#include <fstream>

using namespace std;
int copyFile(char input[], char output[])
{
    ifstream in;
	ofstream out;

	in.open(input);
	out.open(output);

	string line;

	while(!in.eof()){
		getline(in,line);
		out<<line<<'\n';
	}
	in.close();
	out.close();
}
int main()
{
    char input[]="input.txt";
    char output[]="output.txt";
    copyFile(input,output);
    return 0;
}
