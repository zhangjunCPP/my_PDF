//ֱ�Ӹ�Ҫ��
//�϶�����ʲô̰�ĵ�����...��?
//�����Ǽ���,��ô����һ����ʣ�������������
//��μ������?
//����ʹ���߲�ֵ��abs��С
//dp(8:25)
//8:43������
//8:46:�ȵȹ�dp�ǶԵ���
//�����Ҫ��s�ļ�����С��һ��Ҫ���Ӽ��ļ�����С��..
//���� 1 1 1 1 1 5
//�Ǿ���Ҫ��ѭĳ��̰��
//ä������
//������Ȼ,������(8:48) 
//������(9:46)
//��զ�᲻զ��
//д����д���� 
//10:05:����3^n��д����
//ȥ������Ȼ�뵽�᲻�������ԭ���й�:������,����һ�˴��ڵ���ceil(sum/3),����һ��С�ڵ���floor(sum/3)
//������������һ�������
//��ôһ����3!/3^25�ĸ��ʳɹ�
//��2^25����?����û����ɹ�...
//���������������������.��Ȼû������
//��ʲô1-c/2^25�ɹ��ʵķ�����?
//ȷ��һ������?������...
//������ֱ������
//������ֱ����(10:42) 
#include<bits/stdc++.h>
using namespace std;
int n,a[30];
namespace task11{
	int sum[1<<15];
	void solve(){
		for(int s=0;s<(1<<n);s++)
		for(int i=1;i<=n;i++)if(s>>i-1&1)sum[s]+=a[i];
		int s0=0,s1=0,s2=0,ans=2e9,U=(1<<n)-1;
		for(int s=0;s<(1<<n);s++)
		for(int s_=U^s;s_;s_=s_-1&(U^s)){
			int s__=U^s^s_,
			dif=max({sum[s],sum[s_],sum[s__]})-
				min({sum[s],sum[s_],sum[s__]});
			if(dif<ans)ans=dif,s0=s,s1=s_,s2=s__;
		}
		for(int i=1;i<=n;i++,putchar(' ')){
			if(s0>>i-1&1)putchar('1');
			else if(s1>>i-1&1)putchar('2');
			else putchar('3');
		}
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n<=15)return task11::solve(),0;
	return 0;
}
