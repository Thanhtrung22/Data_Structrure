/******************************************************************************
* Includes 
******************************************************************************/
#include <iostream>
#include <conio.h>
using namespace std;

/******************************************************************************
* Definitions
******************************************************************************/
struct Student {
    int studentID;
    string fullName;
    string className;
    float GPA;
    Student* left;
    Student* right;
};

typedef Student* StudentTree;

/******************************************************************************
* Prototypes
******************************************************************************/
void initializeTree(StudentTree& root);
bool isEmpty(StudentTree root);
Student* createStudent(int studentID, string fullName, string className, float GPA);
void insertStudent(StudentTree& root, Student* student);
Student* findStudent(StudentTree root, int studentID);
Student* findMaxGPAStudent(StudentTree root);
float calculateTotalGPA(StudentTree root);
int countStudents(StudentTree root);
float calculateAverageGPA(StudentTree root);
void displayStudentInfo(Student* student);
void displayAllStudents(StudentTree root);
void deleteNode(StudentTree& node);
bool deleteStudent(StudentTree& root, int studentID);
void menu();

/******************************************************************************
* Code
******************************************************************************/
int main() {
    setlocale(LC_ALL, "Vietnamese"); // Đặt locale cho UTF-8 để hỗ trợ ký tự không dấu

    StudentTree myStudentTree;
    initializeTree(myStudentTree);

    int choice, studentID;
    char answer = '\0';

    while (answer != 'n') {
        system("cls");
        menu();
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 0:
            {
                if(isEmpty(myStudentTree))
                {
                    printf("\nList of students is empty");
                }
                else
                {
                    printf("\nList of students is not empty");
                }
                break;
            }
            case 1: {
                int newStudentID;
                string newFullName, newClassName;
                float newGPA;

                cout << "Nhap ma so sinh vien: ";
                cin >> newStudentID;
                cout << "Nhap ho ten: ";
                cin.ignore(); // Clear newline character from the buffer
                getline(cin, newFullName);
                cout << "Nhap lop: ";
                getline(cin, newClassName);
                cout << "Nhap diem trung binh: ";
                cin >> newGPA;

                Student* newStudent = createStudent(newStudentID, newFullName, newClassName, newGPA);
                insertStudent(myStudentTree, newStudent);

                break;
            }
            case 2: {
                cout << "Nhap ma so sinh vien muon xoa: ";
                cin >> studentID;

                if (deleteStudent(myStudentTree, studentID)) {
                    cout << "Da xoa sinh vien co ma so " << studentID << " khoi danh sach.\n";
                } else {
                    cout << "Khong tim thay sinh vien co ma so " << studentID << ".\n";
                }

                break;
            }
            case 3: {
                cout << "Nhap ma so sinh vien muon tim kiem: ";
                cin >> studentID;

                Student* foundStudent = findStudent(myStudentTree, studentID);

                if (foundStudent != nullptr) {
                    cout << "Tim thay sinh vien:\n";
                    printf("%-20s %-10s %-10s %-8s\n","Ho Ten", "Ma so", "Lop", "Diem TB");
                    displayStudentInfo(foundStudent);
                } else {
                    cout << "Khong tim thay sinh vien co ma so " << studentID << ".\n";
                }

                break;
            }
            case 4: {
                Student* maxGPAStudent = findMaxGPAStudent(myStudentTree);

                if (maxGPAStudent != nullptr) {
                    cout << "Sinh vien co diem trung binh cao nhat la:\n";
                    printf("%-20s %-10s %-10s %-8s\n","Ho Ten", "Ma so", "Lop", "Diem TB");
                    displayStudentInfo(maxGPAStudent);
                } else {
                    cout << "Danh sach sinh vien rong.\n";
                }

                break;
            }
            case 5: {
                float averageGPA = calculateAverageGPA(myStudentTree);

                if (averageGPA != 0.0) {
                    cout << "Diem trung binh cua toan bo sinh vien la: " << averageGPA << endl;
                } else {
                    cout << "Danh sach sinh vien rong.\n";
                }

                break;
            }
            case 6: {
                if (myStudentTree == nullptr) {
                    cout << "Danh sach sinh vien rong.\n";
                } else {
                    cout << "Thong tin cua tat ca sinh vien:\n";
                    printf("%-20s %-10s %-10s %-8s\n","Ho Ten", "Ma so", "Lop", "Diem TB");
                    displayAllStudents(myStudentTree);
                }

                break;
            }
            case 7: {
                cout << "\nHen gap lai!";
                return 0;
            }
            default: {
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
                break;
            }
        }

        cout << "\nBan co muon tiep tuc khong?(y/n)";
        answer = getche();
    }

    cout << "\nHen gap lai!";
    return 0;
}

