#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
string s;
int n,q,len,a[N];
int solve(){
	int flag=0,sum=0;
	stack<int> st;
	for(int i=1;i<=len;i++){
		if(s[i]=='x') flag=1;
		else if(flag==1&&(s[i]>='0'&&s[i]<='9')) sum=sum*10+s[i]-'0';
		else if(s[i]==' '&&flag==1){
			st.push(a[sum]);
			sum=flag=0;
		}
		else if(s[i]=='&'){
			int x1=st.top();
			st.pop();
			int x2=st.top();
			st.pop();
			st.push(x1&x2);
		}
		else if(s[i]=='|'){
			int x1=st.top();
			st.pop();
			int x2=st.top();
			st.pop();
			st.push(x1|x2);
		}
		else if(s[i]=='!'){
			int x1=st.top()^1;
			st.pop();st.push(x1);
		}
	}
	return st.top();
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin,s);
	cin>>n;
	len=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++){
        int t;
        cin>>t;
		a[t]^=1;
		cout<<solve()<<"\n";
		a[t]^=1;
	}
	return 0;
}
