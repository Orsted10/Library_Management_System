#include <stdio.h>


int main(){

int a=10, b=50, c=3;

if(a>b && a>c){
    printf("The Largest is %d\n", a);
}
else if(b>a && b>c){
    printf("The Largest is %d\n", b);
}
else{
    printf("The Largest is %d\n", c);
}
}
