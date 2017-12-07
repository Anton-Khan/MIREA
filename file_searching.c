#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[])
{

FILE *file;
char name[20];
if(argc >= 2)
{
    strcpy(name, argv[1]);
}
else
{
    printf("Enter file name:");
    scanf("%s", name);
}

file = fopen(name, "r");
if (file == NULL)
{
    printf("file didn't open or find");
    exit(-1);
}

char str[256],search[30],*adr;
int i,new_string=1,new_char=0;
for(i=0;i<256; i++)
{
str[i]='\0';
}

printf("Enter searching string:");
scanf("%s", search);

while((feof(file)) == 0)
{
    for(i=0;i<256; i++)
    {
        str[i] = fgetc(file);
        if(str[i] == '\n')
        break;
    }
    /*printf("%s\n", str);*/

    if(strstr(str, search))
    {
        adr = strstr(str, search);
        if (adr != NULL)
        {
            new_char = strlen(str) - strlen(adr) + 1;
        }

        printf("string:%i  char:%i >>> %s\n", new_string, new_char, search);
    }

    for(i=0;i<256; i++)
    {
        str[i]='\0';
    }

    new_string++;
}

fclose(file);

    return 0;
}
