#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "namescore.h"

#define size 0xFFFFFFFF

using namespace std;

/* Returns amount of lines for a specific file. */
int getLinesCount(char* file);

int main() {
	int total_score = 0;
	int cnt = getLinesCount("names_and_score.txt");
	vector<NameScore> v_ns;
	ifstream ifile;
	ifile.open("names_and_score.txt");

	if (ifile.is_open()) 
	{
		// Read in the data from the file and store it in a vector<NameScore>. Also calculate the total score. The total score s is defined as s = sum of ( (score of name) * (position in ordered list) )
		for (int i = 0; i < cnt; i++) 
		{
			NameScore ns;
			ifile >> ns;
			v_ns.push_back(ns);
		}
	}

	// Sort the lines by the alphabetical order of the names
	sort(v_ns.begin(), v_ns.end());
	for (int i = 0; i < cnt; i++)
	{
		// (score of name) * (position in ordered list)
		total_score += v_ns[i].getScore() * (i+1);
	}
	// Print out the 2500th name and the total score
	cout << "The 2500th name in the sorted list is: " << v_ns[2499].getName() << endl;
	cout << "total name score = " << total_score << endl;

	ifile.close();
	return 0;
}

/*
*	Returns amount of lines of a text file.
*/
int getLinesCount(char* file) {
	int cnt;	
	ifstream ifile;
	ifile.open(file);
	
	cnt = count(istreambuf_iterator<char>(ifile), istreambuf_iterator<char>(), '\n');

	ifile.close();
	return cnt;
}
