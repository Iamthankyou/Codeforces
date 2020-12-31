#include <bits/stdc++.h>
using namespace std;

//babba
void solve(){
	string s;
	cin >> s;
	bool used[s.length()];
	int ans = 0;
	memset(used,false,sizeof(used));
	
	for (int i=1; i<s.length(); i++){
		if (s[i]==s[i-1] && !used[i-1]){
			used[i]=true;
		}
		
		if (i>=2 && s[i-2]==s[i] && !used[i-2]){
			used[i]=true;
		}
		
		ans+=used[i]==true;
	}
	
	cout << ans << "\n";
}

int main(){
//	freopen("duy.in.cpp","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	while (t--){
		solve();
	}
}
