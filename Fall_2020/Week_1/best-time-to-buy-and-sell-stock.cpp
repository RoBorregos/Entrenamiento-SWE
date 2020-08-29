#include <iostream>
#include <vector>

using namespace std;

int maxProfit(const vector<int>& prices) {
    int min_price = INT_MAX;
    int max_profit = 0;
    for (const int price : prices) {
        if (price < min_price) {
            min_price = price;
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}

int main() {
    vector<int> test = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(test) << endl;
    return 0;
}