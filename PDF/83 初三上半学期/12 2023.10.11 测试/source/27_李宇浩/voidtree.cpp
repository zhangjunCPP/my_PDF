#include <cstdio>
#include <initializer_list>
int data_id,ol,Ch,n;
template<typename T>
inline void r(T&x){
	while((Ch=getchar())<48);
	x=Ch&15;
	while((Ch=getchar())>47)x=(x<<1)+(x<<3)+(Ch&15);
}
template<typename...Ar>
inline void r(Ar&&...x){
	std::initializer_list<int>{(r(x),0)...};
}

class juhua final{
/*
主席树拿十分，我笑了 
*/ 
	juhua(){
	}
};
int main(){
//#undef LYH_LOCAL
#ifndef LYH_LOCAL
	freopen("voidtree.in","r",stdin);
	freopen("voidtree.out","w",stdout);
#endif
	r(data_id,ol,n);
	if(data_id==13||data_id==14){
		juhua{};
	}
	return 0;
}
