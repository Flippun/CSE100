#include <string>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Helper class to implement a Disjoint Set data structure.
class DisjointSet {
    private:
        /**
         * Stores the parent of each element
         */
        unordered_map<string, string> parent;

        /**
         * Stores the size of each set
         */
        unordered_map<string, int> rank;

    public:
        /** 
         * Constructor:  Initialize each element as a separate Set
         * @param nodes A vector<string> containg each node label.
         */
        DisjointSet(vector<string> nodes) {
            for (string node: nodes) {
                parent[node] = node;
                rank[node] = 1;
            }
        }

         /** 
         * Find the sentinel of the set containing node, performing path compression.
         * @param node Label of the node whose sentinel is to be found.
         */
        string find(string node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]); 
            }
            return parent[node];
        }

        /** 
         * Join the two sets containing nodes 'x' and 'y' through union-by-size.
         * @param x Node within set to be joined
         * @param y Node within set to be joined
         */
        void unionSets(string x, string y) {
            string sentinelX = find(x);
            string sentinelY = find(y);

            if (sentinelX == sentinelY) {
                return;
            }
            
            if (rank[sentinelX] < rank[sentinelY]) {
                parent[sentinelX] = sentinelY;
                rank[sentinelY] += rank[sentinelX];
            } 
            else {
                parent[sentinelY] = sentinelX;
                rank[sentinelX] += rank[sentinelY];
            }
        }
};
