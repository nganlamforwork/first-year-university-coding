#include <iostream>
#include <string>
using namespace std;
void Majority_Element_Sol_1(int a[], int n)
{
	for (int i = 0; i < n; i++){
		int cnt = 1;
		for (int j = i + 1; j < n; j++)
			if (a[j] == a[i])
				cnt++;
		if (cnt > n / 2){
			cout << a[i];
			return;
		}
	}
	cout << "NO";
}
void Majority_Element_Sol_2(int a[], int n)
{
	int cnt[100];
	for (int i = 0; i < n; i++){
		cnt[a[i]]++;
		if (cnt[a[i]] > n / 2){
			cout << a[i];
			return;
		}
	}
	cout << "NO";
}
int main()
{
	int a[5] = { 1, 3, 3, 4, 3 };
	int n = 5;
	Majority_Element_Sol_1(a, n);
	system("pause");
	return 0;
}