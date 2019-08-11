#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void fatTreeRead(string nameOfFatTree, int * network_size, double * upper_bound_of_performance, double * upper_bound_number_of_security
	, double * upper_bound_number_of_max_delay, double * max_of_bandwidth, int * fat_tree_size, double ** & fat_tree, map<int, int> * index_map_reverse
	, map<int, int> * index_map, double ** & sg_network, double ** & sg_security, double ** & sg_max_delay);

void testCasesPermutationRead(string nameOfTestcases, int * number_of_queries, vector<int> & queries);

int forwardingGraphRead(int which_query, int network_size, int * query_size, double ** & fg_network, double ** & fg_security, double ** & fg_max_delay);