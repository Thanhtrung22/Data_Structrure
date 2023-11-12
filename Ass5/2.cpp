/******************************************************************************
* Includes 
******************************************************************************/
#include <iostream>
#include <conio.h>
using namespace std;

/******************************************************************************
* Definitions
******************************************************************************/
struct Hoc_Phan
{
    string maHP;
    string tenHP;
    int soTinChi;
    float trong_So_QT;
    float trong_So_CK;

};
struct Node_HP
{
    Hoc_Phan data_HP;
    float diemQT, diemCK;
    Node_HP* next;
};
typedef struct Node_HP* DSHP;

struct Sinh_Vien
{
    long mssv;
    string name;
    string Class;
    DSHP list_HP;
};
struct Node_SV
{
    Sinh_Vien data_SV;
    Node_SV* next;
};
typedef struct Node_SV* DSSV;
typedef struct Node_SV* PNode_SV;

/******************************************************************************
* Prototypes
******************************************************************************/
// Các hàm khởi tạo và kiểm tra trống
void init_SV(DSSV& H);
void init_HP(DSHP& list);
bool isEmpty_HP(DSHP list);
bool isEmpty(DSSV H);

// Các hàm tạo node và tìm kiếm
PNode_SV creat_node_SV(Sinh_Vien person);
PNode_SV Search_Student(DSSV H, int id_search);
Node_HP* Search_course(PNode_SV student, string code_HP);
Node_HP* creat_node_HP(Hoc_Phan course);

// Các hàm thêm sinh viên và môn học
void Insert_Begin_SV(DSSV& H, Sinh_Vien person);
void Insert_Before_SV(DSSV& H, PNode_SV node, Sinh_Vien person);
void Insert_End_SV(DSSV& H, Sinh_Vien person);
void Add_Course_For_Student(PNode_SV student, Hoc_Phan course);
void enter_data_SV(DSSV& H);

// Các hàm hiển thị danh sách sinh viên và môn học
void display_list_SV(DSSV H);
void display_course_details_for_student(PNode_SV studentNode);
void display_Infor_One_student(PNode_SV student);
// Các hàm nhập thông tin
void enter_one_person(Sinh_Vien* person, DSSV H);
void enter_one_course(PNode_SV student, Hoc_Phan* course);

// hàm thêm môn học sau một môn khác
void Add_Course_After_For_Student(PNode_SV student, string targetCourseCode, Hoc_Phan course);

// Các hàm tính điểm trung bình và hiển thị điểm trung bình
float calculate_CPA(PNode_SV student);
void calculate_CPA_for_all_students(DSSV H);

// Menu chương trình
void menu();


/******************************************************************************
* Code
******************************************************************************/
int main()

