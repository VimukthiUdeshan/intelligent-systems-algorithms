# Game Playing Search – Minimax and Alpha-Beta Pruning

This practical implements two fundamental adversarial search algorithms in C++: **Minimax** and **Alpha-Beta Pruning**.

Developed as part of **Practical 4** for the **CO3205 – Intelligent Systems** course at the Department of Computer Engineering, University of Sri Jayewardenepura.

## Concepts Covered

- Adversarial search in two-player zero-sum games
- Complete binary game tree representation
- MAX and MIN decision-making
- Recursive Minimax algorithm
- Alpha-Beta Pruning optimization
- Leaf node evaluation and pruning analysis
- Optimal move selection

## Implementation

**Minimax:** Recursively evaluates the game tree, selecting maximum values at MAX levels and minimum values at MIN levels.

**Alpha-Beta Pruning:** Optimizes Minimax by eliminating branches that cannot influence the final decision using alpha and beta bounds.

The implementation also tracks evaluated and pruned leaf nodes and determines the optimal move for MAX.

## Input Format

```text
d
leaf_1 leaf_2 ... leaf_2^d
```

- `d` – Depth of the complete binary game tree.
- The remaining values represent terminal utility scores from left to right.

**Constraints:**
- `1 <= d <= 10`
- `-1000 <= utility[i] <= 1000`

## Sample Execution

**Input:**
```text
2
4 5 2 7
```

**Output:**
```text
Minimax Value: 4
Alpha-Beta Value: 4
Best Move: 1
Leaf Nodes Evaluated: 3
Leaf Nodes Pruned: 1
```

## Complexity Analysis

| Algorithm | Time Complexity |
|---|---|
| Minimax | O(2^d) |
| Alpha-Beta Pruning (worst case) | O(2^d) |
| Alpha-Beta Pruning (best case) | O(2^(d/2)) |

**Auxiliary Space:** O(d) due to recursive calls.

## Compilation and Execution

```bash
g++ -std=c++17 -O2 minimax_alpha_beta.cpp -o game_search
```

Run:

```bash
./game_search
```

On Windows:

```powershell
.\game_search.exe
```

## Learning Outcomes

- Understand adversarial search and game tree traversal.
- Implement Minimax using recursion.
- Apply Alpha-Beta Pruning to optimize search.
- Compare the evaluation efficiency of both algorithms.

## Related Report

See [`game_playing_search_report.pdf`](../../../../reports/game_playing_search_report.pdf) for the accompanying practical report.