/*
我怎么感觉题目顺序有点怪
看到这道题
n条直线，能组成几个交点？
1：0
2：0,1
3：0,1,2,3
4：0,1,3,4,5,6
5：0,1,4,5,7,8,9,10 
由此我们可以发现规律：
i根木棒能摆出的交点数为：0,1,i-1的所有方案+i-1
注意，1根木棒只能取0
 
好吧题目不对头
不存在三条以上木棒交于一点的情况
也就是说，新来的木棒一定会和之前所有的木棒都产生一个交点
除非平行 
因此重新打表
1：0
2：0,1
3：0,2,3
4：0,3,4,5,6
5：0,4,6,7,8,9,10
由此得出规律
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >a[501];//0存数，1存平行数 
int i,j,k;
int find(int i,int x){
	int l=0,r=a[i].size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[i][mid].first<x)l=mid+1;
		else if(a[i][mid].first>x)r=mid-1;
		else return mid;
	}
	return -1;
}
void prework(int n){
	a[0].push_back({0,0});
	for(i=1;i<=n;++i){//i是层数 
//		printf("size[%d]=%d\n",i-1,a[i-1].size());
		for(j=i;j;--j){//j是平行数 
			int siz=a[i-j].size(),l=0,r=siz-1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[i-j][mid].second>j)l=mid+1;
				else k=mid,r=mid-1;
			}
			for(k=siz-1;~k;--k){
				int x=a[i-j][k].first,id=a[i-j][k].second;
				if(x+(i-j)*j>100000)break;
				if(id>j)break;
//				if(~(id=find(i,x+(i-j)*j)))a[i][id].second=j;
				a[i].push_back({x+(i-j)*j,j});
			}
		}
	}
}
int q,n,m;
bool have(int i,int x){
	for(int j=0;j<a[i].size();++j){
		if(a[i][j].first==x)return 1;
	}
	return 0;
}
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	prework(60);
//	for(i=43;i<=43;++i){
//		printf("%d：",i);
//		for(j=0;j<a[i].size();++j){
//			if(j)putchar(',');
//			printf("%d(%d)",a[i][j].first,a[i][j].second);
//		}
//		putchar(10);
//	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&n,&m);
		if(have(n,m))puts("1");
		else puts("0");
	}
	return 0;
}
