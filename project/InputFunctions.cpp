#include "InputFunctions.h"
#include "ConverterFunctions.h"
#include <fstream>
#include <vector>
#include <map>

void fatTreeRead(string nameOfFatTree, int * network_size, double * upper_bound_of_performance, double * upper_bound_number_of_security
	, double * upper_bound_number_of_max_delay, double * max_of_bandwidth, int * fat_tree_size, double ** & fat_tree, map<int, int> * index_map_reverse
	, map<int, int> * index_map, double ** & sg_network, double ** & sg_security, double ** & sg_max_delay){

	ifstream myReadFile;
	myReadFile.open(nameOfFatTree);
	//myReadFile.open("random_testcases.txt");
	string help_to_read;
	myReadFile >> help_to_read;
	(*upper_bound_of_performance) = stod(help_to_read);
	myReadFile >> help_to_read;
	(*upper_bound_number_of_security) = stod(help_to_read);
	myReadFile >> help_to_read;
	(*upper_bound_number_of_max_delay) = stod(help_to_read);
	myReadFile >> help_to_read;
	(*max_of_bandwidth) = stod(help_to_read);
	myReadFile >> help_to_read;
	(*fat_tree_size) = str_to_int(help_to_read);
	//cout << fat_tree_size << " " << endl;
	//---------
	fat_tree = new double *[(*fat_tree_size) + 100];
	for (int i = 0; i < (*fat_tree_size); ++i)
	{
		fat_tree[i] = new double[(*fat_tree_size) + 100];
	}
	//---------
	for (int i = 0; i < (*fat_tree_size); ++i)
	{
		for (int j = 0; j < (*fat_tree_size); ++j)
		{
			fat_tree[i][j] = 0;
		}
	}
	//---------
	int start_of_edges = -1;
	int help_index = 0;
	vector<double> security_help;
	for (int i = 0; i < (*fat_tree_size); ++i)
	{
		int index, number_of_neibours;
		int type;
		myReadFile >> help_to_read;
		index = str_to_int(help_to_read);
		//cout<<index<<" ";
		//cout<<index<<"\n";
		myReadFile >> help_to_read;
		type = str_to_int(help_to_read);
		//cout<<type<<"\n";
		//cout<<(char)type<<"\n";
		myReadFile >> help_to_read;
		number_of_neibours = str_to_int(help_to_read);
		//cout<<number_of_neibours<<"\n";
		//--------------
		for (int j = 0; j < number_of_neibours; ++j)
		{
			int help;
			double throughput;
			myReadFile >> help_to_read;
			help = str_to_int(help_to_read);
			myReadFile >> help_to_read;
			throughput = stod(help_to_read);
			fat_tree[index][help] = fat_tree[help][index] = throughput;
		}
		if (type == 'e' && start_of_edges == -1){
			start_of_edges = i;
		}
		if (type == 'e'){
			//cout<<"hast"<<endl;
			double foo;
			myReadFile >> help_to_read;
			foo = stod(help_to_read);
			(*index_map_reverse)[help_index] = index;
			//cout<<index<<" "<<help_index<<"\n";
			(*index_map)[index] = help_index++;
			security_help.push_back(foo);
			myReadFile >> help_to_read;
			foo = stod(help_to_read);
			//cout<<"perfomance";
			fat_tree[index][index] = foo;
			(*network_size)++;
		}
	}

	/*for (int i = 0; i < fat_tree_size; ++i)
	{
	for (int j = 0; j < fat_tree_size; ++j)
	{
	cout<<fat_tree[i][j]<<" ";
	}
	cout<<"\n";
	}*/
	//cout<<"foo3"<<network_size-1<<"\n";
	//network_size = network_size - start_of_edges ;
	//cout << "Fat tree loaded!" << endl;

	//cout<<"Ns"<<network_size<<endl;
	sg_network = new double*[(*network_size)];
	sg_security = new double*[(*network_size)];
	sg_max_delay = new double*[(*fat_tree_size)];


	for (int i = 0; i < (*network_size); ++i)
	{
		sg_network[i] = new double[(*network_size)];
		sg_security[i] = new double[(*network_size)];
		//sg_max_delay[i] = new int[network_size];

	}
	for (int i = 0; i < (*network_size); ++i)
	{
		for (int j = 0; j < (*network_size); j++)
		{
			sg_network[i][j] = sg_security[i][j] = 0;
		}
	}

	for (int i = 0; i < (*fat_tree_size); ++i)
	{
		sg_max_delay[i] = new double[(*fat_tree_size)];
	}


	// max_delay
	int just_for_fun;
	myReadFile >> help_to_read;
	myReadFile >> help_to_read;
	just_for_fun = str_to_int(help_to_read);

	for (int i = 0; i < just_for_fun; ++i)
	{
		for (int j = 0; j < just_for_fun; ++j)
		{
			myReadFile >> help_to_read;
			sg_max_delay[i][j] = stod(help_to_read);
			//cout<<sg_max_delay[i][j]<<"H";
		}
		//cout<<endl;
	}
	//cout<<"Boy"<<endl;
	myReadFile.close();

	//cout << "Fat tree max delay loaded!\n";

	// security
	for (int i = 0; i < (*network_size); ++i)
	{
		sg_security[i][i] = security_help[i];
	}
}

void testCasesPermutationRead(string nameOfTestcases, int * number_of_queries, vector<int> &queries){
	ifstream testcase_reader;
	testcase_reader.open("random_testcases.txt");
	string help_to_read;
	testcase_reader >> help_to_read;
	(*number_of_queries) = str_to_int(help_to_read);
	for (int i = 0; i < (*number_of_queries); ++i)
	{
		testcase_reader >> help_to_read;
		queries.push_back(str_to_int(help_to_read));
	}
}