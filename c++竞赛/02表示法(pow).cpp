#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=180+10;
int n;
vector<int> a;
string s;
bool div(string &s){
	for(int i=n-1;i>=0;i--){
		int v=s[i]-'0';
		s[i]=v/2+'0';
		if(i==0) return v%2;
		s[i-1]+=v%2*10;
	}
}
void solve(int x){
	if(x==0) cout<<"2(0)";
	else if(x==1) cout<<"2";
	else{
		int cnt=0,pos=0,tmp[15];
		cout<<"2(";
		while(x){
			if(x&1) tmp[++cnt]=pos;
			pos++;
			x>>=1;
		}
		for(int i=cnt;i>=1;i--){
			solve(tmp[i]);
			if(i!=1) cout<<"+";
		}
		cout<<")";
	}
	return;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>s;
	reverse(s.begin(),s.end());
	n=s.size();
	string t(s.size(),'0');
	for(int i=0;;i++){
		if(div(s)) a.push_back(i);
		if(s==t) break;
	}
	for(int i=a.size()-1;i>=0;i--){
		solve(a[i]);
		if(i!=0) cout<<"+";
	}
	return 0;
}
