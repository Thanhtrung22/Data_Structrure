#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4


// Định nghĩa cấu trúc của hàng đợi vòng
typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} CircularQueue;

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

// Hàm kiểm tra hàng đợi có đầy không
int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Hàm thêm một phần tử vào hàng đợi
void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("full\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->arr[queue->rear] = item;
        printf("add ok\n", item);
    }
}

// Hàm loại bỏ một phần tử khỏi hàng đợi
int dequeue(CircularQueue *queue) {
    int item;
    if (isEmpty(queue)) {
        printf("empty.\n");
        return -1;
    } else {
        item = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("xoa ok\n", item);
        return item;
    }
}

// Hàm hiển thị cấu trúc của hàng đợi vòng
void display(CircularQueue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("empty\n");
    } else {
        printf("queue: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->arr[i]);
        }
        printf("%d\n", queue->arr[i]);
    }
}

int main() {
    CircularQueue queue;
    queue.front = -1;
    queue.rear = -1;

    int a[10] = {74, 99, 60, 55, 64, 84, 67, 72, 77, 89};
    for(int i = 0; i < 10; i++)
    {
    	if(a[i] > a[0] && a[i] % 2 != 0)
    	{
    		dequeue(&queue);
		}
		else
		{
			enqueue(&queue, a[i]);
		}
	}

    display(&queue);

    return 0;
}
