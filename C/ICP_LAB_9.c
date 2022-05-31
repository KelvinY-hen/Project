#include <stdio.h>


float result;
const float phi=3.14;

void Diameter(int a)
{
    result= 2*a;
    printf("Diameter= %.0f", result);
}

void Circumference(int a)
{
    result= 2*phi*a;
    printf("Circumference= %.2f", result);
}

void Area (int a)
{
    result= phi*a*a;
    printf("Area= %.2f", result);
}

int main()
{
    int rad,choice;
    printf("Input Radius: ");
    scanf("%d",&rad);
    
    printf("Select What to find with the radius: ");
    printf("\n\t1. Diameter");
    printf("\n\t2. Circumference");
    printf("\n\t3. Area");

    printf("\n\nInput choice: ");
    scanf("%d", &choice);

    if (choice==1)
    {
        Diameter(rad);
    }
    else if (choice==2)
    {
        Circumference(rad);
    }
    else if (choice==3)
    {
        Area(rad);
    }
    return 0;
}


void Calculatediscount(int *a, int *b, int *c)
{
    *a= *a*80/100;
    *b= *b*70/100;
    *c= *c*60/100;


}

int main ()
{
    int Item_1, Item_2, Item_3;

    printf("Enter item 1 price: ");
    scanf("%d", &Item_1);
    printf("Enter item 2 price: ");
    fflush(stdin);
    scanf("%d", &Item_2);
    printf("Enter item 3 price: ");
    fflush(stdin);
    scanf("%d", &Item_3);

    printf("\nOriginal Price:\n");
    printf("Item 1: %d", Item_1);
    printf("\nItem 2: %d", Item_2);
    printf("\nItem 3: %d", Item_3);

    Calculatediscount(&Item_1, &Item_2, &Item_3);

    
    printf("\n\nDiscounted Price:");
    printf("\nItem 1: %d", Item_1);
    printf("\nItem 2: %d", Item_2);
    printf("\nItem 3: %d", Item_3);

    return 0;
}