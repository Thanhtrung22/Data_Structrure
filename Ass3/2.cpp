/******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
/******************************************************************************
* Definitions
******************************************************************************/
typedef struct
{
    int id;
    string name;
    string Class;
    float point_average;
}Student;

struct Node
{
    Student data;
    Node *next;
};
typedef struct Node* LinkedList;
typedef struct Node* PNode;

/******************************************************************************
* Prototypes
******************************************************************************/
void init(LinkedList &H);
bool isEmpty(LinkedList H);
void Insert_Begin(LinkedList &H, Student person);
void Insert_After(LinkedList &H, PNode node,Student person);
void Insert_Before(LinkedList &H, PNode node,Student person);
PNode Search_Student(LinkedList H, int id_search);
void Delete_Student(LinkedList &H, PNode node);
float Point_Average_All_Student(LinkedList H);
void Sort_up(LinkedList &H);
PNode creat_node(Student person);
void display_list(LinkedList H);
void enter_data(LinkedList &H);
void menu();
void enter_one_person(Student *person, LinkedList H);
/******************************************************************************
* Code
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
                enter_data(H);
                break;
            }
            case 3:
            {
                printf("\nList of student: \n");
                display_list(H);
                break;
            }
            case 4:
            {
            	Student person;
                PNode P = NULL;
                printf("\nNhap thong tin sinh vien muon them:\n");
                enter_one_person(&person, H);
                Insert_Begin(H, person);
                printf("\nAdd list successfully");
                break;
                
            }
            case 5:
            {
                Student person;
                int id_person = 0;
                PNode P = NULL;
                printf("\nNhap thong tin sinh vien muon them:\n");
                enter_one_person(&person, H);
                printf("\nNhap id sinh vien trong list: ");
                scanf("%d", &id_person);
                
                if(isEmpty(H))
                {
                    Insert_Before(H, P, person);
                    printf("\n List is empty.Student %s is added to the list", person.name.c_str());
                }
                
                P = Search_Student(H, person.id);
                if(P != NULL)
                {
                    Insert_Before(H, P, person);
                    printf("\nAdd student before id %d successfully", id_person);
                }
                else
                {
                    printf("\nNot find student has id %d in list", id_person);
                }
                break;
            }
            case 6:
            {
                Student person;
                int id_person = 0;
                PNode P = NULL;
                printf("\nNhap thong tin sinh vien muon them:\n");
                enter_one_person(&person, H);
                printf("\nNhap id sinh vien trong list: ");
                scanf("%d", &id_person);
                
                if(isEmpty(H))
                {
                    Insert_After(H, P, person);
                    printf("\n List is empty.Student %s is added to the list", person.name.c_str());
                }
                
                P = Search_Student(H, person.id);
                if(P != NULL)
                {
                    Insert_After(H, P, person);
                    printf("\nAdd student after id %d successfully", id_person);
                }
                else
                {
                    printf("\nNot find student has id %d in list", id_person);
                }
                break;
            }
            case 7:
            {
                int id_person = 0;
                PNode node = NULL;
                printf("\nNhap vao id muon xoa: ");
                scanf("%d", &id_person);
                node = Search_Student(H, id_person);
                if(node != NULL)
                {
                    Delete_Student(H, node);
                    printf("\nDelete student successfully");
                }
            
                else
                {
                    printf("\nNot finding %d in list", id_person);
                }
                break;
            }
            case 8:
            {
                int id_person = 0;
                PNode node = NULL;
                printf("\nNhap vao id muon xoa: ");
                scanf("%d", &id_person);
                node = Search_Student(H, id_person);
                if(node != NULL)
                {
                    printf("Information of student has id %d: \n", id_person);
                    display_list(node);
                }
                else
                {
                    printf("\nNot finding %d in list", id_person);
                }
                break;
            }
            case 9:
            {
                float avr = 0;
                if(!isEmpty(H))
                {
                    avr = Point_Average_All_Student(H);
                    printf("\nAverage of list is: %.2f", avr);
                }
                else
                {
                    printf("\nList is empty");
                }
                
                break;
            }
            case 10:
            {
                
                
                break;
            }
            case 11:
            {
                
                break;
            }
            case 12:
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
}

/******************************************************************************
* Functions
******************************************************************************/
void menu()
{
    printf("\n\t\t STUDENT MANAGERMENT WITH LINKED LIST\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Check list empty\n");
    printf("2.Enter information list of students: \n");
    printf("3.Display list\n");
    printf("4.Add student at begin\n");
    printf("5.Add student before another student\n");
    printf("6.Add student after another student\n");
    printf("7.Delete student\n");
    printf("8.Search information of student\n");
    printf("9.Point average of all students in list\n");
    printf("10.Sort up list via point average\n");
    printf("11.Edit information of student\n");
    printf("12.Exit\n");
}

