#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
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
}
int n,m,q;
vector< pair<int,int> > G[maxn];
bool dp[1005][1005],dp2[1005][1005];
int s,t;
inline void solve1(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	dp[s][1]=1;
	for(int i=1;i<=log2(m);i++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp2[i][j]=dp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(auto j:G[i]){
				int to=j.first,w=j.second;
				for(int val=1;val*w<=m;val++){
					dp[to][val*w]|=dp2[i][val];
				}
			} 
		}
	}
	int ans=m;
	for( ; ans>=0; ans--){
		if(dp[t][ans]) break;
	}
	if(ans) printf("%d\n",ans);
	else puts("-1");
} 
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout); 
	read(n),read(m),read(q);
	for(int i=2,x,y;i<=m;i++){
		read(x),read(y);
		G[x].push_back(make_pair(y,i));
		G[y].push_back(make_pair(x,i));
	}
	while(q--){
		scanf("%d%d",&s,&t);
		solve1();
	} 
	return 0;
}
/*
dp i j
��ʾ�� S ��ʼ���Ƿ����ߵ� i ����ȨֵΪ j��
�ܹ�����ת�� log m �Ρ�
ÿ�θ��Ӷ��� nm��
��ʱ�临�Ӷ��� O(nm log m)��
���Թ� 40 �֣�
�ܲ��ܰ� m ��һάѹ�� bitset �С�
������ԣ�
���Ӷ� O(n log m m/w) ���Թ� 60?
�����ǳ˷����Ǻܺ�ת�ơ������� 
֪���߳��֣�������֪�㡣
mad������ 40 min ��������������ˡ�
�����и� SB q �ĸ��Ӷ�û�㡣
cao����������������˵�� 
�ղź���������� m^2 log m �ġ�
���걩�������а�Сʱ�������Ż��� 
�Ҿ��ÿ����� bitset �Ż�һ����
����һ��������һ�� w �Ļᷢ��ʲô��
1,2,3,4,...  -> w,2w,3w,4w.....
����Ҳ���Ǻܺø㡣
�����е���ɡ�
˵ʵ�� w ��һ�����ͼ��������Ա������Ӷ���:
m^log^2m 
���ǱȽ������ˣ���Ҫ����һ��SBѯ�ʴ��������� SB �ռ��С��
�ռ��С�� O n m �ĺܱ��ҡ�
�Ҿ��� 1e4 �϶�Ҫ��һЩ�Ƽ��� 
���ǿ�������� q �������ǿ�����ǰ����Ĺ���
Ҳ������һ�μ�¼һ�δ𰸣��ͱ�֤������� n �Ρ�
������ n m^log^2m 
����û�뵽�Ż���
wtcl��
���Ҳ���봦�� q �ˡ�
������ q m log^2 m
������Ҫ���� 20 pts �Ϳ��ɣ���Ҳ���������ˡ� 
*/
