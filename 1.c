#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct memory_struct{
	int data;
	struct memory_struct *right;
	struct memory_struct *left;
};

struct Circle{ /*stack for begin and end only*/
    int circle[40];
    int i;
};

typedef struct Circle  STACK;
STACK s;

typedef struct memory_struct Memory;
typedef Memory *MemoryProt;
MemoryProt memory = NULL;

void operation(char *);/*All commands*/
void add(MemoryProt *,char h);/*create a new Element of memory*/
int isoperation(char *str);/*is this an operation ?*/
void push(char *str);/*push command (for begin and end only)*/
void pop(char *str);/*read command (for begin and end only)*/

int main()
{
    FILE *file;
    char name[15];
    char str[255];
    printf("enter the file name:\t");
    scanf("%s",name);
    s.i=0;
    add(&memory,'r');

    if((file=fopen(name,"r"))!=NULL)
    {
        while (!feof(file))
        {
            fscanf(file,"%s",str);

            if (strcmp(str,"*")==0)   /*print comments */
                {
                    printf("\n%s ",str);
                    while (!feof(file))
                    {
                        fscanf(file,"%s",str);
                        if (isoperation(str)==1)
                            break;
                        printf("%s ",str);
                    }
                    printf("\n");
                }
            if ((strcmp(str,"begin")==0))
                {
                    while(!feof(file))
                    {
                        fscanf(file,"%s",str);
                        if ((isoperation(str)==1) && (memory->data != 0))
                            push(str);
                        if (strcmp(str,"end")==0)
                            break;
                        if (strcmp(str,"*")==0)
                        {
                            printf("\n%s ",str);
                            while (1)
                            {
                                fscanf(file,"%s",str);
                                if (isoperation(str)==1)
                                    break;
                                printf("%s ",str);
                            }
                        printf("\n");
                        }
                    }
                        pop(str);
                }
            if (isoperation(str)==1)
                operation(str);

        }
    }
    else /*  file didn't found*/
    {
        printf("file isn't found or it couldn't be open\n");
        return (-1);
    }

    fclose(file);

    return 0;
}


void add(MemoryProt *list, char h) /* h - right or left */
{
	if(*list == NULL)
	{
		if((*list = malloc(sizeof(Memory))) == NULL)
		{
			printf("Error in add\n");
			exit(-1);
		}
		(*list)->data= 0;
	}
	else
	{
		MemoryProt new_m;
		if((new_m = malloc(sizeof(Memory))) == NULL)
		{
			printf("error in add\n");
			exit(-1);
		}
		new_m->data = 0;
		if(h =='r')
		{
			(*list)->right= new_m;
			new_m->left = (*list);
			new_m->right = NULL;
		}
		else
		{
			(*list)->left = new_m;
			new_m->right= (*list);
			new_m->left = NULL;
		}
	}

}



void operation(char *str)
{
    char c;
    if (strcmp(str,"movl")==0)
    {
     	if(memory->left==NULL)
			add(&memory,'l');
		memory = memory->left;
    }
    if (strcmp(str,"movr")==0)
    {
        if(memory->right == NULL)
			add(&memory,'r');
		memory = memory->right;
    }
    if (strcmp(str,"inc")==0)
    {
        if((memory->data) < 255)
        memory->data++;
        else
        {
                memory->data = 0;
                printf("Data = 0");
        }

    }
    if ((strcmp(str,"dec")==0) && (memory->data != 0))
        memory->data--;
    if (strcmp(str,"print")==0)
        printf("\n%d\n",memory->data);
    if (strcmp(str,"get")==0)
    {
        printf("\nEnter one character from the keyboard\n");
        scanf("%c", &c);
        memory->data=c;
    }
    if (strcmp(str,"printc")==0)
         printf("\n%c\n",memory->data);
}


int isoperation(char *str)
{
	if((strcmp(str,"movl")==0)||(strcmp(str,"movr")==0)||(strcmp(str,"inc")==0)||
	(strcmp(str,"dec")==0)||(strcmp(str,"print")==0)||(strcmp(str,"get")==0)||
	(strcmp(str,"printc")==0)||(strcmp(str,"begin")==0)||(strcmp(str,"end")==0))
        return 1;
	else
        return 0;
}



void push(char *str)
{

    if(strcmp(str,"movl")==0)
       s.circle[s.i]=1;
    if(strcmp(str,"movr")==0)
       s.circle[s.i]=2;
    if(strcmp(str,"inc")==0)
       s.circle[s.i]=3;
    if(strcmp(str,"dec")==0)
       s.circle[s.i]=4;
    if(strcmp(str,"get")==0)
       s.circle[s.i]=5;
    if(strcmp(str,"print")==0)
       s.circle[s.i]=6;
    if(strcmp(str,"printc")==0)
       s.circle[s.i]=7;

      s.i++;
}


void pop(char *str)
{
    int i;
    while(1)
    {
        for (i=0;i<10;i++)
        {

            switch(s.circle[i])
            {
                case 1: strcpy(str,"movl");
                          operation(str);
                          break;
                case 2: strcpy(str,"movr");
                          operation(str);
                          break;
                case 3:   strcpy(str,"inc");
                          operation(str);
                          break;
                case 4:   strcpy(str,"dec");
                          operation(str);
                          break;
                case 5: strcpy(str,"get");
                          operation(str);
                          break;
                case 6: strcpy(str,"print");
                          operation(str);
                          break;
                case 7: strcpy(str,"printc");
                          operation(str);
                          break;
                default:
                         break;
            }
    	}
        if (memory->data==0)
            break;
    }

}
