#include<stdio.h>
#include<stdlib.h>
 class Doubly{
 	struct node{
 		int data;
 		struct  node * next;
 		struct  node * prev;
	 };
 
 struct node * head;
 public :
 Doubly()
 {
 head = NULL;
 }
 int insbeg(int);
 void display();
 int count();
 
 
 
 
};

int main()
{
		int num,pos,opp;
		Doubly d1;
	while(1)
	{
		int num,pos,opp;
		Doubly d1;
		printf("\n ENTER THE OPTION \n1.INSBEG\n2.DISPLAY\n3.EXIT");
		scanf("%d",&opp);
		switch (opp)
		{
			case 1:
				printf("\n enter the number to enter");
				scanf("%d",&num);
				if(d1.insbeg(num))
				{
					printf("\n PODU MAJA DHAAN");
					
				}
				else
				{
					printf("\n JEIKRA VARAIKUM THOKALAM");
				}
				break;
				
			case 2:
				d1.display();
				break;
				
				
			case 3:
				exit(0);
				break;
			default:
				printf("\n MAMA NUMBER OLUNGA SOLLU");
		}
	}
}

int Doubly :: insbeg(int num)
{
	struct node * newnode = (struct node *)malloc(sizeof(struct node));
	
/*	struct node * temp;
	temp = head;
	if (head == NULL)
	{
		newnode -> data = num;
		newnode->prev = NULL;
		newnode -> next  = NULL;
		head = newnode;
		return 1;
		
	}
	else
	{
		newnode -> data = num;
		newnode->prev = NULL;
		newnode->next = head;
		head->prev = newnode;
		head = newnode;
		return 1;
		
		
	}*/
	if (newnode == NULL) {
        printf("Memory allocation failed!");
        return 0;
    }
    newnode->data = num;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    return 1;
}
void Doubly::display()
{
	struct node * temp;
	int c ;
	c = count();
	int a[c];
	int i = 0;
	temp = head;
	while(temp!=NULL)
	{
		a[i]=temp->data;
		printf("%d",a[i]);
		printf("%d ",temp->data);
		temp = temp->next;
		i+=1;
		
	}

	
	
}
int Doubly::count()
{
	int cnt=0;
	struct node * temp;
	temp = head;
	while(temp!=NULL)
	{
		cnt+=1;
		temp = temp->next;
	}
	return cnt;
}

