#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){x=0;char c=getchar();/*T fl=1;*/
while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
template<typename T>void write(T x){if(x>=10)write(x/10);putchar((x%10)+'0');}
#define N 100005
#define INF 1145141919
#define LL long long
//#define int LL
int p,k;
int a[N];
void dfs(int u){
	if(u==p+1){
		for(int i=1;i<=p;i++){
			write(a[i]);
			putchar(' ');
		}
		puts("");
		return ;
	}
	for(int i=(u-1)*p;i<=u*p-1;i++){
		a[u]=i;
		dfs(u+1);
	}
}
int jc(int l,int r){
	int num=1;
	l=Max(l,1);
	for(int i=l;i<=r;i++)num*=i;
	return num;
}
int pk[N];
int y[N];
int mp(int k){
	if(pk[k]!=0)return pk[k];
	int num=1;
	for(int i=1;i<=k;i++)num*=p;
	return num;
}
struct st{
	int cnt=0;
	void dfsn(int u){
		if(u==p+1){
			for(int i=1;i<=p;i++){
				write(a[i]);
				putchar(' ');
			}
			puts("");
			return ;
		}
		for(int i=(y[u]-1)*p;i<=y[u]*p-1;i++){
			a[u]=i;
			dfsn(u+1);
		}
	}
	void dfsw(int u){
		if(cnt==p){
			dfsn(1);
			return ;
		}
		if(u>mp(k-1))return ;
		y[++cnt]=u;
		dfsw(u+1);
		cnt--;
		dfsw(u+1);
	}
}s; 
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(p);
	read(k);
	if(k==1){
		puts("1");
		for(int i=1;i<=p;i++){
			printf("%d ",i);
		}
		return 0;
	}else if(k==2){
		int num=1;
		for(int i=1;i<=p;i++)num*=p;
		num+=p;
		write(num);
		puts("");
		for(int i=1;i<=p;i++){
			for(int j=(i-1)*p;j<=i*p-1;j++){
				write(j);
				putchar(' ');
			}
			puts("");
		}
		dfs(1);
		return 0;
	}else if(p==2){
		int num=1;
		for(int i=1;i<=k;i++)num*=p;
		write(num*(num-1)/2);
		puts("");
		for(int i=1;i<=num;i++){
			for(int j=i+1;j<=num;j++){
				write(i);
				putchar(' ');
				write(j);
				puts("");
			}
		}
		return 0;
	}
//	*/
	printf("%d\n",jc(mp(k-1)-p+1,mp(k-1))/jc(1,p)*mp(p)+mp(k-1));
	for(int i=1;i<=mp(k-1);i++){
		for(int j=(i-1)*p;j<=i*p-1;j++){
			write(j);
			putchar(' ');
		}
		puts("");
	}
	s.dfsw(1);
}

