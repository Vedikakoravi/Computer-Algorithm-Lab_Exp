#include<iostream>
using namespace std;

const int MAX_VILLAGES = 10;
int ary[MAX_VILLAGES][MAX_VILLAGES], completed[MAX_VILLAGES], n, cost = 0;

// Function declaration for least
int least(int c);

void takeInput() {
    int i, j;
    cout << "Enter the number of villages: ";
    cin >> n;
    cout << "\nEnter the Cost Matrix\n";
    for (i = 0; i < n; i++) {
        cout << "\nEnter Elements of Row: " << i + 1 << endl;
        for (j = 0; j < n; j++)
            cin >> ary[i][j];
        completed[i] = 0;
    }
    cout << "\n\nThe cost list is:\n";
    for (i = 0; i < n; i++) {
        cout << endl;
        for (j = 0; j < n; j++)
            cout << "\t" << ary[i][j];
    }
}

void mincost(int city) {
    int i, ncity;
    completed[city] = 1;
    cout << city + 1 << "--->";
    ncity = least(city);
    if (ncity == 999) {
        ncity = 0;
        cout << ncity + 1;
        cost += ary[city][ncity];
        cost += ary[ncity][0]; // Add the cost of the edge from the last vertex back to the starting vertex
        return;
    }
    mincost(ncity);
}

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++) {
        if ((ary[c][i] != 0) && (completed[i] == 0))
            if (ary[c][i] < min) {
                min = ary[c][i];
                kmin = ary[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

int main() {
    takeInput();
    cout << "\n\nThe Path is:\n";
    mincost(0); //passing 0 because starting vertex
    cout << "\n\nMinimum cost is " << cost << endl;
    return 0;
}
