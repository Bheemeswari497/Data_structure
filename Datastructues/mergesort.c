#include<stdio.h>
void merge(int arr[],int low,int mid,int high)
{
	int b[high-low+1];
	int i=low,j=mid+1,k=0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else
		{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		arr[i]=b[k];
	}
}
void mergesort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
void printarray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d\t",arr[i]);
	printf("\n");
}
int main()
{
	int a[25],i,n;
	printf("Enter n value: ");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf("sorted array:\n");
	printarray(a,n);
}
