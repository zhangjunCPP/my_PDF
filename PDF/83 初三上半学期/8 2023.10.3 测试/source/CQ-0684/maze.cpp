#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;
const int SuperBig=2000000005;

int n,m,k;
class Edge{
Pub:int to,t,next;
}e[400005];int cntE;
class Node{
Pub:int fir,d;
    int dis,vis;
    std::multiset<int> s;
}p[200005];
void addEdge(int x,int y,int t){
    e[++cntE]=(Edge){y,t,p[x].fir};
    p[x].fir=cntE;
}

std::queue<std::pair<int,int>> q;
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)p[i].dis=SuperBig;
    for(int i=1,x;i<=k;++i){
        scanf("%d",&x);
        p[x].dis=0;
        q.emplace(0,x);
    }
    for(int i=1;i<=n;++i)scanf("%d",&p[i].d);
    for(int i=1,x,y,t;i<=m;++i){
        scanf("%d%d%d",&x,&y,&t);
        addEdge(x,y,t),addEdge(y,x,t);
    }
    
    while(q.size()){
        int x=q.front().second;q.pop();
        if(p[x].vis)continue;
        else p[x].vis=1;
        for(int i=p[x].fir,y;i;i=e[i].next){
            y=e[i].to;
            if(p[y].vis)continue;
            else{
                int T=p[x].dis+e[i].t;
                if(p[y].s.size()==p[y].d){
                    if(p[y].s.size()&&T<*p[y].s.rbegin()){
                        int TT=*p[y].s.rbegin();
                        p[y].s.erase(std::prev(p[y].s.end()));
                        p[y].s.emplace(T);
                        T=TT;
                    }
                    if(T<p[y].dis){
                        p[y].dis=T;
                        q.emplace(-T,y);
                    }
                }else p[y].s.emplace(T);
            }
        }
    }
    if(p[1].dis==SuperBig)printf("-1");
    else printf("%d",p[1].dis);
        
    return 0;
}
