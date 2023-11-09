#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(long long k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
int n,m,dep[100005],dp[100005][20],vis[100005],first[100005],cnt,val[100005],co[100005],num[100005];
struct node{
    int x,y,p,id;
};
vector<node> q,ans;
struct q1{
    int u,w,nex;
}a[400005];
void add(int u1,int w1){
    a[++cnt]={u1,w1,first[u1]};
    first[u1]=cnt;
}
void dfs(int u,int dad){
    dep[u]=dep[dad]+1;
    dp[u][0]=dad;
    for(int i=1;i<=19;i++){
        dp[u][i]=dp[dp[u][i-1]][i-1];
    }
    for(int i=first[u];i;i=a[i].nex){
        if(a[i].w==dad)
            continue;
        if(!dep[a[i].w])
            dfs(a[i].w,u);
    }
}
int LCA(int x,int y){
    if(dep[x]>dep[y])
        swap(x,y);
    for(int i=19;i>=0;i--){
        if(dep[x]<=dep[dp[y][i]])
            y=dp[y][i];
    }
    if(x==y)
        return x;
    for(int i=19;i>=0;i--){
        if(dp[x][i]!=dp[y][i]){
            x=dp[x][i];
            y=dp[y][i];
        }
    }
    return dp[x][0];
}
void dfs2(int u,int dad){
    vis[u]=1;
    co[u]=1;
    for(int i=first[u];i;i=a[i].nex){
        if(a[i].w==dad)
            continue;
        if(!co[a[i].w])
            dfs2(a[i].w,u);
        else if(vis[a[i].w])
            q.emplace_back(node{u,a[i].w,LCA(u,a[i].w),i});
    }
    vis[u]=0;
}
void dfs3(int u,int dad){
    vis[u]=1;
    for(int i=first[u];i;i=a[i].nex){
        if(a[i].w==dad)
            continue;
        if(!vis[a[i].w])
            dfs3(a[i].w,u);
        num[u]+=val[a[i].w];
    }
    num[u]+=val[u];
}
void dfs4(node h){
    deque<int> g,f;
    int now=h.x,now1=h.y;
    while(now!=h.p){
        g.emplace_front(now);
        now=dp[now][0];
    }
    while(now1!=h.p){
        f.emplace_front(now1);
        now1=dp[now1][0];
    }
    work(g.size()+f.size()+1);
    putchar(' ');
    while(!g.empty()){
        work(g.front());
        putchar(' ');
        g.pop_front();
    }
    work(h.p);
    putchar(' ');
    while(!f.empty()){
        work(f.back());
        putchar(' ');
        f.pop_back();
    }
    putchar('\n');
}
void getans(int k){
    if(k>=q.size()){
        for(int i=1;i<=n;i++){
            num[i]=0;
        }
        dfs3(1,0);
        for(int i=1;i<=n;i++){
            if(num[i]!=1)
                return ;
        }
        puts("YES");
        for(auto i:ans){
            dfs4(i);
        }
        exit(0);
    }
    ans.emplace_back(q[k]);
    val[q[k].x]++;
    val[q[k].y]++;
    val[q[k].p]--;
    val[dp[q[k].p][0]]--;
    getans(k+1);
    val[q[k].x]--;
    val[q[k].y]--;
    val[q[k].p]++;
    val[dp[q[k].p][0]]++;
    ans.pop_back();
    getans(k+1);
}
int main(){
    freopen("hamilton.in","r",stdin);
    freopen("hamilton.out","w",stdout);
    n=read();
    m=read();
    for(int i=1,x,y;i<=m;i++){
        x=read();
        y=read();
        add(x,y);
    }
    puts("NO");
	return 0;
}