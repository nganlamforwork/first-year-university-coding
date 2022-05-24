#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int GreatestCommonDivisorSol1(int u, int v)
{
	if (v == 0) return u;
	return GreatestCommonDivisorSol1(v, u%v);
}
int GreatestCommonDivisorSol2(int u, int v)
{
	for (int i = min(u, v); i > 0; --i)
		if (u % i == 0 && v % i == 0) {
			return i;
		}
}
int main()
{
	cout << GreatestCommonDivisorSol2(16, 24);
	system("pause");
	return 0;
}
