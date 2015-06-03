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
    int n, k, s, c;

    string token;
    cin >> token;
    n = stoi(token);
    cin >> token;
    k = stoi(token);
    cin >> token;
    s = stoi(token);
    cin >> token;
    c = stoi(token);

    int total = 0; // total demand
    vector<int> demand;
    int orders[n][total];

    for (int i = 0; i < n; i++) {
        cin >> token;
        int monthD = stoi(token);
        total += monthD;
        demand.push_back(monthD);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < total; j++) {
            if (i == 0 || j == 0){
                orders[i][j] = 0;
            }
            else if (){

            }
            else {
                orders[i][j] = orders[i-1][j];
            }
        }

        cerr << "something" << endl;
    }

    int cost = orders[n][total];


    cout << n << " " << k << " " << s << " " << c << endl;
    for (int i = 0; i < n; i++) {
        cout << demand[i] << endl;
    }

    return 0;
}
