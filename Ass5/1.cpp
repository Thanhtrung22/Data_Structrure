/******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
#include <conio.h>
using namespace std;

/******************************************************************************
* Definitions
******************************************************************************/
struct DNode
{
    int data;
    DNode *nextL, *nextR;
};
typedef DNode* PDNode;

struct DoubleLinkedList
{
    PDNode H;
    PDNode T;
};
typedef struct DoubleLinkedList* PDoubleLinkedList;

/******************************************************************************
* Prototypes
******************************************************************************/
void init(PDoubleLinkedList &list);
bool isEmpty(const PDoubleLinkedList &list);
PDNode create_node(int x);
PDNode Search_Node(const PDoubleLinkedList &list, int x);
void Insert_Begin(PDoubleLinkedList &list, int k);
void InSert_End(PDoubleLinkedList &list, int k);
void Insert_After(PDoubleLinkedList &list, PDNode P, int k);
void Insert_Before(PDoubleLinkedList &list, PDNode P, int k);
void Delete_Begin(PDoubleLinkedList &list, bool &flag);
void Delete_WithValue(PDoubleLinkedList &list, int k);
float Average(const PDoubleLinkedList &list);
void Display(const PDoubleLinkedList &list);
int List_Length(const PDoubleLinkedList &list);
void sort_up(PDoubleLinkedList &list, bool &flag);
void sort_down(PDoubleLinkedList &list, bool &flag);
void menu();

/******************************************************************************
* Code
******************************************************************************/
int main()
{
    PDoubleLinkedList list;
    char answer = '\0';
    int select = 0;

    init(list);
    while (answer != 'n')
    {
        system("cls");
        menu();
        cout << "\nNhap lua chon cua ban: ";
        cin >> select;
        switch (select)
        {
            case 1:
            {
                if (isEmpty(list))
                {
                    cout << "\nDouble linked list is empty";
                }
                else
                {
                    cout << "\nDouble linked list is not empty";
                }
                break;
            }
            case 2:
            {
                int value = 0;
                cout << "\nNhap gia tri muon them: ";
                cin >> value;
                Insert_Begin(list, value);
                cout << "\nAdd list successfully";
                break;
            }
            case 3:
            {
                int value = 0;
                cout << "\nNhap gia tri muon them: ";
                cin >> value;
                InSert_End(list, value);
                cout << "\nAdd list successfully";
                break;
            }
            case 4:
            {
                int value1 = 0, value2 = 0;
                PDNode P = NULL;

                cout << "Nhap gia tri muon them vao: ";
                cin >> value2;

                if (isEmpty(list))
                {
                    Insert_After(list, P, value2);
                    cout << "\nList is empty.Value " << value2 << " is added to the list";
                }
                else
                {
                    cout << "\nNhap gia tri trong list: ";
                    cin >> value1;
                    P = Search_Node(list, value1);
                    if (P != NULL)
                    {
                        Insert_After(list, P, value2);
                        cout << "\nAdd " << value2 << " after " << value1 << " successfully";
                    }
                    else
                    {
                        cout << "\nNot find  " << value1 << " in list";
                    }
                }

                break;
            }
            case 5:
            {
                int value1 = 0, value2 = 0;
                PDNode P = NULL;

                cout << "Nhap gia tri muon them vao: ";
                cin >> value2;
                if (isEmpty(list))
                {
                    Insert_Before(list, P, value2);
                    cout << "\nList is empty.Value " << value2 << " is added to the list";
                }
                else
                {
                    cout << "\nNhap gia tri trong list: ";
                    cin >> value1;
                    P = Search_Node(list, value1);
                    if (P != NULL)
                    {
                        Insert_Before(list, P, value2);
                        cout << "\nAdd " << value2 << " before " << value1 << " successfully";
                    }
                    else
                    {
                        cout << "\nNot find  " << value1 << " in list";
                    }
                }

                break;
            }
            case 6:
            {
                bool flag = false;
                Delete_Begin(list, flag);
                if (flag)
                {
                    cout << "\nDelete list successfully";
                }
                else
                {
                    cout << "\nDelete not successful";
                }
                break;
            }
            case 7:
            {
                int value = 0;
                bool flag = false;
                PDNode node = NULL;
                if (isEmpty(list))
                {
                    cout << "\nEmpty list";
                }
                else
                {
                    cout << "\nNhap vao gia tri muon xoa: ";
                    cin >> value;
                    node = Search_Node(list, value);
                    if (node != NULL)
                    {
                        Delete_WithValue(list, value);
                        cout << "\nDelete list successfully";
                    }

                    else
                    {
                        cout << "\nNot finding " << value << " in list";
                    }
                }

                break;
            }
            case 8:
            {
                cout << "\nList hien tai: ";
                Display(list);
                break;
            }
            case 9:
            {
                float avg = 0;
                if (!isEmpty(list))
                {
                    avg = Average(list);
                    cout << "\nAverage of list is: " << avg;
                }
                else
                {
                    cout << "\nList is empty";
                }

                break;
            }
            case 10:
            {
                bool flag = false;
                sort_up(list, flag);
                if (flag)
                {
                    cout << "\nSort up list successfully";
                }

                break;
            }
            case 11:
            {
                bool flag = false;
                sort_down(list, flag);
                if (flag)
                {
                    cout << "\nSort down list successfully";
                }

                break;
            }
            case 12:
            {
                int value = 0;
                PDNode node = NULL;
                if (isEmpty(list))
                {
                    cout << "\nEmpty list";
                }
                else
                {
                    cout << "\nNhap gia tri muon tim: ";
                    cin >> value;
                    node = Search_Node(list, value);
                    if (node != NULL)
                    {
                        cout << "Linked list have " << value << " in list";
                    }
                    else
                    {
                        cout << "\nNot finding " << value << " in list";
                    }
                }

                break;
            }
            case 13:
            {
                int length = 0;
                length = List_Length(list);
                cout << "\nLength of list is " << length;
                break;
            }
            case 14:
            {
                cout << "\nSee you again";
                return 0;
            }
            default:
            {
                cout << "\nBan da nhap sai lua chon. Vui long nhap lai!";
                break;
            }
        }
        cout << "\nDo you wanna continue?(y/n)";
        answer = getche();
    }
    cout << "\nSee you again!";
    return 0;
}


