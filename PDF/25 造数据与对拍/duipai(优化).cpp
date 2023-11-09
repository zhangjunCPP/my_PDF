#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int ok = 0;
    int n;
    printf("请输入你希望对拍的次数: ");
    scanf("%d",&n); 
    for (int i = 1; i <= n; ++i)
    {
        system("make.exe > make.txt");
        system("std.exe < make.txt > std.txt");
        double begin = clock();
        system("baoli.exe < make.txt > baoli.txt");
        double end = clock();

        double t = (end - begin);
        if (system("fc std.txt baoli.txt"))
        {
            printf("测试点#%d Wrong Answer\n", i);
        }
        else if (t > 1000) //1秒
        {
            printf("测试点#%d Time Limited Exceeded 用时 %.0lfms\n", i, t);
        }
        else
        {
            printf("测试点#%d Accepted 用时%.0lfms\n", i, t);
            ok++; //AC数量+1
        }
    }
    printf("\n");
    double res = 100.0 * ok / n;
    printf("共 %d 组测试数据，AC数据 %d 组。 得分%.1lf。", n, ok, res);

    Sleep(1000); //休眠1秒，为了节约对拍次数。
}

