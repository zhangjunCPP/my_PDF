#include<stdio.h>
#include<algorithm>
#include<set>

const int N=5e5+5;
int n,m,a[N];
struct dy{
	int id,ci;
	bool operator<(const dy&y)const{return ci<y.ci;}
};
int num[N];bool f[N];
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		m=std::unique(a+1,a+m+1)-a-1;
	for(int i=1;i<=n;i++){
		std::set<dy> se;
		int ans=0;
		for(int j=1;j<=n;j++) num[j]=f[j]=0;
		for(int j=1;j<=i;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				ans++;
			}
			else{
				se.erase({a[j],num[a[j]]});
			}
			num[a[j]]=j;
			se.insert({a[j],j});
		}
		for(int j=i+1;j<=m;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				if(se.size()==i){
					dy t=*se.begin();
					num[t.id]=f[t.id]=0;
					se.erase(t);
				}
					ans++;
			}
			else{
				se.erase({a[j],num[a[j]]});
			}
			num[a[j]]=j;
			se.insert({a[j],j});
		}
		printf("%d ",ans);
	}
	return 0;
}

