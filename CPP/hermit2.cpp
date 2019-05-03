#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define R_MAX 10
#define C_MAX 10
#define WIDTH 8

typedef struct
{
	int Re;
	int Im;
} complex;

void mInput(complex ar[R_MAX][C_MAX], int r, int c);
void cConjugate(complex ar[R_MAX][C_MAX], int r, int c, complex res[R_MAX][C_MAX]);
void mTranspose(complex ar1[R_MAX][C_MAX], int r, int c, complex ar2[R_MAX][C_MAX]);
int isHermitian(complex ar[R_MAX][C_MAX], int r, int c);
int isSkewHermitian(complex ar[R_MAX][C_MAX], int r, int c);
void addMatrices(complex ar1[R_MAX][C_MAX], int r1, int c1, complex ar2[R_MAX][C_MAX], int r2, int c2, complex ar3[R_MAX][C_MAX]);
void subtMatrices(complex ar1[R_MAX][C_MAX], int r1, int c1, complex ar2[R_MAX][C_MAX], int r2, int c2, complex ar3[R_MAX][C_MAX]);
complex addComplex(complex z1, complex z2);
complex subtComplex(complex z1, complex z2);
void sumHermSkew(complex ar[R_MAX][C_MAX], int r, int c);
void mOutput(complex ar[R_MAX][C_MAX], int r, int c);
complex strToComplex(char* str);
void init();
int printMenu();
int calcWidth(complex z);

int main()
{
	complex ar1[R_MAX][C_MAX];
	int r1, c1;

	complex ar2[R_MAX][C_MAX];
	int r2, c2;

	complex ar3[R_MAX][C_MAX];

	while(1)
	{
		init();
		//Get choice as return value from menu
		int choice = printMenu();

		//Use menu based on choice of user
		switch(choice)
		{
			case 1:
				//printf("You chose complex conjugate.\n");
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				cConjugate(ar1, r1, c1, ar2);
				printf("Complex Conjugate: \n");
				mOutput(ar2, r1, c1);
				break;

			case 2:
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				mTranspose(ar1, r1, c1, ar2);
				printf("Transpose Matrix: \n");
				mOutput(ar2, c1, r1);
				break;

			case 3:
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				if(isHermitian(ar1, r1, c1))
					printf("The given Matrix is HERMITIAN.\n");
				else
					printf("The given Matrix is NOT HERMITIAN.\n");
				break;

			case 4:
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				if(isSkewHermitian(ar1, r1, c1))
					printf("The given Matrix is SKEW HERMITIAN.\n");
				else
					printf("The given Matrix is NOT SKEW HERMITIAN.\n");
				break;

			case 5:
				printf("Enter Number of Rows and Columns of First Matrix: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				printf("Enter Number of Rows and Columns of Second Matrix: ");
				scanf("%d%d", &r2, &c2);
				getchar();
				mInput(ar2, r2, c2);
				addMatrices(ar1,r1,c1,ar2,r2,c2,ar3);
				printf("Answer: \n");
				mOutput(ar3, r2, c2);
				break;

			case 6:
				printf("Enter Number of Rows and Columns of First Matrix: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				printf("Enter Number of Rows and Columns of Second Matrix: ");
				scanf("%d%d", &r2, &c2);
				getchar();
				mInput(ar2, r2, c2);
				subtMatrices(ar1,r1,c1,ar2,r2,c2,ar3);
				printf("Answer: \n");
				mOutput(ar3, r2, c2);
				break;

			case 7:
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				getchar();
				mInput(ar1, r1, c1);
				printf("Printing Matrix as a sum of Hermitian and Skew Hermitian Matrices\n");
				sumHermSkew(ar1, r1, c1);
				break;
			case 0:
				printf("Exiting...\n");
				return 0;
			default:
				printf("WRONG CHOICE!\n");
				break;
		}
		printf("Press Enter to Continue...\n");
		getchar();
		getchar();
	}
	return 0;
}

void init()
{
	system("clear");
	printf("***HERMITIAN MATRICES***\n");
}

int printMenu()
{
	printf("1. Get the complex conjugate.\n");
	printf("2. Get the transpose.\n");
	printf("3. Check if the matrix is Hermitian.\n");
	printf("4. Check if the matrix is Skew Hermitian.\n");
	printf("5. Add two complex matrices.\n");
	printf("6. Subtract two complex matrices.\n");
	printf("7. Print a matrix as sum of a Hermitian and Skew Hermitian.\n");
	printf("0. Exit\n");
	printf("Enter your choice: ");
	int c;
	scanf("%d", &c);
	return c;
}

// void mInput(complex ar[R_MAX][C_MAX], int r, int c)
// {
// 	char sign, ch;
// 	printf("Enter elements of the matrix in the form a+bi.\n");
// 	for(int i=0; i<r; ++i)
// 	{
// 		for(int j=0; j<c; ++j)
// 		{
// 			scanf("%d%c%d%c", &ar[i][j].Re, &sign, &ar[i][j].Im, &ch);
// 			if(sign=='-')
// 				ar[i][j].Im=-ar[i][j].Im;
// 			else if(sign == '+');
// 			else
// 			{
// 				printf("Syntax Error!\nABORT...\n");
// 				exit(-1);
// 			}
// 		}
// 	}
// }

void mInput(complex ar[R_MAX][C_MAX], int r, int c)
{
	complex current;
	char str[15];
	printf("Enter elements of the matrix in the form a±bi.\n");
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			scanf("%s", str);
			ar[i][j]=strToComplex(str);
		}
	}
}

