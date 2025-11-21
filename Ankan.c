#include <stdio.h>

extern int Length;
extern int Breadth;


int main() {


    int area = Length * Breadth;

    printf("Length = %d  \n", Length);
    printf("Breadth = %d  \n", Breadth);
    printf("Area of Rectangle = %d \n", area);

    return 0;
}
