
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {

    // Base case
    if (n == 1) {
        cout << "Move disk 1 from "
             << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move n-1 disks to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move largest disk to destination
    cout << "Move disk " << n << " from "
         << source << " to " << destination << endl;

    // Step 3: Move n-1 disks to destination
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "Enter a positive number.\n";
        return 0;
    }

    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "Minimum moves: " << pow(2, n) - 1 << endl;

    return 0;
}
