#include <stdio.h>

typedef struct 
{
    int a;
    int b;
} a;


typedef struct 
{
    int a;
} b;

int main()
{
    a ob1 = {1,2};
    b ob2 = {3};
    a *ptr1 = &ob1;
    b *ptr2 = &ob2;
    ptr1 = reinterpret_cast<ptr2*>(ptr);
    printf("%d\n", ptr1->b);
}
