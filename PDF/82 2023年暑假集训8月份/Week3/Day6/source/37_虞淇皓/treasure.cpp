#include<bits/stdc++.h>
using namespace std;
//bool st;
const int N=30;
int n,a[N],b[10000010],ans[N],s,mn=1e9;
int c[N],d[N],st;
//bool ed;
pair<int,int>w[N]; 
int h(int s1,int s2,int s3){
	if(s1<s2){swap(s1,s2);}
	if(s2<s3){swap(s2,s3);}
	if(s1<s2){swap(s1,s2);}
	int x=s-s1-s2-s3-(s2-s3);
	int fl=(x&1);x/=2;
	if(s1>s2+x)return s1-(s2+x);
	return ((x*2+fl-2*(s1-s2))%3!=0);
}
void dfs(int u,int s1,int s2,int s3){
	if(time(0)-st>=3)return;
	if(u>n){
		if(max({s1,s2,s3})-min({s1,s2,s3})<mn){
			mn=max({s1,s2,s3})-min({s1,s2,s3});
			for(int i=1;i<=n;i++){
				d[i]=c[i];
			}
		}
		return ;
	}
	if(ans[u]){
		c[u]=ans[u];
		dfs(u+1,s1,s2,s3);
		return;
	}
	if(h(s1,s2,s3)>mn)return;
	c[u]=1;
	dfs(u+1,s1+a[u],s2,s3);
	c[u]=2;
	dfs(u+1,s1,s2+a[u],s3);
	c[u]=3;
	dfs(u+1,s1,s2,s3+a[u]);
}
void sol1(){
	st=time(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]=b[a[i]]/3*3;
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]){
			ans[i]=b[a[i]]%3+1;
			s-=a[i];
			b[a[i]]--;
		}
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(!ans[i]){
			w[++tot]=make_pair(a[i],i);
		}
	}
	sort(w+1,w+tot+1);
	int sx[3];
	for(int i=1;i<=tot;i++){
		d[w[i].second]=i%3+1;
		sx[i%3]+=w[i].first;
	}
	mn=max({sx[0],sx[1],sx[2]})-min({sx[0],sx[1],sx[2]});
	dfs(1,0,0,0);
	for(int i=1;i<=n;i++){
		printf("%d ",d[i]);
	}
}
int mx[2],mi[2],fh[10];
void dfs2(int u,int s1,int s2,int s3,int up){
	if(u>up){
		if(max({s1,s2,s3})-min({s1,s2,s3})<mn){
			mn=max({s1,s2,s3})-min({s1,s2,s3});
			if(up!=n){
				if(s1==max({s1,s2,s3}))mx[0]=1;
				if(s2==max({s1,s2,s3}))mx[0]=2;
				if(s3==max({s1,s2,s3}))mx[0]=3;
				if(s1==min({s1,s2,s3}))mi[0]=1;
				if(s2==min({s1,s2,s3}))mi[0]=2;
				if(s3==min({s1,s2,s3}))mi[0]=3;
			}
			else{
				if(s1==max({s1,s2,s3}))mx[1]=1;
				if(s2==max({s1,s2,s3}))mx[1]=2;
				if(s3==max({s1,s2,s3}))mx[1]=3;
				if(s1==min({s1,s2,s3}))mi[1]=1;
				if(s2==min({s1,s2,s3}))mi[1]=2;
				if(s3==min({s1,s2,s3}))mi[1]=3;
			}
			for(int i=1;i<=n;i++){
				d[i]=c[i];
			}
		}
		return ;
	}
	if(ans[u]){
		c[u]=ans[u];
		dfs2(u+1,s1,s2,s3,up);
		return;
	}
	if(h(s1,s2,s3)>mn)return;  
	c[u]=1;
	dfs2(u+1,s1+a[u],s2,s3,up);
	c[u]=2;
	dfs2(u+1,s1,s2+a[u],s3,up);
	c[u]=3;
	dfs2(u+1,s1,s2,s3+a[u],up);
}
bool dfs3(int u,int sd,int id,int up){
	if(u>up){
		if(sd==0){
			for(int i=1;i<=up;i++){
				if(c[i]==id){
					d[w[i].second]=id;
				}
			}
			return 1;
		}
		return 0;
	}
	if(w[u].first>sd||c[u])return dfs3(u+1,sd,id,up);
	c[u]=id;
	if(dfs3(u+1,sd-w[u].first,id,up)){
		return 1;
	}
	c[u]=0;
	if(dfs3(u+1,sd,id,up))return 1;
	return 0;
}
void sol2(){
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]=b[a[i]]/3*3;
	}
	for(int i=1;i<=n;i++){
		if(b[a[i]]){
			ans[i]=b[a[i]]%3+1;
			s-=a[i];
			b[a[i]]--;
		}
	}
	if(s%3==0){
//		cout<<s<<endl;
		int sd=s/3;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!ans[i]){
				w[++tot]=make_pair(a[i],i);
			}
		}
		sort(w+1,w+tot+1);
		for(int i=1;i*2<=tot;i++){
			swap(w[i],w[tot-i+1]);
		}
		bool qw1=dfs3(1,sd,1,tot);
		bool qw2=dfs3(1,sd,2,tot);
		bool qw3=dfs3(1,sd,3,tot);
		if(qw1&&qw2&&qw3){
//			cout<<"a";
			for(int i=1;i<=n;i++){
				if(ans[i])cout<<ans[i]<<" ";
				else cout<<d[i]<<" ";
			}
			return;
		}
	}
	int mid=n/2;
	dfs2(1,0,0,0,mid);
	dfs2(mid+1,0,0,0,n);
	fh[mx[1]]=mx[0];
	fh[mi[1]]=mi[0];
	int x=0,y=0;
	for(int i=1;i<=3;i++){
		if(i!=mx[0]&&i!=mi[0])x=i;
		if(i!=mx[1]&&i!=mi[1])y=i;
	}
	fh[y]=x;
	for(int i=mid+1;i<=n;i++){
		if(!ans[i]){
			d[i]=fh[d[i]];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",d[i]);
	}
}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d",&n);
	if(n<=15)sol1();
	else sol2();
	return 0;
}
/*
13
1 1 4 5 1 4 1 9 1 9 8 1 0
1 3 3 2 3 1 2 2 3 1 3 1 1
*/

