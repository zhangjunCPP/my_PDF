#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T&x){
x=0;char c=getchar();/*T fl=1;*/while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 3000006
int n,m;
int t[N],las[N],fir[N],d[N],num;
void add(int u,int v){
t[++num]=v;las[num]=fir[u];fir[u]=num;d[u]++;
t[++num]=u;las[num]=fir[v];fir[v]=num;d[v]++;}
int fl[N];
int ans=0;
int find(int u){
	if(d[u]>=3)return d[u];
	for(int i=fir[u];i;i=las[i]){
		if(d[t[i]]>=3)return d[u];
		for(int j=fir[t[i]];j;j=las[j]){
			if(d[t[j]]>=3)return d[t[j]];
			if(t[j]==u)continue;
			for(int k=fir[t[j]];k;k=las[k]){
				if(t[k]==u)return 3;
			}
		}
	}
	return d[u]; 
}
int main(){
	freopen("match.in","r",stdin); 
	freopen("match.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);
		read(m);
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		/*多测不清空，爆0痛心中*/ 
		num=0;
		for(int i=1;i<=n;i++)fir[i]=d[i]=0;
		/*多测不清空，爆0痛心中*/
		/*多测不清空，爆0痛心中*/
		/*多测不清空，爆0痛心中*/
		/*多测不清空，爆0痛心中*/
		/*多测不清空，爆0痛心中*/
		/*多测不清空，爆0痛心中*/
		for(int i=1,x,y;i<=m;i++)read(x),read(y),add(x,y);
		int ans=0;
		for(int i=1;i<=n;i++)ans=Max(ans,find(i));
		printf("%d\n",ans);
		/*多测不换行，泪落湿衣裳*/
		/*多测不换行，泪落湿衣裳*/
		/*多测不换行，泪落湿衣裳*/
	}
	return 0;
}
/*多测不清空，爆0痛心中*/ 
/*
3
4 1
2 3
1 0
5 4
3 2
5 3
5 1
4 5
*/