/******************************************************************************
* Functions
******************************************************************************/
void init(PDoubleLinkedList &list)
{
    list = new DoubleLinkedList;
    list->H = NULL;
    list->T = NULL;
}

bool isEmpty(const PDoubleLinkedList &list)
{
    return list->H == NULL;
}

PDNode create_node(int x)
{
    PDNode Q = new DNode;
    Q->data = x;
    Q->nextL = NULL;
    Q->nextR = NULL;
    return Q;
}

PDNode Search_Node(const PDoubleLinkedList &list, int x)
{
    PDNode P = list->H;
    while (P != NULL)
    {
        if (P->data == x)
        {
            return P;
        }
        else
        {
            P = P->nextR;
        }
    }
    return NULL;
}

void Insert_Begin(PDoubleLinkedList &list, int k)
{
    PDNode Q = create_node(k);
    if (isEmpty(list))
    {
        list->H = Q;
        list->T = Q;
    }
    else
    {
        Q->nextR = list->H;
        list->H->nextL = Q;
        list->H = Q;
    }
}
void InSert_End(PDoubleLinkedList &list, int k)
{
    PDNode Q = create_node(k);
    if (isEmpty(list))
    {
        list->H = Q;
        list->T = Q;
    }
    else
    {
        Q->nextL = list->T;
        list->T->nextR = Q;
        list->T = Q;
    }
}
void Insert_After(PDoubleLinkedList &list, PDNode P, int k)
{
    PDNode Q = create_node(k);
    if (isEmpty(list))
    {
        list->H = Q;
        list->T = Q;
    }
    else
    {
        if (P == NULL)
        {
            return;
        }
        Q->nextL = P;
        Q->nextR = P->nextR;
        if (P->nextR != NULL)
        {
            P->nextR->nextL = Q;
        }
        P->nextR = Q;
        if (list->T == P)
        {
            list->T = Q;
        }
    }
}

