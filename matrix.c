/* Example of input:  1, 2, 3.*/


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main()
{
    int m,n,i,j,q,w; /* Counter */

    srand(time(NULL));
    m=3+rand()%6;  /* Creating Matrix 1 */
    n=4+rand()%5;
    printf("Size of random matrix 1 = [%i][%i]\n\n\n",m,n);
    q=m-1;
    w=n-1;
    int matrix1[m][n],matrtemp[q][w];
    for(i=0; i<m; i++)                  /* Random input of matrix 1 */
    {
        for(j=0; j<n; j++)
        {
            matrix1[i][j]=rand()%4;
        }

    }


    for(i=0; i<m; i++)                      /* Output of matrix 1 */
    { printf("|");
        for(j=0; j<n; j++)
        {
            printf(" %i",matrix1[i][j]);
        }
        printf(" \t|\n");
    }

    int temp;                               /* Swap begins and ends */

    for(i=0; i<n; i++)
    {
        temp = matrix1[0][i];
        matrix1[0][i] = matrix1[m-1][(n-1)-i];
        matrix1[m-1][(n-1)-i] = temp;

    }

    printf("________________________________________\n\nSwap 1 and last string\n\n");
for(i=0; i<m; i++)                                  /* Output of new matrix 1 */
    { printf("|");
        for(j=0; j<n; j++)
        {
            printf(" %i",matrix1[i][j]);
        }
        printf(" \t|\n");
    }





    int x,y;                                /* Search of min elem i,j */
    temp = 200;
for(i=0; i<m; i++)
    {

        for(j=0; j<n; j++)
        {
            if(matrix1[i][j] < temp )
            {
                temp = matrix1[i][j];
                x=i;
                y=j;

            }
        }

    }
printf("________________________________________\n\nMin el of marix 1 = [%i] [%i] \n\n", x,y);

for(i=x; i<m-1; i++)                        /* Deleting string */
    {
        for(j=0; j<n; j++)
        {
            matrix1[i][j] = matrix1[i+1][j];
        }
    }

for(i=0; i<m; i++)                          /* Deleting column */
    {
        for(j=y; j<n-1; j++)
        {
            matrix1[i][j] = matrix1[i][j+1];
        }
    }
for(i=0; i<q; i++)
    {
        for(j=0; j<w; j++)
        {
            matrtemp[i][j] = matrix1[i][j];
        }
    }


   printf("\nNew matrix 1 without 1 string and 1 column\n\n");
   printf("Size of this matrix = [%i][%i]\n\n", q,w);
for(i=0; i<q; i++)                          /* Output new matrix 1 (i-1; j-1) */
    { printf("|");
        for(j=0; j<w; j++)
        {
            printf(" %i",matrtemp[i][j]);
        }
        printf(" \t|\n");
    }

char matr[100],t[5];                        /* array for input your matrix */
  int temp1[100],e=0;                       /* array for sorting */
x=0;
y=0;
  for(i=0; i<5; i++)
  {
    t[i]='\0';
  }
  for(i=0; i<100; i++)
  {
    temp1[i]=0;
  }

  printf("\n________________________________________\n\nEnter your matrix 2\n");


  fgets(matr,100, stdin);                   /* Input your matrix */

  for(i=0; i<100; i++)                         /* Search size of your matrix */
  {
    if(matr[i]=='.' || matr[i]==',')
    {
        x++;
    }
  }

  for(i=0; i<100; i++)
  {
    if(matr[i]==',' || matr[i]==' ' || matr[i]=='.')
    {
        if (matr[i]==',')
        {
            y++;
            break;
        }
        y++;
    }
  }

  printf("\nSize of your matrix = [%i] [%i]\n", x,y);


  int matr2[x][y];                              /* Creating your matrix */
    j=0;
  for(i=0; i<100; i++)
  {
      if (matr[i]-'0'>=0 && matr[i]-'0'<=9)
      {
        char a;
        a = matr[i];
        t[j] = a;
        j++;
      }else if (matr[i]=='.' || matr[i]==' ')
      {
          temp1[e]=atoi(t);
          e++;
          for(j=0; j<5; j++)
          {
              t[j]='\0';
          }
          j=0;
      }
  }
  e=0;

  for(i=0; i<x; i++)                /* Creating your matrix (i,j)=(e) */
  {
      for(j=0; j<y; j++)
      {

          matr2[i][j]=temp1[e];
          e++;
      }
  }
printf("\nYour matrix is :\n");

  for(i=0; i<x; i++)                /* Output of your matrix */
  {
      printf("| ");
      for(j=0; j<y; j++)
      {
          printf("%i\t",matr2[i][j]);
      }
    printf("|\n");
  }

    printf("\n\n______________________________________\n\nSize of matrix 1 = [%i] [%i]\n", q,w);
    printf("\t\tx\nSize of your matrix = [%i] [%i]", x,y);


    if (w==x)                                   /* Test of multiplication */
    {
        int k=q,l=y,z;
        printf("\n\t\t||\nSize of new(*) matrix = [%i] [%i] \n",k,l);
        int matrix3[k][l];
        for(i=0; i<k; i++)
        {
            for(j=0; j<l; j++)
            {
                matrix3[i][j] = 0;
            }
        }

int end,res=0;
for (i=0; i < k; i++)                           /* Multiplication of Matrix  */
{
    for (j=0; j < l; j++)
    {
        for (z=0; z < w; z++)
        {
            end =matrtemp[i][z] * matr2[z][j];
            res += end;
           matrix3[i][j] = res;
        }
    res = 0;
    }
}

printf("\n\nNew (*)Matrix is :\n");


for(i=0; i<k; i++)                              /* Output of new(*) matrix */
    { printf("|");
        for(j=0; j<l; j++)
        {
            printf(" %i",matrix3[i][j]);
        }
        printf(" \t|\n");
    }
    }else printf("\n\n\n\n________Error/ -zachet(((_________");

    return 0;
}
