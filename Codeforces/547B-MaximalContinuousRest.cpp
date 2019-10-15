#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    vector<int> B;
    for(int i=0;i<n;i++) {
        B.push_back(A[i]);
    }
    for(int i=0;i<n;i++) {
        B.push_back(A[i]);
    }
 
    int maxc=0, c=0;
    for(int i=0;i<B.size();i++) {
        if(B[i]==0) {
            if(maxc<c) {
                maxc = c;
            }
            c = 0;
        }
        else {
            c++;
        }
    }
    if(maxc<c) {
        maxc = c;
        c = 0;
    }
    cout << maxc;
}