#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Global counter for leaf nodes evaluated during Alpha-Beta Pruning
int leaf_evaluated_count = 0;

/**
 * Standard Minimax Algorithm
 * @param depth Current depth in the tree
 * @param nodeIndex Index of the current node in the current level/array representation
 * @param isMax True if current level is MAX, False if MIN
 * @param leaves Vector containing all terminal leaf utility values
 * @param targetDepth The total depth of the tree (d)
 */
int minimax(int depth, int nodeIndex, bool isMax, const vector<int>& leaves, int targetDepth) {
    // Base Case: Leaf node reached
    if (depth == targetDepth) {
        return leaves[nodeIndex];
    }

    if (isMax) {
        int left_child = minimax(depth + 1, nodeIndex * 2, false, leaves, targetDepth);
        int right_child = minimax(depth + 1, nodeIndex * 2 + 1, false, leaves, targetDepth);
        return max(left_child, right_child);
    } else {
        int left_child = minimax(depth + 1, nodeIndex * 2, true, leaves, targetDepth);
        int right_child = minimax(depth + 1, nodeIndex * 2 + 1, true, leaves, targetDepth);
        return min(left_child, right_child);
    }
}

/**
 * Alpha-Beta Pruning Algorithm
 * @param depth Current depth in the tree
 * @param nodeIndex Index of the current node
 * @param isMax True if current level is MAX, False if MIN
 * @param alpha Best value MAX can guarantee so far
 * @param beta Best value MIN can guarantee so far
 * @param leaves Vector containing all terminal leaf utility values
 * @param targetDepth The total depth of the tree (d)
 */
int alphaBeta(int depth, int nodeIndex, bool isMax, int alpha, int beta, const vector<int>& leaves, int targetDepth) {
    // Base Case: Leaf node reached
    if (depth == targetDepth) {
        leaf_evaluated_count++;
        return leaves[nodeIndex];
    }

    if (isMax) {
        int maxEval = -1e9; // Negative infinity representation
        
        // Evaluate Left Child
        int evalLeft = alphaBeta(depth + 1, nodeIndex * 2, false, alpha, beta, leaves, targetDepth);
        maxEval = max(maxEval, evalLeft);
        alpha = max(alpha, evalLeft);
        
        // Condition for pruning right branch
        if (beta <= alpha) {
            return maxEval; 
        }
        
        // Evaluate Right Child if not pruned
        int evalRight = alphaBeta(depth + 1, nodeIndex * 2 + 1, false, alpha, beta, leaves, targetDepth);
        maxEval = max(maxEval, evalRight);
        
        return maxEval;
    } else {
        int minEval = 1e9; // Positive infinity representation
        
        // Evaluate Left Child
        int evalLeft = alphaBeta(depth + 1, nodeIndex * 2, true, alpha, beta, leaves, targetDepth);
        minEval = min(minEval, evalLeft);
        beta = min(beta, evalLeft);
        
        // Condition for pruning right branch
        if (beta <= alpha) {
            return minEval;
        }
        
        // Evaluate Right Child if not pruned
        int evalRight = alphaBeta(depth + 1, nodeIndex * 2 + 1, true, alpha, beta, leaves, targetDepth);
        minEval = min(minEval, evalRight);
        
        return minEval;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d;
    if (!(cin >> d)) return 0;

    int num_leaves = 1 << d; // 2^d leaf nodes
    vector<int> leaves(num_leaves);
    for (int i = 0; i < num_leaves; ++i) {
        cin >> leaves[i];
    }

    // 1. Compute normal Minimax values for the root's branches to find the optimal move
    // Root is at depth 0 (MAX node). Left child is index 0 at depth 1, right child is index 1.
    int minimax_left = minimax(1, 0, false, leaves, d);
    int minimax_right = minimax(1, 1, false, leaves, d);
    int final_minimax_value = max(minimax_left, minimax_right);

    // 2. Compute Alpha-Beta values
    leaf_evaluated_count = 0; // Reset counter
    int final_alphabeta_value = alphaBeta(0, 0, true, -1e9, 1e9, leaves, d);

    // 3. Determine the Best Move
    // Move 1 = Left Child, Move 2 = Right Child. If values are equal, choose leftmost (1).
    int best_move = (minimax_left >= minimax_right) ? 1 : 2;

    // 4. Calculate total pruned leaf nodes
    int total_pruned = num_leaves - leaf_evaluated_count;

    // Print output exactly as specified by the output format format
    cout << "Minimax Value: " << final_minimax_value << "\n";
    cout << "Alpha-Beta Value: " << final_alphabeta_value << "\n";
    cout << "Best Move: " << best_move << "\n";
    cout << "Leaf Nodes Evaluated: " << leaf_evaluated_count << "\n";
    cout << "Leaf Nodes Pruned: " << total_pruned << "\n";

    return 0;
}
