#include<bits/stdc++.h>
#define _fre_(f,x,y) \
{ \
	if(x) std::freopen(f".in","r",stdin); \
	if(y) std::freopen(f".out","w",stdout); \
}
namespace QL{
	constexpr int N=1e5+3;
	int n,a[N],q;
	namespace solve1{
		struct BIT{
			int c[N];
			void clear(int n){
				__builtin_memset(c,0,sizeof(int)*(n+1));
			}
			void upd(int x,int val){
				for(++x;x<N;x+=x&-x) c[x]+=val;
			}
			int qry(int x){
				int ret=0;
				for(++x;x;x-=x&-x) ret+=c[x];
				return ret;
			}
		};
		BIT tr;
		int cnt[N];
		int MAIN(){
			for(int k;q--;){
				std::scanf("%d",&k);
				for(int i=1;i<=k;++i)
					if(++cnt[a[i]]==1) tr.upd(a[i],1);
				auto work=[](){
					int l=0,r=n;
					for(int mid;l<r;){
						mid=(l+r+1)>>1;
						if(tr.qry(mid)<mid+1) r=mid-1; 
						else l=mid;
					}
					return l+1;
				};
				int ans=work();
				for(int l=2,r=k+1;r<=n;++r,++l){
					if(++cnt[a[r]]==1) tr.upd(a[r],1);
					if(--cnt[a[l-1]]==0) tr.upd(a[l-1],-1);
					if((ans=std::max(ans,work()))==k) break;
				}
				std::printf("%d\n",ans);
				__builtin_memset(cnt,0,sizeof(int)*(n+1));
				tr.clear(n);
			}
			return 0;
		}
	}
	signed _main_(){
		std::scanf("%d",&n);
		for(int i=1;i<=n;++i) std::scanf("%d",&a[i]);
		std::scanf("%d",&q);
		if(n*q<=1000000000) return solve1::MAIN();
		return 0;
	}
}
signed main(){
	 _fre_("maxmex",1,1);
	return QL::_main_();
}
/*
�����㲻������������������
n,q,a�ֱ��������ƣ�ֻҪ�����������ģ������ȵ��ٶ�ֵ���йء� 
�����ҿ�����һ������ɨ��ȥ��Ȼ���һ��lg��mex��
���ͳ��˸� O(qnlgn)���� �ܹ��� 50pts 
����mex������Ҫ�ҵ�һ������Ϊk������ʹ��0~k-1���зֲ� 
f(i,j,l,k)��i��ʼ������Ϊ2^j���ֲ�l~l+2^k�������Ǻܿ�ѧ
�о���������������̰�ĵ�������չ 
��д�������������ٻ������е���� 
����OK 
һ�����䣬����k-1�ǲ��ŵģ���ô����k���ԣ����ƺ�Ҳû�������ĸ���
��Ϊ�������ֿ��Ա�֤���еı����󣬶�����չһ�������ֻ�����������Լ��������͡���
���ˣ�����
����ɨ���Ѿ������Ե��ˣ�ֻ�ܴӶ����ϵ������ 
����������м䲿�����ٵ��Ź��ɡ��� 
����˳����ö�ٴ𰸣�����������е����� 
����Ϊk�Ĵ�������d����С��k�Ķ�������d
����Ϊk�Ĵղ���d���Ǵ���d��Ҳ�ղ���
���ǰ�k���򣬶���d��check
check���Ӷ�O(n)���ܽ��� 
*/ 
