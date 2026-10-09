#include<bits/stdc++.h>
using namespace std;
double w0,w,m;
double kkk(){
	double l=0.00,r=10,ans=0;
	while(r-l>=0.0001){
		double mid=(l+r)/2.0,cnt=1,sum=0;
		for(int i=1;i<=m;i++){
			cnt*=(1+mid);
			sum+=(w/cnt);
		}
		if(sum>=w0){
			ans=mid;
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return ans*100;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>w0>>w>>m;
	printf("%.1lf",kkk());
	return 0;
}

