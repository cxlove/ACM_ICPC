#include <stdio.h>

int main()

{

       int num_1, num_2, num_3;

       while (scanf ("%d%d%d", &num_1, &num_2, &num_3), num_1+num_2+num_3)

       {

              if (num_1 == 0)  printf ("1\n");

              else if (2*num_2+num_1 < 4)   printf ("%d\n",2*num_2+num_1+1);

              else  printf ("%d\n",5*num_3+2*num_2+num_1+1);

       }

       return 0;

}