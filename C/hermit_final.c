#include <stdio.h>
#include <stdlib.h>

#define R_MAX 10
#define C_MAX 10

//Structure of Complex
typedef struct
{
	int Re;
	int Im;
} complex;

//Function Prototypes
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

//mainFunction
int main()
{
	complex ar1[R_MAX][C_MAX];
	int r1, c1;

	complex ar2[R_MAX][C_MAX];
	int r2, c2;

	complex ar3[R_MAX][C_MAX];

	//Run till exiting
	while(1)
	{
		//Print Header and clear Screen
		init();
		//Get choice as return value from menu
		int choice = printMenu();

		//Use menu based on choice of user
		switch(choice)
		{
			case 1:
				//Input Dimensions
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				//Clear Buffer
				getchar();
				//Input Matrix
				mInput(ar1, r1, c1);
				//Calculate Conjugate
				cConjugate(ar1, r1, c1, ar2);
				//Output Matrix
				printf("Complex Conjugate: \n");
				mOutput(ar2, r1, c1);
				break;

			case 2:
				//Input Dimensions
				printf("Enter Number of Rows and Columns: ");
				scanf("%d%d", &r1, &c1);
				//Clear Buffer
				getchar();
				//Input Matrix
				mInput(ar1, r1, c1);
				//Calculate transpose
				mTranspose(ar1, r1, c1, ar2);
				//Output Matrix
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
				//Exit on entering 0
				printf("Exiting...\n");
				return 0;
			default:
				//Any other value as input
				printf("WRONG CHOICE!\n");
				break;
		}
		printf("Press Enter to Continue...\n");
		//Clear Buffer
		getchar();
		//Wait for user to press enter
		getchar();
	}
	return 0;
}

void init()
{
	//Clear Screen
	system("clear");
	//Print Header
	printf("***HERMITIAN MATRICES***\n\n");
}

int printMenu()
{
	//Print Menu
	printf("1. Get the complex conjugate.\n");
	printf("2. Get the transpose.\n");
	printf("3. Check if the matrix is Hermitian.\n");
	printf("4. Check if the matrix is Skew Hermitian.\n");
	printf("5. Add two complex matrices.\n");
	printf("6. Subtract two complex matrices.\n");
	printf("7. Print a matrix as sum of a Hermitian and Skew Hermitian.\n");
	printf("0. Exit\n");
	//Get user's choice
	printf("Enter your choice: ");
	int c;
	scanf("%d", &c);
	//Return user's choice
	return c;
}


void mInput(complex ar[R_MAX][C_MAX], int r, int c)
{
	//Check lfor invalid dimensions
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions! ABORT...\n");
		exit(-1);
	}

	complex current;
	char str[15];
	printf("Enter elements of the matrix in the form a±bi.\n");
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			//Take each element input as string
			scanf("%s", str);
			//Convert the string to complex type and store it in the array
			ar[i][j]=strToComplex(str);
		}
	}
}

