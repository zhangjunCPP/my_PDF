#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q; 
signed main(){
	freopen("klein.in","r",stdin);
	freopen("klein.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	while(q--) {
		int dx,dy,gx,gy,ix,ax,iy,ay;
		scanf("%lld%lld%lld%lld",&dx,&dy,&gx,&gy);
		ix=min( dx,gx ); iy=min( dy,gy );
		ax=max( dx,gx ); ay=max( dy,gy );
		
		int ans1=ax-ix + ay-iy;
		int ans3=ax-ix+iy+1+(n-ay);
		int anss=min( ans1,ans3 );
		//直接走的步数
		int ans5=n-ax+ix+1-1+abs( (n-iy)-ay )+1;
		int ans6=n-ax+ix+1-1+iy+1+ay+1;
		int ans7=n-ax+ix+1-1+iy+1+(n-ay)+1;
		int ans8=n-ax+ix+1-1+(n-iy)+1+(n-ay)+1;
//		cout<<n-ax+ix+1-1<<" "<<n-iy+1<<" "<<n-ay<<" "<<ans8<<endl;
		int anns=min( ans5,min( ans6,min( ans7,ans8 ) ) );
		int ans=min( anss,anns );
//		cout<<ans1<<" "<<ans3<<" "<<ans5<<" "<<ans6<<" "<<ans7<<" "<<endl;
//		if( ans==ans1 ) puts("one");
//		else if( ans==ans3 ) puts("three");
//		else if( ans==ans5 ) puts("five");
		printf("%lld\n",ans);
	}
	return 0;
}
/*
220 2
25 134 201 210
132 183 7 112

142
171
*/
