#include<iostream>
#include<vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas{0};
    int totalCost{0};
    int tankGas{0};
    int firstStation{0};

    if(gas.size() != cost.size()) {
        return - 1;
    }

    for(int i = 0; i < n; i++) {
        totalGas += gas[i];
        totalCost += cost[i];

        tankGas += gas[i] - cost[i];

        if(tankGas < 0) {
            firstStation = i + 1;
            tankGas = 0;
        }
    }

    return (totalGas < totalCost) ? -1 : firstStation; 
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << "The Starting Station is: ";
    cout << canCompleteCircuit(gas, cost);
}