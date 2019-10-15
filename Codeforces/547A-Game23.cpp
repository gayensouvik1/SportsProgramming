#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ll n,m;
    cin >> n >> m;
 
    ll ans=-1;
    if(m%n==0) {
        ll d = m/n;
        ll c = 0;
        while(d%2==0) {
            d/=2;
            c++;
        }
        while(d%3==0) {
            d/=3;
            c++;
        } 
        if(d==1) {
            ans = c;
        }
    }
    cout << ans;
}