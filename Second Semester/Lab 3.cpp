#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
void Swap(int*& a, int*& b)
{
	int * tmp = new int;
	*tmp = *a;
	*a = *b;
	*b = *tmp;
	delete tmp;
}
int* sum(int* a, int* b)
{
	int * ans = new int;
	*ans = *a + *b;
	return ans;
}
void inputArray(int* a, int &n)
{
	cin >> n;
	for (int i = 0; i<n; i++)
		cin >> *(a + i);
}
void printArray(int* a, int n)
{
	for (int i = 0; i<n; i++)
		cout << *(a + i) << ' ';
}
int* findMax(int* arr, int n)
{
	int * ans = new int;
	*ans = 0;
	for (int i = 0; i<n; i++)
		*ans = max(*ans, *(arr + i));
	return ans;
}
int* copyArray(int* arr, int n)
{
	int * ans = new int[n];
	for (int i = 0; i<n; i++)
		*(ans + i) = *(arr + i);
	return ans;
}
int* countEvens(int* arr, int n, int* evens)
{
	int *cnt = new int;
	*cnt = 0;
	for (int i = 0; i<n; i++)
		if (arr[i] % 2 == 0)
			evens[(*cnt)++] = arr[i];
	return cnt;
}
int* genEvenSubarray(int* arr, int n, int * count)
{
	count = new int[n];
	int cnt = 0;
	for (int i = 0; i<n; i++)
		if (arr[i] % 2 == 0)
			*(count + (cnt++)) = *(arr + i);
	return count;
}
int* findLargestTotalSubarray(int* a, int n, int &total, int &length)
{
	int * ans = new int[n]; //Init ans array
	for (int i = 0; i<n; i++){
		int * tmpArr = new int[n]; //Init tmp array
		int tmp = 0; //Init tmp sum
		int cnt = 0; //Quantity of tmp array
		for (int j = i; j<n; j++){
			tmp += a[j];
			tmpArr[++cnt] = a[j];
			if (tmp>total){
				total = tmp;
				ans = tmpArr;
				length = cnt;
			}
		}
		delete tmpArr;
	}
	return ans;
}
int* findLongestAscendingSubarray(int* a, int n, int &length)
{
	int * ans = new int[n]; //Init ans array
	int * tmp = new int[n];
	int cnt = 0;
	length = 1;
	tmp[cnt] = a[0];
	ans[length] = a[0];
	for (int i = 0; i<n - 1; i++)
		if (a[i] <= a[i + 1]){
			tmp[++cnt] = a[i + 1];
			if (cnt + 1>length){
				length = cnt;
				ans = tmp;
			}
		}
		else{
			delete tmp;
			tmp = new int[n];
			cnt = 0;
			tmp[cnt] = a[0];
		}
		return ans;
}

