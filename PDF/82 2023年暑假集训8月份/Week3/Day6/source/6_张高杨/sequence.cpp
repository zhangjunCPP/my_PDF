/*
B 01����
�üһ�����ǰɣ�
AB������ҳ�ͬһ�����ʣ����ⲻ�Ǹ�����̬��
�������Ⱑ�����ȵ�һ���Ǳ���2^20*20=2e7
�������Һ���û��O(n)��⣩ 
ע�⵽��Ŀ�ǳ�����Ȥ�����������ݷ�Χ����������ֻ��10pts
��ô�������Ӧ����һ��״̬ѹ�����뷨�����Ǻ���Ȼ������ʱ����2^n����ը��
���Ƿֳ����룬����ÿһ�붼��2^20�������кܴ���Ż��ռ�
�������ڵ��ߴ������ˣ��������߸��Ի���2^20�����
�򵥿��Ǻϲ�����ʱ����������Ҫö�ٲſ��Ժϲ����ⲻ��
���Ҿ���ö�٣�����Ҳ��Ҫ��һ��ʽ�ӣ���ǳ�������
�Ȱ�ʽ����������û׼�ǳ�����Ϳ���ֱ�������أ�
�������ģ����ʽ���Ƴ����˾Ϳ���ֱ�ӷ��ν�����������������Ʋ������������������Ҷ��ò���
������ͻȻ��������T1��T2�� Data.ver �� Judge.ver �ǰ� 
���У����棬���Ҹ��ɻ����T1��SPJ��ôд��...
����T2������ݷ�Χ������T1��SPJ����û��д����
���ֻ����в�����ֻ��Judge����ֻ��ҪO(n)���㱾�ʲ�ͬ��������SAM
��SAM...
��һ��������SAM����ȥ...
����������ϴ�����ˣ��ٴ�һ��T4��������200pts��
�����У��ȴ���˵��ʱ�䲻���ˣ��벻�������
*/
#include<bits/stdc++.h>
using namespace std;
const int N=300;
class SAM
{
private:
	int trans[N][2];
	int len[N],link[N];
	int tot,last;
	int cnt[N],a[N],siz[N];
public:
	inline void init(){memset(trans,0,sizeof trans);tot=0,link[0]=-1,last=0;return;}
	inline void emplace(bool c)
	{
		int cur=++tot;
		siz[cur]=1;
		int p=last;
		last=cur;
		len[cur]=len[p]+1;
		while(p&&!trans[p][c])trans[p][c]=cur,p=link[p];
		if(!p&&!trans[p][c]){trans[0][c]=cur,link[cur]=0;return;}
		int q=trans[p][c];
		if(len[q]==len[p]+1){link[cur]=q;return;}
		int clone=++tot;
		memcpy(trans[clone],trans[q],sizeof trans[q]);
		link[clone]=link[q],len[clone]=len[p]+1;
		trans[p][c]=clone;
		while(p&&trans[p][c]==q)trans[p][c]=clone,p=link[p];
		link[cur]=link[q]=clone;
		return;
	}
	inline int sub()
	{
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=tot;i++)cnt[len[i]]++;
		for(int i=1;i<=tot;i++)cnt[i]+=cnt[i-1];
		for(int i=1;i<=tot;i++)a[i]=cnt[len[i]]--;
		int ans=0;
		for(int i=tot;i;i--)
		{
			siz[link[i]]+=siz[i];
			ans+=siz[i];
		}
		return ans;
	}
}zgy;
int ans[N];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<n);i++)
	{
		zgy.init();
		for(int j=0;j<n;j++)zgy.emplace((i>>j)&1);
		int sub=zgy.sub();
		ans[sub>k?k+1:sub]++;
	}
	for(int i=1;i<=k;i++)printf("%d ",ans[k]);
	return 0;
}
