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

    int totalCost[months][maxStor+1];

    // i = month, j = cars in storage
    for (int i = 0; i < months; i++) {
        for (int j = 0; j <= maxStor; j++) {
            for (int k = 0; k < maxStor - j; k++) {
                /*if (j == 0) {
                    totalCost[i][j] = fixedCost;
                }*/
                //else {
                    /*int k;
                    if (j < demand[i]) k = demand[i] - j;
                    else k = 0;*/
                    int temp = 0;
                    if (k > 0) temp = fixedCost;
                    totalCost[i][j] = min(temp + (j + k - demand[i]) * monthlyCost +
                                                      totalCost[i - 1][j + k - demand[i]], totalCost[i - 1][j]);
                //}
            }
        }
    }

    // print cost
    int cost = totalCost[months-1][0];
    cout << cost << endl << "----" << endl;

    // print matrix
    for (int i = 0; i < months; i++) {
        for (int j = 0; j < months; j++) {
            cout << totalCost[i][j] << " ";
        }
        cout << endl;
    }

    // print input
    cout << "----" << endl;
    cout << months << " " << fixedCost << " " << maxStor << " " << monthlyCost << endl;
    for (int i = 0; i < months; i++) {
        cout << demand[i] << endl;
    }

    return 0;
}
