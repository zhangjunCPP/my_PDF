#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
const int N=5e5+5;
int n,m,a[N];
int tim[N],in[N];
int solve(int k){
	int last=1,cnt=0;
	for(int i=1;i<=n;i++)tim[i]=in[i]=0;
	for(int i=1;i<=m;i++){
		if(in[a[i]]){tim[a[i]]=i;continue;}
		if(cnt++<k){tim[a[i]]=i,in[a[i]]=1;continue;}
		while(!in[a[last]]||tim[a[last]]!=last)last++;
		in[a[last]]=0,tim[a[i]]=i;in[a[i]]=1;
	}return cnt;
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=rd(),m=rd();for(int i=1;i<=m;i++)a[i]=rd(); 
	for(int i=1;i<=n;i++)printf("%d ",solve(i));
	cout<<endl;
	return 0;
}

