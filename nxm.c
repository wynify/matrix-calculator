#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
//Entering numbers of Cols and Rows

	int N, M;
	printf("Enter an N row: ");
	scanf("%d", &N);
	if (N < 0)
	{
		printf("Row can't be an negative number.");
	}

	printf("Enter an M col ");
	scanf("%d", &M);
	if (M < 0)
	{
		printf("Col can't be an negative number.");
	}

//Allocate memmory for matrix
	int K = N*M;
	printf("%d \n\n\n", K);
	int ** A = malloc(K * sizeof(int*));
	int ** B = malloc(K * sizeof(int*));
	int ** C = malloc(K * sizeof(int*));

	for (int i = 0; i < K; ++i)
	{
		A[i] = malloc(K * sizeof(int*));
		B[i] = malloc(K * sizeof(int*));
		C[i] = malloc(K * sizeof(int*));
	}

/*

Rand numbers in Matrix

srand(time(NULL));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			A[i][j] = rand() %10;
			B[i][j] = rand() %10;
		}
	}
*/

//Entering numbers
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d ", &A[i][j]);
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%d ", &B[i][j]);
		}
	}printf("\n");

//Printing A matrix
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", A[i][j]);
		}printf("\n");
	}printf("\n");

//Printing B matrix
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", B[i][j]);
		}printf("\n");
	}printf("\n");

//Multipliing matrixs
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < K; ++k)
			{
				C[i][j] += A[i][j] * B[i][j];
			}
		}
	}

//Printing C matrix
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}

//Free memory after all calculations
	for (int i = 0; i < K; ++i)
	{
		free(A[i]);
		free(B[i]);
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);


	return 0;
}