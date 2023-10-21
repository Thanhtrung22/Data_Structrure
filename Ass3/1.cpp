/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>

/******************************************************************************
* Definitions
******************************************************************************/
struct Node
{
    int data;
    Node* next;
};

typedef struct Node* LinkedList;
typedef struct Node* PNode;


/******************************************************************************
* Prototypes
******************************************************************************/
void init(LinkedList &H);
bool isEmpty(LinkedList H);
void Insert_Begin(LinkedList &H, int k);
PNode Search_Node(LinkedList H, int x);
void Insert_After(LinkedList &H, PNode P, int k);
void Insert_Before(LinkedList &H, PNode P, int k);
void Delete_Begin(LinkedList &H, bool &flag);
void Display(LinkedList H);
float Average(LinkedList H);
PNode create_node(int x);
void Delete_WithValue(LinkedList &H, int k);
void sort_up(LinkedList &H, bool &flag);
void sort_down(LinkedList &H, bool &flag);
void InSert_End(LinkedList &H, int value);
int List_Length(LinkedList H);
void menu();

/******************************************************************************
* Codes
******************************************************************************/
int main()
{
    LinkedList H;
    char answer = '\0';
    int select = 0;

    init(H);
    while(answer != 'n')
    {
        system("cls");
        menu();
        printf("\nNhap lua chon cua ban: ");
        scanf("%d", &select);
        switch(select)
        {
            case 1:
            {
                if(isEmpty(H))
                {
                    printf("\nLinked list is empty");
                }
                else
                {
                    printf("\nLinked list is not empty");
                }
                break;
            }
            case 2:
            {
                int value = 0;
                printf("\nNhap gia tri muon them: ");
                scanf("%d", &value);
                Insert_Begin(H, value);
                printf("\nAdd list successfully");
                break;
            }
            case 3:
            {
                int value = 0;
                printf("\nNhap gia tri muon them: ");
                scanf("%d", &value);
                InSert_End(H, value);
                printf("\nAdd list successfully");
                break;
                break;
            }
            case 4:
            {
            	int value1 = 0, value2 = 0;
                PNode P = NULL;
                printf("\nNhap gia tri ban dau: ");
                scanf("%d", &value1);
                printf("Nhap gia tri muon them vao sau %d: ", value1);
                scanf("%d", &value2);
                P = Search_Node(H, value1);
                if(isEmpty(H))
                {
                    Insert_After(H, P, value2);
                    printf("\n List is empty.Value %d is added to the list", value2);
                }
                if(P != NULL)
                {
                    Insert_After(H, P, value2);
                    printf("\nAdd %d after %d successfully", value2, value1);
                }
                else
                {
                    printf("\nNot find  %d in list", value1);
                }
                break;
                
            }
            case 5:
            {
                int value1 = 0, value2 = 0;
                PNode P = NULL;
                printf("\nNhap gia tri ban dau: ");
                scanf("%d", &value1);
                printf("Nhap gia tri muon them vao truoc %d: ", value1);
                scanf("%d", &value2);
                if(isEmpty(H))
                {
                    Insert_Before(H, P, value2);
                    printf("\n List is empty.Value %d is added to the list", value2);
                }
                
                P = Search_Node(H, value1);
                if(P != NULL)
                {
                    Insert_Before(H, P, value2);
                    printf("\nAdd %d before %d successfully", value2, value1);
                }
                else
                {
                    printf("\nNot find  %d in list", value1);
                }
                break;
            }
            case 6:
            {
                bool flag = 0;
                Delete_Begin(H, flag);
                if(flag)
                {
                    printf("\nDelete list successfully");
                }
                else
                {
                    printf("\nDelete not successful");
                }
                break;
            }
            case 7:
            {
                int value = 0;
                bool flag = 0;
                PNode node = NULL;
                printf("\nNhap vao gia tri muon xoa: ");
                scanf("%d", &value);
                node = Search_Node(H, value);
                if(node != NULL)
                {
                    Delete_WithValue(H, value);
                    printf("\nDelete list successfully");
                }
            
                else
                {
                    printf("\nNot finding %d in list", value);
                }
                break;
            }
            case 8:
            {
                printf("\nList hien tai: ");
                Display(H);
                break;
            }
            case 9:
            {
                float avg = 0;
                if(!isEmpty(H))
                {
                    avg = Average(H);
                    printf("\nAverage of list is: %.2f", avg);
                }
                else
                {
                    printf("\nList is empty");
                }
                
                break;
            }
            case 10:
            {
                bool flag = 0;
                sort_up(H, flag);
                if(flag)
                {
                    printf("\nSort up list successfully");
                }
                
                break;
            }
            case 11:
            {
                bool flag = 0;
                sort_down(H, flag);
                if(flag)
                {
                    printf("\nSort down list successfully");
                }
                
                break;
            }
            case 12:
            {
                int value = 0;
                PNode node = NULL;
                printf("\nNhap gia tri muon tim: ");
                scanf("%d", &value);
                node = Search_Node(H, value);
                if(node != NULL)
                {
                    printf("Linked list have %d in list", value);
                }
                else
                {
                    printf("\nNot finding %d in list", value);
                }
                break;
            }
            case 13:
            {
                int length = 0;
                length = List_Length(H);
                printf("\nLength of list is %d", length);
                break;
            }
            case 14:
            {
                printf("\nSee you again");
                return 0;
            }
            default:
            {
                printf("\nBan da nhap sai lua chon. Vui long nhap lai!");
                break;
            }
        }
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

void menu()
{
    printf("\n\t\t LINKED LIST SINGLE PROGRAM\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Check list empty\n");
    printf("2.Add value at begin\n");
    printf("3.Add value at end\n");
    printf("4.Add value after another value\n");
    printf("5.Add value before another value\n");
    printf("6.Delete at begin of list \n");
    printf("7.Delete all nodes has value K\n");
    printf("8.Display list\n");
    printf("9.Average of all values in list\n");
    printf("10.Sort up list\n");
    printf("11.Sort down list\n");
    printf("12.Search value in list\n");
    printf("13.Display length of list\n");
    printf("14.Exit\n");
}
void init(LinkedList &H)
{
    H = NULL;
}
PNode create_node(int x)
{
    PNode Q = NULL;
    Q = new Node;
    Q->data = x;
    Q->next = NULL;
    return Q;
}
bool isEmpty(LinkedList H)
{
    return H == NULL;
}

PNode Search_Node(LinkedList H, int x)
{
    PNode P = NULL;
    P = H;
    while(P != NULL)
    {
        if(P->data == x)
        {
            return P;
        }
        else
        {
            P = P->next;
        }
    }
    return NULL;
}

void Insert_Begin(LinkedList &H, int k)
{
    PNode Q = create_node(k);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        Q->next = H;
        H = Q;
    }
}

void Insert_After(LinkedList &H, PNode P, int k)
{
    PNode Q = create_node(k);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        if(P == NULL)
        {
            return;
        }
        Q->next = P->next;
        P->next = Q;
    }
}

