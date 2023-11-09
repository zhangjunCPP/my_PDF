#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 6000005
#define LL long long
int n,q;
struct st{
	int son[30];
	int& operator [] (const int i){
		return son[i];
	}
};
int son[N][30];
//vector<st> son;
int val[N];
char s[N];
int tot=1;
void add(){
	int u=1;
	int k=strlen(s+1);
	val[u]++;
	for(int i=1;i<=k;i++){
		if(!son[u][s[i]-'a'])
			son[u][s[i]-'a']=++tot;
//			(int)son.size();
//		son.push_back({});
		u=son[u][s[i]-'a'];
		val[u]++;
	}
}
LL ask(){
	int u=1;
	LL ans=0;
	int k=strlen(s+1);
	ans+=val[u];
	for(int i=1;i<=k;i++){
		if(!son[u][s[i]-'a'])break;
		u=son[u][s[i]-'a'];
		ans+=val[u];
	}
	return ans;
}
int main(){
//	freopen("lihua.in","r",stdin);
	freopen("ex_lihua2.in","r",stdin);
	freopen("lihua.out","w",stdout);
	read(n);
//	son.push_back({});
//	son.push_back({});
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		add();
	}
	read(q);
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		printf("%lld\n",ask());
	}
	return 0;
}
/*
5
jiarandaxiaojie
jiarenmensheidonga
jiangshuaisanjun
beimingningxiao
fenbenglixi
4
jianghua
jiaruo
beiguan
feng

*/
/*
嘉然大小姐
家人们谁懂啊
奖率三军
？？？？
分崩离析

讲话
假若
悲观
风 
*/
