#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string s,t; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,l,r;
	cin>>n>>l>>r;
	cin>>s;
	for(int i=1;i<=n;i++){
		t.push_back('a');
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		cnt+=(s[i]==t[i]);
	}
	if(cnt>=l&&cnt<=r) cout<<t;
	else if(cnt<l){
		for(int i=n-1;i>=0;i--){
			if(cnt<l&&s[i]!=t[i]){
				cnt++;
				t[i]=s[i];
			}
		}
		cout<<t;
	}
	else{
		for(int i=n-1;i>=0;i--){
			if(cnt>r&&s[i]==t[i]){
                cnt--;
				t[i]='b';
			}
		}
		cout<<t;
	}
	return 0;
}
