 #include <bits/stdc++.h>
 using namespace std;
 int a[10000001]={1,2,2,2,3};
 int b[10000001]={1,3,3,3,4};
 int main()
 {
 	int k=2,n,left,right;
 	n=5;
 	left=lower_bound(a,a+n-1,k)-a;  //��һ�����ڻ����k 
 	right=upper_bound(a,a+n-1,k)-a; //��һ������k 
	cout<<left<<" "<<right<<" "<<right-left<<endl;
	
	left=lower_bound(b,b+n-1,5)-b;  //��һ�����ڻ����k 
	right=upper_bound(b,b+n-1,5)-b; //��һ������k   
	cout<<left<<" "<<right<<" "<<right-left<<endl;
    return 0;
 }
