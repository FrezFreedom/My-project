#include <iostream>
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