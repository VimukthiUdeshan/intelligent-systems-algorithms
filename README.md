# Intelligent Systems Algorithms

A growing collection of Artificial Intelligence algorithms implemented in **modern C++**. This repository explores fundamental AI concepts through practical implementations, with an emphasis on understanding algorithms, problem-solving techniques, and computational efficiency.

The implementations are organized by topic, making it easier to explore different approaches to intelligent problem-solving.

## Implemented Algorithms

| Area | Problem | Algorithm / Technique | Status |
|---|---|---|---|
| Constraint Satisfaction | Map Coloring | Recursive Backtracking | Implemented |
| Game Playing Search | Adversarial Game Tree | Minimax, Alpha-Beta Pruning | Implemented |

## Repository Contents

### 1. Constraint Satisfaction Problems (CSP)

**Map Coloring — Recursive Backtracking**

A constraint satisfaction problem in which neighboring regions must be assigned different colors using a maximum of four available colors.

- Graph representation using an adjacency list.
- Recursive depth-first search.
- Constraint checking through backtracking.

**Implementation:** [`src/constraint_satisfaction/map_coloring/`](src/constraint_satisfaction/map_coloring/)

**Documentation:** [`Map Coloring README`](src/constraint_satisfaction/map_coloring/README.md)

### 2. Game Playing Search

**Minimax and Alpha-Beta Pruning**

Adversarial search algorithms used in two-player, zero-sum games. The implementation evaluates a complete binary game tree to determine the optimal decision for the maximizing player.

- Recursive Minimax evaluation.
- MAX and MIN player decision-making.
- Alpha-Beta Pruning to eliminate unnecessary evaluations.
- Comparison of evaluated and pruned leaf nodes.

**Implementation:** [`src/game_playing_search/minimax_alpha_beta/`](src/game_playing_search/minimax_alpha_beta/)

**Documentation:** [`Minimax and Alpha-Beta README`](src/game_playing_search/minimax_alpha_beta/README.md)

**Practical Report:** [`Game Playing Search Report`](reports/Game_playing_search_report.pdf)

## Project Structure

```text
intelligent-systems-algorithms/
│
├── src/
│   ├── constraint_satisfaction/
│   │   └── map_coloring/
│   │       ├── backtracking.cpp
│   │       └── README.md
│   │
│   └── game_playing_search/
│       └── minimax_alpha_beta/
│           ├── minimax_alpha_beta.cpp
│           └── README.md
│
├── examples/
│   ├── map_coloring/
│   │   └── sample_input.txt
│   │
│   └── game_playing_search/
│       └── minimax_alpha_beta/
│           ├── sample_input.txt
│           └── sample_output.txt
│
├── reports/
│   └── Game_playing_search_report.pdf
│
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Technologies

- **Language:** C++
- **Standard:** C++17
- **Build System:** CMake
- **Compiler:** GCC / G++

## Getting Started

Clone the repository:

```bash
git clone https://github.com/VimukthiUdeshan/intelligent-systems-algorithms.git
cd intelligent-systems-algorithms
```

Compile individual implementations using the instructions provided in their respective README files.

Alternatively, build the project using CMake:

```bash
cmake -S . -B build
cmake --build build
```

## Future Improvements

This repository will continue to grow with implementations of additional Artificial Intelligence concepts and algorithms.

Potential additions include:

- **Search Algorithms:** Breadth-First Search (BFS), Depth-First Search (DFS), and A* Search.
- **Constraint Satisfaction:** Minimum Remaining Values (MRV), Degree Heuristic, Least Constraining Value (LCV), and Forward Checking.
- **Game Playing:** Additional adversarial search strategies and game tree optimizations.
- **Performance Analysis:** Benchmarking and comparing different algorithmic approaches.

## Motivation

This project serves as an independent learning and implementation portfolio inspired by concepts studied in Intelligent Systems. Its goal is to build a practical understanding of Artificial Intelligence algorithms through clear implementations, experimentation, and continuous improvement.

---

*Exploring intelligent problem-solving, one algorithm at a time.*