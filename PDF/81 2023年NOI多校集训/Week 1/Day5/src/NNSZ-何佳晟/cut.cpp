//��Ӧ���Ǹ�dp 
//������Լ�¼һ��ÿһ����ɫ��һ�γ��ֵ�λ��  
//dpӦ������ά����һά���ܺ�λ�û��߶����йأ��ڶ�άӦ�ú���ɫ�й� 
//�������벻�� 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500005,INF=1e9,mod=1e9+7;
int _;
int n;
int a[maxn];
bool ans[maxn];
int fir[20];

int main(){
	ios::sync_with_stdio(0);
	freopen("cut.in","r",stdin); 
	freopen("cut.out","w",stdout); 
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=0;
	}
	a[n+1]=-1;
	if(f){
		ans[1]=1;
		int s=0,d=0;
		for(int i=1;i<=n;i++){
			if((a[i]==1 and a[i+1]==0) or (a[i]==0 and a[i+1]==1)){
				ans[i]=1;
				d++;
				s+=2;
				i++;
				
			}
			else {
				ans[i]=1;
				d++;
				s+=(a[i]==0);
			}
		}

		cout<<s<<" "<<d<<endl;
		for(int i=1;i<=n;i++){
			if(ans[i])cout<<i<<" ";
		}
		return 0;
	}
	cout<<0<<" "<<0<<endl;
    return 0 ^ _ ^ 0;
}
