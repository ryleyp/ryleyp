//
//  MatrixMultiplication.cpp
//  P7
//
//  Name:
//  UIN:

#include <iostream>
#include <fstream>
#include "MatrixMultiplication.h"
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#include <type_traits>
#include <typeinfo>


// IJK MULTIPLICATION
void matrixMult1(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV, const long long sizeN){

	long long aMatrix[sizeN][sizeN];
	long long bMatrix[sizeN][sizeN];
	long long rMatrix[sizeN][sizeN];
	
	long long aint = 0;
	long long bint = 0;
	string astr;
	string bstr;
	int sum = 0;
	string sumstr;
	int i , j, k, m;
    // Matrix Mult 1
	int linecount = 0;
	int numbercount = 0;
	i = 0;
	j = 0;
	int anum, bnum;
	for(m=0; m < (sizeN * sizeN); m++){
		anum = aMatrixV[m];
		aMatrix[j][i]= (anum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0;
		}
		if (j == sizeN){
			break;
		}
	}
	//PRINT OUT MATRIX A
	// cout <<"A Matrix: "<<endl;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << aMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					// // cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }
	i = 0;
	j = 0;
	for(m=0; m < (sizeN * sizeN); m++){
		bnum = bMatrixV[m];
		bMatrix[j][i]= (bnum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0; 
		}
		if (j == sizeN){
			break;
		}
	}
	
	//PRINT OUT MATRIX B
	// // cout<<sizeN<<endl;
	 // //cout <<"B Matrix: "<<endl;
	// linecount = 0;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << bMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }
	for(i=0; i<sizeN; i++){
		for (j=0; j<sizeN; j++){
			sum = 0.0;
			for (k=0; k<sizeN; k++){
				sum += aMatrix[i][k] * bMatrix[k][j];
				////cout << "sum: "<<sum<<endl;
				
			}
			rMatrix[i][j] = (sum);
		}
	}

	// PRINT OUT PRODUCT WITH IJK ORDER // 
	//cout <<"IJK output: " <<endl;
	//linecount = 0;
	//numbercount = 0;
	 //while(linecount != sizeN){
		 //for (i=0; i<sizeN; i++){
			 //for (j=0; j<sizeN; j++){
				 //cout << rMatrix[i][j]<< ' ';
				 //numbercount = numbercount + 1;
				 //cout << numbercount << endl;
				 //if (numbercount ==sizeN){
					// cout<<endl;
					 //numbercount = 0;
				// }
			// }
			// linecount = linecount + 1;
		//  }
		// break;
	// }
}
// KIJ MULTIPLICATION
void matrixMult2(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV2, const long long sizeN){
	long long aMatrix[sizeN][sizeN];
	long long bMatrix[sizeN][sizeN];
	long long rMatrix2[sizeN][sizeN];
	
	int aint = 0;
	int bint = 0;
	string astr;
	string bstr;
	int sum = 0;
	string sumstr;
	int i , j, k, m;
    // Matrix Mult 1
	int linecount = 0;
	int numbercount = 0;
	i = 0;
	j = 0;
	int anum, bnum;
	for(m=0; m < (sizeN * sizeN); m++){
		anum = aMatrixV[m];
		aMatrix[j][i]= (anum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0;
		}
		if (j == sizeN){
			break;
		}
	}
	//PRINT OUT MATRIX A
	//cout<<sizeN<<endl;
	// cout <<"A Matrix: "<<endl;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << aMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }

	i = 0;
	j = 0;
	for(m=0; m < (sizeN * sizeN); m++){
		bnum = bMatrixV[m];
		bMatrix[j][i]= (bnum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0; 
		}
		if (j == sizeN){
			break;
		}
	}
	//PRINT OUT MATRIX B
	// cout<<sizeN<<endl;
	 //cout <<"B Matrix: "<<endl;
	linecount = 0;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << bMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }

	for(k=0; k<sizeN; k++){
		for (i=0; i<sizeN; i++){
			aint = aMatrix[i][k];
			for (j=0; j<sizeN; j++){
				rMatrix2[i][j] += aint * bMatrix[k][j];
				////cout << "sum: "<<sum<<endl;
				
			}
		}
	}
	// PRINT OUT KIJ PRODUCT //

//	//cout <<"KIJ output: " <<endl;
	// linecount = 0;
	// numbercount = 0;
	 // while(linecount != sizeN){
		 // for (i=0; i<sizeN; i++){
			 // for (j=0; j<sizeN; j++){
				// // cout << rMatrix2[i][j]<< ' ';
				 // numbercount = numbercount + 1;
				 // //cout << numbercount << endl;
				 // if (numbercount ==sizeN){
					// // cout<<endl;
					 // numbercount = 0;
				 // }
			 // }
			 // linecount = linecount + 1;
		  // }
		 // break;
	 // }
}

