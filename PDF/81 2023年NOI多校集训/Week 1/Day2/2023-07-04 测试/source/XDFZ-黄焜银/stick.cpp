/*
����ô�о���Ŀ˳���е��
���������
n��ֱ�ߣ�����ɼ������㣿
1��0
2��0,1
3��0,1,2,3
4��0,1,3,4,5,6
5��0,1,4,5,7,8,9,10 
�ɴ����ǿ��Է��ֹ��ɣ�
i��ľ���ܰڳ��Ľ�����Ϊ��0,1,i-1�����з���+i-1
ע�⣬1��ľ��ֻ��ȡ0
 
�ð���Ŀ����ͷ
��������������ľ������һ������
Ҳ����˵��������ľ��һ�����֮ǰ���е�ľ��������һ������
����ƽ�� 
������´��
1��0
2��0,1
3��0,2,3
4��0,3,4,5,6
5��0,4,6,7,8,9,10
�ɴ˵ó�����
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >a[501];//0������1��ƽ���� 
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
	for(i=1;i<=n;++i){//i�ǲ��� 
//		printf("size[%d]=%d\n",i-1,a[i-1].size());
		for(j=i;j;--j){//j��ƽ���� 
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
//		printf("%d��",i);
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
