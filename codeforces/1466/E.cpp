#include <bits/stdc++.h>
using namespace std;

const int modulo = 1e9+7;

void solve(){
	int n ;
	cin >> n;
	long long int arr[n];
	int cntBit[61];
	int ans = 0;
	memset(cntBit,0,sizeof(cntBit));
	
	for (int i=0; i<n; i++){
		cin >> arr[i];
		for (int j=0; j<60; j++){
			cntBit[j]+=arr[i]>>j&1;
			// bit j th of arr[i]
		}
//		cout << arr[i] << " ";
	}
	
	for (int i=0; i<n; i++){
		long long int sumOr = 0;
		long long int sumAnd = 0;
		
		for (int j=0; j<60; j++){
			if (arr[i]>>j&1){
				sumOr+=(1LL<<j)%modulo*n;
				sumAnd+=(1LL<<j)%modulo*cntBit[j];
			}
			else{
				sumOr+=(1LL<<j)%modulo*cntBit[j];
			}
		}
		
		sumOr%=modulo;
		sumAnd%=modulo;
		
		ans=(ans+1LL*sumOr*sumAnd)%modulo;
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
	
	while(t--){
		solve();
	}
}