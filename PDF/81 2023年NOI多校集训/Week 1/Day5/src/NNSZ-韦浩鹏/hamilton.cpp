#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
vector <int> v[N];
void add(int x, int y){
    v[x].push_back(y);
}
bool f[N];
queue <int> q[N];
int cnt;
void dfs(int x, int now){
    f[x]=1, q[now].push(x);
    int k=v[x].size();
    for(int j=1;j<=100;++j){
        int i=rand()%k;
        int y=v[x][i];
        if(f[y]) continue;
        dfs(y, now); break;
    }
}
int main(){
    freopen("hamilton.in", "r", stdin);
    freopen("hamilton.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for(int j=1;j<=1000;++j){
        for(int i=1;i<=cnt;++i)
            while(!q[i].empty()) q[i].pop();
        cnt=0;
        for(int i=1;i<=n;++i)
            if(!f[i])
                dfs(i,++cnt);
        for(int i=1;i<=n;++i)
            if(!f[i]) goto rst;
        puts("YES");
        for(int i=1;i<=cnt;++i){
            printf("%d ", q[i].size());
            while(!q[i].empty()){
                int x=q[i].front();
                q[i].pop();
                printf("%d ", x);
            }
            puts("");
        }
        return 0;
        rst:;
    }
    puts("NO");
    return 0;
}
