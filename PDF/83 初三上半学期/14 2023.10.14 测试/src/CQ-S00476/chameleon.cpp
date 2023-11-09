#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
const int N=2e5+10;
void File(){
	freopen("chameleon.in","r",stdin);
	freopen("chameleon.out","w",stdout);
}
int n,k,l;
double ans[N];
struct G{
	int pos,col,dir;
}a[N];
int cmp(G x,G y){
	return x.pos<y.pos;
}
G L[N],R[N];
int cl=0,cr=0;
int main(){
	File();
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++){
		char c;
		int d,b;
		cin>>d>>b>>c;
		if(c=='L'){
			L[++cl]={d,b,1};
		}
		else R[++cr]={d,b,0};//œÚ”“ 
	}
	sort(L+1,L+1+cl,cmp);
	sort(R+1,R+1+cr,cmp);
	for(int i=1;i<=cr;i++){
		ans[R[i].col]+=(l-R[i].pos);
	}
	for(int i=1;i<=cl;i++){
			double las=0;int cc=L[i].col;
			for(int j=cr;j>=0;j--){
				if(R[j].pos>L[i].pos) continue;;
				double now=(double)(L[i].pos-R[j].pos)/2;
				ans[cc]+=(now-las)*1.0;
				las=now;
				cc=(cc+R[j].col)%k;
			}
			if(las!=0){
				ans[cc]+=las;
			}
		
	}
	for(int i=0;i<k;i++){
		printf("%.1f\n",ans[i]);
	}
}
