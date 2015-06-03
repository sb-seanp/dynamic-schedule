//
// Created by Sean Prasertsit on 6/2/15.
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

    vector<int> demand;

    for (int i = 0; i < n; i++) {
        cin >> token;
        demand.push_back(stoi(token));
    }

    cout << n << " " << k << " " << s << " " << c << endl;
    for (int i = 0; i < n; i++) {
        cout << demand[i] << endl;
    }
    return 0;
}