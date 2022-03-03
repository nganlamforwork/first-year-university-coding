#include <iostream>

using namespace std;
void input2DArray(float A[][100], int m, int n)
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>A[i][j];
}
void print2DArray(float A[][100], int m, int n)
{
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++)
            cout<<A[i][j]<<' ';
        cout<<'\n';
    }
}
void rotate2DArray(float A[][100], int m, int n)
{
    float B[100][100];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            B[i][j]=A[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            B[j][m-i+1]=A[i][j];
    print2DArray(B,n,m);
}
void sum2DArray(float A[][100], float B[][100], float result[][100], int m, int n)
{

    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            result[i][j]=B[i][j]+A[i][j];
}
void multiple2DArray(float A[][], float B[][], float result[][], int m, int n, int p)
{
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            result[i][j]=B[i][j]*A[i][j];
}
bool isUpperTriangularMatrix(int A[][100], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (A[i][j] != 0)
                return 0;
    return 1;
}
bool isLowerTriangularMatrix(int A[][100], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mat[i][j] != 0)
                return 0;
    return 1;
}

bool isDiagonalMatrix(int A[][100], int n)
{
    for (int i = 0; i < N; i++)
        if (mat[i][i] != 0)
            return 0;
    return 1;
}

int main()
{
    float  A[100][100];
    input2DArray(A,5,6);
    rotate2DArray(A,5,6);
    return 0;
}
