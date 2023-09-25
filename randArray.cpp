#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> genRandArray(int size, int maxValue){
	vector<int> randArr;

	for (int i = 0; i < size; i++){
		randArr.push_back(rand() % maxValue);
	}

	return randArr; 
};

void print(const vector<int>& arr){
	for (int i : arr){
		cout << i << endl;
	}
}

int main () {
	srand(time(nullptr));
	int size = rand() % 10;
	cout << "size: " << size << endl;
	int maxValue = 100;
	vector<int> arr = genRandArray(size, maxValue);
	print(arr);
}


