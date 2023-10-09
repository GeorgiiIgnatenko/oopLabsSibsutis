#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class Matrix
{
public:
    Matrix() {}
    Matrix(Matrix &m) : matrix(m.matrix), m_x(m.m_x), m_y(m.m_y) {}
    Matrix(int y, int x) : m_y(y), m_x(x) {init(y, x);}
   
    ~Matrix(){
        matrix.shrink_to_fit();
    };

    void Print(string name){
        cout << name << endl;
        for (int i = 0; i < m_y; i++){
            for (int j = 0; j < m_x; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void SetM(int i, int j, T val){
        matrix[i][j] = val;
    }

private:
    void init(int y, int x)
    {
        for (int i = 0; i < y; i++)
        {
            vector<T> matrixRow;
            for (int j = 0; j < x; j++)
            {
                matrixRow.push_back(0);
            }
            matrix.push_back(matrixRow);
        }
    }

    int m_x{0};
    int m_y{0};
    vector<vector<T>> matrix;
};

int main()
{

    Matrix<double> M(3,4);
    M.Print("M");

    int i, j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            M.SetM(i,j,(i+j)*0.5);
        }
    }
    M.Print("M");

    Matrix <double>M1 = M;
    M1.Print("M1");

    Matrix <double>M2;
    M2 = M;
    M2.Print("M2");

    Matrix <double>M3;
    M3 = M2 = M1 = M;
    M3.Print("M3");

  
}