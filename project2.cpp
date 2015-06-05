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

    //reverse(demand.begin(), demand.end());

    int totalCost[months+1][maxStor+1];
    for (int i = 0; i < maxStor + 1; i++) {
        totalCost[0][i] = 50;
    }

    // i = month, j = cars in storage
    for (int i = 0; i < months; i++) {
        for (int j = 1; j < maxStor; j++) {
            if (demand[i] > j) {
                int inventory; // inventory to order not covered by storage
                if (demand[i] > j) inventory = demand[i] - j;
                else inventory = 0;

                int productCost = 0; // if inventory ordered, add a fixed cost
                if (inventory > 0) productCost = fixedCost;

                totalCost[i][j] = min(productCost + (j + inventory - demand[i]) * monthlyCost +
                                                    totalCost[i - 1][j + inventory - demand[i]], totalCost[i - 1][j]);
                //cout << cost << endl;
            }
            else
                totalCost[i][i] = totalCost[i-1][j];
        }
    }

    // print cost
    int cost = totalCost[months][maxStor];
    cout << cost << endl << "----" << endl;

    // print matrix
    for (int i = 0; i < months; i++) {
        for (int j = 0; j < maxStor; j++) {
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
