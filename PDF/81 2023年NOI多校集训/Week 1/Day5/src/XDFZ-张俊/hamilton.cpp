#include <bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+10;
struct node{
    int v,nex;
}a[MAXN];
int first[MAXN],cnt;
void add(int u,int v){
    a[++cnt]={v,first[u]};
    first[u]=cnt;
}
bool vis[MAXN];
bool vis2[MAXN];
stack<int> s;
vector<int> ans[MAXN];
int tot=0;
void dfs(int u){
    vis[u]= true;
    s.push(u);
    for(int i=first[u];i;i=a[i].nex){
        int v=a[i].v;
        if(!vis2[v]){
            if(vis[v]){
                tot++;
                while (s.top()!=v) {
                    ans[tot].push_back(s.top());
                    vis2[s.top()]=1;
                    s.pop();
                }
                ans[tot].push_back(s.top());
                vis2[s.top()]=1;
                s.pop();
                return;
            }
            else{
                dfs(v);
            }
        }
    }
    return;
}
int main(){
    freopen("hamilton.in","r",stdin);
    freopen("hamilton.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            while (!s.empty())s.pop();
            dfs(i);
        }
    }
    int num=0;
    for(int i=1;i<=tot;i++){
        num+=ans[i].size();
    }
    if(num!=n) { puts("NO");return 0;}
    puts("YES");
    for(int i=1;i<=tot;i++){
        cout<<ans[i].size()<<" ";
        for(int j:ans[i])cout<<j<<" ";
        cout<<"\n";
    }
}