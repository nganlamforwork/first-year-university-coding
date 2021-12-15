#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int deleteLastLine(char input[])
{
    ifstream in;

	in.open(input);

	vector<string> line;
	string tmp;

	while(!in.eof()){
		getline(in,tmp);
		line.push_back(tmp);
	}
	for (int i=0;i<(int)line.size()-1;i++)
        cout<<line[i]<<'\n';
	in.close();
}
int main()
{
    char input[]="input.txt";
    deleteLastLine(input);
    return 0;
}