void Insert_Before(PDoubleLinkedList &list, PDNode P, int k)
{
    PDNode Q = create_node(k);
    if (isEmpty(list))
    {
        list->H = Q;
        list->T = Q;
    }
    else
    {
        if (P == NULL)
        {
            return;
        }
        Q->data = k;
        Q->nextL = P->nextL;
        Q->nextR = P;
        P->nextL = Q;
        
        if (list->H == P)
        {
            list->H = Q;
        }
        else
        {
            if (Q->nextL != NULL)
            {
                Q->nextL->nextR = Q;
            }
        }
    }
}


void Delete_Begin(PDoubleLinkedList &list, bool &flag)
{
    flag = false;
    if (isEmpty(list))
    {
        cout << "\nEmpty list!";
    }
    else
    {
        PDNode P = list->H;
        list->H = P->nextR;
        if (list->H != NULL)
        {
            list->H->nextL = NULL;
        }
        delete P;
        flag = true;
    }
}

void Delete_WithValue(PDoubleLinkedList &list, int k)
{
    if (isEmpty(list))
    {
        cout << "\nEmpty list!";
        return;
    }
    else
    {
        PDNode current = list->H;

        while (current != NULL)
        {
            if (current->data == k)
            {
                if (current->nextL == NULL)
                {
                    // Xóa phần tử đầu tiên có giá trị k
                    PDNode temp = current;
                    current = current->nextR;
                    if (current != NULL)
                    {
                        current->nextL = NULL;
                    }
                    delete temp;
                }
                else
                {
                    // Xóa phần tử có giá trị k khỏi danh sách
                    current->nextL->nextR = current->nextR;
                    if (current->nextR != NULL)
                    {
                        current->nextR->nextL = current->nextL;
                    }
                    delete current;
                    current = current->nextL;
                }
            }
            else
            {
                current = current->nextR;
            }
        }
    }
}

float Average(const PDoubleLinkedList &list)
{
    float sum = 0;
    int count = 0;
    PDNode P = list->H;
    while (P != NULL)
    {
        sum += P->data;
        count++;
        P = P->nextR;
    }

    if (count == 0)
    {
        // To avoid division by zero if the list is empty
        return 0.0;
    }

    return (sum / count);
}

void Display(const PDoubleLinkedList &list)
{
    if (isEmpty(list))
    {
        cout << "\nList is empty";
    }
    else
    {
        PDNode P = list->H;
        while (P != NULL)
        {
            cout << P->data << " ";
            P = P->nextR;
        }
    }
}

int List_Length(const PDoubleLinkedList &list)
{
    int length = 0;
    PDNode P = list->H;
    while (P != NULL)
    {
        length++;
        P = P->nextR;
    }
    return length;
}

void sort_up(PDoubleLinkedList &list, bool &flag)
{
    flag = false;
    if (isEmpty(list))
    {
        cout << "\nEmpty list!";
    }
    else
    {
        PDNode current, index;
        int temp;

        for (current = list->H; current != NULL; current = current->nextR)
        {
            for (index = current->nextR; index != NULL; index = index->nextR)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
        flag = true;
    }
}

void sort_down(PDoubleLinkedList &list, bool &flag)
{
    flag = false;
    if (isEmpty(list))
    {
        cout << "\nEmpty list!";
    }
    else
    {
        PDNode current, index;
        int temp;

        for (current = list->H; current != NULL; current = current->nextR)
        {
            for (index = current->nextR; index != NULL; index = index->nextR)
            {
                if (current->data < index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
        flag = true;
    }
}
void menu()
{
    printf("\n\t\t DOUBLE LINKED LIST  PROGRAM\n\n");
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

/******************************************************************************
* End of file
******************************************************************************/