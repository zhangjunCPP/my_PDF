#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
const int N=7e5+10;
void File(){
//	freopen("test.in","w",stdout);
}
int a[N],p=998244353;
int main(){
	srand(time(0));
	File();
	int n=600000;
	cout<<n<<endl;
	int cnt=0;
	for(int i=1;i<=n/2;i++){
		a[i]=++cnt;
		a[n-i+1]=++cnt;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
}
