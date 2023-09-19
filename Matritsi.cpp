#include <iostream>

using namespace std;

int a[100][100]{};
int b[100][100]{};

void MatrixInput(int m, int n)
{
    //cout << m <<""<< n << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter element " << i + 1 << " " << j + 1 << endl;
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
}

void MatrixOutput(int m,int n)
{
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void MatrixMultiplication(int m, int n, int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = a[i][j] * x;
        }
    }
}

void AnotherMatrixMultiplication(int m, int n)
{

}

int main()
{
    int m, n,x, mm,nn;
    cout << "enter sizes of matrix (height x width)" << endl;
    cin >> m >> n;
    while ((m < 1) || (n < 1)||(m>100)||(n>100))
    {
        cout << "invalid number try again" << endl;
        cin >> m >> n;
    }
    MatrixInput(m, n );
    MatrixOutput(m, n);
    //cout << endl << "enter multiplication" << endl;
    //cin >> x;
    //MatrixMultiplication(m, n, x);
    ////cout << m <<""<< n << endl;
    //for (int i = 0; i < m; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        cout << "enter element " << i+1 << " " << j+1 << endl;
    //        cin >> mas[i][j];
    //    }
    //}
    /*for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mas[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;*/
    //MatrixOutput(m, n);
    cout << endl;
    system("pause");
}
