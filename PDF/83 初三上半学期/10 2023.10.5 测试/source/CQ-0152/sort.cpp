#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
const int N=7e5+10;
void File(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
}
int n;
vector<int>a;
int cnt=0;
int c[N],cc[N];
int A[N];
int pos[N];//记录对应权值的位置 
int find(int l,int r,int x,int y){
	//第一个属于这个区间的数
	int	mid;
	int poss;
	while(l<=r){
		mid=(l+r)>>1;
		if(A[mid]<=y&&A[mid]>=x){
			poss=mid;
			r=mid-1;
		}
		else l=mid+1;
	} 
	return poss;
}
void solve(int len,vector<int>b,int x,int y){
	if(len<=1) return;
//	for(int i:b) cout<<i<<' ';
//	cout<<endl;
//	cout<<len<<endl;
	vector<int>c,cc;
	int cmp=b[(len-1)/2];
	int tot=0,tot2=0;
	for(int i=0;i<len;i++){
		cnt++;
		if(b[i]<cmp) c.pb(b[i]);
		if(b[i]>cmp) cc.pb(b[i]);
	}
	solve(c.size(),c,x,cmp-1);
	solve(cc.size(),cc,cmp+1,y);
}
void ssolve(int x,int y){
	//l,r位置   x,y权值
	int len=(y-x+1);
	if(len<=1) return;
	cnt+=len;
	int L=1;
	for(int i=1;i<(len+1)/2;i++){
		L=find(L,n,x,y)+1;
	}
	L=find(L,n,x,y);
//	cout<<L<<' ';
//	cout<<x<<' '<<y<<endl;
	ssolve(x,A[L]-1);
	ssolve(A[L]+1,y);
}
//维护中位数
 
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	File();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pos[x]=i;
		a.pb(x);
		A[i]=x;
	}
//	cout<<n<<endl;
//	cout<<find(2,5,1,4);
	solve(n,a,1,n); 
	cout<<cnt;
}
