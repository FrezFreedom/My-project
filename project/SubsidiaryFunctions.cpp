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

double dijkstra(double ** graph, int size, int src, int dst){
	int srcc = src, dstt = dst;
	unordered_set<int> check;
	unordered_map<int, int> back_node;

	priority_queue< pair<double, double> > q;
	q.push(make_pair(1e9, src));

	while (!q.empty()){
		pair<double, int> help = q.top();
		q.pop();
		
		if (help.second == dst)return help.first;
		if (check.find(help.second) == check.end()){
			check.insert(help.second);
			//size = NN
			for (int i = 0; i < size; ++i)
			{
				if (i != help.second && check.find(i) == check.end() && graph[help.second][i])
				{
					q.push(make_pair(min(graph[help.second][i], help.first), i));
					back_node[i] = help.second;
				}
			}
		}

	}
	return 0;
}

MatrixXd eigenDecomposition(MatrixXd A, MatrixXd B)
{
	EigenSolver<MatrixXd> es(A);
	MatrixXcd SubstrateEigenVectors = es.eigenvectors();
	//cout << SubstrateEigenVectors << "\n\n";

	EigenSolver<MatrixXd> es1(B);
	MatrixXcd FgEigenVectors = es1.eigenvectors();
	//cout << FgEigenVectors << "\n\n";

	MatrixXd tmpSgEigenVector = SubstrateEigenVectors.real();
	tmpSgEigenVector = tmpSgEigenVector.cwiseAbs();

	MatrixXd tmpFgEigenVector = FgEigenVectors.real();
	tmpFgEigenVector = tmpFgEigenVector.cwiseAbs();

	MatrixXd result = tmpFgEigenVector * tmpSgEigenVector.transpose();
	return result;
}