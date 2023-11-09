/*
t4
打个暴力先

利用hash可以优化到O(n^logn) 
*/ 
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
void wr(int x){
	if(x>10)wr(x/10);
	putchar(x%10|48);
}
const int N=2e5+10;
const ull p=131;
int lena,k,ans,i,lens;
char a[N],s[N];
ull h[N],g[N],jc[N];
ull ha(int l,int r){
	return g[r]-(l?g[l-1]*jc[r-l+1]:0);
}
ull hs(int l,int r){
	return h[r]-(l?h[l-1]*jc[r-l+1]:0);
}
bool check(int st){
	int l=0,r=lena-1,mn=r,mx=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ha(0,mid)==hs(st,st+mid))l=mid+1;
		else mn=mid,r=mid-1;
	}
	l=0,r=lena-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(ha(mid,lena-1)==hs(mid+st,lena-1+st))r=mid-1;
		else mx=mid,l=mid+1;
	}
//	printf("check(%d) mn=%d mx=%d\n",st,mn,mx);
	return mx-mn<k;
}
void work(){
	ans=0;
	scanf("%s",a);
	lena=strlen(a);
	for(i=0;i<lena;++i){
		g[i]=a[i];
		if(i)g[i]+=g[i-1]*p;
	}
	if(lena-1<k)return void(printf("%d\n",lens-lena+1));
	for(i=0;i+lena<=lens;++i)ans+=check(i);
	printf("%d\n",ans);
}
int T;
int main(){
//	puts("start");
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	jc[0]=1;
	for(i=1;i<=N-10;++i)jc[i]=jc[i-1]*p;
	scanf("%d%s%d",&k,s,&T);
	lens=strlen(s);
	for(i=0;i<lens;++i){
		h[i]=s[i];
		if(i)h[i]+=h[i-1]*p;
	}
//	puts("prework finish");
//	printf("T=%d\n",T);
	while(T--)work();
	return 0;
}
/*
2
baccbcbabc
7
a
abc
aaa
bbb
abbb
acbbc
iamasuperlongstring
*/
