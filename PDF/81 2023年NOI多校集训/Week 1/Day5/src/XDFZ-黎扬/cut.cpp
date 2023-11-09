#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void work(int k){
	if(k<0){
		putchar('-');
		k=-k;
	}
	if(k>9)
		work(k/10);
    putchar(k%10+'0');
}
//令dp[i]为前i个最大美丽值
//dp[i]=max{dp[j]+mex(a[j+1]...a[i])}
//因为0<=a[i]<=20,并且mex值随j增长不增,所以最多有21段mex值相同的区间,同时dp[i]单调不降,我们只需考虑最右边的一个就可以了
//考虑如何快速求出这些区间,二分一下即可,时间复杂度O(n*21*logn*21),极限数据4e9,够呛,www
//虽然实际情况肯定跑不满,但是也优化不到这么多
int n,a[500005],dp[500005],cnt[25],sum,num[25],cnt1[500005][25],pre[500005],flag,ans;
stack<int> q;
queue<int> p;
bool check(int now,int mid,int val){
    for(int i=0;i<val;i++){
        if(!(cnt1[now][i]-cnt1[mid-1][i]))
            return 0;
    }
    return 1;
}
int main(){
	freopen("cut.in","r",stdin);
    freopen("cut.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        if(a[i]>1)
            flag=1;
    }
    if(!flag){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                p.emplace(i);
                i++;
                ans+=2;
            }
            else{
                p.emplace(i);
                ans+=(!a[i]);
            }
        }
        work(ans);
        putchar(' ');
        work(p.size());
        putchar('\n');
        while(!p.empty()){
            work(p.front());
            putchar(' ');
            p.pop();
        }
    }
    else if(n<=10000){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
            sum=-1;
            for(int j=0;j<=21;j++){
                num[j]=cnt[j];
                if(!num[j]&&sum==-1)
                    sum=j;
            }
            for(int j=0;j<i;j++){
                if(dp[i]<=dp[j]+sum){
                    dp[i]=dp[j]+sum;
                    pre[i]=j;
                }
                // if(!sum)
                //     break;
                num[a[j+1]]--;
                if(a[j+1]<sum&&!num[a[j+1]])
                    sum=a[j+1];
            }
        }
        work(dp[n]);
        int now=pre[n];
        while(now){
            q.emplace(now+1);
            now=pre[now];
        }
        putchar(' ');
        work(q.size()+1);
        putchar('\n');
        work(1);
        putchar(' ');
        while(!q.empty()){
            work(q.top());
            putchar(' ');
            q.pop();
        }
    }
    else{
        for(int i=1;i<=n;i++){
            cnt1[i][a[i]]++;
            sum=-1;
            for(int j=0;j<=21;j++){
                cnt1[i][j]+=cnt1[i-1][j];
                if(!cnt1[i][j]&&sum==-1)
                    sum=j;
            }
            int last=1,l,r;
            while(sum){
                l=last,r=i+1;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(i,mid,sum))
                        l=mid+1;
                    else
                        r=mid;
                }
                if(dp[i]<dp[l-2]+sum){
                    dp[i]=dp[l-2]+sum;
                    pre[i]=l-2;
                }
                sum=a[l-1];
                last=l;
            }
        }
        work(dp[n]);
        int now=pre[n];
        while(now){
            q.emplace(now+1);
            now=pre[now];
        }
        putchar(' ');
        work(q.size()+1);
        putchar('\n');
        work(1);
        putchar(' ');
        while(!q.empty()){
            work(q.top());
            putchar(' ');
            q.pop();
        }
    }
	return 0;
}