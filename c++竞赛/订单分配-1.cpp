#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N],b[N];
bool check(int x){
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]>=x) sum+=x;
		else sum+=b[i]+(x-b[i])/2;
	}
	return sum>=m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		b[a[i]]++;
	}
	int l=0,r=m*2,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
