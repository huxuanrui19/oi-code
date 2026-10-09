#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+10;
ll d,n,m,t,p;
deque<__int128> a;
__int128 b[N*N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>d>>n>>m>>t;
	for(int i=0;i<n;i++){
		ll num;cin>>num;
		a.push_back((__int128)num);
	}
	//for(int i=1;i<=n;i++) cout<<a[i-1]<<" ";
	p=n*m;
	__int128 sum=0;
	for(int i=0;i<p;i++){
		if(i%m==0){
			__int128 num=a.back();
			a.pop_back();
			a.push_front(num);
		}
		sum=sum+(__int128)(a[i%n]);
		//cout<<a[i%n]<<" ";
		b[i]=sum;
	}
	t--;
	__int128 q=(__int128)(t/p),r=(__int128)(t%p);
	//for(int i=0;i<=t;i++) cout<<b[i]<<" ";
	__int128 ans=q*(b[p-1]%(__int128)(d))%(__int128)(d)+b[r]%(__int128)(d);
	ans=ans%(__int128)(d);
	cout<<ll(ans);
	return 0;
}
