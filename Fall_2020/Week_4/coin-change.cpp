/*
Problem: https://leetcode.com/problems/coin-change/

Approach: Use an array to save the minimum number of coins needed to have i
			amount of money.
			
Time complexity: O(n*m)

Space complexity: O(n)
*/

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int coinChange(const vector<int>& coins, int amount){
    int n=coins.size();
    if(amount==0) return 0;
    
    int dp[amount+1];
    dp[0]=0;
    for(int i=1;i<=amount;i++){
        dp[i]=INT_MAX-1;
    }
    
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(coins[j] <= i){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    if(dp[amount]<INT_MAX-1){
        return dp[amount];
    }
    else{
        return -1;
    }
}

int main() {
	vector<int> test = {1, 2, 5, 6, 7};
	int amount_test = 11;
	cout << coinChange(test, amount_test) << endl;
	return 0;
}
