/*
 * DP 解法
 * 状态转移方程：
 * 若str[i] == str[j]，若dp[i+1][j-1] == 1，则str[i...j]是回文串
 * 若str[i] != str[j]，dp[i][j] = 1
 */
string longestPalindromeDP(string s) {
	if (s == "") return s;
	int len = s.size();
	if (len == 1) return s;
	
	int longest = 1; // 最长的长度
	int start = 0; // 最长回文串的起点
	vector< vector<int> > dp(len, vector<int>(len));

	// 初始化dp数组，dp[i][i] = 1，若s[i] == s[i+1](连续两字符相同)，则dp[i]dp[i+i] = 1
	for(int i = 0; i < len; i++) {
		dp[i][i] = 1;

		if (i < len - 1) {
			if (s[i] == s[i+1]) {
				dp[i][i+1] = 1;
				start = i;
				longest = 2;
			}
		}
	}

	// 开始解决字串
	for (int i = 3; i <= len; i++) { // 字串长度
		for (int t = 0; i + t - 1 < len; t++) { // 字串起点
			int e = i + t - 1; // 终点

			if (s[t] == s[e] && dp[t+1][e-1] == 1) {
				dp[t][e] = 1;
				start = t;
				longest = i;
			}
		}
	}

	return s.substr(start, longest);
}
