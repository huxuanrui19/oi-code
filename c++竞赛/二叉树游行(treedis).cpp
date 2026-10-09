#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
vector<int> num1,num2;
void func(string s,vector<int> &num){
	num.push_back(1);
	for(int i=0;i<s.size();i++){
		char ch=s[i];
		if(ch=='1') num.push_back(0);
		else if(ch=='2') num.push_back(1);
		else if(ch=='U'){
			int t=int(num.size());t--;
			num[t-1]+=num[t]/2;
			num[t]%=2;
			if(num[t]<0){
				num[t-1]--;num[t]+=2;
			}
			num.pop_back();
		}
		else if(ch=='L'){
			int t=int(num.size());t--;
			num[t]--;
		}
		else{
			int t=int(num.size());t--;
			num[t]++;
		}
	}
	for(int i=int(num.size())-1;i>=1;i--){
		num[i-1]+=num[i]/2;
		num[i]%=2;
		if(num[i]<0){
			num[i-1]--;num[i]+=2;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("treedis1.in","r",stdin);
	//freopen("treedisme1.out","w",stdout);
	string s,t;cin>>s>>t;
	func(s,num1);func(t,num2);
	ll ha=num1.size(),hb=num2.size();
	ll ans=1e18;__int128 v=0;
	for(ll i=1;i<=min(ha,hb);i++){
		v=v*2+num1[i-1]-num2[i-1];
		if(v>1e18||v<(-1e18)) break;
		ans=min(ans,abs(ll(v))+(ha-i)+(hb-i));
	}
	cout<<ans;
	return 0;
}
