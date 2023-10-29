int GCD_deQuy(int a, int b)
{
    // Trường hợp cơ sở: Nếu bằng 0, thì a là ước chung lớn nhất
    if (b == 0) 
    {
        return a;
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
    return a;
}