 #include <bits/stdc++.h>
 using namespace std;
 int a[10000001]={1,2,2,2,3};
 int main()
 {
 	int k=2,n,ans=-1;
 	n=5;
 	int left=0,right=n;
	 while (left<right) {
	         //int mid = (left + right) / 2;
	         int mid = left+(right-left) / 2;  //·ÀÖ¹Êý¾ÝÒç³ö
	         if (a[mid] == k) {
	             ans = mid;
	 		 break;
	         }
	         else if (a[mid] < k) {
	             left = mid + 1;
	         }
	         else {
	             right = mid - 1;
	         }
	   }
	cout<<ans;
     return 0;
 }
