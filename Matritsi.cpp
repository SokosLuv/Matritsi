#include <iostream>
#include <algorithm>

using namespace std;

//int a[100][100]{};
//int b[100][100]{};

int** MatrixInput(int** a, int m, int n)
{
    //cout << m <<""<< n << endl;
    /*for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter element " << i + 1 << " " << j + 1 << endl;
            cin >> a[i][j];
        }
    }*/
    a = new int* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) 
        {
            cout << "enter element " << i + 1 << " " << j + 1 << endl;
            cin >> a[i][j];
        }
    }
    return a;
}

void MatrixOutput(int** a, int m,int n)
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
    /*cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
}

int** MatrixMultiplication(int** a, int m, int n, int x)
{
    int** b = new int* [m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new int [n];
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j] * x;
        }
    }
    return b;
}

int** AnotherMatrixMultiplication(int** a, int**b, int** c, int m, int n)
{
    c = new int* [m];
    for (int i = 0; i < m; i++)
    {
        c[i] = new int [n];
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int ii = 0; ii < n; ii++)
            {
                c[i][j] = c[i][j] + a[i][ii] * b[ii][j];
            }  
        }
    }
    return c;
}

void Transpozitsii(int* a, int b)
{
    int c = 1;
    for (int i = 1;  i <= b; i++)
    {
        c = c * i;
    }
    for (int i = 1; i <= c; i++)
    {       
        cout << "{";
        for (int i = 1; i <= b; i++)
        {
            cout <<a[i]<<", ";
        }
        cout << endl;
    }
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int znaki(int a[], int n)
{
    int znak = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                znak = znak * (-1);
            }
        }
    }
    return znak;
}
void heapPermutation(int p[], int size, int n)
{
    if (size == 1) {
        printArr(p, n);
        cout << znaki(p, n) << endl << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        heapPermutation(p, size - 1, n);

        if (size % 2 == 1) {
            std::swap(p[0], p[size - 1]);
        }
        else {
            std::swap(p[i], p[size - 1]);
        }
    }
}

int Monom(int** a, int p[], int n)
{
    int m = 1;
    for (int i=0; i<n)
    m=m*a[0]
}

int main()
{
    int m, x, mm,nn;
    //int** a = nullptr;
    int** b = nullptr;
    int** c = nullptr;
    /*cout << "enter size of matrix" << endl;
    cin >> m;
    n = m;
    while ((m < 1) || (n < 1)||(m>100)||(n>100))
    {
        cout << "invalid number try again" << endl;
        cin >> m >> n;
    }
    a = MatrixInput(a, m, n );
    MatrixOutput(a, m, n);*/

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
   /* cout << endl << "enter second matrix" << endl;
    b = MatrixInput(b, m, n);
    MatrixOutput(b, m, n);*/
    /*cout << endl << "enter multiplier" << endl;
    cin >> x;*/
    /*c = MatrixMultiplication(c,a, m, n,x);*/
    cout << endl;
    /*c=AnotherMatrixMultiplication(a, b, c,m, n);
    MatrixOutput(c, m, n);*/
    int a[] = { 1, 2, 3 };
    int n = sizeof a / sizeof a[0];
    heapPermutation(a, n, n);
    cout << znaki(a, n);
    cout << endl;
    system("pause");
}
