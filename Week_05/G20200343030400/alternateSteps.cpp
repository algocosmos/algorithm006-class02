#include <iostream>
#include <vector>
using namespace std;

/*
	用二维数组dp[boundary_step][distance]来表示第一步（或者是最后一步）上boundary_step个台阶，且总共走了distance个台阶的距离的走法数。
	这样递推关系由一个等式就升级为一组等式： 
	dp[1][n] = dp[2][n-1] + dp[3][n-1] // 先上1个台阶，剩下的n-1个台阶可以先上2个或3个台阶。 
	dp[2][n] = dp[1][n-2] + dp[3][n-2] // 先上2个台阶，剩下的n-2个台阶可以先上1个或3个台阶。 
	dp[3][n] = dp[1][n-3] + dp[2][n-3] // 先上3个台阶，剩下的n-3个台阶可以先上1个或2个台阶。 
	总走法数就是dp[1][n] + dp[2][n] + dp[3][n]。
*/

int alternateSteps(const int& n, const int& maxStep) {
    vector<vector<int>> dp(maxStep + 1, vector<int>(max(n, maxStep) + 1, 0));
    
	  // 当总步数小于最大步长时，逐步增大步长范围
	
    for (int step = 1; step <= maxStep; step++) {
        for (int i = 1; i < step; i++) {
            dp[i][step] = dp[0][step - i] - dp[i][step - i];
            dp[0][step] += dp[i][step];
        }
        dp[step][step] = 1;
        dp[0][step]++;
    }

	  // 用上所有可能的步长
	
    for (int step = maxStep + 1; step <= n; step++) {
        for (int i = 1; i <= maxStep; i++) {
            dp[i][step] = dp[0][step - i] - dp[i][step - i];
            dp[0][step] += dp[i][step];
        }
    }

    return dp[0][n];
}

int main()
{
    int maxStep = 3;
    int n = 6;
	for (int stairs = 0; stairs <= n; stairs++) {
        cout << "n = " << stairs << "  f_n = " << alternateSteps(stairs, maxStep) << endl;
    }
	
	return 0;
}
