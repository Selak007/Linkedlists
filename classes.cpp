#include<stdio.h>
#include<stdlib.h>

class LinkedList          //creating a class with structure as an object(private)
{
	struct node{
		int data;
		struct node * next;
	};
	struct node *head;                // the class will have node(struct),head,public constructor,member functions
	public:
		LinkdedList(){
			head = NULL;
			
					}
	int insbeg(int);
	void display();
	int append(int);
	int inspos(int,int);
	int delbeg();
};
int main()
{
	while(1)
	{
	
	int num,pos,opt;
	LinkedList l1;
	printf("\n ENTER THE OPTION:\n 1.INSERT BEGINING \n 2.APPEND \n3.INSERT POSITION \n4.DELBEG\n8.DISPLAY");
	scanf("%d",&opt);
	switch (opt)
	{
		case 1:
			printf("\n Enter the number to enter");
			scanf("%d",&num);
		if	(l1.insbeg(num))
		{
		
			printf("\n number succesfully inserted");
		}
		else
		{
			printf("\n not inserted");
		}
		break;
		case 2:
			printf("\n Enter the number to enter");
			scanf("%d",&num);
			if(l1.append(num))
			{
				printf("\n  succesfully inserted");
				
			}
			else
			{
				printf("\n not able to insert");
			}
			break;
		case 3:
			printf("\n Enter the number to enter");
			scanf("%d",&num);
			printf("\n Enter the position to enter");
			scanf("%d",&pos);
			if(l1.inspos(num,pos))
			{
				printf("\n succesfully inserted");
			}
			else
			{
				printf("\n not able to insert");
			}
			break;
		case 4:
		if (l1.delbeg())
		{
				
			int r; 
			r=l1.delbeg();
			printf("\n deleted");
		}
		
		else
		{
			printf("\n ERROR");
		}
			break;
			
		case 8:
			l1.display();
			
			
	}
}
	return 0;
}
int LinkedList::insbeg(int num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next = head;
	head = newnode;
	return 1;
}
void LinkedList::display()
{
	struct node * temp;
	temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp =  temp->next;
	}
}
int LinkedList::append(int num)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	    if(head==NULL)
	    {
	    	insbeg(num);
		}
		else
		{
		
		
		newnode->data = num;
		struct node* temp;
		temp = head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next = newnode;
		newnode->next = NULL;
	}
		return 1;
}
int LinkedList:: inspos(int num,int pos)
{
		struct node *newnode = (struct node *)malloc(sizeof(struct node));
	 if(head==NULL)
	    {
	    	insbeg(num);
		}
		else
		{
		

	
	struct node* temp;
	temp = head;
	
	for(int i=0;i<pos-2;i++)
	{
		temp = temp->next;
	}
	newnode->data = num;
	newnode->next = temp->next;
	temp->next = newnode;
}
return 1;
	
}
int LinkedList::delbeg()
{
	int temp3;
	if(head==NULL)
	{
		printf("\n list is empty");
	}
	else{
	
	struct node* temp;
	temp = head;
	
	 
	 temp3 = temp->data;
	 printf("\n data returned is %d",temp3);
	 head = head->next;
	 free(temp);
}
	return 1;
	
	
}
