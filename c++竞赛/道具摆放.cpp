#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll cnt,a[N],b[N];
void mer(int l,int mid,int r){
	ll i=l,j=mid+1,t=0;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]){
			b[t++]=a[j++];
			cnt+=mid-i+1;
		}
		else{
			b[t++]=a[i++];
		}
	}
	while(i<=mid) b[t++]=a[i++];
	while(j<=r) b[t++]=a[j++];
	for(int i=0;i<t;i++){
		a[l+i]=b[i];
	}
}
void ms(int l,int r){
	if(l<r){
		int mid=(l+r)>>1;
		ms(l,mid);
		ms(mid+1,r);
		mer(l,mid,r);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ms(1,n);
	ll t=0;
	if(cnt) t=(cnt-1)/m+1;
	if(t*m%2==cnt%2) cout<<t*m;
	else if((t*m+m)%2==cnt%2) cout<<t*m+m;
	else cout<<-1;
	return 0;
}

