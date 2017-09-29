/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let dp = new Array(s.length);
    dp[0] = 0;
    let ret = 0;
    for (let i = 1; i < s.length; i++) {
        dp[i] = 0;
        if (s[i] === ')') {
            if (s[i - 1] === '(') {
                dp[i] = dp[Math.max(i - 2, 0)] + 2;
            } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] === '(') {
                dp[i] = dp[i - 1] + 2;
                if (i - dp[i - 1] - 2 >= 0) {
                    dp[i] += dp[i - dp[i - 1] - 2];
                }
            }
        }
        ret = Math.max(ret, dp[i]);
    }
    return ret;
};