//我们可以去枚举k
//然后对于每个k，先删除度数<k的点，并把这些点所连的边删除
//重新统计度数， 再进行删除操作，直到无法删除
//剩下的点组成的子图就是G 
//每次求出 G的理论时间复杂度上限为O(n^2) 
//总共的时间应该是n^2多一些 
//但是我们可以从小到大枚举k，把上一次求出的子图G存下来
//下一次就只需要在G上跑删除就可以了
//总共复杂度上限为n^2，但只有在图退化为一条链时才能跑出n^2
//而czc的数据肯定很水，所但是这题是捆绑测试，所以应该只有30分 
//大样例只过了一个 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,N,M,B;
vector<int>f[1000010];
int d[1000010],vis[1000010];
int rt=1,ne[1000010];
void sol1(){
	scanf("%lld%lld%lld%lld%lld",&n,&m,&M,&N,&B);
	int  md=0;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		f[x].push_back(y);
		f[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	for(int i=1;i<=n;i++)md=max(md,d[i]),ne[i]=i+1;
//	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" ";
//	}
//	cout<<endl;
	ne[n]=-1;
	int ans=LONG_LONG_MIN,ansx=0;
	for(int k=0;k<=md;k++){
//		int afl=0;
		while(1){
			int u=rt,la=0,fl=1;
//			cout<<"rt:"<<rt<<"tr";
			while(u!=-1){
//					if(!afl){
//						cout<<"a "<<u<<" "<<d[u]<<" b";
//						afl=1;
//					}
				if(d[u]<k){
					vis[u]=1;
					for(int v:f[u]){
						if(!vis[v])d[v]--;
					}
					if(u==rt)rt=ne[u];
					else{
						ne[la]=ne[u];
					}
					fl=0;
				}
				la=u;
				u=ne[u];
			}
			if(fl)break;
		}
		int x,y,z;
		x=y=z=0;
		int u=rt,la=0;
//		cout<<k<<"     ";
//	afl=0;
		while(u!=-1){
			x++;
			for(int v:f[u]){
				if(!vis[v])y++;
				else z++;
			}
//					if(afl<=5){
////						cout<<"a "<<u<<" "<<d[u]<<" "<<vis[u]<<" b";
//						afl++;
//					}
			la=u;
			u=ne[u];
		}
		y/=2;
//		cout<<x<<" "<<y<<" "<<z<<"  ";
		int sum=M*y-N*x+B*z;
//		cout<<M*y<<" "<<-N*x<<" "<<B*z<<endl;
		if(sum>=ans){
			ans=sum;
			ansx=k;
		}
//		cout<<k<<" "<<sum<<endl;
	}
	cout<<ansx<<" "<<ans<<endl;
}
signed main(){
	freopen("subgraph.in","r",stdin);
//	freopen("ex_data3.in","r",stdin);
	freopen("subgraph.out,","w",stdout);
	sol1();
	return 0; 
}
/* 
3 3
1 1 2
1 2
2 3
3 1
*/
