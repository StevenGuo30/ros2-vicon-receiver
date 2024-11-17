#pragma once

#include <deque>
#include <type_traits>

namespace Utility {
namespace Algorithm {

template <typename Container>
inline typename Container::value_type find_majority_element(const Container& nums) {
  typedef typename Container::value_type T;
  static_assert(std::is_integral<T>::value, "T must be an integral type");
  static_assert(std::is_same<typename Container::value_type, T>::value, "Container value type must be the same as T");

  T majority = nums.front();

  std::size_t count = 1;
  for (std::size_t i = 1; i < nums.size(); ++i) {
    if (count == 0) {
      majority = nums[i];
      count = 1;
    } else if (majority == nums[i]) {
      count++;
    } else {
      count--;
    }
  }

  // Verify if the found majority element is actually the majority
  count = 0;
  for (T num : nums) {
    if (num == majority) {
      count++;
    }
  }

  // If no majority element found, return the most recently stored element
  if (count <= nums.size() / 2) {
    return nums.back();
  }

  return majority;
}

} // namespace Algorithm
} // namespace Utility
