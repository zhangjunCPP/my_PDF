#include<bits/stdc++.h>
using namespace std;
int n,k,L;
const int maxn=1e5+5;
struct node{
	int b,d,op;
}a[maxn];
char op[5];
inline bool cmp(node x,node y){
	return x.d<y.d;
}
double ans[45];
double sum[45][45],sum2[45][45];
deque<int> st;
int main(){
	scanf("%d%d%d",&n,&k,&L);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].d,&a[i].b);
		scanf("%s",op);
		if(op[0]=='D'){
			a[i].op=0;
		}
		else{//�� 
			a[i].op=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
//		cout<<a[i].op<<" "<<a[i].d<<" "<<a[i].b<<endl; 
		if(!a[i].op){
			ans[a[i].b]+=(double)L-(double)a[i].d;
			for(int j=0;j<k;j++){
				for(int g=0;g<k;g++){
					sum2[j][g]=sum[(a[i].b+j)%k][g];
				}
			}
			if(st.empty()){
				for(int j=0;j<k;j++){
					sum2[j][(a[i].b+j)%k]+=(double)(a[i].d)/2.0;
//					if(j==1) cout<<sum2[j][(a[i].b+j)%k]<<" czc:\n";
				}
			}
			else{
				for(int j=0;j<k;j++){
					sum2[j][(a[i].b+j)%k]+=(double)a[i].d/2.0-(double)a[st.back()].d/2.0;
				}
			}
			st.push_back(i);
			for(int j=0;j<k;j++){
				for(int g=0;g<k;g++){
					sum[j][g]=sum2[j][g];
				}
			}
		}
		else{
			for(int j=0;j<k;j++){
				ans[j]+=sum[a[i].b][j];
			}
			if(st.empty()){
				ans[a[i].b]+=(double)a[i].d;
			}
			else{
				ans[a[i].b]+=((double)a[i].d-(double)a[st.back()].d)/2.0;
			}
		}
	}
	for(int i=0;i<k;i++){
		printf("%.1lf\n",ans[i]);
	}
	return 0;
}
/*
T2ΪʲôҲ��ô���ġ�
��T2�ܸ�ȥ�õ�ְɡ�
������֮ǰ�Ĳ��ң�����Ҳ��168��
�����ø�40������200�ˡ�
��T3��12pts
��T4����Ҫ20pts��
���������ֱ�Ӷ�������ȥ��ģ�͡�
�������ԡ�
�����仯����ɫ�����൱�������ߵ���ɫ���䣬�����ߵ���ɫ��� (a+b)%k
Ȼ��Ϳ��� n^2 ͳ���ˡ�
ֱ������ʵ���Թ�2������
�����Ҿ��������ˣ������е�����
k ����С������
�ǻ�˵ʲô��
˵���ҵ�aֻ��40�ֱ仯��
�������ߵ���ɫֻ��һ��ʱ�����ǿ���ֱ���������
�����ˣ�����ÿ������һ��b����ֱ��ά��aΪʲô��ʱ��Ķ�Ӧ�Ĺ��׼��ɡ�
��Ϊaֻ����ǰ���b�йء�
�Ǿ��൱�����ǵ�·�̲
�������ܹ��ˡ� 
*/ 
