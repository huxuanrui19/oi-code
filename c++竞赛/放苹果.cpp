#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int t,m,n;
ll cal(int n,int m){
	if(n==1||m==1||m==0) return 1;
	if(m<n) return cal(m,m);
	else return cal(n,m-n)+cal(n-1,m);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<cal(n,m)<<"\n";
	}
	return 0;
}

