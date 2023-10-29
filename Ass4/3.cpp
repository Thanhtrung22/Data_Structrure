/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>
#include <math.h>

/******************************************************************************
* Prototypes
******************************************************************************/
int GCD_deQuy(int a, int b);
int GCD_khu_Dequy(int a, int b);

/******************************************************************************
* Code
******************************************************************************/
int main() {
    int a, b, gcd;
    printf("\n\tCASE 1: HAM DE QUY\n");
    printf("----------------------------------------------------------------\n");
    printf("Nhap so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf("%d", &b);
    gcd = GCD_deQuy(a, b);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, gcd);
    printf("\n\tCASE 2: HAM KHU DE QUY\n");
    printf("----------------------------------------------------------------\n");
    printf("Nhap so nguyen a: ");
    scanf("%d", &a);
    printf("Nhap so nguyen b: ");
    scanf("%d", &b);
    gcd = GCD_khu_Dequy(a, b);
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, gcd);
    return 0;
}

/******************************************************************************
* Function
******************************************************************************/
int GCD_deQuy(int a, int b)
{
    // Trường hợp cơ sở: Nếu bằng 0, thì a là ước chung lớn nhất
    if (b == 0) 
    {
        return abs(a);
    }

    // Đệ quy: Gọi đệ quy với b làm số mới và a % b
    return GCD_deQuy(b, a % b);
}
int GCD_khu_Dequy(int a, int b)
{
    int temp = 0;
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}




/******************************************************************************
* Enf of file
******************************************************************************/