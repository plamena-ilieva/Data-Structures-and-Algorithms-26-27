#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr double EPS = 1e-7;

double xGuard, yGuard;
double xDrowner, yDrowner;
double vSand, vWater;

double totalTime(double xCrossing) {
    double sandDistance = hypot(xGuard - xCrossing, yGuard);
    double waterDistance = hypot(xDrowner - xCrossing, yDrowner);

    return sandDistance / vSand + waterDistance / vWater;
}

double ternarySearch(double left, double right) {
    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;

        if (totalTime(mid1) < totalTime(mid2)) {
            right = mid2;
        } else {
            left = mid1;
        }
    }

    return (left + right) / 2.0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> xGuard >> yGuard
            >> xDrowner >> yDrowner
            >> vSand >> vWater;

        double left = min(xGuard, xDrowner);
        double right = max(xGuard, xDrowner);

        double optimalCrossing = ternarySearch(left, right);

        cout << fixed << setprecision(5)
             << totalTime(optimalCrossing) << '\n';
    }
}
