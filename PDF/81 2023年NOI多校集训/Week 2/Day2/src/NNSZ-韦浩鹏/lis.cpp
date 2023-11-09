#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
vector <int> v[N];
void add(int x, int y){
    v[x].push_back(y);
    v[y].push_back(x);
}
int w[N];
int main(){
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1;i<n;++i){
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    for(int i=1;i<=n;++i)
        scanf("%d", &w[i]);

    return 0;
}
