#include<stdio.h>
#include<string.h>
struct student{
	char name[10];
	int s1,s2,s3;
};
int main(int argc,char *argv[])
{
	struct student s;
	int total;
	strcpy(s.name,argv[1]);
	s.s1=atoi(argv[2]);
	s.s2=atoi(argv[3]);
	s.s3=atoi(argv[4]);
	total=s.s1+s.s2+s.s3;
	printf("name\ts1\ts2\ts3\ttotal\n");
	printf("%s\t%d\t%d\t%d\t%d",s.name,s.s1,s.s2,s.s3,total);
	return 0;
		
}
