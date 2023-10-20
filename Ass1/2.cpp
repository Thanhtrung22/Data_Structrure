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
    int front;
    int rear;
    int data[MAX];
}Queue;

/******************************************************************************
* Prototypes
******************************************************************************/
void init(Queue &queue);
bool IsEmpty(Queue queue);
bool IsFull(Queue queue);
void enQueue(Queue &queue, int value, bool &flag);
void deQueue(Queue &queue, int &value, bool &flag);
int peek(Queue queue, bool &flag);
void enter_queue(Queue &queue);
void display_queue(Queue queue);
void menu();

/******************************************************************************
* Code
******************************************************************************/
int main()
{

    char select = 0;
    Queue queue;
    char answer[6] = "\0";

    init(queue);
    enter_queue(queue);
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
                if(IsEmpty(queue))
                {
                    printf("\nQueue is empty");
                }
                else
                {
                    printf("\nQueue is not empty");
                }
                break;
            }
            case '2':
            {
                if(IsFull(queue))
                {
                    printf("\nQueue is full");
                }
                else
                {
                    printf("\nQueue is not full");
                }
                break;
            }
            case '3':
            {
                int value = 0;
                bool flag = 0;
                printf("\nNhap gia tri muon them vao queue: ");
                scanf("%d", &value);
                enQueue(queue, value, flag);
                if(flag)
                {
                	printf("\nAdd queue successfully");
				}
                break;
            }
            case '4':
            {
            	bool flag = 0;
                int value = 0;
                deQueue(queue, value, flag);
                if(flag)
                {
                	printf("\nDequeue successfully");
				}
                break;
            }
            case '5':
            {
                printf("\nQueue hien gio: ");
                display_queue(queue);
                break;
            }
            case '6':
            {
                int get_value = 0;
                bool flag = 0;
                get_value = peek(queue, flag);
                if(flag)
                {
                	printf("\nGia tri lay ra o dau hang doi la: %d", get_value);
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
    printf("\n\t\tTHUAT TOAN QUEUE VOI ARRAY\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Kiem tra queue rong\n");
    printf("2.Kiem tra queue day\n");
    printf("3.Them phan tu vao queue\n");
    printf("4.Xoa phan tu khoi queue\n");
    printf("5.In queue\n");
    printf("6.Tra ve phan tu o dau hang doi\n");
    printf("7.Thoat chuong trinh\n");
}

void init(Queue &queue)
{
    queue.front = queue.rear = -1;
}

bool IsEmpty(Queue queue)
{
    return ((queue.front == -1) || (queue.front > queue.rear));
}

bool IsFull(Queue queue)
{
    return (queue.rear == MAX - 1);
}

void enQueue(Queue &queue, int value, bool &flag)
{
    flag = 0;
    if(IsFull(queue))
    {
        printf("\nQueue is full!");
    }
    else
    {
        if(queue.front == -1 && queue.rear == - 1)
        {
            queue.front = queue.rear = 0;
        }
        else
        {
            queue.rear++;
        }
        flag = 1;
        queue.data[queue.rear] = value;
    }
    
}

void deQueue(Queue &queue, int &value, bool &flag)
{
    flag = 0;
    if(IsEmpty(queue))
    {
        printf("\nQueue is empty!");
    }
    else
    {
        value = queue.data[queue.front];
        queue.front++;
        flag = 1;
        if((queue.front > queue.rear) && (queue.rear == MAX - 1))
        {
            queue.front = queue.rear = -1;
        }
    }
}

int peek(Queue queue, bool &flag)
{
    flag = 0;
    if(IsEmpty(queue))
    {
        printf("\nQueue is empty!");
        return NULL;
    }
    else
    {
        flag = 1;
        return queue.data[queue.front]; 
    }
}

void enter_queue(Queue &queue)
{
    int length = 0;
    int temp_value = 0;
    bool flag = 0;
    do
    {
        printf("Nhap so phan tu queue (<= %d): ", MAX);
        scanf("%d", &length);
    }while(length <= 0 || length > MAX);
    for(int i = 0; i < length; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &temp_value);
        enQueue(queue, temp_value, flag);
    }
}

void display_queue(Queue queue)
{
    if(IsEmpty(queue))
	{
		printf("\nQueue is empty");
	}
	else
	{
		for (int i = queue.front; i <= queue.rear ; i++)
	    {
	        
			printf("%d ", queue.data[i]);
	    }
    	printf("\n");
	}
}


/******************************************************************************
* End of File
******************************************************************************/