void swapArrays(int* a, int* b, int &na, int &nb)
{
	int * tmp = new int[max(na, nb)];
	for (int i = 0; i<na; i++)
		*(tmp + i) = *(a + i);
	for (int i = 0; i<nb; i++)
		*(a + i) = *(b + i);
	for (int i = 0; i<na; i++)
		*(b + i) = *(tmp + i);
	swap(na, nb);
}
int* concatenate2Arrays(int* a, int* b, int na, int nb)
{
	int * ans = new int[na + nb];
	for (int i = 0; i<na; i++)
		*(ans + i) = a[i];
	for (int j = 0; j<nb; j++)
		*(ans + na + j) = b[j];
	return ans;
}
int* merge2Arrays(int* a, int* b, int na, int nb, int&nc)
{
	nc = na + nb;
	int * ans = new int[nc];
	for (int i = 0; i<na; i++)
		*(ans + i) = a[i];
	for (int j = 0; j<nb; j++)
		*(ans + na + j) = b[j];
	sort(ans, ans + nc);
	return ans;
}
void generateMatrix1(int** A, int &length, int &width)
{
	//    length = rand()%10;
	//    width = rand()%10;
	for (int i = 0; i<width; i++){
		A[i] = new int[length];
		for (int j = 0; j<length; j++)
			A[i][j] = rand() % 100;
	}

	//cout
	for (int i = 0; i<width; i++){
		for (int j = 0; j<length; j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}
int** generateMatrix2(int* a, int* b, int na, int nb)
{
	int **ans;
	ans = new int*[nb];
	for (int i = 0; i<na; i++)
		for (int j = 0; j<nb; j++)
			ans[i][j] = a[i] * b[j];
	return ans;
}
void swapRows(int** a, int length, int width, int rowX, int rowY)
{
	int *tmpRow1, *tmpRow2;
	tmpRow1 = a[rowX];
	tmpRow2 = a[rowY];

	for (int i = 0; i<length; i++){
		int * x = tmpRow1 + i;
		int * y = tmpRow2 + i;

		Swap(x, y);
	}
	//cout
	for (int i = 0; i<width; i++){
		for (int j = 0; j<length; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}
void swapColumns(int** a, int length, int width, int colX, int colY)
{
	for (int i = 0; i<width; i++){
		int *x = *(a + i) + colX;
		int *y = *(a + i) + colY;
		Swap(x, y);
	}
	//cout
	for (int i = 0; i<width; i++){
		for (int j = 0; j<length; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}
int** transposeMatrix(int** a, int length, int width) {
	for (int i = 0; i<width; i++) {
		for (int j = 0; j<length / 2; j++) {
			int tmp = *(*(a + i) + j);
			*(*(a + i) + j) = *(*(a + i) + length - j - 1);
			*(*(a + i) + length - j - 1) = tmp;
		}
	}
	for (int i = 0; i<width; i++){
		for (int j = 0; j<length; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	return a;
}
int** concatenate2MatricesH(int** a, int** b, int length, int width)
{
	int **c = new int*[width];
	for (int i = 0; i<width; i++){
		c[i] = new int[length * 2];
		for (int j = 0; j<length; j++)
			c[i][j] = a[i][j];
		for (int j = 0; j<length; j++)
			c[i][width + j] = b[i][j];
	}
	//cout
	for (int i = 0; i<width; i++){
		for (int j = 0; j<length * 2; j++)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	return c;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width)
{
	int **c = new int*[width * 2];
	for (int i = 0; i<width; i++){
		c[i] = new int[length * 2];
		for (int j = 0; j<length; j++)
			c[i][j] = a[i][j];
	}
	for (int i = 0; i<width; i++){
		c[width + i] = new int[length * 2];
		for (int j = 0; j<length; j++)
			c[width + i][j] = b[i][j];
	}
	//cout
	for (int i = 0; i<width * 2; i++){
		for (int j = 0; j<length; j++)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	return c;
}
bool multiple2Matrices(int** a, int** b, int lengtha, int widtha, int lengthb, int widthb)
{
	//width = n     length = m
	if (lengtha != widthb) return 0;

	int lengthc = lengthb, widthc = widtha;
	int **c = new int*[widthc];

	for (int i = 0; i<widthc; i++){
		c[i] = new int[lengthc];
		for (int j = 0; j<lengthc; j++){
			c[i][j] = 0;
			for (int k = 0; k<lengtha; k++)
				c[i][j] += a[i][k] + b[k][j];
		}
	}
	//cout
	for (int i = 0; i<widthc; i++){
		for (int j = 0; j<lengthc; j++)
			cout << c[i][j] << ' ';
		cout << '\n';
	}
	return 1;
}
//int** findSubmatrix(int** a, int length, int width, int &length_, int &width_)
//{
//
//}
int* findLargestTotalSubarrayDP(int* a, int n, int &total, int &length)
{
	int * ans = new int[n]; //Init ans array
	int * sum = new int[n];
	int * len = new int[n];
	int id = 0;

	for (int i = 0; i < n; i++){
		//Init
		*(sum + i) = *(a + i);
		*(len + i) = 1;

		//Check sum[i-1]+a[i]>sum[i]
		if (i > 0 && *(sum + (i - 1)) + *(a + i) > *(sum + i)){
            *(sum + i) = *(sum + (i - 1)) + *(a + i);
            *(len + i) = *(len + (i - 1)) + 1;
		}

		//Check total & length
		if (*(sum + i) > total) {
			length = *(len + i);
			total = *(sum + i);
			id = i;
		}
	}

	//Create ans array
	int cnt = 0;
	for (int i=id-length+1;i<=id;i++){
        *(ans+(cnt++)) = *(a + i);
        cout<<*(a+i)<<' ';
	}
	return ans;
}
int main()
{
	int a[] = { 5, 6, 7, -1, 10, -7, 9 };
	int n = 7, total = 0, length = 0;
	findLargestTotalSubarrayDP(a, n, total, length);
	cout<<'\n';
	cout << "Total: "<<total;
	cout<<"\nLength: " << length;
	return 0;
}
