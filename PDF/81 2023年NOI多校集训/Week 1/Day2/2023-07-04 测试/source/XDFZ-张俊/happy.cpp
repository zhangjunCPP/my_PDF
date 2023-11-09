//
// Created by zhang_jun on 2023/7/4.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int t[1000000];
int num[1000000],cost[1000000];
int sum[1000000];
int one;
void dfs(int dep,int to,int money,int time){
    if(dep==to){
        if(t[dep]<=time) sum[dep]=min(sum[dep],money);
        else sum[dep]=min(sum[dep],money+one);
        return;
    }
    if(money>sum[to]) return;
    if(t[dep]<=time) dfs(dep+1,to,money,time);
    else{
        for(int i=1;i<=k;i++){
            int tot=0;
            int tmp=t[dep]+num[i]-1;
            for(int j=dep;j<=to;j++){
                if(t[j]<=tmp) tot++;
                else break;
            }
            if(one*tot>cost[i]) {
                dfs(dep+1,to,money+cost[i],tmp);
            }
        }
        dfs(dep+1,to,money+one,0);
    }
    return;
}
signed main(){
    freopen("happy.in","r",stdin);
    freopen("happy.out","w",stdout);
    for(int i=0;i<1000000;i++) sum[i]=LLONG_MAX;
    sum[0]=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=k;i++){
        cin>>num[i]>>cost[i];
    }
    cin>>one;
    if(k==0){
        for(int i=1;i<=n;i++) cout<<one<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++) dfs(1,i,0,0);
    for(int i=1;i<=n;i++) cout<<sum[i]-sum[i-1]<<"\n";
}