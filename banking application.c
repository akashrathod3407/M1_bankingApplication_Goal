
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct customer
{
	int account_no;
	char name[80];
	int balance;
};
void accept(struct customer[],int);
void display(struct customer[],int);
int search(struct customer[],int,int);
void deposit(struct customer[],int,int,int);
void withdraw(struct customer[],int,int,int);
void main()
{
	struct customer data[20];
	int n,choice,account_no,index,amount;
	getch();
	printf("\n\nBANKING SYSTEM\n\n");
	printf("NUMBER OF CUSTOMER RECORDS YOU WANT TO ENTER ?:");
	scanf("%d",&n);
	accept(data,n);
	do
	{
		printf("\nWELCOME TO BANK MANAGEMENT SYSTEM\n");
		printf("********************MENU********************\n");
		printf("1:To Display all the records\n ");
		printf("2:To Search a record\n");
		printf("3:To Deposit Amount\n");
		printf("4:To Withdraw Amount\n");
		printf("5:Exit\n");
		printf("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display(data,n);
				break;

			case 2:
				printf("enter the account number to search:");
				scanf("%d",&account_no);
				index=search(data,n,account_no);
				if(index==-1)
				{
					printf("Record not found");
				}
				else
				{
					printf("A/c No=%d",data[index].account_no);
					printf("\n Name=%s",data[index].name);
					printf("\nBalance=%d",data[index].balance);
				}
				break;

			case 3:
				printf("enter the account no:");
				scanf("%d",&account_no);
				printf("\nEnter the amount to deposit:");
				scanf("%d",&amount);
				deposit(data,n,account_no,amount);
				break;

			case 4:
				printf("enter the account no:");
				scanf("%d",&account_no);
				printf("\nenter the amount to withdraw:");
				scanf("%d",&amount);
				withdraw(data,n,account_no,amount);
				break;

			case 5:
				exit(0);
		}
	}while(choice<=5);
	getch();
}
void accept(struct customer list[80],int s)
{
	int i;
	for(i=0;i<s;i++)
	{
		printf("\n\nENTER the data for record #%d",i+1);
		printf("\nenter the account no:");
		scanf("%d",&list[i].account_no);
		printf("Enter name:");
		scanf("%s",&list[i].name);
		printf("enter the balance");
		scanf("%d",&list[i].balance);
	}
}

void display(struct customer list[80],int s)
{
	int i;
	printf("\nA/C no\tName\tBalance\n");
	for(i=0;i<s;i++)
	{
		printf("%d\t%s\t%d\n",list[i].account_no,list[i].name,list[i].balance);
	}
}

int search(struct customer list[80],int s,int number)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(list[i].account_no==number)
		{
			return i;
		}

	}
	return -1;
}

void deposit(struct customer list[],int s,int number,int amt)
{
	int i=search(list,s,number);
	if(i==-1)
	{
		printf("RECORD NOT FOUND");
	}
	else
	{
		list[i].balance+=amt;
	}
}

void withdraw(struct customer list[],int s,int number,int amt)
{
	int i=search(list,s,number);
	if(i==-1)
	{
		printf("RECORD NOT FOUND");
	}
	else  if(list[i].balance<amt)
	{
		printf("INSUFFICIENT BALANCE\n");
	}
	else
	{
		list[i].balance-=amt;
	}
}
