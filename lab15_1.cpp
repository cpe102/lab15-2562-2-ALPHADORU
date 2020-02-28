#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *data,int N,int M){
	for(int i=0;i<N;i++){
	double D;
		for(int j=0;j<M;j++){
			D = rand()%101;
			*(data+i*M+j) = D/100;
		}
	}
}

void showData(double *data,int N,int M){
	for(int i=0; i<N ; i++){
		for(int j=0; j<M ; j++){
			cout << *(data+i*M+j) << " " ;
		}
		cout << "\n";
	}
}

void findRowSum(const double *data,double *output,int N,int M){
	for(int i=0;i < N;i++){
		for(int j=0; j<M; j++){
			*(output+i) += *(data+i*M+j);
		}
	}
}