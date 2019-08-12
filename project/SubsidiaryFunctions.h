#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigenvalues>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;

MatrixXd normalize_matrix(MatrixXd M, int n, double MAX);

MatrixXd normalize_matrix_special(MatrixXd M, int n, double a, double b);

double dijkstra(double ** graph, int size, int src, int dst);

MatrixXd eigenDecomposition(MatrixXd A, MatrixXd B);