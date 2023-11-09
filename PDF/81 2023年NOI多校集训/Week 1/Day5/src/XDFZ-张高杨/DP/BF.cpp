#include<bits/stdc++.h>
using namespace std;
const int N=25;
int ans_ord[N],ord[N],ans_tot,ans;
int c[N],n;
void DFS(int i,int sum,int tot,bitset<N> M)
{
	if(i>n)
	{
//		cout<<i<<" "<<sum<<" "<<tot<<" "<<M<<endl; 
		int mex=0;
		while(M[mex])mex++;
		sum+=mex;
		if(sum>ans)
		{
//			printf("update ans %d %d\n",sum,mex);
			ans=sum;
			ans_tot=tot;
			for(int j=1;j<=tot;j++)ans_ord[j]=ord[j];
		}
		return;
	}
	bool t=M[c[i]];
	M[c[i]]=true;
	DFS(i+1,sum,tot,M);
	M[c[i]]=t;
	if(i==1)return;
	int mex=0;
	while(M[mex])mex++;
	ord[++tot]=i;
	M.reset();
	M[c[i]]=true;
	DFS(i+1,sum+mex,tot,M);
	return;
}
int main()
{
	freopen("cut.in","r",stdin);
	freopen("cut.bf","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	bitset<N> M;M.reset();ord[1]=1;
	DFS(1,0,1,M);
//	printf("%d %d\n",ans,ans_tot);
//	for(int i=1;i<=ans_tot;i++)printf("%d ",ans_ord[i]);
	printf("%d",ans);
	return 0;
}
