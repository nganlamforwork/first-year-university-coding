#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int Greatest_Common_Divisor_Sol_1(int u, int v)
{
	if (v == 0) return u;
	return Greatest_Common_Divisor_Sol_1(v, u%v);
}
int Greatest_Common_Divisor_Sol_2(int u, int v)
{
	for (int i = min(u, v); i > 0; --i)
		if (u % i == 0 && v % i == 0) {
			return i;
		}
}
int main()
{
	cout << Greatest_Common_Divisor_Sol_2(16, 24);
	system("pause");
	return 0;
}