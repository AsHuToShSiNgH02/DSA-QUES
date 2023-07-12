#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> result;

void f(vector<int> &c, int idx, int t, vector<int> v) {
    if (t == 0) {
        result.push_back(v);
        return;
    }
    if (idx == c.size())
        return;
    if (c[idx] <= t) {
        v.push_back(c[idx]);
        f(c, idx + 1, t - c[idx], v);
        v.pop_back();
    }

    int j = idx + 1;
    while (j < c.size() && c[j] == c[j - 1])
        j++;
    f(c, j, t, v);
}

vector<vector<int>> combinationSum2(vector<int> &c, int target) {
    sort(c.begin(), c.end());
    vector<int> v;
    f(c, 0, target, v);
    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = combinationSum2(candidates, target);

    cout << "Possible combinations:" << endl;
    for (const auto &combination : combinations) {
        cout<<"[";
        for (const auto &num : combination) {
            cout << num<<" ";
        }
        cout <<"]"<< endl;
    }

    return 0;
}
