#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int arr[n];
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	
	for (int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	for (int i=n; i>=0; i--){
		if (arr[i]+i<n){
			dp[i]=arr[i]+dp[i+arr[i]];
		}
		else{
			dp[i] = arr[i];
		}
	}
	
	int ans = 0;
	
	for (int i=0; i<n; i++){
		ans = max(ans,dp[i]);
	}
	
	cout << ans << "\n";
}

int main(){
//	freopen("duy.in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	
	while (t--){
		solve();
	}
	
}
