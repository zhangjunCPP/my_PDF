#include<bits/stdc++.h>
using namespace std;
int n,m,siz;
int G[21][21];
char s[21];
vector< pair<int,int> > v;
int d[21],ans;
const int mod=998244353;
inline void dfs(int now){
	if(now==siz){
		bool f=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='1' && d[i]<2) f=0;
		} 
		if(f) ans++;
		return ;
	}
	dfs(now+1);
	d[v[now].first]++;
	d[v[now].second]++;
	dfs(now+1);
	d[v[now].first]--;
	d[v[now].second]--;
}
inline void solve1(){
	v.clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i]=='1' && s[j]=='1' && G[i][j]){
				v.push_back(make_pair(i,j));
			}
		}
	}
	siz=v.size();
	memset(d,0,sizeof d); 
	ans=0;
	dfs(0);
	printf("%d\n",ans);
}
inline int C(int n,int m){
	if(n<m) return 0;
	int jc=1ll;
	for(int i=max(n-m,m)+1;i<=n;i++) jc*=i;
	for(int i=1;i<=min(n-m,m);i++) jc/=i;
	return jc;
}
inline void solve2(){
	memset(d,0,sizeof d);
	int M=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]=='1' && s[j]=='1' && G[i][j]){
				d[i]++;
				M++;
			}
		}
	}
	M/=2;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum|=((s[i]-'0')<<(i-1));
	}
	ans=0;
	for(int S=0;S<(1<<n);S++){
		if(S|sum>sum) continue;
		int ss=1,cnt=0;
		for(int i=0;i<n;i++){
			if((S>>i)&1){
				cnt++;
				ss*=C(d[i+1],2);
			}	
		}
		/*
		������Ŀ�������ˡ� 
		
		*/
	}
} 
int main(){
	freopen("big.in","r",stdin);
	freopen("big.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		G[x][y]=G[y][x]=1;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%s",s+1);
		solve1();
	}
	return 0;
}
/*
����ÿ����Ķȶ� >=2 ��
�ǲ�����һ���޸�����Ҷ�ӽڵ㶼��һ��������������
�о���������dp+�ݳ��һЩ������Ķ�����
��ʼ�뷨�϶�����ö��ÿһ�����Ƿ�ѡ�롣
���Թ�ǰ�����㡣
����ĵ��������Ľ������Ѳ��ɼ�֦��
�ն��ϸ�ÿ����Ķ����� 2 ����ͼ��С��ͼ��
��ô����С��ͼ��ߵĲ����ǿ������ѡ�ġ�
�����Ϊ m ������Ϊ n��
��ô�������ڳ���һ��ϵ����
���������©����Ϊ�������д��ͼ����������С��ͼ��
�������ݳ���һ�£�
>=0 �ĸ�����Ҳ�������з������� 
��ȥ������������
�����ն�һ�������>=2-2����+3���㡣
���У���̫���ˣ����ò�һ����
����״ѹ�� ���ӡ�
�ĳ��ն�һ���㼯����>=2�ķ�������
�㼯�ڲ��������ߣ����ô���
�����᲻�����ظ��ɡ�
�ö���ʽ����֤֤��
֤���ӣ�SB��α�ˡ�
�����Ҹо��ҽӽ������ˡ�
��Ϊ���θ��Ӷ��� 2^n
1e5 �ο��Կ���ֻ��һ������𰸣���Ϊ���ж��ǵ㼯���Ӽ���
���ˡ�
�������ɣ�lzҲ������ȷ���ˡ�
��д������˵�� 
�����д�Ͳ�д��࣬���á� 
*/