void enter_one_person(Student *person, LinkedList H)
{
        printf("\nNhap ten: ");
        cin.ignore();
        getline(cin, person->name);
        printf("Nhap ma so: ");
        scanf("%d", &person->id);
        while(Search_Student(H, person->id) != NULL)
        {
            printf("\nBan da nhap giong id voi sinh vien khac.Vui long nhap lai!");
            scanf("%d", &person->id);
        }
        printf("\nNhap lop: ");
        cin.ignore();
        getline(cin, person->Class);
        printf("Nhap diem trung binh: ");
        scanf("%f", &person->point_average);
}

void init(LinkedList &H)
{
    H = NULL;
}

bool isEmpty(LinkedList H)
{
    return H == NULL;
}

PNode creat_node(Student person)
{
    PNode node = NULL;
    node = new Node;
    node->data = person;
    node->next = NULL;
    return node;
}
void Insert_Begin(LinkedList &H, Student person)
{
    PNode node = creat_node(person);
    if(isEmpty(H))
    {
        H = node;
    }
    else
    {
        node->next = H;
        H = node;
    }
}

PNode Search_Student(LinkedList H, int id_search)
{
    PNode node = NULL;
    node = H;
    while(node != NULL)
    {
        if(node->data.id == id_search)
        {
            return node;
        }
    }
    return NULL;
}

void Insert_After(LinkedList &H, PNode node, Student person)
{
    PNode Q = creat_node(person);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        if(node == NULL)
        {
            return;
        } 
        Q->next = node->next;
        node->next = Q;
    }
}

void Insert_Before(LinkedList &H, PNode node, Student person)
{
    PNode Q = creat_node(person);
    if(isEmpty(H))
    {
        H = Q;
    }
    else
    {
        if(node == NULL)
        {
            return;
        } 
        Q->data = node->data;
        node->data = person;
        Q->next = node->next;
        node->next = Q;
    }
}

void Delete_Student(LinkedList &H, PNode node)
{
    if(isEmpty(H))
    {
        printf("\nList is empty");
        return;
    }
    if(H == node && node->next == NULL)
    {
        H = NULL;
        delete node;
    }
    else
    {
        if(H == node)
        {
            H = H->next;
            delete node;
        }
        else
        {
            PNode temp = H;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp = node->next;
            delete node;
        }
    }
}

float Point_Average_All_Student(LinkedList H)
{
    int count = 0;
    float sum = 0, avr = 0;
    PNode node = H;
    while(node != NULL)
    {
        sum += node->data.point_average;
        count++;
    }
    if(count > 0)
    {
        avr = sum / count;
    }
    return avr;
}

void display_list(LinkedList H)
{
    if(isEmpty(H))
    {
        printf("\nEmpty list!");
        return;
    }
    PNode node = H;
    int i = 1;
    printf("%-5s %-20s %-10s %-8s %-8s\n", "STT", "Ho Ten", "Ma so", "Lop", "Diem TB");
    while(node != NULL)
    {
        printf("%-5d %-20s %-10s %-10s %-8.2f\n", i++, node->data.name.c_str(), node->data.id, node->data.Class, node->data.point_average);
        node = node->next;
    }
}

void enter_data(LinkedList &H)
{
    Student person;
    int i = 1;
    while(1)
    {
        printf("\nNhap sinh vien thu %d: ", i++);
        printf("\nNhap ten: ");
        cin.ignore();
        getline(cin, person.name);
        // Kết thúc khi nhập tên rỗng
        if(person.name.length() == 0)
        {
            break;
        }
        printf("Nhap ma so: ");
        scanf("%d", &person.id);
        while(Search_Student(H, person.id) != NULL)
        {
            printf("\nBan da nhap giong id voi sinh vien khac.Vui long nhap lai!");
            scanf("%d", &person.id);
        }
        printf("\nNhap lop: ");
        cin.ignore();
        getline(cin, person.Class);
        printf("Nhap diem trung binh: ");
        scanf("%f", &person.point_average);
        Insert_Begin(H, person);

    }
}

