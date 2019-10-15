
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int Q[n-1];
    int P[n];
    for(int i=0;i<n-1;i++) {
        cin >> Q[i];
    }
    P[0] = 0;
    int min = 0;
    for(int i=1;i<n;i++) {
        P[i] = Q[i-1]+P[i-1];
        if(min>P[i]) {
            min=P[i];
        }
    }
    int R[n+1];
    for(int i=0;i<=n;i++) {
        R[i] = 0;
    }
 
    for (int i = 0; i < n; i++) {
      P[i] -= (min - 1);
      int x = P[i];
      if(x>0 && x<=n) {
          R[x] = 1;
      }
    }
 
    int sum=0;
    for(int i=0;i<=n;i++) {
        sum+=R[i];
    }
 
    if(sum==n) {
      for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
      }
    }
    else {
        cout << -1;
    }
}