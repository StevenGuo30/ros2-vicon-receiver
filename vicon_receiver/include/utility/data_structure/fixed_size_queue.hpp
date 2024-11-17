#pragma once

#include <deque>

namespace Utility {
namespace DataStructure {

template <typename T, int MaxLen>
class FixedQueue : public std::deque<T> {
public:

    /*
     * Overload push function to pop the front element if the queue is full
     */
    void push_back(const T& value) {
        if (this->size() >= MaxLen) {
            this->c.pop_front();
        }
        std::deque<T>::push_back(value);
    }

    void push_back(T&& value) {
        if (this->size() >= MaxLen) {
            this->c.pop_front();
        }
        std::deque<T>::push(std::move(value));
    }

    void emplace_back(const T& value) {
        if (this->size() >= MaxLen) {
            this->pop_front();
        }
        std::deque<T>::emplace_back(value);
    }

    void emplace_back(T&& value) {
        if (this->size() >= MaxLen) {
            this->pop_front();
        }
        std::deque<T>::emplace_back(std::move(value));
    }

    constexpr std::size_t max_size() const {
        return MaxLen;
    }
};

}   // namespace DataStructure
}   // namespace Utility
