#include <iostream>
#include <fstream>
#include "MatrixMultiplication.h"
//#include "MatrixMultiplication.cpp"
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include <type_traits>
#include <typeinfo>


int main(int argc, const char * argv[]) {

	string filename;
	string temp;
	string line;
	string size;

	int i = 0;
	int j = 0;
	int linecount = 1;
	int linecount1 = 1;
	// File Read Operation
	cout << "Enter file name: ";
	cin >> filename;
	ifstream ifs;
	ifs.open(filename.c_str());

	getline(ifs, size);

	//cout << size << endl;

	long long sizeN = stoi(size);
	cout << sizeN << endl;


	getline(ifs, temp); // empty line 

	vector<long long> aMatrixV;
	vector<long long> bMatrixV;
	vector<long long> rMatrixV;
	vector<long long> rMatrixV2;
	vector<long long> rMatrixV3;
	int lineint;

	//cout << '2';

		//cout<<"A Matrix:" <<endl;
		int numbercount = 0;
		while(linecount != sizeN){
			for (i=0; i<sizeN; i++){
				for (j=0; j<sizeN; j++){
					getline(ifs, line, ' ');
						if (line == "\n"){
							break;
						}
					aMatrixV.push_back(stoi(line));
					numbercount = numbercount + 1;
					 if (numbercount ==sizeN){
						 numbercount = 0;
					 }
				}
				linecount = linecount + 1;
			}
			break;
		}





	getline(ifs, temp); // empty line
	linecount = 1;
	numbercount = 0;
	while (linecount != sizeN) {
		for (i = 0; i < sizeN; i++) {
			for (j = 0; j < sizeN; j++) {
				getline(ifs, line, ' ');
				if (line == "\n") {
					break;
				}
				bMatrixV.push_back(stoi(line));
				numbercount = numbercount + 1;
				if (numbercount == sizeN) {
					numbercount = 0;
				}
			}
			linecount = linecount + 1;
		}
		break;
	}
	

	linecount = 1;
	numbercount = 0;
	while (linecount != sizeN) {
		for (i = 0; i < sizeN; i++) {
			for (j = 0; j < sizeN; j++) {
				rMatrixV.push_back(0);
				numbercount = numbercount + 1;
				if (numbercount == sizeN) {
					numbercount = 0;
				}
			}
			linecount = linecount + 1;
		}
		break;
	}
	
	linecount = 1;
	numbercount = 0;
	while (linecount != sizeN) {
		for (i = 0; i < sizeN; i++) {
			for (j = 0; j < sizeN; j++) {
				rMatrixV2.push_back(0);
				numbercount = numbercount + 1;
				if (numbercount == sizeN) {
					numbercount = 0;
				}
			}
			linecount = linecount + 1;
		}
		break;
	}
	
	linecount = 1;
	numbercount = 0;
	while (linecount != sizeN) {
		for (i = 0; i < sizeN; i++) {
			for (j = 0; j < sizeN; j++) {
				rMatrixV2.push_back(0);
				numbercount = numbercount + 1;
				if (numbercount == sizeN) {
					numbercount = 0;
				}
			}
			linecount = linecount + 1;
		}
		break;
	}
	

	long double duration;
	clock_t start = clock();
	matrixMult1(aMatrixV, bMatrixV, rMatrixV, sizeN);
	clock_t end = clock();
	duration = (end - start) / (long double)CLOCKS_PER_SEC;
	std::cout << "Duration of IJK: " << duration << " seconds.\n";

	// Matrix Mult 2
	start = clock();
	matrixMult2(aMatrixV, bMatrixV, rMatrixV, sizeN);
	end = clock();
	duration = (end - start) / (long double)CLOCKS_PER_SEC;
	std::cout << "Duration of KIJ: " << duration << " seconds.\n";

	// Matrix Mult 3
	start = clock();
	matrixMult3(aMatrixV, bMatrixV, rMatrixV2, sizeN);
	end = clock();
	duration = (end - start) / (long double)CLOCKS_PER_SEC;
	std:cout << "Duration of JKI: " << duration << " seconds.\n";

	// Matrix Mult Blocking
	//INPUT BLOCK SIZE//
	int block_size = 5;
	start = clock();
	blockingMatrixMult(aMatrixV, bMatrixV, rMatrixV3, sizeN, block_size);
	end = clock();
	duration = (end - start) / (long double)CLOCKS_PER_SEC;
	std::cout << "Duration of BIJK: " << duration << " seconds.\n";

	return 0;
}
