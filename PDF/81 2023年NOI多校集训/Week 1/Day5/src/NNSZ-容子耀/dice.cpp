#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        cout << "Yes\n";
        for (int i = 1; i <= 6; ++i)
            cout << i * k << ' ';
        return 0;
    }
    if (k == 2)
    {
        cout << "Yes\n";
        for (int i = 1, k = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 6; ++j, ++k)
                cout << 2 * k << ' ';
            cout << endl;
        }
        return 0;
    }
    else if (k == (k & -k))
    {
        cout << "Yes\n";
        for (int i = 1, l = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 6; ++j, ++l)
                cout << l * k << ' ';
            cout << endl;
        }
        return 0;
    }
    else cout << "No\n";

    return 0;
}
