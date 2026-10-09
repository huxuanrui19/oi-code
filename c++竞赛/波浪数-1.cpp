#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll vis[N]; 
void solve(int l,int r){
	for(ll k=l;k<=r;k++){
		for(ll i=1;i<k;i++){
			for(ll j=0;j<k;j++){
				if(i==j) continue;
				ll cnt=i,len=1;
				while(cnt<N){
					vis[cnt]++;
					if(len%2==1) cnt=cnt*k+j;
					else cnt=cnt*k+i;
					len++;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll l,r,L,R,k;
	cin>>l>>r>>L>>R>>k;
	solve(l,r);
	for(int i=L;i<=R;i++){
		if(vis[i]==k) cout<<i<<"\n";
	}
	return 0;
}

