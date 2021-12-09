//USE VALGRIND ./*FILENAME TO TEST FOR MEMORYLEAK, Sweety~

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define M 5

int main()
{
	int K = M*N;
	printf("%d", K);
	int **A = (int**)malloc(K * sizeof(int*));
	int **B = (int**)malloc(K * sizeof(int*));
	int **C = (int**)malloc(K * sizeof(int*));
	for (int i = 0; i < K; ++i)
	{
		A[i] = (int*)malloc(K * sizeof(int));
		B[i] = (int*)malloc(K * sizeof(int));
		C[i] = (int*)malloc(K * sizeof(int));
	}

	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", A[i][j]);
		}printf("\n");
	}printf("\n");

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", B[i][j]);
		}printf("\n");
	}printf("\n");

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < K; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf("%d ", C[i][j]);
		}printf("\n");
	}printf("\n");

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