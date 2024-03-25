#include <iostream>
#include <climits>
#include <vector>
using namespace std;

static char name = 'A';

void printParenthesis(int i, int j, int n, vector<vector<int>>& partition) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << '(';
    printParenthesis(i, partition[i][j], n, partition);
    printParenthesis(partition[i][j] + 1, j, n, partition);
    cout << ')';
}

int main() {
    int n = 5;
    int dimensions[] = {5, 4, 6, 2, 7};

    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> partition(n, vector<int>(n, 0));

    int j, min, q;
    for (int d = 1; d < n - 1; d++) {
        for (int i = 1; i < n - d; i++) {
            j = i + d;
            min = INT_MAX;
            for (int k = i; k < j; k++) {
                q = cost[i][k] + cost[k + 1][j] + (dimensions[i - 1] * dimensions[j] * dimensions[k]);
                if (q < min) {
                    min = q;
                    partition[i][j] = k;
                }
            }
            cost[i][j] = min;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << partition[i][j] << " ";
        }
        cout << endl;
    }

    printParenthesis(1, n - 1, n, partition);

    return 0;
}
