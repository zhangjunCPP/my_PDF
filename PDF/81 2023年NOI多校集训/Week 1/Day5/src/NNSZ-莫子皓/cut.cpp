/*
����ж�����Ļ������Ǵ���������ͷ�ҵ�β����������ҹ��ľ���
��Ϊ������������һ��Ҳ��mexû�й���
�����ܸо��ֵֹ�
˼��һ�·��� 
��ʱ�벻������������ôд�˰�
�ҵ�������
8
3 3 2 2 1 1 0 0
��Ӧ��
5 2
1 8
��ʵ�����Ϊ 
3 5
1 2 4 6 8
��Ϊ���������ػ�©�������ظ�������
��ʱ����ȥдt1�� 
����ʵ�������֣����Ƿ����ˣ��ø����50'Ҳ���ǲ��� 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,ans,tmp;
int c[N],k=1;
bool s[N],vis[25],flag;
int Find()
{
	for(int i=0;i<=20;i++){
		if(vis[i]==false)
			return i;
	}
	return 21;
}
void solve()
{
	for(int i=2;i<=n;i++){
		flag=false;
		if(vis[c[i]]==true){
			s[i]=true;
			++k;
			ans+=Find();
			memset(vis,false,sizeof(vis));
			vis[c[i]]=true;
			continue;
		}
		vis[c[i]]=true;
	}
}
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	s[1]=true;
	vis[c[1]]=true;
	solve();
	ans+=Find();
	printf("%d %d\n",ans,k);
	for(int i=1;i<=n;i++){
		if(s[i]==true) printf("%d ",i);
	}
	return 0;
}
