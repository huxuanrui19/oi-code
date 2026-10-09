#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+10;
map<ull,int> ma;
static const ull base=131;
static const ull mod=1e9+7;
ull get_hash(string s){
	ull hash=0;
	for(int i=0;i<s.size();i++){
		hash=(hash*base+(ull)(s[i]))%mod;
	}
	return hash;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t,s;
		string name;
		cin>>t;
		if(t==1){
			cin>>name>>s;
			ull hash=get_hash(name);
			ma[hash]=s;
			cout<<"OK\n";
		}
		else if(t==2){
			cin>>name;
			ull hash=get_hash(name);
			if(ma.count(hash)){
				cout<<ma[hash]<<"\n";
			}
			else{
				cout<<"Not found\n";
			}
		}
		else if(t==3){
			cin>>name;
			ull hash=get_hash(name);
			if(ma.count(hash)){
				ma.erase(hash);
				cout<<"Deleted successfully\n";
			}
			else{
				cout<<"Not found\n";
			}
		}
		else{
			cout<<ma.size()<<"\n";
		}
	}
	return 0;
}

