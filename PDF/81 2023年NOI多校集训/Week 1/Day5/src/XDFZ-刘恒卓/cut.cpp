#include<bits/stdc++.h>

using namespace std;
const int N=5e5+10,M=20+5;
int dp[N],pre[N];
int last[M];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int color;
        cin>>color;
        last[color]=i;
        dp[i]=dp[i-1],pre[i]=i;
        int Min=0x3f3f3f;
        for(int j=1;j<=21&&last[j-1];j++){
            Min=min(Min,last[j-1]);
            if(dp[Min-1]+j>dp[i]){
                dp[i]=dp[Min-1]+j,pre[i]=Min;
            }
        }
    }
    vector<int> v;
    for(int now=n;now;v.push_back(pre[now]),now=pre[now]-1);
    printf("%d %zu\n",dp[n],v.size());
    reverse(v.begin(),v.end());
    for(int i: v){
        printf("%d ",i);
    }
    return 0;
}
