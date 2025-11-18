#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int>& S, vector<int>& subset, int n, int index, int currentSum, int target, bool& found) {
    // if current sum equals target
    if (currentSum == target) {
        found = true;
        cout << "{ ";
        for (int num : subset) cout << num << " ";
        cout << "}" << endl;
        return;
    }

    if (index == n || currentSum > target)
        return;

    // include 
    subset.push_back(S[index]);
    subsetSum(S, subset, n, index + 1, currentSum + S[index], target, found);

    // backttrack)
    subset.pop_back();
    subsetSum(S, subset, n, index + 1, currentSum, target, found);
}

int main() {
    int n, d;

    cout << "Enter number of elements in the set: ";
    cin >> n;

    vector<int> S(n);
    cout << "Enter elements of the set: ";
    for (int i = 0; i < n; i++)
        cin >> S[i];

    cout << "Enter desired sum d: ";
    cin >> d;

    vector<int> subset;
    bool found = false;

    cout << "\nSubsets with sum " << d << " are:\n";
    subsetSum(S, subset, n, 0, 0, d, found);

    if (!found)
        cout << "No subset found with the given sum.\n";

    return 0;
}
