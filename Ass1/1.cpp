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
int Pop(Stack &stack, bool &flag);
int Top(Stack stack, bool &flag);
void enter_stack(Stack &stack);
void display_stack(Stack stack);
void menu();
/******************************************************************************
* Code
******************************************************************************/
int main()
{
    char select = 0;
    Stack stack;
    char answer[6] = "\0";

    init(stack);
    enter_stack(stack);
    while(strcmp(answer, "no") != 0)
    {
        system("cls");
        menu();
        printf("\nNhap lua chon cua ban: ");
        select = getche();
        switch(select)
        {
            case '1':
            {
                if(IsEmpty(stack))
                {
                    printf("\nStack is empty");
                }
                else
                {
                    printf("\nStack is not empty");
                }
                break;
            }
            case '2':
            {
                if(IsFull(stack))
                {
                    printf("\nStack is full");
                }
                else
                {
                    printf("\nStack is not full");
                }
                break;
            }
            case '3':
            {
                int value = 0;
                bool flag = 0;
                printf("\nNhap gia tri muon them vao stack: ");
                scanf("%d", &value);
                Push(stack, value, flag);
                if(flag)
                {
                	printf("\nAdd stack successfully");
				}
                break;
            }
            case '4':
            {
            	bool flag = 0;
                Pop(stack, flag);
                if(flag)
                {
                	printf("\nPop stack successfully");
				}
                break;
            }
            case '5':
            {
                printf("\nStack hien gio: ");
                display_stack(stack);
                break;
            }
            case '6':
            {
                int get_value = 0;
                bool flag = 0;
                get_value = Top(stack, flag);
                if(flag)
                {
                	printf("\nGia tri lay ra tren top stack la: %d", get_value);
				}
                
                break;
            }
            case '7':
            {
                printf("\nSee you again!");
                return 0;
            }
            default:
            {
                printf("\nBan da nhap sai lua chon. Vui long nhap lai!");
                break;
            }
        }
        printf("\nDo you wanna continue?(yes/no)");
        fflush(stdin);
        scanf("%s", answer);

    }
    printf("\nSee you again!");
    return 0;
}



/******************************************************************************
* Functions
******************************************************************************/

void menu()
{
    printf("\n\t\tTHUAT TOAN STACK VOI ARRAY\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Kiem tra stack rong\n");
    printf("2.Kiem tra stack day\n");
    printf("3.Them phan tu vao stack\n");
    printf("4.Xoa phan tu khoi stack\n");
    printf("5.In stack\n");
    printf("6.Tra ve phan tu o dinh stack\n");
    printf("7.Thoat chuong trinh\n");
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
int Pop(Stack &stack, bool &flag)
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