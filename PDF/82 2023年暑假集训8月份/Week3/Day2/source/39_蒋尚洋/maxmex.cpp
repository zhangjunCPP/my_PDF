//�������,Ȼ��˫ָ��check?
//�����ܵ�>mid��ѯ��,�϶�ҲҪ����<=mid�������,ȡmax����? 
//ע:���˲���10min?����8:33
//��ϸ������ôά��left pointer?
//����һ����ֱ��sgtά��+����
//��ʱ������벻��ɶ��������... 
//8:46:�ȵȹ�,�������mex��r,��l������<=mex����������һ�γ���λ�õ�min 
//�����ǵ�ѡ��϶��ǰ�����k������� 
//�������Ҫд�����ô������Ҫдsgt��...
//�������һ��node��ά��lptrΪl�ķ�Χ��?
//lptr�϶��Ǵ�������ĳ����,���Ա�����û����? 
//�����,�ͽ���. 
//8:53:�ȵȵ�
//���������k��mex��������������������?
//�����������г�Ϊk���������Ƿ���һ������[l,r]��������
//��ôcheck���?
//�϶��ǰ�����[l,r]��pos������,Ȼ��˳����
//�G�����
//����ôcheck���?�������check����?
//9:03upd:wtm����node��ά���˲���ֱ��������.... 
//�ٿ�һ��ʱ�临�Ӷ�:ֻҪ��ÿ�ζ�ֻ�ϲ���Ҫ����ôֻ��n�� 
//9:20:��tm��д
//��ĥһ��д��:
//1.������д�϶��ǿ��Ե�
//2.����odt��split�ĺ���(?)
//9:28:���˵Ȼ���д
//10:10:�һ�����
//û�õ�lptr��Ϊ0����,��ʱ����һ�� 
//10:35д���С����!
//10:37����������
//10:37:��ʼд���� 
//10:50��ʼ���� 
//11:06:������ô������!��!����
//����Ҫ��һ�� 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],ans[100010];
vector<int>pos[100010];
struct node_t{int l;mutable int r,lptr;bool operator<(const node_t&o)const{return l<o.l;};};
set<node_t>odt;
map<int,int>cnt;
auto upd=[](node_t x,int v){if(x.lptr)if(!(cnt[x.l-x.lptr+1]+=v))cnt.erase(x.l-x.lptr+1);};
auto split(int x){
	if(x==n+1)return end(odt);
	if(!x)return begin(odt);
	auto it=prev(odt.upper_bound({x,0,0}));
	if(x==it->l)return it;
	int r=it->r,ptr=it->lptr;
	it->r=x-1;
	upd({x,r,ptr},1);
	return odt.insert({x,r,ptr}).first;
}
int main(){
	freopen("maxmex.in","r",stdin);
	freopen("maxmex.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n+1;i++)pos[i].push_back(0);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i),odt.insert({i,i,i}),upd({i,i,i},1);
	for(int i=0;i<=n+1;i++)pos[i].push_back(n+1);
	for(int mex=1;mex<=n+2;mex++){//����mex-1
		int ad=mex-1,sz=pos[ad].size();
		for(int i=0;i+1<sz;i++){
			int l=pos[ad][i],r=pos[ad][i+1];
			auto rit=split(r),lit=split(l),pr=rit;
			if(rit!=lit){
				for(;pr!=lit&&prev(pr)->lptr>l;upd(*--pr,-1));
				if(pr!=rit){
					int newl=pr->l; 
					odt.erase(pr,rit),
					upd(*odt.insert({newl,r-1,l}).first,1);
				}
			}
		}if(!cnt.empty())ans[begin(cnt)->first]=mex;
	}for(int i=1;i<=n;i++)ans[i]=max(ans[i],ans[i-1]);
	cin>>m;for(int k;m--;)
	scanf("%d",&k),printf("%d\n",ans[k]);
	return 0;
}
