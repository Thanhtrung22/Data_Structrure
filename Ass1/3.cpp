/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
* Definitions
******************************************************************************/
#define MAX_SIZE 100
typedef struct 
{
    int data[MAX_SIZE]; // Mảng lưu trữ các phần tử
    int size;           // Số lượng phần tử hiện tại trong danh sách
} List;


/******************************************************************************
* Prototypes
******************************************************************************/
void initList(List &list);
bool isEmpty(List &list);
bool isFull(List &list);
void insert(List &list, int element, int position);
int get(List &list, int position);
void Delete(List &list, int position);
void update(List &list, int element, int position);
int find(List &list, int element);
void display(List &list);
void enter_list(List &list);


/******************************************************************************
* Code
******************************************************************************/
int main() 
{
    List list;
    initList(list);

    // Thêm các phần tử vào danh sách
    enter_list(list);
	printf("Danh sach sau khi nhap: ");
    display(list); // Hiển thị danh sách

    // Xóa phần tử tại vị trí 1
    Delete(list, 1);
    printf("\nDanh sach sau khi xoa:");
    display(list);

    // Cập nhật phần tử tại vị trí 0
    update(list, 15, 0);
    printf("\nDanh sach sau khi cap nhat:");
    display(list);

    // Tìm kiếm phần tử 20
    int position = find(list, 20);
    if (position != -1) {
        printf("Phan tu 20 nam o vi tri %d\n", position);
    } else {
        printf("Phan tu 20 khong tim thay trong danh sach\n");
    }
	// lấy ra phần tử tại 1 vị trí bất kì
	printf("Nhap vao vi tri muon lay gia tri: ");
	scanf("%d", &position);
	int get_value = get(list, position);
	if(get_value != -1)
	{
		printf("Gia tri tai %d la %d\n", position, get_value);
	}
	
    return 0;
    

    
}


void initList(List &list) {
    list.size = 0;
}

bool isEmpty(List &list) {
    return (list.size == 0);
}

bool isFull(List &list) {
    return (list.size == MAX_SIZE);
}

// Hàm để thêm một phần tử vào danh sách tại vị trí chỉ định
void insert(List &list, int element, int position) {
    if (isFull(list)) {
        printf("Danh sach da day. Khong the chen phan tu vao vi tri %d\n", position);
        return;
    }

    if (position < 0 || position > list.size) {
        printf("Vi tri khong hop le. Khong the chen phan tu vao vi tri %d\n", position);
        return;
    }

    // Dịch chuyển các phần tử phía sau để tạo chỗ trống cho phần tử mới
    for (int i = list.size; i > position; i--) {
        list.data[i] = list.data[i - 1];
    }

    // Chèn phần tử mới vào vị trí chỉ định
    list.data[position] = element;
    list.size++;
}

// Hàm để lấy ra một phần tử từ danh sách tại vị trí chỉ định
int get(List &list, int position) {
    if (isEmpty(list)) {
        printf("Danh sach rong. Khong the lay phan tu.\n");
        return -1;
    }

    if (position < 0 || position >= list.size) {
        printf("Vi tri khong hop le. Khong the lay phan tu tai vi tri %d\n", position);
        return -1;
    }

    return list.data[position];
}

void Delete(List &list, int position) {
    if (isEmpty(list)) {
        printf("Danh sach rong. Khong the xoa phan tu.\n");
        return;
    }

    if (position < 0 || position >= list.size) {
        printf("Vi tri khong hop le. Khong the xoa phan tu tai vi tri %d\n", position);
        return;
    }

    // Dịch chuyển các phần tử phía sau để loại bỏ phần tử ở vị trí chỉ định
    for (int i = position; i < list.size - 1; i++) {
        list.data[i] = list.data[i + 1];
    }

    list.size--;
}

void update(List &list, int element, int position) {
    if (isEmpty(list)) {
        printf("Danh sach rong. Khong the cap nhat phan tu.\n");
        return;
    }

    if (position < 0 || position >= list.size) {
        printf("Vi tri khong hop le. Khong the cap nhat phan tu tai vi tri %d\n", position);
        return;
    }

    list.data[position] = element;
}

int find(List &list, int element) {
    if (isEmpty(list)) {
        printf("Danh sach rong. Khong the tim kiem phan tu.\n");
        return -1;
    }

    for (int i = 0; i < list.size; i++) {
        if (list.data[i] == element) {
            return i;
        }
    }

    return -1;
}
void enter_list(List &list)
{
    int length = 0;
    int temp_value = 0;
    bool flag = 0;
    do
    {
        printf("Nhap so phan tu list (<= %d): ", MAX_SIZE);
        scanf("%d", &length);
    }while(length <= 0 || length > MAX_SIZE);
    for(int i = 0; i < length; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &temp_value);
        insert(list, temp_value, i);
    }
}
void display(List &list) {
    if (isEmpty(list)) {
        printf("Danh sach rong.\n");
        return;
    }

    
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");
}

/******************************************************************************
* End of file
******************************************************************************/