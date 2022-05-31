#include <stdio.h>

int main(){
    int *p1;
    int **p2;
    int c = 4;
    p1 = &c;
    printf("%d p1\n", *p1);
    p2 = &p1; // 
    printf("%d p2\n", **p2);
    c = (*p1) * c * (**p2); // ampersand dihilangkan, perbaikan tanda operasi, dan reference pointer p2
    printf("%d c\n", c);
    return 0;
}