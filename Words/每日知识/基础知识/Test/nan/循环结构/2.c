#include <stdio.h>
int main ()
{
     int a= 3;
     int b= 4;
    int c= 0;

    c = a | (b+a);
    {
        printf ("line 1 - c的值  %d\n",c);
    
    }
}
