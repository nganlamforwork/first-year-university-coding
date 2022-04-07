#include <iostream>
#include <ctime>
using namespace std;
void printSMatrix(int** A, int n)
{
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            cout<<A[i][j]<<' ';
        cout<<'\n';
    }
}
int** generateCmatrix(int** A, int** B, int na, int nb)
{
    int sum=0, ans = 0, ansi=-1,ansj=-1;
    int ** C = new int* [nb];
    for (int i=0;i<nb;i++)
        C[i]=new int[nb];

    for (int i=0;i<nb;i++)
        for (int j=0;j<nb;j++){
            C[i][j]=B[i][j];
            sum+=B[i][j];
        }

    for (int i=0;i<nb-na+1;i++)
        for (int j=0;j<nb-na+1;j++){
            int curSum = sum;
            for (int ia = 0; ia<na;ia++)
                for (int ja=0;ja<na;ja++)
                    curSum+=A[ia][ja]-B[i+ia][j+ja];
            if (curSum>ans){
                ans=curSum;
                ansi=i;
                ansj=j;
            }
        }

    for (int i = 0; i<na;i++)
        for (int j=0;j<na;j++)
            C[ansi+i][ansj+j]=A[i][j];

    return C;
}

int findEven(int n)
{
    if (n==0) return 0;
    if ((n%10)%2==0) return findEven(n/10)*10+n%10;
    return findEven(n/10);
}

int main()
{
    int na=3, nb=6;
    int ** A = new int* [na];
    int ** B = new int* [nb];

    //For testing
    for (int i=0;i<na;i++)
        A[i]=new int[na];
    for (int i=0;i<nb;i++)
        B[i]=new int[nb];
    //For testing
    for (int i=0;i<na;i++)
        for (int j=0;j<na;j++)
            cin>>A[i][j];
    for (int i=0;i<nb;i++)
        for (int j=0;j<nb;j++)
            cin>>B[i][j];
    //For testing

    int ** C = generateCmatrix(A,B,na,nb);
    printSMatrix(C,nb);

//----------------------------------------------
    srand(time(NULL));
    int n=rand()%1000000000;
    cout<<"n = "<<n<<'\n';
    cout<<findEven(n);

    return 0;
}
