# Intelligent Systems Algorithms

A growing collection of AI algorithms implemented in modern C++, with a focus on understanding the ideas, writing clear code, and improving performance over time.

## Implemented algorithms

| Topic | Problem | Technique | Status |
| --- | --- | --- | --- |
| Constraint Satisfaction (CSP) | Map coloring | Recursive backtracking | Implemented |

## CSP: Map coloring

The goal is to color a graph using at most four colors without giving adjacent countries the same color.

- **Variables:** Countries (vertices)
- **Domain:** Yellow, Red, Green, Blue
- **Constraint:** Neighboring countries must have different colors
- **Representation:** An undirected graph stored as an adjacency list (`std::vector<std::vector<int>>`)
- **Solver:** Depth-first recursive backtracking with an `isSafe()` constraint check

### Input format

First line: `N M`, where `N` is the number of countries and `M` is the number of borders.

Next `M` lines: two 1-based country numbers `u v` for each undirected border.

### Compile and run (g++)

From the repository root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/constraint_satisfaction/map_coloring/backtracking.cpp -o map_coloring
./map_coloring < examples/map_coloring/sample_input.txt
```

On Windows PowerShell, after compiling with `-o map_coloring.exe`, use:

```powershell
Get-Content examples/map_coloring/sample_input.txt | .\map_coloring.exe
```

### Build with CMake (optional)

```bash
cmake -S . -B build
cmake --build build
```

The executable will be in the build directory (or a configuration subdirectory such as `build/Debug` on some Windows generators).

### Example output

```text
YES
1 Yellow
2 Red
3 Yellow
4 Red
5 Green
6 Yellow
7 Green
8 Red
9 Yellow
10 Red
```

The solver returns `NO` if no valid coloring with the four colors exists.

## Project structure

```text
src/constraint_satisfaction/map_coloring/backtracking.cpp  # CSP solver
examples/map_coloring/sample_input.txt                      # Example graph
CMakeLists.txt                                               # Optional CMake build
.gitignore                                                   # Ignore generated files
README.md                                                    # Project documentation
```

## Future improvements

- Minimum Remaining Values (MRV) variable selection
- Degree heuristic and Least Constraining Value (LCV) ordering
- Forward checking
- Automated tests for valid, invalid, and unsatisfiable graphs
- Search algorithms such as BFS, DFS, and A*
- Benchmarks comparing naive and improved solvers

## Motivation

This project is an independent learning collection inspired by concepts studied in Intelligent Systems. It is organized as a growing algorithm portfolio rather than a collection of lab submissions.
