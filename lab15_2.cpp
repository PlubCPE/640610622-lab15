#include<iostream>
#include<string>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}


void inputMatrix(double A[][N])
{
	
	for(int i = 0 ; i < N ; i++)
	{
		cout << "Row " << i+1 << ": " ;
		for(int j = 0 ; j < N  ; j++)
		{
		    cin  >> A[i][j];
		    
		}
	
	}
}

void findLocalMax(const double A[][N], bool B[][N])
{
	for(int i = 0 ; i < N-2 ; i++)
	{
		 for(int j = 0 ; j < N-2 ; j++)
		 {
			 if(A[i+1][j+1] >= A[i][j+1] && A[i+1][j+1] >= A[i+1][j+2] && A[i+1][j+1] >= A[i+1][j] && A[i+1][j+1] >= A[i+2][j+1])
			 B[i+1][j+1] = true;

			 else
			 B[i+1][j+1] = false;
		 }
	}

	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			if(B[i][j] != 1)
			B[i][j] = false;
		}
	}

}

void showMatrix(const bool A[][N])
{
	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			cout << A[i][j] << " " ;
			if(j == N -1)
			cout << endl;
			
		}
	}

}

