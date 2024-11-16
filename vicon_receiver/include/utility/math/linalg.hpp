#pragma once

#include <cmath>
#include <iterator>
#include <stdexcept>
#include <type_traits>

namespace Utility{
namespace Math{

template <typename Container>
inline typename Container::value_type calculate_distance(const Container& a, const Container& b) {
    static_assert(std::is_arithmetic<typename Container::value_type>::value,
                  "Container value type must be arithmetic");

    // if (a.size() != b.size()) {
    //     throw std::invalid_argument("Both containers must have the same size");
    // }

    typename Container::value_type sum = 0;
    auto it_a = std::begin(a);
    auto it_b = std::begin(b);

    while (it_a != std::end(a) && it_b != std::end(b)) {
        sum += std::pow(*it_a - *it_b, 2);
        ++it_a;
        ++it_b;
    }

    return std::sqrt(sum);
}

} // namespace Math
} // namespace Utility
