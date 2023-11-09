#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

int a[N],b[N],n,f[N];
int t[N];
void change(int x,int k){
    for(;x<=n;x+=x&-x)t[x]=max(t[x],k);
}

int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans=max(ans,t[x]);
    return ans;
}

int main(){
	freopen("comb.in","r",stdin);
	freopen("comb.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=4;i<=n;i++){
        if(a[i]==a[i-2]&&a[i-1]==a[i-3])
            change(i,ask(i-4)+4);
    }
    printf("%d\n",ask(n));
    return 0;
}
/*
10
3 1 2 1 2 3 4 5 4 5
*/
