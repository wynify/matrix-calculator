#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	int rowsA, colsA, rowsB, colsB;
	int ** A;
	int ** B;
	int ** C;
	
	printf("Enter number of A rows: ");
	scanf("%d", &rowsA);
	printf("Enter number of A cols: ");
	scanf("%d", &colsA);

	printf("\n");

	printf("Enter number of B rows: ");
	scanf("%d", &rowsB);
	printf("Enter number of B cols: ");
	scanf("%d", &colsB);

	if (rowsA != colsB) 
	{
		while(true)
		{
			printf("Rows A need to be equal to Cols B.\n Please reenter number: ");
			scanf("%d", &rowsA);
		}
	}
	if(colsB != rowsA)
	{
		while(true)
		{
			printf("Cols B need to be equal to Rows A.\n Please reenter number: ");
			scanf("%d", &colsB);
		}
	}

	int sizeA = rowsA*colsA;
	int sizeB = rowsB*colsB;
	int sizeC = rowsA*colsB;
	int sizeAll = sizeA+sizeB;

//DEBUG PRINTING
/*
	printf("Size of A matrix = %d\n", sizeA);
	printf("Size of B matrix = %d\n", sizeB);
	printf("Size of C matrix = %d\n", sizeC);
	printf("Size of ALL = %d\n", sizeAll);
*/

//allocate
	A = (int**)malloc(sizeA * sizeof(int*));
	for (int i = 0; i < sizeA; ++i)
	{
		A[i] = (int*)malloc(i * sizeof(int));
	}

//filling
	printf("Eneter numbers of matrix A: \n");
	for (int i = 0; i < rowsA; ++i)
	{
		for (int j = 0; j < colsA; ++j)
		{
			scanf("%d", &A[i][j]);
		}
	}

//allocate 
	B = (int**)malloc(sizeB * sizeof(int*));
	for (int i = 0; i < sizeB; ++i)
	{
		B[i] = (int*)malloc(i * sizeof(int));
	}

//filling
	printf("Eneter numbers of matrix B: \n");
	for (int i = 0; i < rowsB; ++i)
	{
		for (int j = 0; j < colsB; ++j)
		{
			scanf("%d", &B[i][j]);
		}
	}

//printing A
	printf("Matrix A: \n");
	for (int i = 0; i < rowsA; ++i)
	{
		for (int j = 0; j < colsA; ++j)
		{
			printf("[%d] ", A[i][j]);
		}printf("\n");
	}printf("\n");

//printing B
	printf("Matrix B: \n");
	for (int i = 0; i < rowsB; ++i)
	{
		for (int j = 0; j < colsB; ++j)
		{
			printf("[%d] ", B[i][j]);
		}printf("\n");
	}printf("\n");	

//allocate C
	C = (int**)malloc(sizeC * sizeof(int*));
	for (int i = 0; i < sizeC; ++i)
	{
		C[i] = (int*)malloc(i * sizeof(int));
	}

//Multiplication
	for (int i = 0; i < sizeC; ++i)
	{
		for (int j = 0; j < sizeC; ++j)
		{
			C[i][j] = 0;
			for (int k = 0; k < sizeC; ++k)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
//printing product
	printf("Multiplication of Matrix A and Matrix B: \n");
	for (int i = 0; i < rowsA; ++i)
	{
		for (int j = 0; j < colsB; ++j)
		{
			printf("[%d] ", C[i][j]);
		}printf("\n");
	}printf("\n");

//free
	for (int i = 0; i < sizeA; ++i)
	{
		free(A[i]);
	}
	for (int i = 0; i < sizeB; ++i)
	{
		free(B[i]);
	}
	for (int i = 0; i < sizeC; ++i)
	{
		free(C[i]);
	}
	free(A);
	free(B);
	free(C);

	return 0;
}
