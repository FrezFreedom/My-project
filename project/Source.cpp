#include <iostream>
#include <limits.h> 
#include <string.h>
#include "InputFunctions.h"
#include "OutputFunctions.h"
#include <queue>
#include <map>
#include <ctime>
#include <fstream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Eigenvalues> 

using Eigen::MatrixXd;
using namespace Eigen;
using namespace std;

double** query_matrix;
double** network_matrix;
double** maximum_delay;
double** security;
double duration1;
int** help;
int N;

double upper_bound_of_performance;
double upper_bound_number_of_security;
double upper_bound_number_of_max_delay;
double max_of_bandwidth;


double alpha, beta;
int network_size;
int query_size;
int fat_tree_size;
int number_of_queries;
double ** sg_network, **sg_security, **sg_max_delay;
double ** fg_network, **fg_security, **fg_max_delay;
double ** fat_tree;

double ** fat_tree_copy;

map<int, int> index_map;
map<int, int> index_map_reverse;
vector<int> queries;
vector< pair< pair<int, int>, double > > fat_tree_recover;
vector< pair< pair<int, int>, double > > sg_network_recover;

int main(){

	string nameOfFatTree = "testcase.txt";

	fatTreeRead(nameOfFatTree,& network_size, &upper_bound_of_performance, &upper_bound_number_of_security
		, &upper_bound_number_of_max_delay, &max_of_bandwidth, &fat_tree_size, fat_tree, &index_map_reverse
		, &index_map, sg_network, sg_security, sg_max_delay);

	printMatrixDouble(fat_tree,fat_tree_size,fat_tree_size);
	printMatrixDouble(sg_max_delay, network_size, network_size);
	printMatrixDouble(sg_network,network_size,network_size);
	printMatrixDouble(sg_security, network_size, network_size);

	string nameOfTestcases = "random_testcases.txt";

	testCasesPermutationRead(nameOfTestcases, &number_of_queries, queries);

	printVector(queries);
	
	double time = 0;
	int accepted_queries = 0;

	for (int i = 0; i < number_of_queries; i++)
	{
		forwardingGraphRead(queries[i],network_size, &query_size, fg_network, fg_security, fg_max_delay);
		printMatrixDouble(fg_network, network_size, network_size);
		printMatrixDouble(fg_security, network_size, network_size);
		printMatrixDouble(fg_max_delay, network_size, network_size);
		int foo; cin >> foo;
	}

	int foo; cin >> foo;
	return 0;
}