//ά����һ������ջ,���Ի��ܵ�����ǰ׺���ֵ�ĸ���
//̰�ĵ����ô�ľ������õ���Ļ�����(�Ͼ��ܻ�����=n-1)
//����v��һ��Ļ��i����С��ȫ����
//v�ڶ����:1.��v��һ�����,����;2.ǰ��,Ҳ�Ǿ����ܶ���
//����DP��:
//       ��x 
//       |
//a b ........ k
//��ֵΪ:bx+a
//dpi=max(ai-1 + (k-i)ai);
//�ȵȹ�,һ�����������������?
//Ӧ���ǳ�vС�ĲŶ԰�
//����Ե���ǰxС,��ô???
//���1��v���,��ô�϶���1����
//����,���2��v���,Ӧ��2������������1��2
//����,���3��v���,Ӧ��3���������ٿ�v1,v2:v1>v2Ӧ����v1����2,3,������Ե�
//����,���4��v���,Ӧ��4���������ٿ�
//���԰��ⲻ�Ǻ�һ��ʼ��Ĳ���һ����???
//�ղž���û��ø㷨...��ʵ��Ҫ���Ե��ڵ��´�һ���Ϳ���
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
int n,a[200010],b[200010];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=i;
	ll ans=0;
	deque<int>res;
	sort(b+1,b+n+1,[](int x,int y){return a[x]>a[y];});
	for(int i=1,las=n+1;i<=n;i++)
	if(b[i]<las){
		int p=b[i];
		ans+=(min(las,n)-p)*1ll*a[p];
		for(int j=las-1;j>p;j--)res.push_front(j);
		res.push_back(p),las=p;
	}cout<<ans<<endl;
	for(int x:res)printf("%d ",x);
	return 0;
}