// JKI MULTIPLICATION
void matrixMult3(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV3, const long long sizeN){
	long long aMatrix[sizeN][sizeN];
	long long bMatrix[sizeN][sizeN];
	long long rMatrix3[sizeN][sizeN];
	
	int aint = 0;
	int bint = 0;
	string astr;
	string bstr;
	int sum = 0;
	string sumstr;
	int i , j, k, m;
    // Matrix Mult 1
	int linecount = 0;
	int numbercount = 0;
	i = 0;
	j = 0;
	int anum, bnum;
	for(m=0; m < (sizeN * sizeN); m++){
		anum = aMatrixV[m];
		aMatrix[j][i]= (anum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0;
		}
		if (j == sizeN){
			break;
		}
	}
	// PRINT OUT MATRIX A
	//cout<<sizeN<<endl;
	// cout <<"A Matrix: "<<endl;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << aMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					// // cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }

	i = 0;
	j = 0;
	for(m=0; m < (sizeN * sizeN); m++){
		bnum = bMatrixV[m];
		bMatrix[j][i]= (bnum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0; 
		}
		if (j == sizeN){
			break;
		}
	}
	// PRINT OUT MATRIX B
	// cout<<sizeN<<endl;
	 //cout <<"B Matrix: "<<endl;
	// linecount = 0;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << bMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }


	for(j=0; j<sizeN; j++){
		for (k=0; k<sizeN; k++){
			bint = bMatrix[i][j];
			for (i=0; i<sizeN; i++){
				rMatrix3[i][j] += aMatrix[i][k] * bint;
				////cout << "sum: "<<sum<<endl;
				
			}
		}
	}
	// PRINT OUT JKI PRODUCT OUTPUT //

//	//cout <<"JKI output: " <<endl;
	// linecount = 0;
	// numbercount = 0;
	 // while(linecount != sizeN){
		 // for (i=0; i<sizeN; i++){
			 // for (j=0; j<sizeN; j++){
				 // //cout << rMatrix3[i][j]<< ' ';
				 // numbercount = numbercount + 1;
				 // //cout << numbercount << endl;
				 // if (numbercount ==sizeN){
					// // cout<<endl;
					 // numbercount = 0;
				 // }
			 // }
			 // linecount = linecount + 1;
		  // }
		 // break;
	 // }
}

// BIJK MULTIPLICATION
void blockingMatrixMult(vector<long long>  aMatrixV, vector<long long>  bMatrixV, vector<long long> rMatrixV3, const long long sizeN, const int block_size) {

	long long aMatrix[sizeN][sizeN];
	long long bMatrix[sizeN][sizeN];
	long long rMatrix[sizeN][sizeN];
	
	long long aint = 0;
	long long bint = 0;
	string astr;
	string bstr;
	int sum = 0;
	string sumstr;
	int i , j, k, m, kk, jj;
    // Matrix Mult 1
	int linecount = 0;
	int numbercount = 0;
	i = 0;
	j = 0;
	int anum, bnum;
	for(m=0; m < (sizeN * sizeN); m++){
		anum = aMatrixV[m];
		aMatrix[j][i]= (anum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0;
		}
		if (j == sizeN){
			break;
		}
	}
	// PRINT OUT MATRIX A
	//cout<<sizeN<<endl;
	// cout <<"A Matrix: "<<endl;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << aMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					// // cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }

	i = 0;
	j = 0;
	for(m=0; m < (sizeN * sizeN); m++){
		bnum = bMatrixV[m];
		bMatrix[j][i]= (bnum);
		i++;
		if (i == (sizeN)){
			j++;
			i = 0; 
		}
		if (j == sizeN){
			break;
		}
	}
	// PRINT OUT MATRIX B
	// cout<<sizeN<<endl;
	 //cout <<"B Matrix: "<<endl;
	// linecount = 0;
	// while(linecount != sizeN){
		// for (i=0; i<sizeN; i++){
			// for (j=0; j<sizeN; j++){
				// //cout << bMatrix[i][j]<<' ';
				// numbercount = numbercount + 1;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			// }
			// linecount = linecount + 1;
		// }
		// break;
	// }

	int en = block_size*(sizeN/block_size);
	
	for (i=0;i<sizeN;i++){
		for (j=0;j<sizeN;j++){
			rMatrix[i][j] = 0.0;
		}
	}
	
	for(kk = 0; kk<en; kk+=block_size){
		for(jj = 0; jj<en; jj+=block_size){
			for(i=0; i<sizeN; i++){
				for (j = jj; j < (jj+block_size); j++){
					sum = rMatrix[i][j];
					for (k = kk; k < (kk+block_size); k++){
						sum +=aMatrix[i][k]*bMatrix[k][j];
					}
					rMatrix[i][j] = sum;
				}
			}
		}
	}
	



	// PRINT OUT BIJK OUTPUT //
	 // linecount = 0;
	 // numbercount = 0;
	 // while(linecount != sizeN){
		 // for (i=0; i<sizeN; i++){
			 // for (j=0; j<sizeN; j++){
				 // //cout << rMatrix[i][j]<< ' ';
				 // numbercount = numbercount + 1;
				 // //cout << numbercount << endl;
				 // if (numbercount ==sizeN){
					 // //cout<<endl;
					 // numbercount = 0;
				 // }
			 // }
			 // linecount = linecount + 1;
		  // }
		 // break;
	 // }
}
