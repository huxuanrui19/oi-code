#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m,a[N],w[N];
bool check(int x){
	ll sum=0,minn=2e9;
	for(int i=1;i<=n;i++){
		if(w[i]>=x) sum+=x;
		else sum+=w[i]+(x-w[i])/2; 
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
		w[a[i]]++;
	}
	int l=1,r=m*2,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}