complex strToComplex(char* str)
{
	//printf("String I got: %s\n", str);
	char aSign='+',bSign='+', iCount=0, signCount=0;
	char* ptr=str;
	int len=0;
	//Error Checking
	while(*ptr != '\0')
	{
		len++;
		if(*ptr=='-' || *ptr=='+')
		{
			++ptr;
			continue;
		}
		if((!(*ptr > '0' && *ptr < '9')) && (*ptr!='i') && (*ptr!='+') && (*ptr!='-'))
		{
			printf("SYNTAX ERROR! ABORT...\n");
			exit(-1);
		}
		else if(*ptr=='i')
		{
			++iCount;
			if(iCount>1)
			{
				printf("SYNTAX ERROR! ABORT...\n");
				exit(-1);
			}
		}
		else if((*ptr=='+') || (*ptr=='-'))
		{
			++signCount;
			if(signCount>1)
			{
				printf("SYNTAX ERROR! ABORT...\n");
				exit(-1);
			}
		}
		ptr++;
	}


	complex z;
	z.Re=0;
	z.Im=0;


	if(*str=='-' || *str=='+')
	{
		aSign=*str;
		++str;
	}
	if(*str=='i')
	{
		z.Im=1;
		if(aSign=='-')
			z.Im=-z.Im;
		return z;
	}
	while(*str <'9' && *str>'0' && *str!='\0')
	{
		z.Re = z.Re*10 + (*str) - '0';
		++str;
	}
	if(aSign=='-')
		z.Re=-z.Re;

	if(*str == '\0')
		return z;

	if(*str=='i')
	{
		z.Im=z.Re;
		z.Re=0;
		if(*(str+1) != ' ' && *(str+1)!= '\0')
		{
			printf("SYNTAX ERROR! ABORT...\n");
			exit(-1);
		}
		return z;
	}

	if(*str=='-' || *str=='+')
	{
		bSign=*str;
		++str;
	}

	if(*str=='i')
	{
		z.Im=1;
		if(bSign=='-')
			z.Im=-z.Im;
		return z;
	}

	while(*str <'9' && *str>'0' && *str!='\0')
	{
		z.Im = z.Im*10 + (*str) - '0';
		++str;
	}
	if(bSign=='-')
		z.Im=-z.Im;

	return z;
}

void cConjugate(complex ar[R_MAX][C_MAX], int r, int c, complex res[R_MAX][C_MAX])
{
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			res[i][j].Re=ar[i][j].Re;
			res[i][j].Im=-ar[i][j].Im;
		}
	}
}

void mTranspose(complex ar1[R_MAX][C_MAX], int r, int c, complex ar2[R_MAX][C_MAX])
{
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			ar2[i][j].Re=ar1[j][i].Re;
			ar2[i][j].Im=ar1[j][i].Im;
		}
	}
}

