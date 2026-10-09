#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
int n,a,b,c,arr[N],sum[N];
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		if((sum[i+x-1]-sum[i-1])>=a*(b*(i+x-1)-c*(i))){
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>a>>b>>c;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]+arr[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		} 
	}
	cout<<ans;
	return 0;
}

