/*
�����о��е�����
�����Ի�
Ҳ����˵���Ҵ�s��t֮�󣬻���һֱ��t���Ի�������У�
�����Ҵ�s��t֮�󣬻����ٴ�t��s��һ�飬����s��t
�����һ�������һ�����Ϸ�������
������������ 
*/ 

#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
struct node{
	int v,nex,w;
}a[5000000];
int first[5000000],cnt;
void add(int u,int v,int w){
	a[++cnt]={v,first[u],w};
	first[u]=cnt;
} 
int n,m,q;
int s,t;
int ans=-1;
void dfs(int u,int now){
	if(u==t) ans=max(ans,now);
	for(int i=first[u];i;i=a[i].nex){
		int v=a[i].v;
		if(a[i].w*now<=m)dfs(v,a[i].w*now);
	}
}
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout); 
	n=read();m=read();q=read(); 
	for(int i=2;i<=m;i++){
		int u,v;
		u=read();v=read();
		add(u,v,i);
		add(v,u,i);
	} 
	while(q--){
		ans=-1;
		s=read();t=read();
		dfs(s,1);
		printf("%d\n",ans);
	}
	return 0;
}

