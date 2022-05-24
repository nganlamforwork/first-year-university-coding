#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
void WordCloudProblemSol1(string source)
{
	stringstream ss;
	ss << source;
	int n = 0;
	string a[1000];
	bool check[1000] = {};
	while (ss >> a[n]){
		++n;
	}
	for (int i = 0; i < n; i++){
		if (check[i]) continue;
		int cnt = 1;
		for (int j = i + 1; j < n; j++){
			cnt += a[j] == a[i];
			check[j] = a[j] == a[i];
		}
		cout << a[i] << " = " << cnt << '\n';
	}
}
void WordCloudProblemSol2(string source)
{
	stringstream ss;
	ss << source;
	int n = 0;
	string a[1000];
	bool check[1000] = {};
	while (ss >> a[n]){
		++n;
	}
	sort(a + 0, a + n);
	int cnt = 0;
	string tmp = a[0];
	for (int i = 0; i < n; i++){
		if (a[i] == tmp)
			cnt++;
		else{
			cout << tmp << " = " << cnt << '\n';
			cnt = 1;
			tmp = a[i];
		}
	}
	cout << tmp << " = " << cnt << '\n';
}
int main()
{
	WordCloudProblemSol2("hello hallo Helloo hello");
	return 0;
}