#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int i;
	FILE *fp;
	long long int n;
	fp = fopen("input.txt","w+");
	for(i=0;i<1000000;i++)
	{
		n=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	do
	{
		n=rand()%10;
		
	}while(n==0);
	for(int j=0;j<9;j++)
	{
		n=n*10;
		n=n+(rand()%10);
	}
		//printf("%ld ",n);
		fprintf(fp,"%lld ",n);
		
	}
	return 0;
}