/******************************************************************************
* Functions
******************************************************************************/
void initializeTree(StudentTree& root) {
    root = nullptr;
}
bool isEmpty(StudentTree root)
{
    return root == NULL;
}
Student* createStudent(int studentID, string fullName, string className, float GPA) {
    Student* newStudent = new Student;
    newStudent->studentID = studentID;
    newStudent->fullName = fullName;
    newStudent->className = className;
    newStudent->GPA = GPA;
    newStudent->left = nullptr;
    newStudent->right = nullptr;
    return newStudent;
}

void insertStudent(StudentTree& root, Student* student) {
    if (root == nullptr) {
        root = student;
    } else {
        if (student->studentID < root->studentID) {
            insertStudent(root->left, student);
        } else if (student->studentID > root->studentID) {
            insertStudent(root->right, student);
        } else {
           return;
        }
    }
}

Student* findStudent(StudentTree root, int studentID) {
    if (root == nullptr || root->studentID == studentID) {
        return root;
    }

    if (studentID < root->studentID) {
        return findStudent(root->left, studentID);
    }

    return findStudent(root->right, studentID);
}

Student* findMaxGPAStudent(StudentTree root) {
    if (root == nullptr) {
        return nullptr; // Cây rỗng
    }

    Student* temp = root;
    Student* max = root;

    while (temp->right != nullptr) {
        if(temp->GPA > max->GPA)
        {
            max = temp;
        }
        temp = temp->right;
    }

    return max;
}


float calculateTotalGPA(StudentTree root) {
    if (root == nullptr) {
        return 0.0;
    }

    float totalGPA = root->GPA + calculateTotalGPA(root->left) + calculateTotalGPA(root->right);
    return totalGPA;
}

int countStudents(StudentTree root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countStudents(root->left) + countStudents(root->right);
}

float calculateAverageGPA(StudentTree root) {
    int studentCount = countStudents(root);
    if (studentCount == 0) {
        return 0.0;
    }

    float totalGPA = calculateTotalGPA(root);
    return totalGPA / studentCount;
}


void displayStudentInfo(Student* student) {
    printf("%-20s %-10d %-10s %-8.2f\n",student->fullName.c_str(), student->studentID,
    student->className.c_str(), student->GPA);
}

void displayAllStudents(StudentTree root) {
    
    if (root != nullptr) {
        displayAllStudents(root->left);
        displayStudentInfo(root);
        displayAllStudents(root->right);
    }
}

void deleteNode(StudentTree& node) {
    if (node->left == nullptr) {
        Student* temp = node->right;
        delete node;
        node = temp;
    } else if (node->right == nullptr) {
        Student* temp = node->left;
        delete node;
        node = temp;
    } else {
        Student* temp = findMaxGPAStudent(node->left);
        node->studentID = temp->studentID;
        node->fullName = temp->fullName;
        node->className = temp->className;
        node->GPA = temp->GPA;
        deleteNode(node->left);
    }
}

bool deleteStudent(StudentTree& root, int studentID) {
    if (root == nullptr) {
        return false;
    }

    if (studentID < root->studentID) {
        return deleteStudent(root->left, studentID);
    } else if (studentID > root->studentID) {
        return deleteStudent(root->right, studentID);
    } else {
        deleteNode(root);
        return true;
    }
}


void menu()
{
        cout << "0. Kiem tra rong\n";
        cout << "1. Them sinh vien\n";
        cout << "2. Xoa sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Thong tin sinh vien co diem trung binh cao nhat\n";
        cout << "5. Tinh diem trung binh cua toan bo sinh vien\n";
        cout << "6. Hien thi thong tin cua tat ca sinh vien\n";
        cout << "7. Thoat\n";
}

/******************************************************************************
* End of file
******************************************************************************/