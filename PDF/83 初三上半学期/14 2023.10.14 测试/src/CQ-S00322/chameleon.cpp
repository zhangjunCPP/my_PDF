#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 1000005
#define K 45
#define LL long long
int n,k,l;
struct st{
	int fd,col;
}a[N];
LL ans[K];
int cnt[K];
int xxr[K];
int main(){
	freopen("chameleon.in","r",stdin);
//	freopen("ex_chameleon1.in","r",stdin);
	freopen("chameleon.out","w",stdout);
	read(n);
	read(k);
	read(l);
	for(int i=0;i<=l;i++)a[i].fd=-1;
	for(int i=1;i<=n;i++){
		int d;
		read(d);
		read(a[d].col);
		char c=getchar();
		while(c!='L'&&c!='D')c=getchar();
		a[d].fd=(c=='L');
//		b[d]=a[d];
	}
	LL sum=0;
	int nw=l+1;
	for(int i=0;i<=l;i++){
//		cout<<i<<','<<nw<<endl;
		if(a[i].fd==1){
			ans[(a[i].col+sum)%k]+=Min(i*2,nw+i);
		}else if(a[i].fd==0){
			ans[a[i].col]+=((l-i)<<1);
			nw=Min(nw,i);
			sum+=a[i].col;
		}
	}
//	for(int i=0;i<k;i++){
//		printf("%lld",(ans[i]>>1));
//		puts((ans[i]&1)?".5":".0");
//	}
//	puts("----------");
	for(int i=l;i>nw;i--){
		if(a[i].fd==1)cnt[a[i].col]++;
		else if(a[i].fd==0){
			for(int j=0;j<k;j++)xxr[j]=cnt[j];
			for(int j=0;j<k;j++)cnt[(j+a[i].col)%k]=xxr[j];
		}
		for(int j=0;j<k;j++)ans[j]+=cnt[j];
	}
	for(int i=0;i<k;i++){
		printf("%lld",(ans[i]>>1));
		puts((ans[i]&1)?".5":".0");
	}
	return 0;
}
/*
2 3 10
0 0 D
10 1 L
*/
/*
4 3 7
1 0 D
3 0 D
4 1 L
6 2 D

*/
