#include <stdlib.h>
#include <stdio.h>

int main ()
{
    int d,m,y,res,vis;
    printf("Enter the date: xx xx xxxx\n");
    scanf("%i %i %i", &d,&m,&y);
    printf("You entered:%i.%i.%i", d,m,y);
    vis = 0;

    if( y % 4 == 0 || y % 400 == 0 ) 
        vis = 1;

	switch (m) /* Index of month*/
	{
	case 3:
	case 11:
	case 2: 
	{
		if (vis == 1 && m == 2 )
        	m = 0;
        else m = 1;	
		break;
	}
	case 6: m = 2; break;
	case 9:
	case 12: m = 3; break;
	case 4:
	case 7: m = 4; break;
	case 10:
	case 1:
	{
		if (m == 1 || vis == 1)
			m = 4;
		else m = 5;	
		break;
	}
	case 5: m = 6; break;
	case 8: m = 0; break; 	
	}
        
	y = (int)(y*1.25)%7; /* Index of year*/
    res = (d+m+y)%7;
    printf("\nDay num_ %i\n", res);

    switch (res)
    {
    case 6: printf("Saturday");  break;
    case 7: printf("Sunday");	 break;
    case 1: printf("Monday");    break;
    case 2: printf("Tuesday"); 	 break;
    case 3: printf("Wednesday"); break;
    case 4: printf("Thursday");  break;
    case 5: printf("Friday");    break;
    }

    return 0;
}