{
     DSSV H;
    char answer = '\0';
    int select = 0;
    init_SV(H);
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
                    printf("\nList of student is empty");
                }
                else
                {
                    printf("\nList of student is not empty");
                }
                break;
            }
            case 2:
            {
                enter_data_SV(H);
                break;
            }
            case 3:
            {
                printf("\nList of student: \n");
                display_list_SV(H);
                break;
            }
            case 4:
            {
            	Sinh_Vien person;
                PNode_SV P = NULL;
                printf("\nNhap thong tin sinh vien muon them:\n");
                enter_one_person(&person, H);
                Insert_Begin_SV(H, person);
                printf("\nAdd list successfully");
                break;
                
            }
            case 5:
            {
                Sinh_Vien person;
                int id_person = 0;
                PNode_SV P = NULL;
                printf("\nNhap thong tin sinh vien muon them:\n");
                enter_one_person(&person, H);
                
                
                if(isEmpty(H))
                {
                    Insert_Before_SV(H, P, person);
                    printf("\nList is empty.Student %s is added to the list", person.name.c_str());
                }
                else
                {
                    printf("\nNhap id sinh vien trong list: ");
                    scanf("%d", &id_person);
                    P = Search_Student(H, id_person);
                    if(P != NULL)
                    {
                        Insert_Before_SV(H, P, person);
                        printf("\nAdd student before id %d successfully", id_person);
                    }
                    else
                    {
                        printf("\nNot find student has id %d in list", id_person);
                    }
                }
                
                break;
            }
            case 6:
            {
                Hoc_Phan course;
                int id_person;
                PNode_SV student = NULL;
                printf("Nhap ma so sinh vien muon them mon hoc: ");
                scanf("%d", &id_person);
                student = Search_Student(H, id_person);
                if(student !=  NULL)
                {
                    display_Infor_One_student(student);
                    printf("\nNhap thong tin mon hoc muon them: \n");
                    enter_one_course(student, &course);
                    Add_Course_For_Student(student, course);
                    printf("\nAdd course for student successfully");

                }
                else
                {
                    printf("\nKhong tim thay sinh vien co ma %d trong list", id_person);
                }
                break;
            }
            case 7:
            {
                Hoc_Phan course;
                int id_person;
                PNode_SV student = NULL;
                printf("Nhap ma so sinh vien muon them mon hoc: ");
                scanf("%d", &id_person);
                student = Search_Student(H, id_person);
                if(student !=  NULL)
                {
                    display_Infor_One_student(student);
                    string ma_HP;
                    Node_HP* temp = NULL;
                    printf("\nNhap ma hoc phan trong list: ");
                    cin >> ma_HP;
                    temp = Search_course(student, ma_HP);
                    if(temp != NULL)
                    {
                        
                        printf("Nhap thong tin mon hoc muon them: \n");
                        enter_one_course(student, &course);
                        Add_Course_After_For_Student(student, ma_HP, course);
                    }
                    else
                    {
                        if(isEmpty_HP(student->data_SV.list_HP))
                        {
                            printf("\nList mon hoc rong. Mon hoc moi se duoc them");
                            printf("\nNhap thong tin mon hoc muon them: \n");
                            enter_one_course(student, &course);
                            Add_Course_After_For_Student(student, ma_HP, course);
                            printf("Mon %s  duoc them vao", course.tenHP.c_str());
                        }
                        else
                        {
                            printf("\nKhong tim thay mon hoc trong list");
                        }
                        
                    }

                }
                else
                {
                    printf("\nKhong tim thay sinh vien co ma %d trong list", id_person);
                }
                break;
            }
            case 8:
            {
                if(isEmpty(H))
                {
                    printf("\nEmpty list");
                }
                else
                {
                    int id_person = 0;
                    PNode_SV node = NULL;
                    printf("\nNhap vao id muon tim: ");
                    scanf("%d", &id_person);
                    node = Search_Student(H, id_person);
                    if(node != NULL)
                    {
                        display_Infor_One_student(node);
                    }
                    else
                    {
                        printf("\nNot finding %d in list", id_person);
                    }
                }
                
                break;
            }
            case 9:
            {
                if(isEmpty(H))
                {
                    printf("\nList of students is empty");
                }
                else
                {
                    int id_student;
                    PNode_SV student = NULL;
                    printf("Nhap ma so sinh vien can xem: ");
                    cin >> id_student;
                    student = Search_Student(H, id_student);
                    if (student != NULL)
                    {
                        float cpa = calculate_CPA(student);
                        printf("\nCPA for student with ID %d: %.2f", student->data_SV.mssv, cpa);
                    }
                    else
                    {
                        printf("\nKhong tim thay sinh vien co ma %d", id_student);
                    }
                }
                

                break;
            }
            case 10:
            {
                calculate_CPA_for_all_students(H);
                break;
            }
            case 11:
            {
                if(isEmpty(H))
                {
                    printf("\nEmpty list");
                }
                else
                {
                    int id_student;
                    PNode_SV student = NULL;
                    printf("Nhap ma so sinh vien can xem: ");
                    cin >> id_student;
                    student = Search_Student(H, id_student);
                    if(student != NULL)
                    {
                        if(isEmpty_HP(student->data_SV.list_HP))
                        {
                            printf("\nSinh vien khong co mon hoc nao");
                        }
                        else
                        {
                            display_Infor_One_student(student);
                            printf("\n");
                            display_course_details_for_student(student);
                        }
                    }
                    else
                    {
                        printf("\nKhong tim thay sinh vien co ma %d", id_student);
                    }
                }
                
                
                 
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
        printf("\nDo you wanna continue the program?(y/n)");
        fflush(stdin);
        answer = getche();

    }
    printf("\nSee you again!");
    return 0;
}