void Insert_Before(LinkedList &H, PNode P, int k)
{
    PNode Q = create_node(k);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        if(P == NULL)
        {
            
            return;
        }
        Q->data = P->data;
        P->data = k;
        Q->next = P->next;
        P->next = Q;
    }
}

void Delete_Begin(LinkedList &H, bool &flag)
{
    flag = 0;
    if(isEmpty(H))
    {
        printf("\nEmpty list!");
    }
    else
    {
        PNode P = H;
        H = H->next;
        delete P;
        flag = 1;
    }
}




void Delete_WithValue(LinkedList &H, int k)
{
    
	if (isEmpty(H))
    {
        printf("\nEmpty list!");
        return;
    }
    else
    {
    	PNode current = H;
	    PNode prev = NULL;
	
	    while (current != NULL)
	    {
	        if (current->data == k)
	        {
	            if (prev == NULL)
	            {
	                // Xóa phần tử đầu tiên có giá trị k
	                PNode temp = current;
	                current = current->next;
	                H = current;
	                delete temp;
	            }
	            else
	            {
	                // Xóa phần tử có giá trị k khỏi danh sách
	                prev->next = current->next;
	                delete current;
	                current = prev->next;
	            }
	        }
	        else
	        {
	            prev = current;
	            current = current->next;
	        }
	    }
       
	}
    
    
}

float Average(LinkedList H)
{
    float sum = 0;
    int count = 0;
    PNode P = H;
    while(P != NULL)
    {
        sum += P->data;
        count++;
        P = P->next;
    }
    return (sum / count);
}
void Display(LinkedList H)
{
    if(isEmpty(H))
    {
        printf("\nList is empty");
    }
    else
    {
        PNode P = H;
        while(P != NULL)
        {
            printf("%d ", P->data);
            P = P->next;
        }
    }
}

void InSert_End(LinkedList &H, int value)
{
    PNode Q = NULL;
    Q = create_node(value);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        PNode P = H;
        while(P->next != NULL)
        {
            P = P->next;
        }
        P->next = Q;
    }
}
int List_Length(LinkedList H)
{
    int length = 0;
    PNode P = H;
    while(P != NULL)
    {
        length++;
        P = P->next;
    }
    return length;
}
void sort_up(LinkedList &H, bool &flag)
{
     if (isEmpty(H)) {
        printf("\nEmpty list!");
        flag = 0;
        return;
    }

    LinkedList current = H;
    LinkedList min;

    while (current->next != NULL) {
        min = current;

        // Tìm phần tử có giá trị nhỏ nhất trong phần còn lại của danh sách.
        LinkedList temp = current->next;
        while (temp != NULL) {
            if (temp->data < min->data) {
                min = temp;
            }
            temp = temp->next;
        }

        // Đổi chỗ phần tử hiện tại và phần tử nhỏ nhất tìm được.
        int tempData = current->data;
        current->data = min->data;
        min->data = tempData;

        current = current->next;
    }
    flag = 1;
}

void sort_down(LinkedList &H, bool &flag)
{
    if (isEmpty(H)) {
        flag = 0;
        printf("\nEmpty list!");
        return;
    }

    LinkedList current = H;
    LinkedList max;

    while (current->next != NULL) {
        max = current;

        // Tìm phần tử có giá trị nhỏ nhất trong phần còn lại của danh sách.
        LinkedList temp = current->next;
        while (temp != NULL) {
            if (temp->data > max->data) {
                max = temp;
            }
            temp = temp->next;
        }

        // Đổi chỗ phần tử hiện tại và phần tử nhỏ nhất tìm được.
        int tempData = current->data;
        current->data = max->data;
        max->data = tempData;

        current = current->next;
    }
    flag = 1;
}







/******************************************************************************
* End of File
******************************************************************************/