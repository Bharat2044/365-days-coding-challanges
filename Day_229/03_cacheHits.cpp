// Question Link: https://www.codechef.com/problems/CACHEHIT


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, b, m;
        cin >> n >> b >> m;

        vector<int> accesses(m);
        for (int i = 0; i < m; i++) {
            cin >> accesses[i];
        }

        // Initialize variables
        int currentBlock = -1;  // No block loaded initially
        int blockChanges = 0;

        for (int i = 0; i < m; i++) {
            // Calculate the block index of the current access
            int currentAccessBlock = accesses[i] / b;

            // Check if the block is already in the cache
            if (currentAccessBlock != currentBlock) {
                // Load the new block into the cache
                currentBlock = currentAccessBlock;
                blockChanges++;
            }
        }

        cout << blockChanges << endl;
    }

    return 0;
}
