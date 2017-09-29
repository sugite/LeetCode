/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    if (word1.length === 0) {
        return word2.length;
    } else if (word2.length === 0) {
        return word1.length;
    }

    var dp = new Array(word2.length + 1);
    for (var i = 0; i < dp.length; i++) {
        dp[i] = new Array(word1.length + 1);
    }
    for (var i = 0; i < dp.length; i++) {
        for (var j = 0; j < dp[i].length; j++) {
            if (i === 0) {
                dp[i][j] = j;
            } else if (j === 0) {
                dp[i][j] = i;
            }
        }
    }

    for (var i = 1; i < dp.length; i++) {
        for (var j = 1; j < dp[i].length; j++) {
            if (word2[i - 1] === word1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[word2.length][word1.length];
};