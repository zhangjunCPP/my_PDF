/*
t2
Ҫʹ �ϸ�>S��ƽ���� ��������������
���ǲ������Ƕ����е�S���¼���һ���������ʲô���
�������<S��ƽ����������������S��ƽ������С���Դ���Ȼ����
������ڣ����Ӱײ���
������ڣ�����𰸴���1�Ĺ��ף���������ƽ����

���ԣ����������¼��ֿ��ܵ�˼·��
1.dp
2.����
3.̰��

��˵̰��
���ǿ���ȫѡ
��ʱ����һ��ƽ����s
��Ȼ�����ǲ���ɾ����ƽ����С������
��ˣ�����ÿ��ɾ��������

д�����ˣ�����Ҳ����
��˵ʵ���е㲻���� 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,i,a[N],ans,sum;
ll calc(ll x){//>=x
	ll l=1,r=n,res=-1;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(a[mid]>=x)res=n-mid+1,r=mid-1;
		else l=mid+1;
	}
	return res;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%lld",&n);
	for(i=1;i<=n;++i)scanf("%lld",a+i),sum+=a[i];
	sort(a+1,a+1+n);
	for(;n;--n){
		ans=max(ans,calc(sum/n+1));
		sum-=a[n];
	}
	printf("%lld",ans);
	return 0;
}
