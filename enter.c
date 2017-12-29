#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

void Show(int *, const int);
void instruct();
void Swap(int *, int *);
void Bubble(int *, const int);
void Qsort(int *, int , const int);
void Random_ent(int *, const int);
void Enter(int *, const int N);

int Twins(int *, const int);

int Maxt(int *, const int, int);
int Mint(int *, const int, int);
int Max(int *, const int);
int Min(int *, const int);




int main()
{
	setlocale(LC_ALL, "rus");
	
	const int N;
	int twin;
	 
	instruct();
	
	printf("Введите длинну массива:\t");
	
	do
	{
	scanf("%d", &N);
	if(N>100 || N<2)
	printf("Некорректная длинна, введите заново:\t");
	}while(N>100 || N<2);	
	int arr[N];
	
	printf("\n\nВы хотите сами заполнить массив , или автоматически\n1. Вручную\n2. Автоматически\n");
	int a;
	do
	{
	scanf("%d", &a);
	if(!(a==1 || a==2))
	printf("Некорректный ввод, выберите режим заполнения повторно:\t");
	}while(!(a==1 || a==2));
	
	printf("\n");
	if(a == 1)
	Enter(arr, N);
	else if(a == 2)
	Random_ent(arr, N);
	Show(arr, N);
	
	a = 0;
	printf("\n\nКакую сортировку хотите использовать ?\n1. Сортировка пузырьком\n2. Сортировка Хоара\n");
	do
	{
	scanf("%d", &a);
	if(!(a==1 || a==2))
	printf("Некорректный ввод, выберите режим сортировки повторно:\t");
	}while(!(a==1 || a==2));
	
	if(a == 1)
	Bubble(arr, N);
	else if(a == 2)
	Qsort(arr,0, N-1);
	Show(arr, N);
	
	a = 0;
	printf("\n\nХотите удалить повторяющиеся элементы и вывести массив на экран?\n1. Да\n2. Нет\n");
	do
	{
	scanf("%d", &a);
	if(!(a==1 || a==2))
	printf("Некорректный ввод, выберите Действие(1 или 2) повторно:\t");
	}while(!(a==1 || a==2));
	
	if(a == 1)
	{
		twin = Twins(arr, N);
		Show(arr, N-twin);
	}else if(a == 2)
	Show(arr, N);
	
	if(a == 1)
	{
		printf("\n\n\nMax = %d\n\n", arr[Maxt(arr, N, twin)]);
		printf("\nMin = %d", arr[Mint(arr, N, twin)]);
	}
	else if(a == 2)
	{
		printf("\n\n\nMax = %d\n\n", arr[Max(arr, N)]);
		printf("\nMin = %d", arr[Min(arr, N)]);	
	}
	
	
	
	printf("\n\t***Программа выполнена***\n(Нажмите на любую клавишу для завершения)");
	
	
	getchar();
	getchar();
	return 0;
}

void instruct()
{
	printf("\t\t***Вас приветствует программа сортировки массива***\n");
	
	
}

void Show(int *arr, int N)
{
	printf("\n\n\t***Ваш массив***:\n");
	int i;
	for(i=0; i<N; i++)
	{
		printf("%d.\t%d\n",i+1, arr[i]);
	}
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

void Bubble(int *arr, const int N)
{
   int i, j;
   for (i = 0; i < N-1; i++)    
       
       for (j = 0; j < N-i-1; j++) 
       
           if (arr[j] > arr[j+1])
              Swap(&arr[j], &arr[j+1]);
}

void Qsort (int *arr,int first, int last)
{
	
	int i = first, j = last; 
	int tmp, x = arr[(first + last) / 2]; 
	
	do { 
		while (arr[i] < x) 
		i++; 
		while (arr[j] > x) 
		j--; 
		if (i <= j) 
		{	 
			if (i < j) 
			Swap(&arr[i], &arr[j]); 	
			
			i++; 
			j--; 
		} 
	} while (i <= j);
	 
	if (i < last) 
	Qsort(arr, i, last); 
	
	if (first < j) 
	Qsort(arr, first,j); 	
}

void Random_ent(int *arr,const int N)
{
	int i;
	srand(time(NULL));
	for(i=0; i<N; i++)
		arr[i] = rand()%100;
	
}

int Twins(int *arr, const int N)
{
	int i,j,count=0, Last = N-1;
	
	Bubble(arr, N);
	
	for(i=0; i<N-1; i++)
	{
		while(arr[i]==arr[i+1])
		{
			if(arr[i] == arr[i+1])
			{
				for(j=i; j<Last; j++)
				arr[j] = arr[j+1];
				count++;
				arr[Last] = -(count+1);
				Last--;
			}
		}
	}

return count;		
}


 void Enter(int *arr, const int N)
{
	int i,j, Error=0;
	char str[40];
	
	for(i=0; i<40; i++)
		str[i] = '\0';
		
	for(i=0; i<N; i++)
	{	
		do
		{
			Error = 0;	
			for(j=0; j<40; j++)
			str[j] = '\0';
			
			printf("Введите %d элемент массива:", i+1);
			scanf("%s", str);
			
			if(atoi(str) != 0 )
			{
				for(j=0; j<40; j++)
				{
					if(isalpha(str[j])) 
					{
						Error = 1;
						break;
					}
					
				}
			
				if(Error == 0)
				{
				 	arr[i] = atoi(str);
				}
				
			}
			else if (strlen(str) == 1)
				{
					if(str[0]=='0')
					{
						arr[i] = 0;
						Error = 0;
					}
					else Error = 1;
				}
			else Error = 1;
			
			
			
		}while(Error == 1);
		
		printf("\t\t%d\n", arr[i]);
	}
	
}

int Maxt(int *arr, const int N, int twin)
{
	int a;
	printf("Введите номер искомого максимума: \t");
	do
	{
	scanf("%d", &a);
	if((N-a-twin)<0 || a<1)
	printf("Некорректный ввод, выберите максимум повторно:\t");
	}while((N-a-twin)<0 || a<1);
	return N-a-twin;	
}

int Mint(int *arr, const int N, int twin)
{
	int a;
	printf("Введите номер искомого максимума минимума: \t");
	do
	{
	scanf("%d", &a);
	if((a-1)>=N-twin || a<1)
	printf("Некорректный ввод, выберите минимум  повторно:\t");
	}while((a-1)>=N-twin || a<1);

	return a-1;	
}

int Max(int *arr, const int N)
{
	int a;
	printf("Введите номер искомого максимума: \t");
	do
	{
	scanf("%d", &a);
	if((N-a)<0 || a<1 )
	printf("Некорректный ввод, выберите максимум повторно:\t");
	}while((N-a)<0 || a<1);
	return N-a;	
}

int Min(int *arr, const int N)
{
	int a;
	printf("Введите номер искомого максимума минимума: \t");
	do
	{
	scanf("%d", &a);
	if((a-1)>=N || a<1 )
	printf("Некорректный ввод, выберите минимум  повторно:\t");
	}while((a-1)>=N || a<1);

	return a-1;	
}





