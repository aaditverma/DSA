#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 

using namespace std;

struct Vegetable {
    int weight;
    double profit;
};

bool compare(Vegetable a, Vegetable b) {
    return (a.profit / a.weight) > (b.profit / b.weight);
}

double fractionalKnapsack(int capacity, vector<Vegetable>& vegetables) {
    sort(vegetables.begin(), vegetables.end(), compare);

    double totalProfit = 0.0;
    double remainingCapacity = capacity;

    for (const auto& veg : vegetables) {
        if (remainingCapacity >= veg.weight) {
            totalProfit += veg.profit;
            remainingCapacity -= veg.weight;
        } else {
            totalProfit += (veg.profit / veg.weight) * remainingCapacity;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n; 
    cout << "Enter the number of vegetable types: ";
    cin >> n;

    vector<Vegetable> vegetables(n);

    cout << "Enter the weight of each vegetable type:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vegetables[i].weight;
    }

    cout << "Enter the profit for each vegetable type:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vegetables[i].profit;
    }

    int capacity;
    cout << "Enter the capacity of the container available on that day: ";
    cin >> capacity;

    double maxProfit = fractionalKnapsack(capacity, vegetables);

    cout << "Total profit for the day: " << fixed << setprecision(2) << maxProfit << endl;

    return 0;
}