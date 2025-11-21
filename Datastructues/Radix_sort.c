#include<stdio.h>
int getmax(int a[],int n)
{
	int max=a[0],i;
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max= a[i];
	}
	return max;
}
void radixsort(int a[],int n)       //function to implement radixsort
{
	int big,nod=0,steps,count[10],i,j,k,bucket[10][n],loc,div=1;
	big=getmax(a,n);
	while(big>0)        //count the number of digits in the largest number
	{
		nod++;
		big=big/10;
	}
	for(steps=1;steps<=nod;steps++)
   {
		for(j=0;j<10;j++)   //intialize elements into count array
		{
			count[j]=0;
		}
	    for(i=0;i<n;i++)         //distribute elments into buckets
     	{
		loc= (a[i]/div)%10;
		bucket[loc][count[loc]++] =a[i];             
	    }
	   k=0;                  //count the elements back into the array
	   for(j=0;j<10;j++)    // looping through digits 0-9
     	{
	    	for(i=0;i<count[j];i++)
	     	{
	    	a[k]= bucket[j][i];
	    	k++;
	        }
     	}
	    div = div*10;	
    }
}
void printarray(int a[],int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{
	int i,n;
	printf("Enter the array of them size");
	scanf("%d",&n);
	printf("Enter the %d elements",n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("radixsort,array elements are:\n");
	radixsort(arr,n);
	
	printarray(arr,n);
	return 0;
}
