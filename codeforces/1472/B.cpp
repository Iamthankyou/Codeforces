#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int m1=0,m2=0;
	int sum = 0;
	for (int i=0; i<n; i++){
		int t;
		cin >> t;
		if (t==1){
			m1++;
		}
		else{
			m2++;
		}
		
		sum+=t;
	}
	
	if (sum%2!=0 or m1%2!=0){
		cout << "NO\n";
		return;
	}
	else{
		
		int t = sum/2;
		sum/=2;
		
		bool ok = true;
		
		while ((m1>0 || m2>0) && (sum>0)){
			bool ok2 = false;
			
			if (m2>0 && sum-2>=0){
				sum-=2;
				m2--;
				ok2 = true;
			}
			else if (m1>0 && sum-1>=0){
				sum-=1;
				m1--;
				ok2 = true;
			}
			
			if (!ok2){
				ok = false;
				break;
			}
		}

//		cout << sum;
		
		if (m1+m2*2==t && ok){
			cout << "YES\n";
		}		
		else{
			cout << "NO\n";
		}
	}
}

int main(){
//	freopen("duy.in.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	
	while(t--){
		solve();
	}
}