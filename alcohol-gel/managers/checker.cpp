#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;


int wrong_ans() {
	cout << "0.0\n";
	return 0;
}

int right_ans() {
	cout << "1.0\n";
	return 0;
}

int main (int argc, char *argv[]) {
	ifstream fin;  	// Input
	ifstream fcorr;	// Expected
	ifstream ftest;	// Submission
	
	fin.open(argv[1]);
	fcorr.open(argv[2]);
	ftest.open(argv[3]);
	
	if (argc < 4) {
		cerr << "Missing parameter. Please contact contest administrator.\n";
		return -1;
	}
	
	if (!fin.is_open()) {
		cerr << "Could not open file \"" << argv[1] << "\". Please contact contest administrator.\n";
		return 1;
	}

	if (!fcorr.is_open()) {
		cerr << "Could not open file \"" << argv[2] << "\". Please contact contest administrator.\n";
		return 2;
	}

	if (!ftest.is_open()) {
		cerr << "Could not open file \"" << argv[3] << "\". Please contact contest administrator.\n";
		return 3;
	}

	int n; 
	fin >> n;
	std::vector<int> daily(n);
	for(int i = 0; i < n; ++i) {
		int c, p, k, v;
		fin >> c >> p >> k >> v;
		daily[i] = k*v - c*p;
	}
	int corr_a, corr_b, corr_s;
	fcorr >> corr_a >> corr_b >> corr_s;
	int test_a, test_b, test_s;
	ftest >> test_a >> test_b >> test_s;
	if(test_s != corr_s) {
		return wrong_ans();
	}
	if(test_b - test_a != corr_b - corr_a) {
		return wrong_ans();
	}
	int s = 0;
	for(int i = test_a - 1; i < test_b; ++i) {
		s += daily[i];
	}
	return (s == test_s ? right_ans() : wrong_ans());
}
