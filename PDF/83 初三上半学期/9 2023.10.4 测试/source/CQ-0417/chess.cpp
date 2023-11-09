#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

int p,k,pk=1;
std::vector<int> ans;
void solve(int l,int r,int d){
    if(d==0)return;
    else{
        int n=r-l+1,nn=n/p;
        for(int i=1,L=l,R=l+nn-1;i<=p;++i,L+=nn,R+=nn)
            solve(L,R,d-1);
        for(int j=0;j<nn;++j){
            std::vector<int> vec;
            for(int c=1,J=j,P=nn/p;c<=d-1;++c){
                vec.emplace_back(J/P);
                J%=P,P/=p;
            }
            for(int i=0;i<nn;++i){
                std::vector<int> veci;
                for(int c=1,J=i,P=nn/p;c<=d-1;++c){
                    veci.emplace_back(J/P);
                    J%=P,P/=p;
                }
                for(int x=1;x<=p;++x){
                    int now=l;
                    for(int c=1,P=nn/p;c<=d-1;++c,P/=p)now+=veci[c-1]*P;
                    ans.emplace_back(now+(x-1)*nn);
                    for(int c=1;c<=d-1;++c)veci[c-1]=(veci[c-1]+vec[c-1])%p;
                }
            }
        }
    }
}

int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    
    scanf("%d%d",&p,&k);
    for(int i=1;i<=k;++i)pk*=p;
    solve(0,pk-1,k);
    printf("%llu\n",ans.size()/p);
    for(int i=0;i<ans.size();++i)
        printf("%d%c",ans[i]," \n"[i%p==p-1]);
    return 0;
}
