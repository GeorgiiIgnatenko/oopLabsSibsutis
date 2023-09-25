#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

vector<int> genRandArray(int size, int maxValue)
{
    vector<int> randArr;

    for (int i = 0; i < size; i++)
    {
        randArr.push_back(rand() % maxValue + 10);
    }

    return randArr;
};

vector<vector<int>> genRandMatrix(int intsize, int intmaxValue)
{
    vector<vector<int>> matrix;
    for (int i = 0; i < intsize; i++)
    {
        matrix.push_back(genRandArray(intsize, intmaxValue));
    }

    return matrix;
};

void printMatrix(vector<vector<int>> matrix)
{
    int mSize = matrix.size();
    for (int i = 0; i < mSize; i++)
    {
        int lSize = matrix[i].size();
        for (int j = 0; j < lSize; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void printMatrixDiag(vector<vector<int>> matrix)
{
    int mSize = matrix.size();
    int currentDiag = 0;

    for (; currentDiag < mSize; currentDiag++)
    {
        for (int i = 0; i < currentDiag + 1; i++)
        {
            cout << matrix[i][currentDiag - i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int maxElementsCount = currentDiag - 1;

    for (; currentDiag < mSize * 2 - 1; currentDiag++)
    {
        for (int i = 0; i < maxElementsCount; i++){
            cout << matrix[currentDiag - mSize + 1 + i][mSize - 1 - i] << " ";
        }
        cout << endl;
        maxElementsCount--;
    }
}

void printMatrixSpiral(vector<vector<int>> matrix){
    cout << "Matrix spiral: " << endl;
    int matrix_size = matrix.size();
    for(int i = 0; i <= matrix_size/2; i++)
    {   
        if(i == 0)
        {
            cout << matrix[matrix_size/2][matrix_size/2] << " ";
        }
 
        for(int k = 0; k < 2*i; k++) 
        {
            cout << matrix[matrix_size/2 - i][matrix_size/2 - i + 1 + k] << " ";
        }
 
        for(int k = 0; k < 2*i; k++) 
        {
            cout << matrix[matrix_size/2 - i + 1 + k][matrix_size/2 + i] << " ";
        }
 
        for(int k = 0; k < 2*i; k++) 
        {
            cout << matrix[matrix_size/2 + i][matrix_size/2 + i - 1 - k] << " ";
        }
 
        for(int k = 0; k < 2*i; k++) 
        {
            cout << matrix[matrix_size/2 + i - 1 - k][matrix_size/2 - i] << " ";
        }
    }
}

void printMatrixSpiralOrder(vector<vector<int>> matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << matrix[top][i] << " ";
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}


int main()
{
    srand(time(NULL));
    int size = 5;
    int maxValue = 91;
    vector<vector<int>> matrix = genRandMatrix(size, maxValue);

    printMatrix(matrix);
    cout << endl;
    cout << "Matrix Diag: " << endl;
    printMatrixDiag(matrix);
    cout << endl;

    printMatrixSpiral(matrix);
    cout << endl;
    printMatrixSpiralOrder(matrix);
}