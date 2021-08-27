vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(1024,vector<ll>(10)));
		for(int i = 0;i<n;i++){
			for(int j  =0;j<1024;j++){
				int x = s[i] - 'A';
				if(j & 1<<x == 0){
					for(int k = 0;k<10;k++){
						dp[i][(j | 1<<x)][x] += dp[i-1][j][k];
						dp[i][(j | 1<<x)][x] %= mod;
					}
				}
				else{
						dp[i][j][x] += dp[i-1][j][x] * 2;
						dp[i][j][x] %= mod;
					}
				}
			}
		}
		ll ans = 0;
		for(int i = 0;i<1024;i++){
			for(int j = 0;j<10;j++){
				ans += dp[n-1][i][j];
				ans = (ans%mod + mod)%mod;
			}
		}
