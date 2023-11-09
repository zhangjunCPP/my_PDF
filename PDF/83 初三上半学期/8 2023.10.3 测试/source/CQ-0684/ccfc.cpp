#include<bits/stdc++.h>
#define  Int  long long int
#define  Pub  public
using std::min;using std::max;

char a[100005];
int n,ans[100005];
unsigned Int h1[100005],p1[100005],P1=131,mod1=1000000007;
unsigned Int h2[100005],p2[100005],P2=13331,mod2=1000000009;
bool check(int a,int b,int c,int d){
    return (h1[b]-h1[a-1]*p1[b-a+1]%mod1+mod1)%mod1==(h1[d]-h1[c-1]*p1[d-c+1]%mod1+mod1)%mod1
        && (h2[b]-h2[a-1]*p2[b-a+1]%mod2+mod2)%mod2==(h2[d]-h2[c-1]*p2[d-c+1]%mod2+mod2)%mod2;
}

int main(){
    freopen("ccfc.in","r",stdin);
    freopen("ccfc.out","w",stdout);
    
    scanf("%s",a+1),n=strlen(a+1);
    p1[0]=1;for(int i=1;i<=n;++i)p1[i]=p1[i-1]*P1%mod1;
    p2[0]=1;for(int i=1;i<=n;++i)p2[i]=p2[i-1]*P2%mod2;
    for(int i=1;i<=n;++i)h1[i]=(h1[i-1]*P1+a[i])%mod1;
    for(int i=1;i<=n;++i)h2[i]=(h2[i-1]*P2+a[i])%mod2;
    
    for(int i=1;i<=n;++i){
        if(i+i+i>=n)continue;
        for(int j=1;j<=n;++j){
            if(j+i+i+i>n)continue;
            if(check(j,j+i-1,n-i+1,n)&&check(j+i,j+i+i-1,n-i+1,n))++ans[j];
        }
    }
    for(int i=1;i<=n;++i)printf("%d ",ans[i]);
    
    return 0;
}
