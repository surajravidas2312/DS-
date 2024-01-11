#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();
int queue[1000];
int front = -1, rear = -1;
int n;
void main()
{
	int op;
	printf("Enter queue size : ");
	scanf("%d",&n);
	while(1)
	{
		printf("\n\nQueue Operations");
		printf("\n----------------\n");
       		printf("1.Enqueue Operation\n");
        	printf("2.Dequeue Operation\n");
        	printf("3.Display the Queue\n");
        	printf("4.Exit\n");
        	printf("\nEnter your choice of operations : ");
        	scanf("%d", &op);
        	switch (op)
        	{
            	case 1:
            		enqueue();
            		break;
            	case 2:
            		dequeue();
            		break;
            	case 3:
            		display();
            		break;
            	case 4:
            		exit(0);
            	default:
            		printf("\nIncorrect choice \n");
        	} 
        }
}
void enqueue()
{
	int num;
	if (rear==n-1)
	{
		printf("\nQueue Overflow !");
	}
	else
	{ 
		if (front == -1)
		{
			front=0;
		}
		printf("\nEnter number to be added :");
		scanf("%d",&num);
		rear=rear+1;
		queue[rear]=num;
	}
}
void dequeue()
{
	if (front == - 1 || front > rear)
	{
		printf("\nQueue Underflow");
	}
	else
	{
		printf("\nElement deleted : %d",queue[front]);
		front=front+1;
	}
}
void display()
{
	if (front == - 1)
	{
        	printf("\nEmpty Queue \n");
        }
        else
        {
		printf("\nElements in queue :");
		for(int i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    
	
