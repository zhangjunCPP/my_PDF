//�Ҳ�������ǰ������һ�κ��м�����һ��
//ǰ��һ�θ�������ƽ����,��һ�θ����ռ�����
//��ô��һ�ο϶��Ƕ���ƽ������
//*,ûʱ����,����,����!
//��ô����ǰ����һ��,Ȼ�������ǰ����һ��
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[1000010];
ll s[1000010];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<n;i++)if(a[i]!=a[i+1]){
		int l=i,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(a[i]*1ll*mid>=s[mid])l=mid;
			else r=mid-1;
		}ans=max(ans,l-i+(a[i]*1ll*l>s[l]));
	}cout<<ans;
	return 0;
}