int isHermitian(complex ar[R_MAX][C_MAX], int r, int c)
{
	//TODO: Check if Square Matrix
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			if(ar[i][j].Re!=ar[j][i].Re || ar[i][j].Im != -ar[j][i].Im)
				return 0;
		}
	}
	return 1;
}

int isSkewHermitian(complex ar[R_MAX][C_MAX], int r, int c)
{
	//TODO: Check if Square Matrix

	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			if(ar[i][j].Re!=-ar[j][i].Re || ar[i][j].Im != ar[j][i].Im)
				return 0;
		}
	}
	return 1;
}

void addMatrices(complex ar1[R_MAX][C_MAX], int r1, int c1, complex ar2[R_MAX][C_MAX], int r2, int c2, complex ar3[R_MAX][C_MAX])
{
	if(r1!=r2 || c1!=c2)
	{
		printf("Matrices must be of the same order for this operation!\nExiting... \n");
		exit(-1);
	}

	for(int i=0; i<r1; ++i)
	{
		for(int j=0; j<c1; ++j)
		{
			ar3[i][j]=addComplex(ar1[i][j], ar2[i][j]);
		}
	}
}
void subtMatrices(complex ar1[R_MAX][C_MAX], int r1, int c1, complex ar2[R_MAX][C_MAX], int r2, int c2, complex ar3[R_MAX][C_MAX])
{
	if(r1!=r2 || c1!=c2)
	{
		printf("Matrices must be of the same order for this operation!\nExiting... \n");
		exit(-1);
	}

	for(int i=0; i<r1; ++i)
	{
		for(int j=0; j<c1; ++j)
		{
			ar3[i][j]=subtComplex(ar1[i][j], ar2[i][j]);
		}
	}
}
complex addComplex(complex z1, complex z2)
{
	complex temp;
	temp.Re=z1.Re+z2.Re;
	temp.Im=z1.Im+z2.Im;
	return temp;
}
complex subtComplex(complex z1, complex z2)
{
	complex temp;
	temp.Re=z1.Re-z2.Re;
	temp.Im=z1.Im-z2.Im;
	return temp;
}
void sumHermSkew(complex ar[R_MAX][C_MAX], int r, int c)
{
	if(r!=c)
	{
		printf("Operation only supported for Square Matrix!\nABORT...\n");
		exit(-1);
	}
	//Printing First Matrix
	for(int i=0, cur=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			printf("%d", ar[i][j].Re);

			if(ar[i][j].Im<0)
				printf("-%di", -ar[i][j].Im);
			else
				printf("+%di", ar[i][j].Im);
			printf("\t");
		}
		//Printing = sign
		if(i==0)
			printf("=");
		printf("\t");

		//Printing Hermitian Matrix
		for(int j=0; j<c; ++j)
		{
			printf("%.2f", (ar[i][j].Re + ar[j][i].Re)/2.0);

			if(ar[j][i].Im<ar[i][j].Im)
				printf("-%.2fi", -(ar[i][j].Im-ar[j][i].Im)/2.0);
			else
				printf("+%.2fi", (ar[i][j].Im-ar[j][i].Im)/2.0);

			printf("\t");
		}

		//Printing + sign
		if(i==0)
			printf("+");
		printf("\t");

		//Printing Skew Hermitian Matrix
		for(int j=0; j<c; ++j)
		{
			printf("%.2f", (ar[i][j].Re - ar[j][i].Re)/2.0);

			if(ar[i][j].Im+ar[j][i].Im<0)
				printf("-%.2fi", -(ar[i][j].Im+ar[j][i].Im)/2.0);
			else
				printf("+%.2fi", (ar[i][j].Im+ar[j][i].Im)/2.0);
			printf("\t");
		}
		printf("\n");
	}
}
void mOutput(complex ar[R_MAX][C_MAX], int r, int c)
{
	int cur;
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			printf("%d", ar[i][j].Re);

			if(ar[i][j].Im<0)
				printf("-%di\t", -ar[i][j].Im);
			else
				printf("+%di\t", ar[i][j].Im);
		}
		printf("\n");
	}
}
