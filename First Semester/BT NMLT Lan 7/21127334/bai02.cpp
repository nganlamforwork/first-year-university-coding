#include <iostream>
#include <fstream>

using namespace std;
int convertFile60CharsperLine(char input[], char output[])
{
    ifstream in;
	ofstream out;

	in.open(input);
	out.open(output);

	char c;
	int cnt=0;

	while(in.get(c)){
		++cnt;
		out<<c;
		if (cnt==60){
            cnt=0;
            out<<'\n';
		}
	}
	in.close();
	out.close();
}
int main()
{
    char input[]="input.txt";
    char output[]="output.txt";
    convertFile60CharsperLine(input,output);
    return 0;
}
