#include<bits/stdc++.h>
#define inf 2e9
using namespace std;
int read(){int s=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^48),c=getchar();return s*f;}
const int N=5e5+10;
/*�۲������𰸷��֣��������ǲ�����(�ðɺ�����Ȼ) 
�����Ҷ��֣�
�����ģ��һ�����ҪO(n^2)��ʱ�临�Ӷ� ����ģ��϶�GG
so...��ʵ�Ҿ�����DP
����һ������k��λ�õ�Ԫ�ضԴ𰸵Ĺ���
C�������
����ģ���������� �Ϳ���ô�Ż�
����һ��ģ�O(n^2)�Ż��ɣ�
ά�����λ�ù�ϵ
*/
int n,m,a[N],lastvis[N],in[N],hav,ans,cnt[N],kind,lastend;
set<int> S;
int solve(int k){
	hav=ans=0,S.clear();
	for(int i=1;i<=n;++i)lastvis[i]=in[i]=0;
	for(int i=1;i<=m;++i){
		if(in[a[i]]){lastvis[a[i]]=i;continue;}
		if(hav<k&&!in[a[i]]){in[a[i]]=1,lastvis[a[i]]=i,++hav,S.insert(a[i]),++ans;continue;}
		int minn=inf,pos=0;
		for(auto j:S)
			if(in[j]&&lastvis[j]<minn)minn=lastvis[j],pos=j;
		in[pos]=0,S.erase(pos),lastvis[a[i]]=i,in[a[i]]=1,S.insert(a[i]),++ans;
	}
	return ans;
}
void add(int pos){
	++cnt[a[pos]];
	if(cnt[a[pos]]==1)++kind;
}
void del(int pos){
	if(!pos)return;
	--cnt[a[pos]];
	if(!cnt[a[pos]])--kind;
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)a[i]=read(),add(i);
	int tmp=kind;
	if(n<=500&&m<=500)
		for(int k=1;k<=n;++k)printf("%d ",solve(k));
	else{
		for(int k=1;k<=tmp;++k){
			for(int i=1;i<=n;++i)cnt[i]=0;
			kind=0,lastend=0,ans=k;
			while(lastend<m&&kind<=k)++lastend,add(lastend);
			if(kind>k)del(lastend),--lastend;
//			cout<<"cc:1 "<<lastend<<" "<<ans<<"\n";
			for(int i=2;i<=m;++i){
				if(lastend==m)break;
				del(i-1);
				if(kind<k){
					++ans;
					while(lastend<m&&kind<=k)++lastend,add(lastend);
					if(kind>k)del(lastend),--lastend;
				}
//				cout<<"cc:"<<i<<" "<<lastend<<" "<<ans<<endl;
			}
			printf("%d ",ans);
		}
		for(int i=tmp+1;i<=n;++i)printf("%d ",ans);
	}
	return 0;
}
