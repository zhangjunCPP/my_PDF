#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	char ch=getchar();
	ll f=1,x=0;
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
inline void work(ll k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//第一个捆绑可以直接暴力枚举哪些点选,哪些点不选
ll n,m,M,N,B,d[1000005],vis[1000005],ans,now,boss[1000005],p;
pair<ll,ll> a[1000005];
ll find(ll x){
    if(boss[x]!=x)
        return boss[x]=find(boss[x]);
    return x;
}
int main(){
	freopen("subgraph.in","r",stdin);
    freopen("subgraph.out","w",stdout);
    n=read();
    m=read();
    M=read();
    N=read();
    B=read();
    for(ll i=1;i<=n;i++){
        boss[i]=i;
    }
    for(ll i=1;i<=m;i++){
        a[i].first=read();
        a[i].second=read();
    }
    ans=-1e9;
    for(int i=(1<<m)-1;i;i--){
        if(p-i==(i^p))
            continue;
        for(int j=1;j<=n;j++){
            boss[j]=j;
            d[j]=0;
        }
        for(int j=1;j<=m;j++){
            if((i>>(j-1))&1){
                int k=find(a[j].first),k1=find(a[j].second);
                if(k!=k1)
                    boss[k]=k1;
                d[a[j].first]++;
                d[a[j].second]++;
            }
        }
        ll sum=1e9,cnt1=0,num=0;
        for(int j=1;j<=n;j++){
            if(d[j]){
                sum=min(sum,d[j]);
                if(boss[j]==j)
                    cnt1++;
                num++;
            }
        }
        if(cnt1>1)
            continue;
        ll h=0,h1=0,flag=0;
        for(int j=1;j<=m;j++){
            if((i>>(j-1))&1)
                h++;
            else if((d[a[j].first]&&d[a[j].second])||(d[a[j].first]+1>=sum&&d[a[j].second]+1>=sum))
                flag=1;
            else{
                if(d[a[j].first]&&!d[a[j].second])
                    h1++;
                else if(!d[a[j].first]&&d[a[j].second])
                    h1++;
            }
        }
        if(flag)
            continue;
        else if(ans<h*M-N*num+h1*B){
            ans=h*M-N*num+h1*B;
            now=sum;
            p=i;
        }
        else if(ans==h*M-N*num+h1*B)
            now=max(now,sum);
    }
    work(now);
    putchar(' ');
    work(ans);
	return 0;
}