#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "namescore.h"

#define size 0xFFFFFFFF

using namespace std;



int main() {
	char ns[size];
	int total_score = 0;
	vector<NameScore> v_ns;
	ifstream ifile;
	
	ifile.read("name_and_score.txt", size)
	while ()

	sort(v_ns.begin(), v_ns.end());

	for (int i = 1; i <= v_ns.end(); i++) {
		total_score += v_ns[i-1] * i;
	}
}
