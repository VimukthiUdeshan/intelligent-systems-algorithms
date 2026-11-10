# Map Coloring — Constraint Satisfaction Problem

A C++ implementation of the **Map Coloring Problem** using recursive backtracking, demonstrating how Constraint Satisfaction Problems (CSPs) can be solved through systematic search and constraint checking.

## Problem Overview

The objective is to assign colors to countries on a map such that no two neighboring countries share the same color, using at most four available colors.

The problem is modeled as a Constraint Satisfaction Problem with the following components:

| Component | Description |
|---|---|
| Variables | Countries represented as graph vertices |
| Domain | Yellow, Red, Green, Blue |
| Constraints | Adjacent countries must have different colors |
| Representation | Undirected graph using an adjacency list |
| Solver | Recursive depth-first backtracking |

## Algorithm

The implementation uses **recursive backtracking** to explore possible color assignments.

The algorithm works as follows:

1. Select an uncolored country.
2. Try assigning one of the four available colors.
3. Check whether the selected color conflicts with any already-colored neighboring country.
4. If the assignment is valid, continue recursively with the next country.
5. If no color works, backtrack and try a different assignment.
6. If every country receives a valid color, return a successful solution.

## Implementation Details

- **Language:** C++
- **Standard:** C++17
- **Graph Representation:** `std::vector<std::vector<int>>`
- **Search Strategy:** Depth-First Search
- **Constraint Checking:** `isSafe()`
- **Backtracking:** Recursive function calls

## Input Format

The program reads the graph from standard input.

**First line:**

```text
N M
```

- `N` — Number of countries (vertices).
- `M` — Number of borders (edges).

**Next M lines:**

```text
u v
```

Each line represents an undirected border between countries `u` and `v`, using 1-based country numbering.

## Example

**Sample Input**

```text
10 11
1 2
1 3
2 3
2 4
3 4
3 5
4 5
4 6
5 6
6 7
7 8
```

*The input above is an illustrative graph. The actual sample input used by the implementation is available in the examples directory.*

**Example Output**

```text
YES
1 Yellow
2 Red
3 Green
4 Yellow
5 Red
6 Green
7 Yellow
8 Red
```

The exact coloring may vary depending on the graph and the order in which colors are tested. A valid solution must ensure that every pair of adjacent countries has different colors.

If no valid assignment can be found using the four available colors, the program outputs:

```text
NO
```

## Compile and Run

Run the following commands from the repository root.

**Compile using g++:**

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/constraint_satisfaction/map_coloring/backtracking.cpp -o map_coloring
```

**Run using the sample input:**

Linux / macOS:

```bash
./map_coloring < examples/map_coloring/sample_input.txt
```

Windows PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic src/constraint_satisfaction/map_coloring/backtracking.cpp -o map_coloring.exe

Get-Content examples/map_coloring/sample_input.txt | .\map_coloring.exe
```

## Complexity

Let `N` represent the number of countries and `K` the number of available colors.

- **Worst-case time complexity:** O(K^N × (N + M)) as a broad upper bound for this backtracking approach with adjacency-based constraint checking.
- **Space complexity:** O(N + M), including graph storage, color assignments, and recursive call stack.

The actual execution time depends on the graph structure and how early invalid assignments are detected.

## Project Files

```text
map_coloring/
├── backtracking.cpp
└── README.md
```

**Example input:**

[`examples/map_coloring/sample_input.txt`](../../../../examples/map_coloring/sample_input.txt)

## Learning Outcomes

- Understand how a problem can be modeled as a Constraint Satisfaction Problem.
- Represent graph relationships using an adjacency list.
- Apply recursive backtracking to explore possible solutions.
- Enforce constraints during variable assignments.
- Understand how backtracking avoids continuing with invalid partial solutions.

---

Part of the [Intelligent Systems Algorithms](../../../../README.md) repository.