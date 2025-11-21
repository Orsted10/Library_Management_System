#include <stdio.h>

int main() {
    int a;

    printf("Enter a number: ");
    scanf("%d", &a);

    if (a%7 == 0 || a%11 == 0) {
        printf("%d is divisible by 7 or 11\n", a);
    }
    else {
        printf("%d is not divisible by 7 or 11\n", a);
    }

    return 0;
}
