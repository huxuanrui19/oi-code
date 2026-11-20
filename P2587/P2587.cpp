#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,M=1e7+10;
ll n,a[N],b[N],vis[N];
ll cal(ll a[],ll b[]){
	ll sum=0;
	int l=1,r=n,lt=1,rt=n;
	while(lt<=rt&&l<=r){
		if(a[l]>b[lt]) sum+=2,l++,lt++;
		else if(a[r]>b[rt]) sum+=2,r--,rt--;
		else if(a[l]==b[rt]) sum++,l++,rt--;
		else l++,rt--;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	cout<<cal(a,b)<<" "<<(2*n-cal(b,a));
	return 0;
}

