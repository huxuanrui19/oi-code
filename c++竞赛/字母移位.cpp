#include<bits/stdc++.h>
using namespace std;
long long a[int(1e5+10)],sum[int(1e5+10)];
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i&1){
			a[i]=-a[i];
		}
	}
	for(int i=n;i>=1;i--){
		sum[i]=(sum[i+1]+a[i])%26;
	}
	for(int i=0;i<n;i++){
		sum[i+1]%=26;
		cout<<char((s[i]-'a'+sum[i+1]+26)%26+'a');
	}
	return 0;
}
