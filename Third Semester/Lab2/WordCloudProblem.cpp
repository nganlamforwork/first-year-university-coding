#include <iostream>
#include <sstream>
using namespace std;
void Word_Cloud_Problem_Sol_1(string source)
{
	stringstream ss;
	ss << source;
	int n = 0;
	string a[1000];
	bool check[1000] = {};
	while (ss >> a[n]){
		++n;
	}
	for (int i = 0; i < n; i++)
}
int main()
{
	return 0;
}