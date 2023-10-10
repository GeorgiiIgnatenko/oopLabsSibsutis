#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>

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

void diag(vector<vector<int>> matrix, vector<int> &arr)
{
    int size = matrix.size();
    int n = size - 1;
    int i, j, count = 0;
    while (n >= 0)
    {
        i = 0;
        j = n--;
        while (j < size)
        {
            arr.push_back(matrix[i][j]);
            count++;
            i++;
            j++;
        }
    }
    n = 1;
    while (n < size)
    {
        i = n++;
        j = 0;
        while (i < size)
        {
            arr.push_back(matrix[i][j]);
            count++;
            i++;
            j++;
        }
    }

}

void diagReverse(vector<vector<int>> matrix, vector<int> &arr)
{   int size = matrix.size();
    int n = 0;
    int i, j, count = 0;
    while (n < size)
    {
        j = 0;
        i = n++;
        while (i >= 0)
        {
            arr.push_back(matrix[i][j]);
            count++;
            j++;
            i--;
        }
    }
    n = 1;
    while (n < size)
    {
        i = size - 1;
        j = n++;
        while (j < size)
        {
            arr.push_back(matrix[i][j]);
            count++;
            i--;
            j++;
        }
    }
}

void spiral(vector<vector<int>> matrix, vector<int> &arr)
{
    int n = matrix.size();
    int shift, count, i, j;
    shift = count = i = j = 0;

    while (count < n * n)
    {
        arr.push_back(matrix[i][j]);
        if (i == shift && j < n - shift - 1)
            j++;
        else if (j == n - shift - 1 && i < n - shift - 1)
            i++;
        else if (i == n - shift - 1 && j > shift)
            j--;
        else
            i--;

        if ((i == shift + 1) && (j == shift) && (shift != n - shift - 1))
        {
            shift++;
        }

        count++;
    }
}

void spiralReverse(vector<vector<int>> matrix, vector<int> &arr)
{
    int n = matrix.size();
    int shift, count, i, j;
    shift = count = i = j = 0;

    while (count < n * n)
    {
        arr.push_back(matrix[i][j]);
        if (i == shift && j < n - shift - 1)
            j++;
        else if (j == n - shift - 1 && i < n - shift - 1)
            i++;
        else if (i == n - shift - 1 && j > shift)
            j--;
        else
            i--;

        if ((i == shift + 1) && (j == shift) && (shift != n - shift - 1))
        {
            shift++;
        }

        count++;
    }

    reverse(arr.begin(), arr.end());

}

void printMatrix(vector<vector<int>> vect) {
    for (vector<int> row : vect){
        for (int el : row){
            cout << el << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}


void printOut(vector<int> out){
    for (int el : out) {
        cout << el << " ";
    }
    cout << '\n';
}

int main()
{
    srand(time(NULL));
    int size = 5;
    int maxValue = 90;
    vector<vector<int>> matrix = genRandMatrix(size, maxValue);
    vector<int> out;

    printMatrix(matrix);
    diag(matrix, out);
    printOut(out);

    out.clear();
    out.shrink_to_fit();
    diagReverse(matrix, out);
    printOut(out);

    out.clear();
    out.shrink_to_fit();
    spiral(matrix, out);
    printOut(out);

    out.clear();
    out.shrink_to_fit();
    spiralReverse(matrix, out);
    printOut(out);
}