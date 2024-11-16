#pragma once

#include <vector>
#include <limits>
#include <type_traits>

namespace Utility {
namespace Algorithm {

template <typename T, typename Matrix = std::vector<std::vector<T>> >
std::vector<std::size_t> hungarian_algorithm(const Matrix& cost_matrix) {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    // TODO: add assertion for 2D container

    constexpr auto SIZEMAX = std::numeric_limits<std::size_t>::max();

    const std::size_t n = cost_matrix.size();
    const std::size_t m = cost_matrix[0].size();

    std::vector<std::size_t> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    std::vector<std::size_t> minv(m + 1, SIZEMAX);
    std::vector<bool> used(m + 1, false);

    std::size_t i0;
    std::size_t j0, j1;
    std::size_t delta, cur;
    for (std::size_t i = 1; i <= n; ++i) {
        // initialize minv and used
        std::fill(minv.begin(), minv.end(), SIZEMAX);
        std::fill(used.begin(), used.end(), false);

        j0 = 0;
        p[0] = i;
        do {
            used[j0] = true;
            i0 = p[j0];

            delta = SIZEMAX;
            for (std::size_t j = 1; j <= m; ++j) {
                if (!used[j]) {
                    cur = cost_matrix[i0 - 1][j - 1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (std::size_t j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    std::vector<std::size_t> result(n);
    for (std::size_t j = 1; j <= m; ++j) {
        if (p[j] != 0) {
            result[p[j] - 1] = j - 1;
        }
    }
    return result;
}

} // namespace Algorithm
} // namespace Utility
