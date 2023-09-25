#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

vector<int> genRandArray(int size, int maxValue){
	vector<int> randArr;

	for (int i = 0; i < size; i++){
		randArr.push_back(rand() % maxValue);
	}

	return randArr; 
};

vector<vector<int>> genRandMatrix(int intsize, int intmaxValue){
    vector<vector<int>> matrix;
    for (int i = 0; i < intsize; i++){
        int lineSize = rand() % intsize;
        matrix.push_back(genRandArray(lineSize, intmaxValue));
    }

    return matrix;
};

void printMatrix(vector<vector<int>> matrix){
    int mSize = matrix.size();
    cout << "matrixSize: " << mSize << endl;
    for (int i = 0; i < mSize; i++){
        int lSize = matrix[i].size();
        cout << "lineSize: " << lSize << endl;
        for (int j = 0; j < lSize; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

}

int main() {
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;
    vector<vector<int>> matrix = genRandMatrix(size, maxValue);
    printMatrix(matrix);
}