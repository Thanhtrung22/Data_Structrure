/******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
#include <conio.h>
using namespace std;

/******************************************************************************
* Definition
******************************************************************************/
struct Node
{

    int Key; 
    Node * LP, *RP;
};
typedef Node* PNode;
typedef PNode BinaryTree;
typedef BinaryTree BSearchTree;

/******************************************************************************
* Prototypes
******************************************************************************/
void initializeTree(BSearchTree &root);
bool isEmpty(BSearchTree root);
PNode creat_node(int key);
void insertElement(BinaryTree& root, int key);
void DelNode(PNode & P);
bool DeleteT(BSearchTree& Root, int x);
bool searchElement(BinaryTree root, int key);
void displayKeys(BinaryTree root);
int sumKeys(BinaryTree root);
int countNodes(BinaryTree root);
void menu();
void displayKeys1(BinaryTree root);
void displayKeys2(BinaryTree root);
// Hàm khởi tạo cây rỗng


/******************************************************************************
* Code
******************************************************************************/
int main()
{
    BSearchTree myTree;
    int key, choice;
    char answer = '\0';
    initializeTree(myTree);
    while(answer != 'n')
    {
        system("cls");
        menu();
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) 
        {
            case 0:
            {
                if(isEmpty(myTree))
                {
                    printf("\nTree is empty");
                }
                else
                {
                    printf("\nTree is not empty");
                }
                break;
            }
            case 1:
            {
                cout << "Nhap gia tri muon them: ";
                cin >> key;
                insertElement(myTree, key);
                break;
            }
                
            case 2:
            {
                 cout << "Nhap gia tri muon loai bo: ";
                 cin >> key;
                if (DeleteT(myTree, key)) 
                {
                    cout << "Da xoa phan tu " << key << " khoi cay.\n";
                } 
                else 
                {
                    cout << "Khong tim thay phan tu " << key << " trong cay.\n";
                }
                    break;
            }
                
            case 3:
            {
                if (isEmpty(myTree))
                {
                    cout << "Cay rong. Khong co khoa nao de hien thi.\n";
                }
                else
                {
                    cout << "Nhap gia tri muon tim kiem: ";
                    cin >> key;
                    if (searchElement(myTree, key)) 
                    {
                        cout << "Phan tu " << key << " ton tai trong cay.\n";
                    } 
                    else 
                    {
                        cout << "Phan tu " << key << " khong ton tai trong cay.\n";
                    }
                }
                
                break;
            }
                
            case 4:
            {
                if (isEmpty(myTree))
                {
                    cout << "Cay rong. Khong co khoa nao de hien thi.\n";
                }
                else
                {
                    cout << "Cac khoa tren cay: ";
                    displayKeys(myTree);
                    cout << endl;
                }
                break;
            }

            case 5:
            {
                if (isEmpty(myTree))
                {
                    cout << "Cay rong. Khong co khoa nao de tinh tong.\n";
                }
                else
                {
                    cout << "Tong so cac phan tu khoa cua cay: " << sumKeys(myTree) << endl;
                }
                break;
            }

            case 6:
            {
                if (isEmpty(myTree))
                {
                    cout << "Cay rong. Khong co phan tu nao de dem.\n";
                }
                else
                {
                    cout << "So phan tu cua cay: " << countNodes(myTree) << endl;
                }
                break;
            }
                
            case 7:
            {
                cout << "\nSee you again!";
                return 0;
            }
                
            default:
            {
                cout << "Lua chon khong hop le. Vui long thu lai.\n";
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
void initializeTree(BSearchTree &root)
{
    root = NULL;
}
bool isEmpty(BSearchTree root)
{
    return root == NULL;
}
PNode creat_node(int key)
{
    PNode Q = new Node;
    Q->Key = key;
    Q->LP = Q->RP = NULL;
    return Q;
}
// Hàm bổ sung một phần tử vào cây
void insertElement(BinaryTree& root, int key)
{
    PNode Q = creat_node(key);
    if (root == NULL)
    {
        root = Q;
    } else 
    {
        if (key < root->Key) 
        {
            insertElement(root->LP, key);
        } 
        else if (key > root->Key) 
        {
            insertElement(root->RP, key);
        }
        else
        {
            return;
        }
    }
}

void DelNode (PNode & P) 
{ 
    PNode Q, R;
    if (P->LP == NULL) 
    { //Xóa nút chỉ có cây con phải
        Q = P;
        P = P->RP;
    } 
    else if (P->RP == NULL) //Xóa nút chỉ có cây con trái
    {
        Q = P;
        P = P->LP;
    } 
    else 
    { 
        Q = P->LP;
        if (Q->RP == NULL)
        {
            P->Key = Q->Key;
            P->LP = Q->LP;
        } 
        else 
        {
            do 
            {
                R = Q;
                Q = Q->RP;
            }while (Q->RP != NULL);
            P->Key = Q->Key; //Lấy giá trị ở Q đưa lên
            R->RP = Q->LP; //Chuyển con của Q lên vị trí Q
        }
    }
    delete Q; //Xoá Q
}

bool DeleteT(BSearchTree& Root, int x) {
    if (Root == NULL) {
        return false; // Không tìm thấy giá trị cần xóa
    } else if (x < Root->Key) {
        return DeleteT(Root->LP, x);
    } else if (x > Root->Key) {
        return DeleteT(Root->RP, x);
    } else {
        DelNode(Root);
        return true; // Xóa thành công
    }
}

// Hàm tìm kiếm một phần tử trong cây
bool searchElement(BinaryTree root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (key == root->Key) {
        return true;
    } else if (key < root->Key) {
        return searchElement(root->LP, key);
    } else {
        return searchElement(root->RP, key);
    }
}

// Hàm hiển thị các khóa trên cây
void displayKeys(BinaryTree root) {
    if (root != nullptr) {
        displayKeys(root->LP);
        cout << root->Key << " ";
        displayKeys(root->RP);
    }
}
void displayKeys1(BinaryTree root) {
    if (root != nullptr) {
        cout << root->Key << " ";
        displayKeys(root->LP);
        
        displayKeys(root->RP);
    }
}
void displayKeys2(BinaryTree root) {
    if (root != nullptr) {
        
        displayKeys(root->LP);
        
        displayKeys(root->RP);
        cout << root->Key << " ";
    }
}
// Hàm tính tổng số các phần tử khóa của cây
int sumKeys(BinaryTree root) {
    if (root == nullptr) {
        return 0;
    }
    return root->Key + sumKeys(root->LP) + sumKeys(root->RP);
}

// Hàm đếm số phần tử của cây
int countNodes(BinaryTree root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->LP) + countNodes(root->RP);
}

void menu() 
{
    printf("\n0. Kiem tra cay rong");
    printf("\n1. Bo sung mot phan tu");
    printf("\n2. Loai bo mot phan tu");
    printf("\n3. Tim kiem mot phan tu");
    printf("\n4. Hien thi cac khoa tren cay");
    printf("\n5. Tinh tong so cac phan tu khoa cua cay");
    printf("\n6. Dem so phan tu cua cay");
    printf("\n7. Thoat");
}

/******************************************************************************
* End of file
******************************************************************************/