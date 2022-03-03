#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int  insertDoubleSpaced(char input[])
{
    ifstream in;

	in.open(input);

	string line;

	while(!in.eof()){
		getline(in,line);
		cout<<line<<"\n\n";
	}
	in.close();
}
int main()
{
    char input[]="input.txt";
    insertDoubleSpaced(input);
    return 0;
}
