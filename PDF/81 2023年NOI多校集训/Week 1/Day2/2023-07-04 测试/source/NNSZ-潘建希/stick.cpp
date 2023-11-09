#include<bits/stdc++.h>
using namespace std;
int n,m,q,cs,k=1,u;
int f(int b,int a,int c){
	if(b<(a/c+1)*(a/c+1)*c*(c-1)/2)return c;
	return f(b,a,c+1);
}
void js(int sy,int he,int ji,int w){
	if(w==0&&ji==m&&sy==0)u=1;
	if(w==0||sy==0)return;
	else for(int i=1;i<=sy-w+1;i++)js(sy-i,he+i,ji+i*he,w-1);
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		k=1;
		scanf("%d%d",&n,&m);
		if(m==(n*(n-1))/2-1){
			cout<<"1\n";
			continue;
		}
		if(m==0){
			cout<<"1\n";
			continue;
		}
	    if(m==n-1){
	    	cout<<"1\n";
			continue;
		}
		if(m<n-1){
			cout<<"0\n";
			continue;
		}
		if(m>n*(n-1)/2){
			cout<<"0\n";
			continue;
		}
		if(m==n*(n-1)/2){
			cout<<"1\n";
			continue;
		}
		if(m%2){
			for(int j=3;j<=sqrt(m);j+=2)if(m%i==0){k=0;break;}
		}else k=0;
		if(k){
			cout<<"0\n";
			continue;
		}
		cs=f(m,n,2);
		k=1;
		for(int j=0;(cs+j-1)*(n-cs-j+1)+(cs+j)*(cs+j-1)/2<=m&&j+cs<=n;j++){
			u=0;
			js(n,0,0,cs+j);
			if(u){
				cout<<"1\n";
				k=0;
				break;
			}
		}
		if(k)cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
