//���ǿ���ȥö��k
//Ȼ�����ÿ��k����ɾ������<k�ĵ㣬������Щ�������ı�ɾ��
//����ͳ�ƶ����� �ٽ���ɾ��������ֱ���޷�ɾ��
//ʣ�µĵ���ɵ���ͼ����G 
//ÿ����� G������ʱ�临�Ӷ�����ΪO(n^2) 
//�ܹ���ʱ��Ӧ����n^2��һЩ 
//�������ǿ��Դ�С����ö��k������һ���������ͼG������
//��һ�ξ�ֻ��Ҫ��G����ɾ���Ϳ�����
//�ܹ����Ӷ�����Ϊn^2����ֻ����ͼ�˻�Ϊһ����ʱ�����ܳ�n^2
//��czc�����ݿ϶���ˮ��������������������ԣ�����Ӧ��ֻ��30�� 
//������ֻ����һ�� 
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
