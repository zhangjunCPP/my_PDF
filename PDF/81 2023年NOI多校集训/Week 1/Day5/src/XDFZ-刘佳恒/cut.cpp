#include<bits/stdc++.h>
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int N=5e5+55;
int n,a[N],f[N];
int t[N<<4];
void bird(int k,int l,int r) {
	if(l==r) { t[k]=( 1<<a[l] ); return ; }
	int mid=( ( l+r )>>1 );
	bird(lson,l,mid);
	bird(rson,mid+1,r);
	t[k]=t[lson] | t[rson] ;
}

int ans;
void ctrl(int k,int l,int r,int x,int y) {
	if(x<=l&&r<=y) { ans=ans|t[k]; return ; }
	int mid=( ( l+r )>>1 );
	if(x<=mid) ctrl(lson,l,mid,x,y);
	if(y>mid) ctrl(rson,mid+1,r,x,y);
} 
int pre[N],tot,cf[N];
bool fd=true;
int main() {
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),fd=( fd&( a[i]<=1 ) );
	if(fd){
		ans=0; cf[++tot]=1;
		for(int i=1;i<=n;i++) {
			if(a[i]==0) {
				cf[++tot]=i,ans++;
				if(a[i+1]==1) ans++,i++;
			}
			else if(a[i]==1) {
				if(a[i+1]==0&&i+1<=n) cf[++tot]=i,ans+=2,i++;
			}
		}
		printf("%d %d\n",ans,tot);
		for(int i=1;i<=tot;i++) printf("%d ",cf[i]);
		return 0;
	}/**/
	bird(1,1,n); pre[0]=-1;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<i;j++) {
			ans=0; ctrl(1,1,n,j+1,i);
			int w=0,cnt=0; bool fl=false;
			/*cout<<i<<" "<<j<<endl;
			while(ans) cout<<ans%2,ans/=2;;
			puts("");
			*/while(ans) {
				if(ans%2==0) { w=cnt; fl=true; break; }
				cnt++; ans>>=1;
			}
			if(!fl) w=cnt;
			//cout<<f[j]+w<<" ";
			//cout<<"i: "<<i<<"  j: "<<j<<"  w: "<<w<<endl;
			if( f[i] < f[j]+w ){
				f[i] = f[j]+w;
				pre[i]=j;
			}/**/
		}
		puts("");
		//cout<<pre[i]<<" ";
	}
	printf("%d ",f[n]);
	for(int i=pre[n];i!=-1;i=pre[i]) cf[++tot]=i+1;
	printf("%d\n",tot);
	for(int i=tot;i;i--) printf("%d ",cf[i]);
	return 0;
}
/*
10
1 0 0 0 1 1 1 0 0 1
*/
