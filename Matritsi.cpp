#include <iostream>
#include <algorithm>

using namespace std;

//int a[100][100]{};
//int b[100][100]{};

float** MatrixInput(float** a, int m, int n)
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
    a = new float* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new float[n];
        for (int j = 0; j < n; j++) 
        {
            cout << "enter element " << i + 1 << " " << j + 1 << endl;
            cin >> a[i][j];
        }
    }
    return a;
}

void MatrixOutput(float** a, int m,int n)
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

float** AnotherMatrixMultiplication(float** a, float**b, int m, int n)
{
    float** c = new float* [m];
    for (int i = 0; i < m; i++)
    {
        c[i] = new float[n];
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

/*int Monom(int** a, int p[], int n)
{
    int m = 1;
    for (int i=0; i<n)

    m=m*a[0]
}*/

float** copy(float** a, int m)
{
    int n = m;
    float** b = new float* [m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    return b;
}

float** edinichniy(int m)
{
    int n = m;
    float** b = new float* [m];
    for (int i = 0; i < m; i++)
    {
        b[i] = new float[n];
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }
    return b;
}

void change_row(float** a, int k, int j, int m)
{
    for (int i = 0; i < m; i++)
    {
        int x = a[j][i];
        a[j][i] = a[k][i];
        a[k][i] = x;
    }

}

void mult_row(float** a, int k, float b, int m)
{
    for (int i = 0; i < m; i++)
    {
        a[k][i] = a[k][i] * b;
    }
}

void substract_row(float** a, int k, int j, float b, int m)
{
    for (int i = 0; i < m; i++)
    {
        a[k][i] = a[k][i] - b * a[j][i];
    }
}

float** inverse(float** a, int m)
{
    float** e = copy(a, m);
    float** f = edinichniy(m);
    for (int p = 0; p < m ; p++)
    {
        if (e[p][p] == 0)
        {
            for (int i = p + 1; i < m; i++)
            {
                if (e[i][p] != 0)
                {
                    change_row(e, p, i, m);
                    change_row(f, p, i, m);
                    break;
                }
            }
        }
        if (e[p][p] == 0)
        {
            cout << "matrix cant be inversed" << endl;
            return {};
        }
        if (e[p][p] != 1)
        {
            float x = 1 / e[p][p];
            mult_row(e, p, x, m);
            mult_row(f, p, x, m);
        }
        for (int i = p + 1; i < m; i++)
        {
            if (e[i][p] != 0)
            {
                float x = e[i][p];
                substract_row(e, i, p, x, m);
                substract_row(f, i, p, x, m);
            }
        }
        
    }
    //MatrixOutput(e, m, m);
    //cout << endl;
    //MatrixOutput(f, m, m);
    for (int p = m - 1; p > 0; p--)
    {
        for (int i = 0; i < p; i++)
        {
            if (e[i][p] != 0)
            {
                float x= e[i][p];
                substract_row(e, i, p, x, m);
                substract_row(f, i, p, x, m);
            }
        }
    }
    //MatrixOutput(e, m, m);
    //cout << endl;
    //MatrixOutput(f, m, m);
    return f;
}

int main()
{
    int m, n;
    float** a = nullptr;
    //int** b = nullptr;
    //int** c = nullptr;
    cout << "enter size of matrix" << endl;
    cin >> m;
    n = m;
    while ((m < 1) || (n < 1)||(m>100)||(n>100))
    {
        cout << "invalid number try again" << endl;
        cin >> m >> n;
    }
    a = MatrixInput(a, m,m);
    float** ff= inverse(a, m);
    MatrixOutput(ff, m,m);

    system("pause");
}
