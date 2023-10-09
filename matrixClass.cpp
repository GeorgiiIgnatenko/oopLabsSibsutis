#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
public:
    Matrix() {}
    Matrix(int size) : m_x(size), m_y(size) { init(size, size); }
    Matrix(int n, int m) : m_x(n), m_y(m) { init(n, m); }

    int area() { return m_x * m_y; }

    void print()
    {
        for (int i = 0; i < m_y; i++)
        {
            for (int j = 0; j < m_x; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void randomFill()
    {
        srand(time(NULL));
        for (int i = 0; i < m_x; i++)
        {
            for (int j = 0; j < m_y; j++)
            {
                matrix[i][j] = rand() % 10;
            }
        }
    }

    void keyboardFill()
    {
        cout << "Введите " << m_x * m_y << " элементов в матрицу" << endl;
        for (int i = 0; i < m_y; i++)
        {
            for (int j = 0; j < m_x; j++)
            {
                cin >> matrix[i][j];
            }
        }
    }

    void sum()
    {
        for (int i = 0; i < m_y; i++)
        {
            for (int j = 0; j < m_x; j++)
            {
                sumVal += matrix[i][j];
            }
        }
        cout << sumVal << endl;
    }

    ~Matrix(){
        matrix.shrink_to_fit();
    };

private:
    void init(int y, int x)
    {
        for (int i = 0; i < x; i++)
        {
            vector<int> matrixRow;
            if (y == x)
            {
                for (int j = 0; j < y; j++)
                {
                    if (i == j)
                    {
                        matrixRow.push_back(1);
                    }
                    else
                    {
                        matrixRow.push_back(0);
                    }
                }
            }
            for (int j = 0; j < y; j++)
            {
                matrixRow.push_back(0);
            }
            matrix.push_back(matrixRow);
        }
    }

    int m_x{0};
    int m_y{0};
    int sumVal{0};
    vector<vector<int>> matrix;
};

int main()
{

    Matrix firstMatrix;
    Matrix secondMatrix(3);
    Matrix thirdMatrix(3, 4);
    Matrix fourthMatrix(2, 3);

    secondMatrix.print();
    thirdMatrix.print();
    fourthMatrix.print();

    thirdMatrix.randomFill();
    thirdMatrix.print();

    fourthMatrix.keyboardFill();
    fourthMatrix.print();

    thirdMatrix.sum();
}