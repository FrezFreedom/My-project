#include "SubsidiaryFunctions.h"



MatrixXd normalize_matrix(MatrixXd M, int n, double MAX){
	//normalize
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			M(i, j) /= MAX;
		}
	}
	return M;
}
MatrixXd normalize_matrix_special(MatrixXd M, int n, double a, double b){
	//normalize
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)M(i, j) /= a;
			else M(i, j) /= b;
		}
	}
	return M;
}