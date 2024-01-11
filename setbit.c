#include<stdio.h>
void main()
{
	int n1,n2,n3,i,set1[100],set2[100],uni[100];
	printf("Enter the size of Universal Set :");
	scanf("%d",&n3);
	printf("\nEnter the element of Universal Set :");
	for(i=0;i<n3;i++)
		scanf("%d",&uni[i]);

	printf("\nEnter the size of sets1 :");
	scanf("%d",&n1);
	printf("\nEnter the element of set1 :");
	for(i=0;i<n1;i++)
		scanf("%d",&set1[i]);

	printf("\nEnter the size of sets2 :");
	scanf("%d",&n2);
	printf("Enter the elements of set2 :");
	for(i=0;i<n2;i++)
		scanf("%d",&set2[i]);

	printf("Set 1 :");
	for(i=0;i<n1;i++)
		printf("%d ",set1[i]);

	printf("\nSet 2 :");
	for(i=0;i<n2;i++)
		printf("%d ",set2[i]);

while(1)
{
printf("\n Menu for set operations");
printf("\n 1. UNION");
printf("\n 2. INTERSECTION");
printf("\n 3. DIFFERENCE");
printf("\n 4. Exit")
printf("\n Enter your Choice");
scanf("%d",&ch);
switch(ch)
{
case 1://for union
	k=0;
	for(i=0;i<n1;i++)
	{
		set3[k]=set1[i];
		k++;
	}
	for(i=0;i<n2;i++)
	{
		flag=1;
		for(j=0;j<n1;j++)
		{
		if(set2[i]==set1[j])
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
set3[k]=set2[i];
k++;
}
}
p=k;
for(k=0;k <p;k++)

{
printf(" %d",set3[k]);
}

break;


case 2: //for intersection

k=0;
for(i=0;i<n2;i++)
{
flag=1;
for(j=0;j<n1;j++)
{
if(set2[i]==set1[j])
{
flag=0;
break;
}
}
if(flag==0)
{
set3[k]=set2[i];
k++;
}
}
p=k;
for(k=0;k <p;k++)

{
printf("%d",set3[k]);

}
break;


case 3://for difference

k=0;
for(i=0;i<n1;i++)
{
flag=1;
for(j=0;j<n2;j++)
{
if(set1[i]==set2[j])
{
flag=0;
break;
}
}
if(flag==1)
{
set3[k]=set1[i];
k++;
}
}
p=k;
for(k=0;k <p;k++)

{
printf(" %d",set3[k]);

}
break;

}


}