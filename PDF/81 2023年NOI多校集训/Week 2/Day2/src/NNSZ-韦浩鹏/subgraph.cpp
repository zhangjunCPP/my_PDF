#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
vector <int> v[N];
void add(int x, int y){
    v[x].push_back(y);
    v[y].push_back(x);
}

int main(){
    freopen("subgraph.in", "r", stdin);
    freopen("subgraph.out", "w", stdout);
    int n, m, N, M, B;
    scanf("%d%d%d%d%d", &n, &m, &N, &M, &B);
    while(m--){
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }

    return 0;
}
