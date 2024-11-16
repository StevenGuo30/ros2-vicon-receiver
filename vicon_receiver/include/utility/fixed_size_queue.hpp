#pragma once

#include <queue>
#include <deque>

namespace ViconReceiver{
namespace Utility{

template <typename T, int MaxLen, typename Container=std::deque<T>>
class FixedQueue : public std::queue<T, Container> {
public:

    /*
     * Overload push function to pop the front element if the queue is full
     */
    void push(const T& value) {
        if (this->size() >= MaxLen) {
            this->c.pop_front();
        }
        std::queue<T, Container>::push(value);
    }

    void push(T&& value) {
        if (this->size() >= MaxLen) {
            this->c.pop_front();
        }
        std::queue<T, Container>::push(std::move(value));
    }

    std::size_t max_size() const {
        return MaxLen;
    }
};

}   // namespace Utility
}   // namespace ViconReceiver
