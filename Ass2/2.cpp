/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include  <string.h>
#include <conio.h>
#include <stdlib.h>
/******************************************************************************
* Definitions
******************************************************************************/
#define MAX 100
typedef struct
{
    unsigned int n;
    int data[MAX];
}Stack;

/******************************************************************************
* Prototypes
******************************************************************************/
void init(Stack &stack);
bool IsEmpty(Stack stack);
bool IsFull(Stack stack);
void Push(Stack &stack, int value, bool &flag);
char Pop(Stack &stack, bool &flag);
int Top(Stack stack, bool &flag);
void enter_stack(Stack &stack);
void display_stack(Stack stack);
void convertToBaseN(Stack &S, int so, int coSo, char* ketQua);

/******************************************************************************
* Code
******************************************************************************/
int main()
{
    Stack stack;
    char answer = '\0';
    int coSo, so;
    char ketQua[MAX];

    init(stack);
    while( answer != 'n')
    {
        system("cls");
        printf("Nhap so can chuyen: ");
        scanf("%d", &so);
        
        printf("Nhap co so can chuyen: ");
        scanf("%d", &coSo);
        
        convertToBaseN(stack ,so, coSo, ketQua);
    
        printf("Sau khi chuyen doi: %s\n", ketQua);
        printf("\nDo you wanna continue?(y/n)");
        fflush(stdin);
        answer = getche();

    }
    printf("\nSee you again!");
    return 0;
}



/******************************************************************************
* Functions
******************************************************************************/

void convertToBaseN(Stack &S, int so, int coSo, char* ketQua)
{
    char num[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    

    int du, i = 0;
    bool flag = 0;
    if (so == 0) {
        ketQua[i++] = '0';
    } else {
        while (so) {
            du = so % coSo;
            Push(S, num[du], flag);
            so /= coSo;
        }
    }
    
    while (!IsEmpty(S)) {
        ketQua[i++] = Pop(S, flag);
    }
    
    ketQua[i] = '\0';
}
void init(Stack &stack)
{
    stack.n = 0;
}

bool IsEmpty(Stack stack)
{
    return (stack.n == 0);
}
bool IsFull(Stack stack)
{
    return (stack.n == MAX);
}
void Push(Stack &stack, int value, bool &flag)
{
	flag = 0;
    if(!(IsFull(stack)))
    {
    	flag = 1;
        stack.data[stack.n] = value;
        stack.n++;
    }
    else
    {
        printf("\nStack is full");
    }
}
char Pop(Stack &stack, bool &flag)
{
	flag = 0;
    if(!(IsEmpty(stack)))
    {
    	flag = 1;
        stack.n--;
        return stack.data[stack.n];
        
    }
    else
    {
        printf("\nStack is empty");
        return NULL;
    }
}

int Top(Stack stack, bool &flag)
{
	flag = 0;
    if(!(IsEmpty(stack)))
    {
    	flag = 1;
        return stack.data[stack.n -1];
    }
    else
    {
        printf("\nStack is empty");
        return NULL;
    }
}

void enter_stack(Stack &stack)
{
    int length = 0;
    int temp_value = 0;
    bool flag = 0;
    do
    {
        printf("Nhap so phan tu stack (<= %d): ", MAX);
        scanf("%d", &length);
    }while(length <= 0 || length > MAX);
    for(int i = 0; i < length; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &temp_value);
        Push(stack, temp_value, flag);
    }
}

void display_stack(Stack stack)
{
	if(IsEmpty(stack))
	{
		printf("\nStack is empty");
	}
	else
	{
		for (int i = stack.n - 1; i >= 0; i--)
	    {
	        
			printf("%d ", stack.data[i]);
	    }
    	printf("\n");
	}
    
}

/******************************************************************************
* End of File
******************************************************************************/