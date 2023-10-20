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
#define MAX 4
typedef struct
{
    int front;
    int rear;
    int count;
    int data[MAX];
}Queue_Cir;

/******************************************************************************
* Prototypes
******************************************************************************/
void init(Queue_Cir &queue);
bool IsEmpty(Queue_Cir queue);
bool IsFull(Queue_Cir queue);
void enQueue(Queue_Cir &queue, int value, bool &flag);
void deQueue(Queue_Cir &queue, int &value, bool &flag);
int peek(Queue_Cir queue, bool &flag);
void enter_queue(Queue_Cir &queue);
void display_queue(Queue_Cir queue);
void menu();

/******************************************************************************
* Code
******************************************************************************/

int main()
{
    char select = 0;
    Queue_Cir queue;
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
                    printf("\nQueue Circular is empty");
                }
                else
                {
                    printf("\nQueue Circular is not empty");
                }
                break;
            }
            case '2':
            {
                if(IsFull(queue))
                {
                    printf("\nQueue Circular is full");
                }
                else
                {
                    printf("\nQueue Circular is not full");
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
    
    /* 1 ví dụ khác để hiểu hơn về hàng đợi vòng 
    

    int a[] ={74, 99, 60, 55, 64, 84, 67, 72, 77, 89};
    Queue_Cir queue;
    bool flag = 0;
    int value = 0;
    init(queue);
    for(int i = 0; i < 10; i++)
    {
        if(a[i] > a[0] && a[i] % 2 == 1)
        {
            deQueue(queue, value, flag);
        }
        else
        {
            enQueue(queue, a[i], flag);
        }
    }
    printf("queue sau khi chay: ");
    display_queue(queue);
*/
    
    return 0;
}

/******************************************************************************
* Functions
******************************************************************************/
void menu()
{
    printf("\n\t\tTHUAT TOAN QUEUE CIRCULAR VOI ARRAY\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Kiem tra queue rong\n");
    printf("2.Kiem tra queue day\n");
    printf("3.Them phan tu vao queue\n");
    printf("4.Xoa phan tu khoi queue\n");
    printf("5.In queue\n");
    printf("6.Tra ve phan tu o dau hang doi\n");
    printf("7.Thoat chuong trinh\n");
}

void init(Queue_Cir &queue)
{
    queue.front = queue.rear = -1;
    queue.count = 0;
}

bool IsEmpty(Queue_Cir queue)
{
    return (queue.count == 0);
    // hoặc có thể viết return (queue.front == -1)
}

bool IsFull(Queue_Cir queue)
{
    return (queue.count == MAX);
}
/* 1 cách viết khác kiểm tra queue full
bool IsFull(Queue_Cir queue)
{
    return ((queue.front == 0 && queue.rear == MAX - 1) || (queue.rear == queue.front - 1));
    // lệnh trên có thể viết gọn lại là:  return ((queue.rear + 1) % MAX == queue.front)
}
*/

void enQueue(Queue_Cir &queue, int value, bool &flag)
{
    flag = 0;
    if(IsFull(queue))
    {
        printf("\nQueue Circular is full\n");
    }
    else
    {
        if(queue.front == -1 && queue.rear == -1)
        {
            queue.front = queue.rear = 0;
        }
        else
        {
           queue.rear = (queue.rear + 1) % MAX;
        }
        queue.data[queue.rear] = value;
        flag = 1;
        queue.count++;
    }
}

void deQueue(Queue_Cir &queue, int &value, bool &flag)
{
    flag = 0;
    if(IsEmpty(queue))
    {
        printf("\nQueue Circular is empty");
    }
    else
    {
        value = queue.data[queue.front];
        if (queue.front == queue.rear) {
            queue.front = queue.rear = -1; // Đặt lại hàng đợi rỗng
        } else {
            queue.front = (queue.front + 1) % MAX;
        }
        queue.count--;
        flag = 1;
    }
}
int peek(Queue_Cir queue, bool &flag)
{
    flag = 0;
    if(IsEmpty(queue))
    {
        printf("\nQueue Circular is empty!");
        return NULL;
    }
    else
    {
        flag = 1;
        return queue.data[queue.front]; 
    }
}

void enter_queue(Queue_Cir &queue)
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
void display_queue(Queue_Cir queue)
{
    if(IsEmpty(queue))
	{
		printf("\nQueue Circular is empty!");
	}
	else
	{
        int i = 0;
		for ( i = queue.front; i != queue.rear; i = (i + 1) % MAX) {
            printf("%d ", queue.data[i]);
        }
        printf("%d\n", queue.data[i]);
    }
}

/******************************************************************************
* End of File
******************************************************************************/