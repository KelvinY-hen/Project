#include <stdio.h>

int main ()
{
    int born_year, age;
    printf ("Please enter the year you are born: ");
    scanf("%d", &born_year);
    age = 2021 - born_year;
    printf ("You are %d years old this year", age);

    return 0;
}