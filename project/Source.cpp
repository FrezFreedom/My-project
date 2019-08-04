#include <iostream>
#include <limits.h> 
#include <string.h>
#include "InputFunctions.h"
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
double ** sg_network, **sg_security, **sg_max_delay;
double ** fg_network, **fg_security, **fg_max_delay;
double ** fat_tree;

double ** fat_tree_copy;

map<int, int> index_map;
map<int, int> index_map_reverse;
vector< pair< pair<int, int>, double > > fat_tree_recover;
vector< pair< pair<int, int>, double > > sg_network_recover;

int main(){

	string nameOfFatTree = "testcase.txt";

	fatTreeRead(nameOfFatTree,& network_size, &upper_bound_of_performance, &upper_bound_number_of_security
		, &upper_bound_number_of_max_delay, &max_of_bandwidth, &fat_tree_size, fat_tree, &index_map_reverse
		, &index_map, sg_network, sg_security, sg_max_delay);

	return 0;
}