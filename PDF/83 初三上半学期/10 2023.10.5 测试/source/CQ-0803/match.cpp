#include<bits/stdc++.h>
using namespace std; 
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
int n,m;
const int maxn=1e6+5; 
vector<int> G[maxn];
int d[maxn],vis[maxn];
inline void solve(){
	read(n),read(m);
	for(int i=1;i<=n;i++){
		vis[i]=0,d[i]=0; G[i].clear();
	}
	for(int i=1,x,y;i<=m;i++){
		read(x),read(y);
		d[x]++; d[y]++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d[i]);
	if(ans>=3){
		printf("%d\n",ans);
		return ;
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		for(auto j:G[i]) vis[j]=1;
		for(auto j:G[i]){
			for(auto k:G[j]){
				if(vis[k]) f=1;
			}
		}
		for(auto j:G[i]) vis[j]=0;
	}
	if(f) ans=max(ans,3);
	printf("%d\n",ans);
}
int main(){
	freopen("match.in","r",stdin); 
	freopen("match.out","w",stdout); 
	int T; 
	read(T);
	while(T--){
		solve();
	} 
	return 0;
}
/*
T1 �о���
ͼ�Ϸ�ƥ�����
��Ϊ���������߹��˵㡣
�������ĺܶ࣬���Ըо��򵥡�
����һ�£����� 3 Ԫ�����ǺϷ���ƥ�䡣
����һ�������ھջ�ͼ����һ����Ϊ���ģ���Χ�ĵ㶼��ѡ��
�𰸾��Ƕ�����
֤���˳���� 
���֤��ֻ�������������Ҫ�ԣ�
����һ���������������4���㣬��һ�����С�
�Ա߲����˵㡣
��Ϊ�Ƕ������������ߣ����Զ�����ȫͼҲ���˴��š�
����ͼ��ֻҪѡ����4Ԫ�������ϣ�һ��GG��
����ֻ�ܰ���3Ԫ����
ͬʱ3Ԫ��������ģ�����������һ���㣬����һ���߲����ڡ�
���ھջ������Ҳ��һ���ģ����Ա����ж�һ���Ƿ����3Ԫ����
���ںͶ���ȡmax���ɡ� 
1e6ֱ����Ԫ������ m sqrt(m) �е�Σ�գ�ֻ���� 1s��
��Ȼ�ܲ�������֪���ܲ��ܿ���
û���������õ��㷨�ˡ����� 
ֻ���ж��Ƿ����3Ԫ��Ӧ�ú��аɡ�
�������������㡣 �ǲ��绹����3Ԫ���������⡣
û��ϵ���Ҿ��ÿ����Ҹ㡣
��ans<3ʱ���Ҳſ���û����Ԫ����>=3ֱ�Ӱݰݡ�
˵��ÿ����Ķ�����<=3Ȼ����ö�����㣬������9�ĳ�����
6�� 
С����Ŀ�� 
*/