/******************************************************************************
* Functions
******************************************************************************/
void init_SV(DSSV &H)
{
    H = NULL;
   
}
void init_HP(DSHP &list)
{
    list = NULL;
}
bool isEmpty_HP(DSHP list)
{
    return list == NULL;
}
bool isEmpty(DSSV H)
{
    return H == NULL;
}

PNode_SV creat_node_SV(Sinh_Vien person)
{
    PNode_SV new_node = new Node_SV;
    new_node->data_SV = person;
    new_node->data_SV.list_HP = NULL;
    new_node->next = NULL;
    return new_node;
}
PNode_SV Search_Student(DSSV H, int id_search)
{
    PNode_SV node = NULL;
    node = H;
    while(node != NULL)
    {
        if(node->data_SV.mssv == id_search)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
Node_HP* Search_course(PNode_SV student, string code_HP)
{
    Node_HP* node = NULL;
    node = student->data_SV.list_HP;
    while(node != NULL)
    {
        if(node->data_HP.maHP == code_HP)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}
Node_HP* creat_node_HP(Hoc_Phan course)
{
    Node_HP* node = new Node_HP;
    
    printf("Nhap diem qua  trinh hoc phan %s: ", course.tenHP.c_str());
    scanf("%f", &node->diemQT);
    printf("Nhap diem cuoi ki hoc phan %s: ", course.tenHP.c_str());
    scanf("%f", &node->diemCK);
    node->data_HP = course;
    node->next = NULL;
    return node;
}
void Insert_Begin_SV(DSSV &H, Sinh_Vien person)
{
    PNode_SV node = creat_node_SV(person);
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

void Insert_Before_SV(DSSV &H, PNode_SV node, Sinh_Vien person)
{
    PNode_SV Q = creat_node_SV(person);
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
        Q->data_SV = node->data_SV;
        node->data_SV = person;
        Q->next = node->next;
        node->next = Q;
    }
}

void Insert_End_SV(DSSV &H, Sinh_Vien person)
{
    PNode_SV node = creat_node_SV(person);
    if(isEmpty(H))
    {
        H = node;
    }
    else
    {
        PNode_SV temp = H;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}
void Add_Course_For_Student(PNode_SV student, Hoc_Phan course)
{
    DSHP courseList = student->data_SV.list_HP;
    Node_HP *newCourseNode = creat_node_HP(course);

    if (isEmpty_HP(courseList))
    {
        student->data_SV.list_HP = newCourseNode;
    }
    else
    {
        Node_HP *lastCourseNode = courseList;
        while (lastCourseNode->next != NULL)
        {
            lastCourseNode = lastCourseNode->next;
        }

        lastCourseNode->next = newCourseNode;
    }
}
void enter_data_SV(DSSV &H)
{
    Sinh_Vien person;
    int i = 1;
    while(1)
    {
        printf("\nNhap sinh vien thu %d: ", i++);
        person.list_HP = NULL;
        printf("\nNhap ten: ");
        fflush(stdin);
        getline(cin, person.name);
        // Kết thúc khi nhập tên rỗng
        if(person.name.length() == 0)
        {
            break;
        }
        printf("\nNhap ma so: ");
        scanf("%d", &person.mssv);
        while(Search_Student(H, person.mssv) != NULL)
        {
            printf("\nBan da nhap giong id voi sinh vien khac.Vui long nhap lai: ");
            scanf("%d", &person.mssv);
        }
        printf("\nNhap lop: ");
        cin.ignore();
        getline(cin, person.Class);
        Insert_End_SV(H, person);

    }
}


void display_list_SV(DSSV H)
{
    if(isEmpty(H))
    {
        printf("\nEmpty list!");
        return;

    }
    PNode_SV node = H;
    int i = 1;
    printf("%-5s %-30s %-15s %-15s\n", "STT", "Ho Ten", "Ma so", "Lop");
    while(node != NULL)
    {
        printf("%-5d %-30s %-15d %-15s\n", i++, node->data_SV.name.c_str(), node->data_SV.mssv, node->data_SV.Class.c_str());
        node = node->next;
    }
}

void enter_one_person(Sinh_Vien *person, DSSV H)
{
        printf("\nNhap ten: ");
        fflush(stdin);
        getline(cin, person->name);
        printf("Nhap ma so: ");
        scanf("%d", &person->mssv);
        while(Search_Student(H, person->mssv) != NULL)
        {
            printf("\nBan da nhap giong id voi sinh vien khac.Vui long nhap lai: ");
            scanf("%d", &person->mssv);
        }
        printf("Nhap lop: ");
        cin.ignore();
        getline(cin, person->Class);
        
}
void enter_one_course(PNode_SV student, Hoc_Phan *course)
{
    printf("Nhap ten hoc phan: ");
   fflush(stdin);
    getline(cin, course->tenHP);

    printf("Nhap ma hoc phan: ");
    getline(cin, course->maHP);

    // Kiểm tra mã số học phần đã tồn tại hay chưa
    while (Search_course(student, course->maHP) != NULL)
    {
        printf("\nBan da nhap giong id voi hoc phan khac. Vui long nhap lai: ");
        getline(cin, course->maHP);
    }

    printf("Nhap so tin chi hoc phan: ");
    cin >> course->soTinChi;
    printf("Nhap trong so qua trinh: ");
    cin >> course->trong_So_QT;
    printf("Nhap trong so cuoi ki: ");
    cin >> course->trong_So_CK;
}


void display_course_details_for_student(PNode_SV studentNode)
{
    printf("Thong tin chi tiet ve danh sach hoc phan cua sinh vien co MSSV %d:\n", studentNode->data_SV.mssv);
    
    DSHP courseList = studentNode->data_SV.list_HP;
    Node_HP *currentCourseNode = courseList;

    printf("%-15s %-20s %-12s %-15s %-20s %-10s %-10s\n", "Ma HP", "Ten HP", "So tin chi", "Trong So QT", "Trong So Cuoi Ki", "Diem QT", "Diem CK");

    while (currentCourseNode != NULL)
    {
        printf("%-15s %-20s %-12d %-15.2f %-20.2f %-10.2f %-10.2f\n",
               currentCourseNode->data_HP.maHP.c_str(),
               currentCourseNode->data_HP.tenHP.c_str(),
               currentCourseNode->data_HP.soTinChi,
               currentCourseNode->data_HP.trong_So_QT,
               currentCourseNode->data_HP.trong_So_CK,
               currentCourseNode->diemQT,
               currentCourseNode->diemCK);

        currentCourseNode = currentCourseNode->next;
    }
}
void Add_Course_After_For_Student(PNode_SV student, string targetCourseCode, Hoc_Phan course)
{
    DSHP courseList = student->data_SV.list_HP;
    Node_HP *newCourseNode = creat_node_HP(course);
    if(isEmpty_HP(courseList))
    {
        student->data_SV.list_HP = newCourseNode;
    }
    else
    {
        Node_HP *currentCourseNode = courseList;
        while (currentCourseNode != NULL && currentCourseNode->data_HP.maHP != targetCourseCode)
        {
            currentCourseNode = currentCourseNode->next;
        }

        if (currentCourseNode != NULL)
        {
            newCourseNode->next = currentCourseNode->next;
            currentCourseNode->next = newCourseNode;
            printf("\nAdd course for student successfully");
        }
        else
        {
            cout << "Khong tim thay hoc phan co ma so: " << targetCourseCode << endl;
            delete newCourseNode;
        } 
    }
    
}

void display_Infor_One_student(PNode_SV student)
{
    printf("Information of student has id %d: \n\n", student->data_SV.mssv);
    printf("%-20s %-10s %-10s\n", "Ho Ten", "Ma so", "Lop");
    printf("%-20s %-10d %-10s\n", student->data_SV.name.c_str(), student->data_SV.mssv, student->data_SV.Class.c_str());
}
void menu()
{
    printf("\n\t\t STUDENT MANAGEMENT WITH LINKED LIST\n\n");
    printf("----------------------------------------------------------------\n");
    printf("1.Check list empty\n");
    printf("2.Enter information list of students\n");
    printf("3.Display list\n");
    printf("4.Add student at begin\n");
    printf("5.Add student before another student\n");
    printf("6.Add course for student\n");
    printf("7.Add course before another course\n");
    printf("8.Search information of student\n");
    printf("9.CPA Grade for one student\n");
    printf("10.CPA Grade for all student\n");
    printf("11.Display detail of information for one student\n");
    printf("12.Exit the program\n");
}

float calculate_CPA(PNode_SV student)
{
    DSHP courseList = student->data_SV.list_HP;
    Node_HP *currentCourseNode = courseList;

    float tong_so_tin = 0.0;
    float total_point = 0.0;

    while (currentCourseNode != NULL)
    {
        float So_Tin = currentCourseNode->data_HP.soTinChi;
        float courseGrade = (currentCourseNode->diemQT * currentCourseNode->data_HP.trong_So_QT +
                             currentCourseNode->diemCK * currentCourseNode->data_HP.trong_So_CK);

        // Chuyển đổi điểm từ thang điểm 10 sang thang điểm 4
        float convertedGrade = 0.0;
        if (courseGrade >= 8.5)
        {
            convertedGrade = 4.0;
        }
        else if (courseGrade >= 8.0)
        {
            convertedGrade = 3.5;
        }
        else if (courseGrade >= 7.0)
        {
            convertedGrade = 3.0;
        }
        else if (courseGrade >= 6.5)
        {
            convertedGrade = 2.5;
        }
        else if(courseGrade >= 5.5)
        {
            convertedGrade = 2.0;
        }
        else if(courseGrade >= 5.0)
        {
            convertedGrade = 1.5;
        }
        else if(courseGrade >= 4.0)
        {
            convertedGrade = 1.0;
        }

        tong_so_tin += So_Tin;
        total_point += So_Tin * convertedGrade;

        currentCourseNode = currentCourseNode->next;
    }

    if (tong_so_tin > 0)
    {
        float cpa = total_point / tong_so_tin;
        return cpa;
    }
    else
    {
        return 0.0; // Tránh chia cho 0
    }
}

void calculate_CPA_for_all_students(DSSV H)
{
    if (isEmpty(H))
    {
        printf("\nEmpty list of students");
        return;
    }

    PNode_SV currentStudentNode = H;

    while (currentStudentNode != NULL)
    {
        if(isEmpty_HP(currentStudentNode->data_SV.list_HP))
        {
            printf("\nSinh vien %s voi id %d khong co mon hoc nao", currentStudentNode->data_SV.name.c_str(),currentStudentNode->data_SV.mssv);
        }
        else
        {
            float cpa = calculate_CPA(currentStudentNode);
            display_Infor_One_student(currentStudentNode);
            printf("CPA cua sinh vien %s la: %.2f\n\n", currentStudentNode->data_SV.name.c_str(), cpa);
        }
        

        currentStudentNode = currentStudentNode->next;
    }
}

/******************************************************************************
* End of file
******************************************************************************/