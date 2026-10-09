#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	stack<int> st;
	int flag=0,num=0;
	for(int i=1;i<=n;i++){
		if(isdigit(s[i])) flag=1,num=num*10+s[i]-'0';
		else if(flag==1&&s[i]=='.'){
			flag=0;
			st.push(num);
			num=0;
		}
		else if(s[i]=='.') continue;
		else if(s[i]!='@'){
			int x1,x2;
			x2=st.top();st.pop();
			x1=st.top();st.pop();
			if(s[i]=='+') st.push(x1+x2);
			if(s[i]=='-') st.push(x1-x2);
			if(s[i]=='*') st.push(x1*x2);
			if(s[i]=='/') st.push(x1/x2);
		}
	}
	cout<<st.top();
	return 0;
}

