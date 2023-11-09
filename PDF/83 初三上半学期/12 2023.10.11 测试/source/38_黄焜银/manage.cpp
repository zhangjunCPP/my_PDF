/*
������
���set�ǲ��Ǿͽ����ˣ�

�������ǵ�
set��O(nmlogn)��

n��С�����ǿ���ֱ���ö���ά��
ʱ��O(nm)

��������Ҫ�����������1~i-1�Ĵ����i��

���ǲ�������һ�����˼·
��ԭ����ȥ��
����a[i]�����a[i-k]~a[i-1]֮��û�е�������
�͸����ۼ�1�Ĺ���
����˫ָ��Ҳ��������O(nm)

�����Ż��������
��¼ÿ������ǰ����Լ���ȵ������������
���ǾͿ�����k�仯ʱ��̯O(logm)����� 

������
�����ǰ���ĳ����û���¿��ռ�
������ʵ���Զ���ǰ����չһ��

������Ҫά��ԭ����
һ��ĳ�����Դ�û�й�����
����Ҫ���������������Ȩֵ-1
�Ҹо����ܲ�����t 

��֪��Ϊʲôʵ�ִ��˰�
�ܹ֣�������

��˵wc�Ǻõط�
��Ҳ��ô���ð�
3 5
3 1 2 1 3
�������ݣ���Ӧ����
5 4 3
�������
5 4 4

����ԭ��
��ʵ���ǡ�����a[i]�����a[i-k]~a[i-1]֮��û�е������ģ��͸����ۼ�1�Ĺ��ס� 
��仰��������
��Ϊ�����п��ܻ����ظ������ֳ��֣�������ֻ��ռһ��λ��
��������Ԥ����ʱ��¼��Ӧ����������ȵ�λ��֮���ж��ٸ���ͬ������ 
*/ 
#include<bits/stdc++.h>
using namespace std;
inline int re(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void wr(int x){
	if(x>9)wr(x/10);
	putchar(x%10|48);
}
const int N=5e5+10;
int i,n,las[N],len,a[N],m;
priority_queue<int,vector<int>,greater<int> >q;
struct B{
	int l,r;
}ask[N];
int blo[N],vis[N],ans;
bool cmp(B x,B y){
	return blo[x.l]==blo[y.l]?blo[x.l]&1?x.r<y.r:x.r>y.r:blo[x.l]<blo[y.l];
}
void add(int x){
	x=a[x];
	if(!vis[x])++ans;
	++vis[x];
}
void del(int x){
	x=a[x];
	--vis[x];
	if(!vis[x])--ans;
}
void prework(){
	for(i=1;i<=n;++i)las[i]=-1e9;
	int num=max((int)sqrt(len),1);
	for(i=1;i<=len;++i){
		if(las[a[i]]==-1e9)q.push((int)1e9),ask[i]={0,0};
		else ask[i]={las[a[i]]+1,i};
		las[a[i]]=i;
		blo[i]=(i+num-1)/num;
	}
	sort(ask+1,ask+1+len,cmp);
	int l=1,r=0;
	for(i=1;i<=len;++i){
		if(ask[i].l==0||ask[i].r==0)continue;
		while(l>ask[i].l)add(--l);
		while(r<ask[i].r)add(++r);
		while(l<ask[i].l)del(l++);
		while(r>ask[i].r)del(r--);
//		printf("ask[i]={%d,%d} ans=%d\n",ask[i].l,ask[i].r,ans);
		q.push(ans);
	}
}
int main(){
	freopen("manage.in","r",stdin);
	freopen("manage.out","w",stdout);
	n=re();
	m=re();
	for(i=1;i<=m;++i)a[i]=re();
	len=unique(a+1,a+1+m)-a-1;
//	for(i=1;i<=len;++i)printf("%d ",a[i]);putchar(10);
	prework();
	for(i=1;i<=n;++i){
		while(!q.empty()&&q.top()<=i)q.pop();
		wr(q.size());
		putchar(32);
	}
	return 0;
}

