#pragma once

#include <cmath>
#include <iterator>
#include <stdexcept>
#include <type_traits>

namespace Utility{
namespace Math{

template <typename Container>  // Forcing container to be a same size
inline typename Container::value_type calculate_distance(const Container& a, const Container& b) {
    typedef typename Container::value_type T;

    static_assert(std::is_arithmetic<T>::value,
                  "Container value type must be arithmetic");
    static_assert(std::is_same<decltype(a.size()), decltype(b.size())>::value,
                  "Both containers must have a size() method of the same type.");

    T sum = 0;
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
