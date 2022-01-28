//
//  MatrixMultiplication.h
//  P7
//
//  Name:
//  UIN:

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#ifndef MatrixMultiplication_h
#define MatrixMultiplication_h
//int sizeN = 3;
void matrixMult1(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV, const long long sizeN);

void matrixMult2(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV2, const long long sizeN);

void matrixMult3(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV3, const long long sizeN);

void blockingMatrixMult(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV, const long long sizeN, const int block_size);

#endif /* MatrixMultiplication_h */
