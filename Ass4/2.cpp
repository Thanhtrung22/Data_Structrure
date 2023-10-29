/******************************************************************************
* Includes
******************************************************************************/
#include <stdio.h>

/******************************************************************************
* Prototypes
******************************************************************************/

int To_Hop_De_Quy(int k, int n);
int giaiThua(int n);
int To_Hop_Khu_De_Quy(int k, int n);

/******************************************************************************
* Code
******************************************************************************/
int main()
{
    int n = 0, k = 0;
    int result = 0;
    printf("\n\tCASE 1: HAM DE QUY\n");
    printf("----------------------------------------------------------------\n");
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("Vui long nhap lai n voi n >= 0\n");
        }
    }while(n < 0);
    do
    {
        printf("Nhap k: ");
        scanf("%d", &k);
        if(k < 0 || k > n)
        {
             printf("Vui long nhap lai k voi 0 <= k <= n\n");
        }
    }while(k < 0 || k > n);
    result = To_Hop_De_Quy(k, n);
    printf("To hop chap %d cua %d la: %d", k, n, result);
    printf("\n\n\tCASE 2: HAM KHU DE QUY\n");
    printf("----------------------------------------------------------------\n");
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("Vui long nhap lai n voi n >= 0\n");
        }
    }while(n < 0);
    do
    {
        printf("Nhap k: ");
        scanf("%d", &k);
        if(k < 0 || k > n)
        {
             printf("Vui long nhap lai k voi 0 <= k <= n\n");
        }
    }while(k < 0 || k > n);
    result = To_Hop_Khu_De_Quy(k, n);
    printf("To hop chap %d cua %d la: %d", k, n, result);

    return 0;
}

/*******************************************************************************
 *Functions
 ******************************************************************************/
int giaiThua(int n)
{
    int tich = 1;

    for(int i = 1; i <= n; i++)
    {
        tich *= i; 
    }

    return tich;
}
int To_Hop_Khu_De_Quy(int k, int n)
{
    return giaiThua(n) / ( giaiThua(k) * giaiThua(n -k) );
}

int To_Hop_De_Quy(int k, int n)
{
    if(k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return (To_Hop_De_Quy(k -1, n -1) + To_Hop_De_Quy(k, n - 1));
    }
}

/******************************************************************************
* End of file
******************************************************************************/