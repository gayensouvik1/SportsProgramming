#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;
 
    int C1[26];
    vector<int> I1[26];
    int C2[26];
    vector<int> I2[26];
    int q1 = 0;
    int q2 = 0;
    for(int i=0;i<26;i++) {
        C1[i] = 0;
        C2[i] = 0;
    }
 
    for(int i=0;i<n;i++) {
        if(s1[i]=='?') q1++;
        else {
            C1[s1[i]-'a']++;
            I1[s1[i]-'a'].push_back(i);
        }
        if(s2[i]=='?') q2++; 
        else {
            C2[s2[i]-'a']++;
            I2[s2[i]-'a'].push_back(i);
        }
    }
 
    int ans=0;
    for(int i=0;i<26;i++) {
        ans+=min(C1[i],C2[i]);
    }
    ans+=(q1+q2);
    if(ans>n) {
        ans = n;
    }
 
    cout << ans << endl;
 
    int ans1=0;
    for(int i=0;i<26;i++) {
        int sz = min(I1[i].size(),I2[i].size());
        for(int j=0;j<sz;j++) {
            cout << I1[i][j]+1 << " " << I2[i][j]+1 << endl;
            ans1++;
            s1[I1[i][j]] = '*';
            s2[I2[i][j]] = '*';
        }
    }
 
    vector<int> Q2;
    vector<int> D1;
    for(int i=0;i<n;i++) {
        if(s2[i]=='?') Q2.push_back(i);
        if(s1[i]!='?' && s1[i]!='*') D1.push_back(i);
    }
    
    int sz1 = min(D1.size(), Q2.size());
    for(int i=0;i<sz1;i++) {
        cout << D1[i]+1 << " " << Q2[i]+1 << endl;
        s1[D1[i]] = '*';
        s2[Q2[i]] = '*';
        ans1++;
    }
 
    vector<int> Q1;
    vector<int> D2;
    for(int i=0;i<n;i++) {
        if(s1[i]=='?') Q1.push_back(i);
        if(s2[i]!='?' && s2[i]!='*') D2.push_back(i);
    }
 
    int sz2 = min(D2.size(), Q1.size());
    for(int i=0;i<sz2;i++) {
        cout << Q1[i]+1 << " " << D2[i]+1 << endl;
        s1[Q1[i]] = '*';
        s2[D2[i]] = '*';    
        ans1++;
    }
 
    vector<int> QP1;
    vector<int> QP2;
    for(int i=0;i<n;i++) {
        if(s1[i]=='?') QP1.push_back(i);
        if(s2[i]=='?') QP2.push_back(i);
    }
 
    for(int i=0;i<ans-ans1;i++) {
        cout << QP1[i]+1 << " " << QP2[i]+1 << endl;
    }
}