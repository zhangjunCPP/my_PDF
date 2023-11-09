#include<bits/stdc++.h>
using namespace std;
template<typename T>void read(T&x){
x=0;/*T fl=-1;*/char c=getchar();while(c<'0'||'9'<c){/*if(c=='-')fl=-1;*/c=getchar();}
while('/'<c&&c<':'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}/*x*=fl;*/}
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define N 3000000
#define LL long long
#define ULL unsigned long long
int n,q;
struct st{
	vector<pair<int,int> > son;
//	int& operator [] (const int i){
//		for(pair<int,int> it:son){
//			if(it.first==i)return it.second;
//		}
//		return 0; 
//	}
	int find(int i){
		for(pair<int,int> it:son)
			if(it.first==i)return it.second;
		return 0;
	}
	void ins(int i,int id){
		son.push_back({i,id});
	}
};
//int son[N][30];
vector<st> son;
int val[N];
char s[N];
int tot=1;
void add(){
	int u=1;
	int k=strlen(s+1);
	val[u]++;
	for(int i=1;i<=k;i++){
		if(!son[u].find(s[i]-'a'))
			son[u].ins({s[i]-'a',(int)son.size()})
			son[u][s[i]-'a']=
			(int)son.size();
			//++tot;
		son.push_back({});
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
const int X=31;
const int Y=37;
const int P1=5000011,P2=5000077;
int hs1(){
	int x=0;
	for(int i=1;s[i];i++)
		x=(x*X+s[i]-'a')%P1;
	return x;
}
int hs2(){
	int x=0;
	for(int i=1;s[i];i++)
		x=(x*Y+s[i]-'a')%P2;
	return x;
}
LL ans1[N],ans2[N];
int main(){
//	freopen("lihua.in","r",stdin);
	freopen("ex_lihua3.in","r",stdin);
	freopen("lihua.out","w",stdout);
	read(n);
	son.push_back({});
	son.push_back({});
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		add();
		ans1[hs1()]=ans2[hs2()]=ask();
	}
	read(q);
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		LL xx=ans1[hs1()];
		if(xx==ans2[hs2()]&&xx!=0)
			printf("%lld\n",xx);
		else printf("%lld\n",ask());
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
