#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    //这是一个生成随机数随机种子，需要用到 ctime 库
    printf("%d %d\n", rand(), rand());
    //这样就生成了2个随机数
    return 0;
}
