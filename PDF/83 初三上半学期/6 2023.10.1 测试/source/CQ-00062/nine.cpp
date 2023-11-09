#include<bits/stdc++.h>
using namespace std;
int rd(int x=0){scanf("%d",&x);return x;}
int k,x,y,ok,step;
vector<pair<int,int> > se;
void dfs(int h,int w,int s){
	if(ok)return;
	if(s)se.push_back({h,w});
	if(h==x&&w==y){
		ok=1;
		cout<<s<<endl;
		for(auto id:se)cout<<id.first<<' '<<id.second<<endl;
		return;
	}if(s>=step){se.pop_back();return;}
	if(s+(abs(h-x)+abs(w-y))/k>step){se.pop_back();return;}
	for(int i=-k;i<=k;i++){
		if((long long)h+i>(long long)INT_MAX)continue;
		if((long long)w+k-abs(i)<=(long long)INT_MAX)
		dfs(h+i,w+k-abs(i),s+1);
		if((long long)w-k+abs(i)<=(long long)INT_MAX)
		dfs(h+i,w-k+abs(i),s+1);
	}
	se.pop_back();
}
int main(){
	freopen("nine.in","r",stdin);
	freopen("nine.out","w",stdout);
	k=rd(),x=rd(),y=rd();
	if(k%2==0&&(x+y)%2!=0){
		puts("-1");
		return 0;
		
	}
	/*for(int i=1;i*i<=k;i++){
		if(k%i==0){
			if((x+y)%i!=0){
				puts("-1");
				return 0;
			}if((x+y)%(k/i)!=0){
				puts("-1");
				return 0;
			}
		}
	}*/
	for(;!ok&&ok<=20;step++)se.clear(),dfs(0,0,0);
	if(!ok)puts("-1");
	return 0;
}
