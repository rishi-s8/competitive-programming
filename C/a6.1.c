/*
*** RISHI SHARMA
*** B17138
*** ASSIGNMENT 6
*** TASK 1
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
void extract_word(char* dest, char* source);
void print_prompt();
void print_help();
int substr(char* sub, char* mainStr);
int strToInt(char* str);


int main()
{
	char str[1000], word[10], mainStr[500];
	int i, index;
	while(1)
	{
		i=0;
		print_prompt();
		fgets(str,500,stdin);
		str[strlen(str)-1]='\0';
		extract_word(word, str);
		//Handle Situations where no operation is done
		i+=strlen(word)+1;

		if(!strcmp(word, "exit"))
		{
			printf("Exiting!\n");
			return 0;
		}
		else if(!strcmp(word, "help"))
		{
			print_help();
			continue;
		}

		else if(!strcmp(word, "max"))
		{
			int max=INT_MIN, num;
			while(str[i]!='\n' && str[i]!='\0')
			{
				extract_word(word, str+i);
				i+=strlen(word)+1;
				num=atoi(word);
				if(num>max)
					max=num;
			}
			print_prompt();
			printf("%d\n", max);
		}

		else if(!strcmp(word, "srch"))
		{
			extract_word(mainStr, str+i);
			int len=strlen(str);
			i+=strlen(mainStr)+1;
			print_prompt();
			while(i<len)
			{
				extract_word(word, str+i);
				i+=strlen(word)+1;
				index=substr(word, mainStr);
				printf("%d ", index);
			}
		}
		else
		{
			print_help();
			continue;
		}
		printf("\n");

	}
}

void print_prompt()
{
	printf("b17138$ ");
}

void print_help()
{
	printf("<max> : Prints Maximum of given numbers. \n");
	printf("SYNTAX: \nb17138$: max n1 n2 n3 ....\n\n");
	printf("<srch> : Prints first occurance of given <substr> in <str>. Prints <-1> if not found \n");
	printf("SYNTAX: \nb17138$: srch str substr1 substr2 ....\n\n");
	printf("<help> : Display Commands and Syntax. \n");
	printf("SYNTAX: \nb17138$: help\n\n");
	printf("<exit> : Terminates the program. \n");
	printf("SYNTAX: \nb17138$: exit\n\n");
}

void extract_word(char* dest, char* source)
{
	int i;
	for(i=0; source[i]!=' ' && source[i]!='\0'; ++i)
		dest[i]=source[i];
	dest[i]='\0';
}

int substr(char* str2, char* str1)
{
	int len_str1=strlen(str1), len_str2=strlen(str2);
	
	for(int i=0, count=0; i<len_str1; ++i)
	{
		int j=0;
		if(str1[i]==str2[j])
		{
			for(int k=i; j<len_str2; ++k, ++j)
			{
				if(j==(len_str2-1) && str1[k]==str2[j])
					return i+1;
				else if(str1[k] != str2[j])
					break;
			}
		}
	}
	return -1;

}

int strToInt(char* str)
{
	int len=strlen(str);
	int num = 0; int i=0;
	if(str[i]=='-')
		i++;
	for(i; i<len; ++i)
		num = num*10 + (str[i] - '0');
	if(str[i]=='-')
		return -num;
	return num; 
}