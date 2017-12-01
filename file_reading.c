#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
FILE *file;
char name[20];
if(argc < 2)
{
    printf("Enter File_name: ");
    scanf("%s", name);
} else if (argc == 2)
        {
            strcpy(argv[1], name);
        }

file = fopen(name, "rb");

int c, fsize = 0;
do
{
    c = fgetc(file);
    printf("%c", c);
}while(c != EOF);

    rewind(file);
    while ((fgetc(file)) != EOF)
        fsize++;

    fclose(file);
    printf("\n%i bytes\n", fsize);

    return 0;
}
