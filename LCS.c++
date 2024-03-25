#include <bits/stdc++.h>
using namespace std;

// Values for direction
const int diagonal = 1;

int maxLength = 0;
unordered_set<string> results;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void printSequences(const vector<vector<int>>& cost, const vector<vector<int>>& direction, const string& s1,
                     const string& s2, int m, int n, string seq) {
    if (n == 0 || m == 0) {
        reverse(seq.begin(), seq.end());
        results.insert(seq);
        return;
    }

    string helper = seq;
    if (direction[m][n] == diagonal) {
        helper += s1[m - 1];
        printSequences(cost, direction, s1, s2, m - 1, n - 1, helper);
    } else {
        if (cost[m - 1][n] == cost[m][n - 1]) {
            printSequences(cost, direction, s1, s2, m - 1, n, helper);
            printSequences(cost, direction, s1, s2, m, n - 1, helper);
        } else if (cost[m - 1][n] == cost[m][n]) {
            printSequences(cost, direction, s1, s2, m - 1, n, helper);
        } else {
            printSequences(cost, direction, s1, s2, m, n - 1, helper);
        }
    }
}

void computeLcs(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Cost matrix
    vector<vector<int>> cost(m + 1, vector<int>(n+ 1, 0));
    // Direction matrix
    vector<vector<int>> direction(m + 1, vector<int>(n + 1, 0));

    // Compute cost matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cost[i][j] = cost[i - 1][j - 1] + 1;
                direction[i][j] = diagonal;
            } else {
                cost[i][j] = max(cost[i][j - 1], cost[i - 1][j]);
            }
        }
    }

    maxLength = cost[m][n];

    // Print cost matrix
    cout << "Cost Matrix" << endl;
    printMatrix(cost);

    cout << "Direction Matrix" << endl;
    printMatrix(direction);

    cout << "\nMaximum length of LCS: " << maxLength << endl;

    // Printing sequences
    printSequences(cost, direction, s1, s2, m, n, "");

    for (const string& s : results) {
        cout << s << endl;
    }
}

int main() {
    string s1 = "abaaba";
    string s2 = "babbab";
    computeLcs(s1, s2);

    return 0;
}