/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>

/******************************************************************************
* Prototypes
******************************************************************************/
int findMin_deQuy(int *a, int first, int last);
int findMin_khu_Dequy(int *a, int n);

/******************************************************************************
* Code
******************************************************************************/
int main()
{
    int a[] = {6, 2, 3, 4, 5, 1, 0 -1, -2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    printf("\n\tCASE 1: HAM DE QUY\n");
    printf("----------------------------------------------------------------\n");

    int min = findMin_deQuy(a, 0, n - 1); // Bắt đầu từ index 0 đến index n - 1
    printf("Gia tri nho nhat cua day so tren la: %d\n", min);

    printf("\n\tCASE 2: HAM KHU DE QUY\n");
    printf("----------------------------------------------------------------\n");
    min = findMin_khu_Dequy(a, n);
    printf("Gia tri nho nhat cua day so tren la: %d\n", min);

}

/******************************************************************************
* Function
******************************************************************************/
int findMin_deQuy(int *a, int first, int last)
{
    // Trường hợp cơ sở: Mảng chỉ có một phần tử
    if (first == last)
    {
        return a[first];
    }
    else
    {
        // Tìm giá trị nhỏ nhất trong hai nửa của mảng
        int mid = (first + last) / 2;
        int min1 = findMin_deQuy(a, first, mid);
        int min2 = findMin_deQuy(a, mid + 1, last);
        return (min1 < min2) ? min1 : min2;
    }
    

    
}
int findMin_khu_Dequy(int *a, int n)
{
    int min = a[0];
    for(int i = 1; i < n; i++)
    {
        if(min > a[i])
        {
            min = a[i];
        } 
    }
    return min;
}

/******************************************************************************
* End of file
******************************************************************************/