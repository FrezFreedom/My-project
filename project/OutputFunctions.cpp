#include <iostream>
#include <vector>
#include "OutputFunctions.h"

using namespace std;

void printMatrixDouble(double ** matrix, int row, int col){

	cout << "++++++++++++++++++++++++++++++++++++\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------\n";
}

void printVector(vector<int> & V){
	cout << "++++++++++++++++++++++++++++++++++++\n";
	for (int i = 0; i < (int)V.size(); i++)
	{
		cout << V[i] << " ";
	}
	cout << "\n------------------------------------\n";
}