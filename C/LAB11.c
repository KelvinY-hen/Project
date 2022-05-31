#include <stdio.h>
#include <string.h>

struct car
{
	char model[50];
	char colour[50];
	char num[50];
	int price;
	int available;
};

int addcar(struct car *addcar, int counter)
{
    for (int i = counter; i < counter+1; ++i)
	{
	fflush(stdin);
	printf("\nInput Car");
	printf("\nModel : ");fflush(stdin);gets(addcar[i].model);
	printf("Colour : ");fflush(stdin);gets(addcar[i].colour);	
	printf("Registration Number : ");fflush(stdin);gets(addcar[i].num);
	printf("Rental Price : ");scanf("%d",&addcar[i].price);
	printf("Availability (0/1): ");scanf("%d",&addcar[i].available);
	}
    counter +=1;
    return counter;
}

void display(struct car *displaycar, int counter)
{
    printf("\nDisplay Car Function: ");
    for (int i = 0; i < counter; ++i)
	{
    printf("\n%d.",i+1);
	printf("car model : %s\n",displaycar[i].model);
	printf("  colour : %s\n",displaycar[i].colour);
	printf("  registration number : %s\n",displaycar[i].num);
	printf("  price : %d\n",displaycar[i].price);
	printf("  availability (0/1): %d\n",displaycar[i].available);
	}
}

void RentACar(struct car *rentcar, int counter)
{
	char reg[10];

	for(int i=0; i < counter; i++)
	{
		if(rentcar[i].available == 1)
		{
			printf("\nCar: %s %s ,Registration Code: %s",rentcar[i].colour,rentcar[i].model, rentcar[i].num);
		}
	}
	printf("\nEnter the Registration number= ");
	fflush(stdin);
	gets(reg);
	for(int i=0; i < counter; i++)
	{
		if(strcmp(rentcar[i].num,reg)==0)
		{
			rentcar[i].available=0;
			printf("car successfully rented");
		}
	}
}

void returncar(struct car *returncar, int counter)
{
	char reg[10];

	printf("\nEnter the Registration number = ");
	fflush(stdin);
	gets(reg);
	for(int i=0; i < counter; i++)
	{
		if(strcmp(returncar[i].num,reg)==0)
		{
			returncar[i].available=1;
			printf("car successfully returned");
		}
	}
}


int main() 
{
    
    struct car rentalcar[20];
    int counter = 0;
    int choice;
	do {
		printf("\n\nSelect a Command: ");
		printf("\n\t1.) Add Car");
		printf("\n\t2.) Display Car");
		printf("\n\t3.) Rent Car");
		printf("\n\t4.) Return Car");
		printf("\n\t5.) exit");
		printf("\n\nChoice:  ");
		scanf("%d", &choice);
        fflush(stdin);
		switch (choice) 
			{
			case 1:
				counter = addcar(rentalcar, counter);
				break;
			case 2:
				display(rentalcar, counter);
				break;
			case 3:
				RentACar(rentalcar, counter);
				break;
			case 4:
				returncar(rentalcar, counter);
				break;
			default:
				printf("\nOut of Range\n");
			}
	} while (choice != 5);
    return 0;
}
