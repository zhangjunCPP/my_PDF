#include<bits/stdc++.h>
using namespace std;
int n,k,L;
const int maxn=1e5+5;
struct node{
	int b,d,op;
}a[maxn];
char op[5];
inline bool cmp(node x,node y){
	return x.d<y.d;
}
double ans[45];
double sum[45][45],sum2[45][45];
deque<int> st;
int main(){
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].d,&a[i].b);
		scanf("%s",op);
		if(op[0]=='D'){
			a[i].op=0;
		}
		else{//右 
			a[i].op=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
//		cout<<a[i].op<<" "<<a[i].d<<" "<<a[i].b<<endl; 
		if(!a[i].op){
			ans[a[i].b]+=(double)L-(double)a[i].d;
			for(int j=0;j<k;j++){
				for(int g=0;g<k;g++){
					sum2[j][g]=sum[(a[i].b+j)%k][g];
				}
			}
			if(st.empty()){
				for(int j=0;j<k;j++){
					sum2[j][(a[i].b+j)%k]+=(double)(a[i].d)/2.0;
//					if(j==1) cout<<sum2[j][(a[i].b+j)%k]<<" czc:\n";
				}
			}
			else{
				for(int j=0;j<k;j++){
					sum2[j][(a[i].b+j)%k]+=(double)a[i].d/2.0-(double)a[st.back()].d/2.0;
				}
			}
			st.push_back(i);
			for(int j=0;j<k;j++){
				for(int g=0;g<k;g++){
					sum[j][g]=sum2[j][g];
				}
			}
		}
		else{
			for(int j=0;j<k;j++){
				ans[j]+=sum[a[i].b][j];
			}
			if(st.empty()){
				ans[a[i].b]+=(double)a[i].d;
			}
			else{
				ans[a[i].b]+=((double)a[i].d-(double)a[st.back()].d)/2.0;
			}
		}
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ans[i]);
	}
	return 0;
}
/*
T2为什么也这么恶心。
我T2总该去拿点分吧。
就算我之前的不挂，现在也才168。
我再拿个40就能上200了。
我T3打12pts
我T4就需要20pts。
不能想象成直接对饮穿过去的模型。
不，可以。
这样变化的颜色就是相当于向右走的颜色不变，想左走的颜色变成 (a+b)%k
然后就可以 n^2 统计了。
直接做其实可以过2个档。
但是我觉得我行了，我能切掉他。
k 尼玛小的离谱
那还说什么。
说明我的a只有40种变化。
当向右走的颜色只有一种时，我们可以直接算出后面
我悟了，对于每个更新一次b，我直接维护a为什么的时候的对应的贡献即可。
因为a只和最前面的b有关。
那就相当于他们的路程差。
反正就能过了。 
*/ 
