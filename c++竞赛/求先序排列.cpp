#include<bits/stdc++.h>
using namespace std;
string s1,s2;
void pre(string in,string post){
	if(in.size()>0){
		cout<<post[post.size()-1];
		int div=in.find(post[post.size()-1]);
		pre(in.substr(0,div),post.substr(0,div));
		pre(in.substr(div+1),post.substr(div,in.size()-div-1));
	}
}
int main(){
	cin>>s1>>s2;
	pre(s1,s2);
	return 0;
}
