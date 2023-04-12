#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& price) {
    int length = price.size();
    if (length < 2) return 0;

    //max profit 1                                                                                                 
    vector<int> max_profit1(length);
    int min_price = price[0];
    for (int i = 1; i < length; i++) {
        min_price = min(min_price, price[i]);
        max_profit1[i] = max(max_profit1[i-1], price[i] - min_price);
    }
    
    //max profit 2
    vector<int> max_profit2(length);
    int max_price = price[length-1];
    for (int i = length-2; i >= 0; i--) {
        max_price = max(max_price, price[i]);
        max_profit2[i] = max(max_profit2[i+1], max_price - price[i]);
    }
    
    // find maximum overall profit
    int max_profit = 0;
    for (int i = 0; i < length; i++) {
        max_profit = max(max_profit, max_profit1[i] + max_profit2[i]);
    }
    
    return max_profit;
}

int main() {
    //size of array with prices
    int price_vals, maximum_profit;
    vector<int> price;

    cout<<"Enter the price of silicon (enter -1 to stop): "<<endl;
    while(cin >> price_vals && price_vals != -1){
        price.push_back(price_vals);

    }
    
    //int maximum_profit;
    //vector<int> price = {5,4,1,2,8};
    maximum_profit = maxProfit(price);
    cout << maximum_profit << endl; 
    
    return 0;
}
