/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>

/******************************************************************************
* Prototypes
******************************************************************************/
/* Tính tổng của n số đầu tiên của dãy tự nhiên bằng đệ quy*/
int Sum_DeQuy(int n);
int Sum_KhuDeQuy(int n);

/******************************************************************************
* Code
******************************************************************************/
int main()
{
    int n = 0, sum = 0;
    printf("\n\tCASE 1: HAM DE QUY\n");
    printf("----------------------------------------------------------------\n");
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("Vui long nhap lai n\n");
        }
    }while(n < 0);
    
    sum = Sum_DeQuy(n);
    printf("Tong cua day %d so tu nhien dau tien la: %d", n, sum);
    printf("\n\n\tCASE 2: HAM KHU DE QUY\n");
    printf("----------------------------------------------------------------\n");
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("Vui long nhap lai n\n");
        }
    }while(n < 0);
    sum = Sum_KhuDeQuy(n);
    printf("Tong cua day %d so tu nhien dau tien la: %d", n, sum);
    return 0;
}

/******************************************************************************
* Function
******************************************************************************/
int Sum_DeQuy(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return (n + Sum_DeQuy(n - 1));
    }
}

int Sum_KhuDeQuy(int n)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}


/******************************************************************************
* End of File
******************************************************************************/