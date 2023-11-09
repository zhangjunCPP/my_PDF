#include<bits/stdc++.h>
using namespace std;
int k,x,y,dx[5]={1,1,-1,-1},dy[5]={1,-1,1,-1};
vector <pair<int,int> > ans;
int dis(int a,int b){
	return abs(a-x)+abs(b-y);
}
bool check(){
	int a=0,b=0,k1=k/2,k2=(k+1)/2;
	if(dis(a,b)<k){
		if(x>0&&y>0){while(dis(a,b)<k) a-=k1,b-=k2,ans.push_back({a,b});}
		else if(x>0&&y<0){while(dis(a,b)<k) a-=k1,b+=k2,ans.push_back({a,b});}
		else if(x<0&&y>0){while(dis(a,b)<k) a+=k1,b-=k2,ans.push_back({a,b});}
		else if(x<0&&y<0){while(dis(a,b)<k) a+=k1,b+=k2,ans.push_back({a,b});}
	}
	while(dis(a,b)!=k){
		int lst=dis(a,b);
		for(int i=0;i<=3;i++){
			int fa=a+dx[i]*k1,fb=b+dy[i]*k2;
			if(lst>dis(fa,fb)&&dis(fa,fb)>=k){
				a=fa,b=fb,ans.push_back({a,b});
				goto again;
			}
		}
		for(int i=0;i<=3;i++){
			int fa=a+dx[i]*k2,fb=b+dy[i]*k1;
			if(lst>dis(fa,fb)&&dis(fa,fb)>=k){
				a=fa,b=fb,ans.push_back({a,b});
				goto again;
			}
		}
		return false;
		again:;
	}
	for(auto i:ans) printf("%d %d\n",i.first,i.second);
	printf("%d %d",x,y);
	return true;
}
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	
	scanf("%d%d%d",&k,&x,&y);
	if(!check()) printf("-1");
	return 0;
}
