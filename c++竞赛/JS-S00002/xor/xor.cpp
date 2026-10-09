#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
ll a[N],fib[64];
pair<ll,ll> p[N];
void cal(){
	for(int i=0;i<N;i++){
		if((i&(2*i))==0) a[i]=1;
	}
	for(int i=0;i<N;i++){
		a[i]+=a[i-1];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	cal();
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].first>>p[i].second;
		if(p[i].first>=N||p[i].second>=N) flag=1;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			cout<<a[p[i].second]-(p[i].first==0?0:a[p[i].first-1])<<"\n";
		}
	}
	else{
		for(int i=1;i<=n;i++) cout<<"0\n";
	}
	return 0;
}

