#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	if(((n+k)/k-1)>k) cout<<"-1\n";
	else{
		for(int i=1;i<=n/k;i++){
			for(int j=k;j>=1;j--){
				cout<<(i-1)*k+j<<" ";
			}
		}
		for(int i=n;i>k*(n/k);i--) cout<<i<<" ";
	}
	return 0;
}

