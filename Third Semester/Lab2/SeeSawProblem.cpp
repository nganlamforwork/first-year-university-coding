#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
void SeeSawProblem1(int left, int right, int hatW[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
			if (i != j)
				if (left + hatW[i] == right + hatW[j]){
					cout << i << ' ' << j;
					return;
				}
	cout << "impossible";
}
void SeeSawProblem2(int left, int right, int hatW[], int n)
{
	sort(hatW + 0, hatW + n);
	for (int i = 0; i < n; i++){
		int tmp = left + hatW[i] - right;

		int l = 0, r = n-1, mid = 0;
		while (l <= r){
			mid = (l + r) / 2;
			if (hatW[mid] == tmp){
				cout << i << ' ' << mid;
				return;
			}
			if (hatW[mid] > tmp)
				r = mid - 1;
			else l = mid + 1;
		}
	}
	cout << "impossible";
}
int main()
{
	int left = 4, right = 2, n = 5;
	int hatW[] = { 1, 2, 3, 4, 5 };
	SeeSawProblem2(left, right, hatW, n);
	return 0;
}