#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n; cin >> n;
    string ans = "989";
 
    if (n<3){
        cout << ans.substr(0,n) << "\n";
        return;
    }
    
    cout << ans;
 
    for (int i=3; i<n; i++){
        cout << (i-3)%10;
    }
 
    cout << "\n";
}
 
int main(){
    // freopen("duy.in","r",stdin);
    // freopen("duy.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
 
    while (t--){
        solve();
    }
}