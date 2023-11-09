#include<bits/stdc++.h>
using namespace std; 
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
#define ll long long
const int maxn=7e5+5;
int n;
int a[maxn],pos[maxn];
int root[maxn];
struct Tree{
	int lc,rc;
	int sum;
}T[maxn*25];
int tot=0;
inline void build(int &rt,int l,int r){
	rt=++tot;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(T[rt].lc,l,mid);
	build(T[rt].rc,mid+1,r);
}
inline void up_data(int p,int &q,int l,int r,int val){
	q=++tot;
	T[q].sum=T[p].sum+1;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(val<=mid) T[q].rc=T[p].rc,up_data(T[p].lc,T[q].lc,l,mid,val);
	else T[q].lc=T[p].lc,up_data(T[p].rc,T[q].rc,mid+1,r,val);
}
inline int query(int p,int q,int l,int r,int k){//�� k С 
	if(l==r) return l;
	int cnt=T[T[q].lc].sum-T[T[p].lc].sum;
	int mid=(l+r)>>1;
//	cout<<l<<" "<<r<<" "<<cnt<<" "<<k<<" czc\n";
	if(k>cnt) return query(T[p].rc,T[q].rc,mid+1,r,k-cnt);
	return query(T[p].lc,T[q].lc,l,mid,k);
}
ll ans=0;
inline void my_sort(int l,int r){
	if(l>r) return ;
	if(l==r) return ;
	ans=ans+(ll)(r-l+1ll);
	int num=(r-l+1)/2+(r-l+1)%2; 
	int p=query(root[l-1],root[r],1,n,num);
//	cout<<l<<" "<<r<<" "<<p<<" "<<a[p]<<" "<<num<<endl;
//	system("pause");
	my_sort(l,a[p]-1);
	my_sort(a[p]+1,r);
}
int main(){
	freopen("sort.in","r",stdin); 
	freopen("sort.out","w",stdout); 
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]); 
		pos[a[i]]=i;
	}
	build(root[0],1,n);
	for(int i=1;i<=n;i++){
		up_data(root[i-1],root[i],1,n,pos[i]);
	}
	my_sort(1,n);
	printf("%lld",ans);
	return 0;
}
/*
ɵ������ˣ�����д��ô���󣬲�����C++��
����������ţ�
����ģ���⣿
ֱ��ģ��ᱻ���� n^2 �ɣ���������
�о����ѵ����ӡ� 
�۲�һ�£����ִ��ǵݹ�������������֮�ͳ�ȥ��Ԫ�صļ��ϡ� 

3e3 �Լ��������ģ�⼴�ɡ�
ai=i��һ����������У�ģ�⻹��һ�� nlogn
ֱ��ģ���� 40/50 pts?
���Ǻ���⡣
��Щ��������������ף��о��������ͷ֡�
ֱ��������ɣ����� 16:10
ͳ�� cnt ���Ժܿ죬���ڵ������������ģ�⣬�Ҳ�֪����һ������С�
��һ��Ҳ��֪�����ڶ����ڵ�һ�㲻���������û��֪����
���ڲ��������ÿһ����pivot
ΪʲôҪ�� 1e5 ��һ���֡�
����������
�ǿ��ֿ��㷨��
��֪����
�ò��������ø�Splayʲô���ɡ�
�������Կ���������������ʵ�� 1 s 1e11
�Ҳ�֪���ݹ����һ�㣬����ͷ����һ�㰡��
�ܲ�����ʲô������������Ż�һ��������bitset��
�����Ǻ��У���Ҫά�����˳��
�����Ҳ��ı����ǵ�˳��ݹ顣
���൱�ڵݹ��ÿһ����һ�����䡣
����Ҫ����ô��������ҵ��������м���Ǹ�����
�ò�����Ի���ֵ����һЩ����ɡ�
��Ī�ӣ�����Ī�ӣ�Ī��Ҫ���ߡ�
��ֵ�����������൱����ֵ���� l~r �У�λ����м����λ��
��Ȼ���ò��ҵ�k����
ֱ��дһ����ϯ����
�ҽ���Ϊʲô��������ϯ����
�������ǶԵģ���硣
���ڸ�Щʲô�ɻ��� 
�ռ����ͦ��ģ��Ҿ��þ�����ϯ���� 
ˮ��һö�������ϯ����6��
д���������İɡ� 
*/ 
