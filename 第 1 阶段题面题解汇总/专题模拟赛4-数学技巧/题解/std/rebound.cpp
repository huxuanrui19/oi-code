#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll exgcd(ll a,ll b,ll& x,ll& y)
{
    if(b==0){x=1;y=0;return a;}
    ll g=exgcd(b,a%b,x,y);
    x-=a/b*y;swap(x,y);
    return g;
}

int main()
{
    int T;
    ll a,b,n;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>n;
        if(n%b==0)
            puts(b<=n&&n<=a*b?"Yes":"No");
        else
        {
            ll x,y;
            exgcd(a,b,x,y);
            x*=(n%b);y*=(n%b);x=(x%b+b)%b;
            if(n<=a*x)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}