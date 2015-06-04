//
// Created by Sean Prasertsit on 6/2/15.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {

    // # of months, cost of making an order, max storage size, monthly cost of storing a car
    int months, fixedCost, maxStor, monthlyCost;

    string token;
    cin >> token;
    months = stoi(token);
    cin >> token;
    fixedCost = stoi(token);
    cin >> token;
    maxStor = stoi(token);
    cin >> token;
    monthlyCost = stoi(token);

    vector<int> demand;

    for (int i = 0; i < months; i++) {
        cin >> token;
        demand.push_back(stoi(token));
    }

    reverse(demand.begin(), demand.end());

    int purchased = 0;
    int totalCost[months][maxStor];

    // i = month, j = cars in storage
    for (int i = 0; i < months; i++) {
        for (int j = 0; j < maxStor; j++) {
            if (i == 0 || j == 0){
                totalCost[i][j] = fixedCost;
            }
            else if (demand[i] >= 0) {
                // purchased - k
                purchased = maxStor - j;
                totalCost[i][j] = min(fixedCost + (j + purchased - demand[i])*monthlyCost + totalCost[i-1][j + purchased - demand[i]], totalCost[i-1][j]);
            }
            else {
                totalCost[i][j] = totalCost[i-1][j];
            }
        }

        cerr << totalCost[i][maxStor] << endl;
    }

    int cost = totalCost[months][maxStor];
    cout << cost << endl;


    cout << months << " " << fixedCost << " " << maxStor << " " << monthlyCost << endl;
    for (int i = 0; i < months; i++) {
        cout << demand[i] << endl;
    }

    return 0;
}
