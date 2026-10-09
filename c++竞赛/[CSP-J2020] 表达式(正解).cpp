#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
string s;
int n,q,len,m,cnt,root,ans,flag[N];
struct edge{
	int to,nxt;
}e[N];
int head[N],num[N];
char op[N];
void add_edge(int u,int v){
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
stack<int> st;
void build(){
	len=s.size(),m=n;
	s=' '+s;
	int flag=0,sum=0;
	for(int i=1;i<=len;i++){
		if(s[i]=='x') flag=1;
		else if(s[i]<='9'&&s[i]>='0'&&flag) sum=sum*10+s[i]-'0';
		else if(s[i]==' '&&flag==1){
			st.push(sum);
			sum=flag=0;
		}
		else if(s[i]=='!'){
			int x=st.top();
			op[++m]=s[i];
			st.pop();
			num[m]=!num[x];
			st.push(m);
			add_edge(m,x);
		}
		else if(s[i]=='&'||s[i]=='|'){
			int x=st.top();
			st.pop();
			int y=st.top();
			st.pop();
			op[++m]=s[i];
			if(s[i]=='&') num[m]=num[x]&num[y];
			else num[m]=num[x]|num[y];
			st.push(m);
			add_edge(m,x);
			add_edge(m,y);
		}
	}
	root=st.top();
	ans=num[root];
	return;
}
void dfs(int u){
	flag[u]=1;
	if(u<=n) return;
	if(op[u]=='!'){
		dfs(e[head[u]].to);
		return;
	}
	int n1=e[head[u]].to,n2=e[e[head[u]].nxt].to;
	if(op[u]=='&'){
		if(num[n1]==1) dfs(n2);
		if(num[n2]==1) dfs(n1);
	}
	else if(op[u]=='|'){
		if(num[n1]==0) dfs(n2);
		if(num[n2]==0) dfs(n1);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin,s);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	memset(head,-1,sizeof(head));
	build();
	dfs(root);
	int q;
	cin>>q;
	while(q--){
		int u;
		cin>>u;
		if(flag[u]) cout<<(ans^1)<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}

