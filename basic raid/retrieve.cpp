#include<iostream>
#include<string>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
using namespace std;

int myXOR(int x, int y) 
{ 
   return (x | y) & (~x | ~y); 
}

int main(){
	system("split -n 4 -d file.txt");
	long n1,n2,n3,n4;
	FILE *fptr1,*fptr2;
	fptr1=fopen("x00","r");
	fscanf(fptr1,"%ld",&n1);
	fclose(fptr1);
	fptr2=fopen("x01","r");
	fscanf(fptr2,"%ld",&n2);
	fclose(fptr2);
	fptr1=fopen("x02","r");
	fscanf(fptr1,"%ld",&n3);
	fclose(fptr1);
	fptr2=fopen("parity.txt","r");
	fscanf(fptr2,"%ld",&n4);
	fclose(fptr2);
	long store=myXOR(myXOR(myXOR(n1,n2),n3),n4);
	int fd=open("lost.txt",O_WRONLY|O_APPEND);
	dup2(fd,1);
	cout<<store<<endl;
	return 0;
}
