#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	
	for (auto &i:arr){
		cin >> i;
	}
	
	sort(arr.rbegin(),arr.rend());
	
	ll ans = 0;
	
	for (int i=0; i<n; i++){
		if (i%2){
			// Turn bod
			if (arr[i]%2){
				ans-=arr[i];
			}
			// Else bod + 0
		}
		else{
			if (arr[i]%2==0){
//				cout << arr[i];
				ans+=arr[i];
			}
		}
	}
	
	if (!ans){
		cout << "Tie\n";
	}
	else if (ans>0){
		cout << "Alice\n";
	}
	else{
		cout << "Bob\n";
	}
}

int main(){
//	freopen("duy.in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	
	while (t--){
		solve();
	}
}
