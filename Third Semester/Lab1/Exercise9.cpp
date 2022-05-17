#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;
int* merge2Arrays(int* a, int* b, int na, int nb, int&nc)
{
	nc = na + nb;
	int* ans = new int[nc];
	int i = 0, j = 0, k = 0;
	while (i < na&&j < nb){
		if (a[i] < b[j]){
			ans[k] = a[i];
			i++;
		}
		else{
			ans[k] = b[j];
			j++;
		}
		k++;
	}
	if (i < na)
		while (i < na){
			ans[k] = a[i]; i++; k++;
		}
	else
		while (j < nb){
			ans[k] = b[j]; j++; k++;
		}
	return ans;
}
int main()
{
	srand(time(0));
	int na = 5, nb = 6, nc = 0;
	int *a = new int[na];
	int *b = new int[nb];

	for (int i = 0; i < na; i++)
		a[i] = rand() % 100;
	for (int i = 0; i < nb; i++)
		b[i] = rand() % 100;

	sort(a, a + na);
	sort(b, b + nb);

	for (int i = 0; i < na; i++)
		cout << a[i] << ' ';
	cout << '\n';
	for (int i = 0; i < nb; i++)
		cout << b[i] << ' ';
	cout << '\n';

	int *c = merge2Arrays(a, b, na, nb, nc);
	for (int i = 0; i < nc; i++)
		cout << c[i] << ' ';
	delete[]a;
	delete[]b;
	delete[]c;
	system("pause");
	return 0;
}