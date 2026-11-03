#include <array>
#include <iostream>
#include <string_view>
#include <vector>

constexpr std::array<std::string_view, 4> kColors = {
    "Yellow", "Red", "Green", "Blue"
};

bool isSafe(int country, int color,
            const std::vector<std::vector<int>>& adjacency,
            const std::vector<int>& assigned) {
    for (int neighbor : adjacency[country]) {
        if (assigned[neighbor] == color) {
            return false;
        }
    }
    return true;
}

bool solve(int country,
           const std::vector<std::vector<int>>& adjacency,
           std::vector<int>& assigned) {
    if (country == static_cast<int>(adjacency.size())) {
        return true;  // All countries have colors.
    }

    for (int color = 0; color < static_cast<int>(kColors.size()); ++color) {
        if (!isSafe(country, color, adjacency, assigned)) {
            continue;
        }

        assigned[country] = color;
        if (solve(country + 1, adjacency, assigned)) {
            return true;
        }
        assigned[country] = -1;  // Undo the choice (backtrack).
    }
    return false;
}

int main() {
    int countryCount, borderCount;
    if (!(std::cin >> countryCount >> borderCount) ||
        countryCount <= 0 || borderCount < 0) {
        std::cerr << "Invalid input: expected positive N and nonnegative M.\n";
        return 1;
    }

    std::vector<std::vector<int>> adjacency(countryCount);
    for (int i = 0; i < borderCount; ++i) {
        int u, v;
        if (!(std::cin >> u >> v) ||
            u < 1 || u > countryCount ||
            v < 1 || v > countryCount || u == v) {
            std::cerr << "Invalid border at line " << (i + 2) << ".\n";
            return 1;
        }

        --u;  // Convert 1-based input to 0-based indices.
        --v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);  // Borders go both ways.
    }

    std::vector<int> assigned(countryCount, -1);  // -1 = uncolored.
    if (!solve(0, adjacency, assigned)) {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    for (int country = 0; country < countryCount; ++country) {
        std::cout << country + 1 << ' ' << kColors[assigned[country]] << '\n';
    }
    return 0;
}
