#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,q;
int a[maxn];
int cnt[maxn];
set< pair<int,int> > st;
inline void INSERT(int i){
	bool flag=0;
	auto it=st.lower_bound({a[i],0});
	if(it!=st.end()){
		pair<int,int> now=(*it);
		if(now.first==a[i]+1){
			now.first--;
			st.erase(it);
			st.insert(now);
			flag=1;
		}
	}
	it=st.lower_bound({a[i],0});
	if(it!=st.begin()){
		it=prev(it);
		pair<int,int> now=(*it); 
		if(now.second+1==a[i]){
			if(!flag){
				now.second++;
				st.erase(it);
				st.insert(now);
			} 
			else{
				it=st.erase(it);
				now.second=(*it).second;
				st.erase(it);
				st.insert(now);
			}
			flag=1;
		}
	}
	if(!flag){
		st.insert({a[i],a[i]});
	}
}
inline void ERASE(int i){
	auto it=st.upper_bound({a[i],n+1});
	it=prev(it);
	pair<int,int> now=(*it);
	st.erase(it);
	pair<int,int> now2={now.first,a[i]-1};
	pair<int,int> now3={a[i]+1,now.second};
	if(now2.first<=now2.second) st.insert(now2);
	if(now3.first<=now3.second) st.insert(now3);
}
inline void print(){
	cout<<"czc:"<<endl;
	for(auto v:st){
		cout<<v.first<<" "<<v.second<<endl;
	}
	cout<<endl;
}
inline void solve1(){
	while(q--){
		int k;
		int ans=0;
		scanf("%d",&k);
		memset(cnt,0,sizeof cnt);
		st.clear();
		for(int i=1;i<=k;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]==1){
				INSERT(i);		
			}
		}
		if((*st.begin()).first==0) ans=((*st.begin()).second+1);
		for(int r=k+1,l=1;r<=n;l++,r++){
			if(a[r]==a[l]) continue;
			cnt[a[r]]++;
			if(cnt[a[r]]==1) INSERT(r);
			cnt[a[l]]--;
			if(!cnt[a[l]]) ERASE(l);
			if((*st.begin()).first==0) ans=max(ans,(*st.begin()).second+1);
		}
		printf("%d\n",ans);
	}
}
int R[maxn][11],ANS[11];
inline void solve2(){
	memset(ANS,0x3f,sizeof ANS);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10;j++){
			if(a[i]==j) R[i][j]=i;
			else R[i][j]=n+1;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<=10;j++){
			R[i][j]=min(R[i+1][j],R[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int len=0;
		for(int j=0;j<=10;j++){
			if(R[i][j]>n) break;
			len=max(len,R[i][j]-i+1);
			ANS[j]=min(ANS[j],len);
		}
	}
	while(q--){
		int k;
		scanf("%d",&k);
		int ans=-1;
		while(ans<10 && ANS[ans+1]<=k) ans++;
		printf("%d\n",ans+1); 
	}
}
int main(){
//	freopen("czc.txt","r",stdin);
//	freopen("czc.out","w",stdout);
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout); 
//	int x=clock();
	scanf("%d",&n);
	bool f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>10) f=0;
	}
	scanf("%d",&q);
	if(f) solve2();
	else solve1();
//	cout<<clock()-x<<endl;
	return 0;
}
/*
前 50 暴力，对于每次询问随便用个数据结构都能维护一下，如分块+bitset。
也不是特别好维护。 
20 处理每个答案的最少区间。 
直接磕正解。
应该和 Subtask 3有关系，也没有多大关系。
mex 运算很烦。
虽然具有单调性，但没什么用。
应该会是一道数据结构题。
也不一定，只给了 128 MB。
最开始预处理是不是一个调和级数，n log n * 单次操作 呀。
震惊！我想多了是 n*(n+1)/2 ，没有调。
MM生的，这题好恶心。
首先必须的快速回答查询，和简洁的预处理。
所以枚举区间不科学。
对于每个答案二分一次区间大小。
具有单调性，所以变成了一个判定问题。
能否预处理出每个点到达某个值时的最小区间。
是可以线性倒推的，但是这就 n^2 了。
对于 a_i<=10 能推。
MD 我不做了。
值域大的和狗一样。
a_i<=10 的又伪了。//没有 
也极大可能会放 n^2 / w 的做法。
其实如果能想出 qn 的做法，相当于成功一半了。
如果直接是 qn^2 的，瓶颈在于维护值。
用一个链表维护值。
其实也类似与并查集。
说实话，用set挺好维护的：
复杂度 q n long n。
 
*/ 
