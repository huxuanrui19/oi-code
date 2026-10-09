#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e16;
ll n,m,q,len1=0,len2=0;
ll a[N],x[N],se[N],en[N],pos1[N],pos2[N];
int se_fi(int pos){
	ll num=x[pos];
	ll l=1,r=len1,ans=len1+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(se[mid]+mid*num>=m){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i];
	}
	
	fill(pos1,pos1+N,inf);
    fill(pos2,pos2+N,inf);
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			len1++;
			se[len1]=se[len1-1]+abs(a[i]);
			pos1[len1]=i;
		}
		else{
			len2++;
			en[len2]=en[len2-1]+abs(a[i]);
			pos2[len2]=i;
		}
	}
	
	for(int i=1;i<=q;i++){
		ll x1=se_fi(i);
		ll x2=(lower_bound(en+1,en+len2+1,m)-en);
		ll p1=x1<=len1?pos1[x1]:inf;
		ll p2=x2<=len2?pos2[x2]:inf;
		if(p1<p2) cout<<"Yes";
		else if(p1>p2) cout<<"No";
		else cout<<"Tie";
		cout<<"\n";
	}
	return 0;
}

