#include<bits/stdc++.h>
using namespace std;
string s[5][4]={".....","****.",".....",".....",".***.","****.","****.","****.",".***.","****.",".....",".....",".***.","****.",".****","****.",".....","****.",".....","....."};
int main()
{
	string n;
	cin>>n;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<n.size();j++)
		{
			cout<<s[i][int(n[j]-'0')];
		}
		cout<<endl;
	}
	return 0;
}
