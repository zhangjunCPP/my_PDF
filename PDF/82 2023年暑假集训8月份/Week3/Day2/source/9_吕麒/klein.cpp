#include<bits/stdc++.h>
#define _fre_(f,x,y) \
{ \
	if(x) std::freopen(f".in","r",stdin); \
	if(y) std::freopen(f".out","w",stdout); \
}
namespace QL{
	int n,q;
	signed _main_(){
		std::scanf("%d%d",&n,&q);
		for(int x1,y1,x2,y2;q--;){
			std::scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(y1>y2) std::swap(x1,x2),std::swap(y1,y2);
			int ans=0x3f3f3f3f;
			{
				int y=y2;
				int p1=std::min(std::abs(y-y1),n+1-std::abs(y-y1));
				int p2=std::abs(x2-x1);
				ans=std::min(ans,p1+p2);
			}
			{
				int y=n-y2;
				int p1=std::min(std::abs(y-y1),n+1-std::abs(y-y1));
				int p2=(n+1)-std::abs(x2-x1);
				ans=std::min(ans,p1+p2);
			}
			std::printf("%d\n",ans);
		}
		return 0;
	}
}
signed main(){
	 _fre_("klein",1,1);
	return QL::_main_();
}
/*
CF/AT 即视感
就是分讨嘛…… 
小锅一会儿，半小时搞定 
*/
