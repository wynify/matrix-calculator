/*Нужно добавить:
	1. Новый интерфейс с возможностью выбора действия над матрицой. 					+
	2. Добавление квадратных матриц(по формуле возможно добавлять только квадратные)	+
	3. Отнимание квадратных матриц(по формуле возможно отнимать только квадратные)		+

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
//Matrix announcement
	int rowsA, colsA, rowsB, colsB;
	int ** A;
	int ** B;
	int ** C;

//new UI
	int FunctionForMatrix;
	printf("Please enter a funtion wich you want to do:\n");
	printf("1. Addition matrix(Matrices must be the same size!)\n2. Subtraction matrix(Matrices must be the same size!)\n3. Multiplication matrix(Any dimension)\nEnter: ");
	scanf("%d", &FunctionForMatrix);

	printf("Welcome!\nPlease enter a two Matrix\n");

	printf("Enter number of A rows: ");
	scanf("%d", &rowsA);
	printf("Enter number of A cols: ");
	scanf("%d", &colsA);

	printf("\n");

	printf("Enter number of B rows: ");
	scanf("%d", &rowsB);
	printf("Enter number of B cols: ");
	scanf("%d", &colsB);

	int sizeA = rowsA*colsA;
	int sizeB = rowsB*colsB;
	int sizeC = rowsA*colsB;
	int sizeAll = sizeA+sizeB;

//allocate
	A = (int**)malloc(sizeA * sizeof(int*));
	for (int i = 0; i < sizeA; ++i)
	{
		A[i] = (int*)malloc(i * sizeof(int));
	}

//allocate 
	B = (int**)malloc(sizeB * sizeof(int*));
	for (int i = 0; i < sizeB; ++i)
	{
		B[i] = (int*)malloc(i * sizeof(int));
	}

//allocate 
	C = (int**)malloc(sizeC * sizeof(int*));
	for (int i = 0; i < sizeC; ++i)
	{
		C[i] = (int*)malloc(i * sizeof(int));
	}

//DEBUG PRINTING
/*
	printf("Size of A matrix = %d\n", sizeA);
	printf("Size of B matrix = %d\n", sizeB);
	printf("Size of C matrix = %d\n", sizeC);
	printf("Size of ALL = %d\n", sizeAll);
*/

	if (FunctionForMatrix == 1)
	{
	//filling A
		printf("Eneter numbers of matrix A: \n");
		for (int i = 0; i < rowsA; ++i)
		{
			for (int j = 0; j < colsA; ++j)
			{
				scanf("%d", &A[i][j]);
			}
		}
	//filling B
		printf("Eneter numbers of matrix B: \n");
		for (int i = 0; i < rowsB; ++i)
		{
			for (int j = 0; j < colsB; ++j)
			{
				scanf("%d", &B[i][j]);
			}
		}

	//Addition
		for (int i = 0; i < sizeC; ++i)
		{
			for (int j = 0; j < sizeC; ++j)
			{
				C[i][j] += A[i][j] + B[i][j];
			}
		}
	}

	if (FunctionForMatrix == 2)
	{
	//filling A
		printf("Eneter numbers of matrix A: \n");
		for (int i = 0; i < rowsA; ++i)
		{
			for (int j = 0; j < colsA; ++j)
			{
				scanf("%d", &A[i][j]);
			}
		}
	//filling B
		printf("Eneter numbers of matrix B: \n");
		for (int i = 0; i < rowsB; ++i)
		{
			for (int j = 0; j < colsB; ++j)
			{
				scanf("%d", &B[i][j]);
			}
		}

	//Subtraction
		for (int i = 0; i < sizeC; ++i)
		{
			for (int j = 0; j < sizeC; ++j)
			{
				C[i][j] += A[i][j] - B[i][j];
			}
		}
	}

	if (FunctionForMatrix == 3)
	{
	//filling A
		printf("Eneter numbers of matrix A: \n");
		for (int i = 0; i < rowsA; ++i)
		{
			for (int j = 0; j < colsA; ++j)
			{
				scanf("%d", &A[i][j]);
			}
		}

	//filling B
		printf("Eneter numbers of matrix B: \n");
		for (int i = 0; i < rowsB; ++i)
		{
			for (int j = 0; j < colsB; ++j)
			{
				scanf("%d", &B[i][j]);
			}
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
	}
	else{
		printf("You don't enter a function which you want to do with matrix :c\n");
	}

//end of UI

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