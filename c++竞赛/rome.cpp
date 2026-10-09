#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[15]={0,4,10,20,35,56,83,116,155,198,244,292,341,390,439};
int main(){
	//freopen("rome.in","r",stdin);
	//freopen("rome.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	if(n<=14) cout<<a[n];
	else{
		cout<<(a[14]+(n-14)*49);
	}
	return 0;
}

