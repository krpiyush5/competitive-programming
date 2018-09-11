#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define push push_back
#define ppb pop_back
#define srt(v) sort(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
#define ll long long
#define u unsigned long long int
#define lim 100000002
vector<bool>mark(lim+2,1);
vector<ll>primes;
void seive(){
    for(ll i=2;i<=lim;i++){
        if(mark[i]==1)
        {
            for(ll j=i*i;j<=lim;j+=i)
                mark[j]=0;
        }
    }
    for(ll i=2;i<=lim;i++){
        if(mark[i])
            primes.push(i);
    }
}
ll power(ll a,ll b){
    ll ans=1;
    while(b!=0){
        if(b&1){
            ans=ans*a;
        }
        b/=2;
        a=a*a;
    }
    return ans;

}
ll factorise(ll n){
    ll i=0,ans=1;
    ll p=primes[0];
    while(p*p<=n){
        if(n%p==0){
            ll cnt=0;
            while(n%p==0){
                n/=p;
                cnt++;
            }
            ll num=power(p,cnt+1)-1;
            ll den=p-1;
            ll curans=num/den;
            ans=ans*curans;
        }
        if(n==1)
        {
            break;
        }
        i++;
        p=primes[i];
    }
    if(n!=1)
        ans=ans*(n+1);

    return ans;

}
int main() {
    fast;
   int t;
    cin>>t;
    seive();
    while(t--){
        ll n;
        cin>>n;
        ll ans=factorise(n);
        cout<<ans-n<<endl;
    }

}