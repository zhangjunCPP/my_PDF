//����ֻ���Ǻڵ�Ĺ���,�׵��2����(��ɫ) 
//�ݳ�ᷢ��ʲô?
//������Pi��ʾ������������Ϊi��Ϳɫ��������,�����ݳⲻ��,ϵ����֪��
//����������*������?
//����...������������.
//��α�֤��ɫ�������������x?
//�ն��˺ڶ˵��,��ɫ�е���ѡͿ,�е��Ǳ�Ϳ 
//emm...���ǵ��ڰױ���һ��>=n/2,һ��<=n/2...����ûʲô���� 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
auto qpow=[](ll p,ll t){ll ret=1;for(;t;t>>=1,p=p*p%mod)if(t&1)(ret*=p)%=mod;return ret;};
int n;
vector<int>G[1000010];
namespace case1{
	int dis[20][20];
	void solve(){
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=1e9;
		for(int i=1;i<=n;i++)for(int v:G[i])dis[i][v]=1;
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ll ans=0;
		for(int s=0;s<(1<<n);s++){
			int tmp=0;
			for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
			if(~((s>>u-1)^(s>>v-1))&1)tmp=max(tmp,dis[u][v]);
			(ans+=tmp)%=mod;
		}
		cout<<ans;
	}
}
namespace taskA{
	//��ʱ����������˵����һ�������������
	void solve(){
		//�ն�1Ϊ�ڷ�ֹ����,����2 
		ll ans=0;
		for(int i=n/2+1;i<n;i++){
			int xpos=n-i+1;
			if(i==xpos)(ans+=(i-1)*2)%=mod;
			else (ans+=qpow(2,i-xpos-1)*(i-1)*3)%=mod; 
		}
		(ans+=(n-1)*qpow(2,n-2))%=mod;
		if(~n&1)(ans+=n/2-1)%=mod;
		cout<<ans*2%mod;
	}
	//д�귢��������������й�?
	//����������˵������ֱ���˵㴦,��ôֱ�����Ѿ������ǳ��� 
	//�����ڶ���ֱ����𰸱�Ϊֱ���� 
}
namespace taskB{
	void solve(){cout<<qpow(2,n)*2%mod;}
}
namespace taskinf{
	struct bfs{
		vector<int>dis;
		int mxver,mxcnt;
		bfs(int s):dis(n+5,-1){
			dis[s]=0;static int q[1000010];
			for(int i=0,tp=0,u=s;i<=tp;u=q[++i])
			for(int v:G[u])if(dis[v]==-1)dis[v]=dis[u]+1,q[++tp]=v;
			mxver=max_element(begin(dis),end(dis))-begin(dis);
			mxcnt=count(begin(dis),end(dis),dis[mxver]);
		}
	};
	int len;
	void solve(){
		int A=bfs(1).mxver,B=bfs(A).mxver;
		auto Adis=bfs(A),Bdis=bfs(B);len=Adis.dis[B];
		if(Adis.mxcnt>1||Bdis.mxcnt>1){cout<<qpow(2,n)*len%mod;return;}
		ll ans=qpow(2,n-2)*len;//ֱ���˵�ͬɫ 
		//�������ǵó�2
		vector<vector<int>>nodea(n+5),nodeb(n+5);
		for(int i=1;i<=n;i++)nodea[Adis.dis[i]].push_back(i),nodeb[Bdis.dis[i]].push_back(i);
		unordered_set<int>ableA,ableB;//able�е��κ�һ����Ⱦ�ɺͶ�Ӧ�˵�ͬɫ������,�����������able�н�����ֱ�ӳɹ�,�����ֻ��1�����ʧ�� 
		for(int i=len-1,com=0;i;i--){//ת��Ϊ���ٵķ�������� 
			for(int x:nodea[i])ableA.insert(x),com=com||ableB.count(x);//x!=B
			for(int x:nodeb[i])ableB.insert(x),com=com||ableA.count(x);//x!=A
			if(com)(ans+=qpow(2,n-2))%=mod;
			else if(!ableA.empty()||!ableB.empty()){
				int sum=(int)ableA.size()+(int)ableB.size();
				(ans+=qpow(2,n-2-sum)*(qpow(2,sum)-1))%=mod;
			} 
		}cout<<ans*2%mod;//ţ��,һ��ɹ� 
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	bool flagA=true;
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u),flagA=flagA&&abs(u-v)==1;
//	if(n<=10){case1::solve();return 0;}
//	if(flagA){taskA::solve();return 0;}
//	if((int)G[1].size()==n-1){taskB::solve();return 0;}
	taskinf::solve();
	return 0;
}
