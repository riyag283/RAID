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
	fstream fd1,fd2,fd3,fd4,fd5;
	fd1.open("file1.txt",ios::in|ios::out|ios::app|ios::binary);
	fd2.open("file2.txt",ios::in|ios::out|ios::app|ios::binary);
	fd4.open("file3.txt",ios::in|ios::out|ios::app|ios::binary);
	fd5.open("file4.txt",ios::in|ios::out|ios::app|ios::binary);
	fd3.open("parity.txt",ios::in|ios::out|ios::app|ios::binary);
	char a1,a2,a3,a4,a5;
	fd1.seekg(0,ios::beg);
	fd2.seekg(0,ios::beg);
	fd4.seekg(0,ios::beg);
	fd5.seekg(0,ios::beg);
	while(fd1.read((char *) &a1, sizeof(a1))&&fd2.read((char *) &a2, sizeof(a2))&&fd5.read((char *) &a5, sizeof(a5))&&fd4.read((char *) &a4, sizeof(a4))){
          a3=a1^a2^a4^a5;
          fd3.write((char *) &a3, sizeof(a3));
    }
    fd1.close();
	fd2.close();
	fd3.close();
	fd4.close();
	fd5.close();
	/*fscanf(fptr,"%ld",&n1);
	fclose(fptr);
	fptr=fopen("/media/riya/10AE8782AE875F5A/x01","r");
	fscanf(fptr,"%ld",&n2);
	fclose(fptr);
	fptr=fopen("/home/riya/x02","r");
	fscanf(fptr,"%ld",&n3);
	fclose(fptr);
	fptr=fopen("/home/riya/x03","r");
	fscanf(fptr,"%ld",&n4);
	fclose(fptr);
	long store=myXOR(myXOR(myXOR(n1,n2),n3),n4);
	int fd=open("parity.txt",O_WRONLY|O_APPEND);
	dup2(fd,1);
	cout<<store<<endl;*/
	return 0;
}