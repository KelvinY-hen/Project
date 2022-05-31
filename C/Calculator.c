#include <stdio.h>

struct angka
{
    double A;
    double B;
};

float i(int B,int A,int tinggi)
{
    float hasil;
    hasil= (0,5*(tinggi*2+1)*A) - (0,5*(tinggi*2+1)*B);
    return(hasil);
}

int main() 
{
    struct angka parel;

    printf("Angka 1: ");
    scanf("%lf", &parel.A); 
    printf("Angka 2: ");
    fflush(stdin);
    scanf("%lf", &parel.B);

    char operator;
    printf("Operator: ");
    fflush(stdin);
    scanf("%c", &operator);

    int j;

    double result = 0;

    switch (operator)
    {
    case '+':       // Jika input operator '+'
        printf("%.1lf", parel.A+parel.B);
        break;
    case '-':       // Jika input operator '-'
        printf("%.1lf", parel.A-parel.B);
        break;
    case '*':       // Jika input operator '*'
        printf("%.1lf", parel.A*parel.B);
        break;
    case '/':       // Jika input operator '/'
        printf("%.1lf", parel.A/parel.B);
        break;
    case '^':
        for (j = 1; j <= parel.B; ++j)
        {
            result += (1*parel.A);
        }
        printf("%.1lf", result);
        break;
    case 'i':
        for (j = parel.A; j+1 <= parel.B; ++j)
        {
            result += i(parel.A,parel.A+1);
        }


        printf("%.1lf", result);
        break;
    default:
        printf("Error");
        break;
    }
    return 0;
}