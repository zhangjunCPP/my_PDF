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
int pk[N];
vector<int> x[N];
int y[N];
int mp(int k){
	if(pk[k]!=0)return pk[k];
	int num=1;
	for(int i=1;i<=k;i++)num*=p;
	return num;
}
int cntt=0;
void dfsn(int u){
	if(u==p+1){
		cntt++; 
		for(int i=1;i<=p;i++){
			if(i)
			cout<<a[i]; 
//			write(a[i]);
			putchar(' ');
		}
		puts("");
		return ;
	}
	for(int i=(y[u]-1)*p;i<=y[u]*p-1;i++){
		if(i==0&&u==p)system("pause");
//		cout<<y[u]<<endl;
		a[u]=i;
		dfsn(u+1);
	}
}
int cnt;
void dfsw(int u){
	if(cnt==p){
//		for(int i=1;i<=cnt;i++)cout<<y[i]<<' ';
//		puts("----"); 
		dfsn(1);
//		puts("++++");
		return ;
	}
	if(u>mp(k-1))return ;
	y[++cnt]=u;
//	for(int i=1;i<=cnt;i++)putchar('>');
//	cout<<u<<endl;
	dfsw(u+1);
	cnt--;
	dfsw(u+1);
}
int main(){
//	freopen("a.out","w",stdout);
	read(p);
	read(k);
//	cout<<mp(k)<<endl;
	dfsw(1);
	cout<<cntt;
}
/*

*/ 