//Function to convert string to complex type
complex strToComplex(char* str)
{

	char aSign='+'; //Sign of Real Part
	char bSign='+'; //Sign of Imaginary Part
	char iCount=0; //Number of iota present: For syntax checking
	char signCount=0; //Number of signs present
	char* ptr=str;

	//Error Checking

	//Move pointer ahead if the first character is + or -
	if(*ptr=='-' || *ptr=='+')
			++ptr;
	while(*ptr != '\0')
	{
		//Check if it is not a digit AND not i AND not a + or a -
		if((!(*ptr >= '0' && *ptr <= '9')) && (*ptr!='i') && (*ptr!='+') && (*ptr!='-'))
		{
			printf("SYNTAX ERROR!\nABORT...\n");
			exit(-1);
		}
		//If current character is 'i', increment iCount
		else if(*ptr=='i')
		{
			++iCount;
			//There should not be more than one i
			if(iCount>1)
			{
				printf("SYNTAX ERROR!\nABORT...\n");
				exit(-1);
			}
		}
		//Increment signCount
		else if((*ptr=='+') || (*ptr=='-'))
		{
			++signCount;
			if(signCount>1)
			{
				printf("SYNTAX ERROR!\nABORT...\n");
				exit(-1);
			}
		}
		ptr++;
	}
	//There are more than one signs and no i
	if(iCount==0 && signCount==1)
	{
		printf("SYNTAX ERROR!\nABORT...\n");
		exit(-1);
	}

	//EVALUATE
	complex z;
	z.Re=0;
	z.Im=0;

	//aSign is the first sign
	if(*str=='-' || *str=='+')
	{
		aSign=*str;
		++str;
	}
	//If first character, ignoring sign is i
	if(*str=='i')
	{
		//There is a character after i
		if(*(str+1) != ' ' && *(str+1)!= '\0')
		{
			printf("SYNTAX ERROR!\nABORT...\n");
			exit(-1);
		}
		//Imaginary part is 1
		z.Im=1;
		if(aSign=='-')
			z.Im=-z.Im;
		return z;
	}
	//Read Real Part
	while(*str <='9' && *str>='0' && *str!='\0')
	{
		z.Re = z.Re*10 + (*str) - '0';
		++str;
	}
	if(aSign=='-')
		z.Re=-z.Re;

	//Complex number is real
	if(*str == '\0')
		return z;

	//If i is encountered The already read part wasn't real, it was imaginary
	if(*str=='i')
	{
		if(*(str+1) != ' ' && *(str+1)!= '\0')
		{
			printf("SYNTAX ERROR!\nABORT...\n");
			exit(-1);
		}
		z.Im=z.Re;
		z.Re=0;
		return z;
	}

	//Otherwise when another sign is encountered, the sign is the sign of the imaginary part
	if(*str=='-' || *str=='+')
	{
		bSign=*str;
		++str;
	}

	if(*str=='i')
	{
		if(*(str+1) != ' ' && *(str+1)!= '\0')
		{
			printf("SYNTAX ERROR!\nABORT...\n");
			exit(-1);
		}
		z.Im=1;
		if(bSign=='-')
			z.Im=-z.Im;
		return z;
	}

	while(*str <'9' && *str>'0')
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
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}
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
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}
	for(int i=0; i<c; ++i)
	{
		for(int j=0; j<r; ++j)
		{
			ar2[i][j].Re=ar1[j][i].Re;
			ar2[i][j].Im=ar1[j][i].Im;
		}
	}
}

int isHermitian(complex ar[R_MAX][C_MAX], int r, int c)
{
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}

	if(r!=c)
	{
		printf("Operation only supported for Square Matrix!\nABORT...\n");
		exit(-1);
	}

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
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}
	if(r!=c)
	{
		printf("Operation only supported for Square Matrix!\nABORT...\n");
		exit(-1);
	}

	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			if(ar[i][j].re!=-ar[j][i].re||ar[i][j].im!=ar[j][i].im)
				return 0;
		}
	}
	return 1;
}

void addMatrices(complex ar1[R_MAX][C_MAX], int r1, int c1, complex ar2[R_MAX][C_MAX], int r2, int c2, complex ar3[R_MAX][C_MAX])
{
	if(r1<=0 || c1<=0 || r2<=0 || c2<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}
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
	if(r1<=0 || c1<=0 || r2<=0 || c2<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}

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
	if(r<=0 || c<=0)
	{
		printf("Invalid Dimensions!\nABORT...\n");
		exit(-1);
	}

	if(r!=c)
	{
		printf("Operation only supported for Square Matrix!\nABORT...\n");
		exit(-1);
	}
	//Printing First Matrix
	for(int i=0; i<r; ++i)
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
			printf("%.1f", (ar[i][j].Re + ar[j][i].Re)/2.0);

			if(ar[j][i].Im>ar[i][j].Im)
				printf("-%.1fi", -(ar[i][j].Im-ar[j][i].Im)/2.0);
			else
				printf("+%.1fi", (ar[i][j].Im-ar[j][i].Im)/2.0);

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
