#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define c 10

 struct Stack         /*Struct of stack */
{
    float Stk[c];
    int count;

};

struct Stack Stack; /*This is stack*/

int isempty(); /* Is Stack empty?*/
int isfull(); /* Is Stack full?*/
void Push(float); /*Add a value to Stack*/
float Pop(); /* Take a value from Stack*/
void Top(); /* Show top element*/
void Print(); /* Show all Stack*/


int main(int argc, char *argv[])
{
    Stack.count = 0;

    Push(10);
    Push(564);
    Push(111);
    Top();
    Push(12);
    Print();
    Pop();
    Pop();
    Print();
    Top();



     return 0;
}

void Push(float a)          /* Add a value to Stack*/
{
    if( isfull() )
    {
        return;
    }
    Stack.Stk[Stack.count] = a;
    Stack.count++;

}

float Pop()                 /* Take a value from Stack*/
{
    if ( !isempty() )
    {
        Stack.count--;
    float p = Stack.Stk[Stack.count];
    Stack.Stk[Stack.count] = '\0';
    return p;
    }
return -999999;

}

void Top()                     /*Show top element of Stack*/
{
    printf("%.0f\n", Stack.Stk[Stack.count-1]);
}

void Print()                    /* Show all Stack*/
{
    int i;
    for (i=0; i<c; i++)
    {
        printf("%.0f  ", Stack.Stk[i]);

    }
    printf("\n\n");
}

int isempty()                      /* Is Stack empty?*/
{
   if(Stack.count == 0 && Stack.Stk[0] == '\0')
   {
       printf("\nStack is empty:(\n");
        return 1;
   }
   return 0;
}

int isfull()                        /* Is Stack full?*/
{
    if ( Stack.count >= (c-1) && Stack.Stk[c-1])
        {
            printf("\nStack is full:(\n");
            return 1;
        }

        return 0;
}
