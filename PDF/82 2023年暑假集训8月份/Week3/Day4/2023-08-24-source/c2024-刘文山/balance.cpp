#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
int n;
vector<int> G[maxn];
int siz[maxn],fa[maxn];
inline void dfs(int x,int f){
	siz[x]=1;
	for(auto v:G[x]){
		if(v==f) continue;
		fa[v]=x;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
int RT=0;
int SIZ[maxn],dp[maxn];
inline void get_rt(int x,int sum,int f){
	dp[x]=0;
	SIZ[x]=1;
	for(auto y:G[x]){
		if(y==f) continue;
		get_rt(y,sum,x);
		SIZ[x]+=SIZ[y];
		dp[x]=max(dp[x],SIZ[y]);
	}
	dp[x]=max(dp[x],sum-SIZ[x]);
	if(dp[x]<dp[RT]) RT=x;
}
inline void solve1(){//���� 
	for(int i=1;i<=n;i++){
		int rt=0,sum=0;
		for(auto x:G[i]){
			if(x==fa[i]){
				if(sum<n-siz[i]){
					rt=x;
					sum=n-siz[i];
				}
			}
			else{
				if(sum<siz[x]){
					rt=x;
					sum=siz[x]; 
				}
			}
		}
		RT=0;
		get_rt(rt,sum,i);
		printf("%d\n",RT);	
	}
}
inline void solve2(){//�ջ�ͼ
	printf("2\n");
	for(int i=2;i<=n;i++){
		printf("1\n");
	} 
}
inline void solve3(){//�� 
	for(int i=1;i<=n;i++){
		int len1=i-1,len2=n-i;
		if(len1>len2){
			printf("%d\n",(len1-1)/2+1);
		}
		else{
			printf("%d\n",(len2-1)/2+1+i);
		}
	}
}
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout); 
	scanf("%d",&n);
	bool f1=1,f2=1;
	dp[0]=n+1;
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
		if(x!=1 || y!=i+1)
			f1=0;
		if(x!=i || y!=i+1)
			f2=0;
	}
	if((!f1) && (!f2)){
		dfs(1,1);
		solve1(); 
	}
	else if(f1){
		solve2();
	}
	else if(f2){
		solve3(); 
	}
	else{
		for(int i=1;i<=n;i++)
			cout<<"�⼦\n"; 
	}
	return 0;
}
/*�ں� n^2
����ɾȥһ���㣬��ʹ�����������������ɭ�֡�
��ô�����������ǻۣ��϶��ʹӴ������ɾ����
ɾ���ĵ㣬�������������������ļ��ɡ�
���� 100 % ������Ӧ�ò���̫�ѡ�
�϶������Ż������ĵĹ��̣����� dp + ������
6��
��ʵ�Ҿ����ڿ�һ�����ʷ־Ͳ���ˣ��Ͼ�T3�������о��С�
���ڲ���������һ���������оջ�ͼ��
�ջ�ͼ�ܼ򵥣�ֱ����� 1 �����ˣ�1��� 2��
�������������
һ����ֳ���������ֱ�ӽ������������۰�ͺ��ˡ�
���� 60 �־���ôˮ����ò������ռ�+ ���- ���ѶȰɡ����� 
�պ� 114 �У�����ţ�ƣ� 
*/ 
