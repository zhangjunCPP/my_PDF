/*
B game
����һ���򵥵ķ��������Ǹ�����ջ
���ǵĲ��Կ϶�������������x
�Ӵ��x��ʼ���Ȱ�����С�ĸ������������Լ��ķֳ���
��������һ���Ǹ��ŵģ���Ȼ�������yʹ��vy<vx��������һ�ַ���ʹ��x��������y�����Ļ�����Ȼ�ҿ�����y�Եĸ�һ���ָ�xʹ�ô𰸸���
��������֮������Ϊ��һ��˼·����ȱ����ȷ��֤�����򵥴ֱ��Ķ��ģ� 
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void r(T &&x)
{
	char c;x=0;
	while((c=getchar())<'0'||c>'9');
	while(c>='0'&&c<='9')x*=10,x+=c-'0',c=getchar();
	return;
}
template<typename T,typename ...Args>
inline void r(T &&x,Args &&...args){r(x);r(args...);return;}
const int N=1919810;
using ll=long long;
struct person{
	ll v;
	int id;
	bool operator < (const person &oth){if(v==oth.v)return id<oth.id;return v>oth.v;}
}p[N];
int op[N],opt;
int main()
{
	int n;
	r(n);
	for(int i=1;i<=n;i++)r(p[i].v),p[i].id=i;
	sort(p+1,p+n+1);
	ll ans=0;
	for(int i=1,ptr=n;i<=n;i++)
	{
		if(p[i].id<ptr)
		{
			op[++opt]=p[i].id;
			ans+=(ptr-p[i].id)*p[i].v;
			ptr=p[i].id;
		}
	}
	printf("%lld\n",ans);
	for(int i=1,ptr=n;i<=opt;i++)
	{
		for(int j=op[i]+1;j<=ptr;j++)printf("%d ",j);
		ptr=op[i];
	}
	printf("1");
	return 0;
}
