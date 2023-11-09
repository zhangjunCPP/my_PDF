//这应该是个dp 
//或许可以记录一下每一种颜色第一次出现的位置  
//dp应该有两维，第一维可能和位置或者段数有关，第二维应该和颜色有关 
//啊啊，想不到 
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
