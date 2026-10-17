#include "exercise.hpp"

CopyBuffer::CopyBuffer(const CopyBuffer& other) : data(nullptr), length(0), allocated(0) {
    // TODO: Deep-copy the buffer, preserving both its used size and allocated capacity. Assume capacity >= 0. Copy the used values in order. Capacity 0 means data == nullptr. An empty buffer may still have positive capacity.
    (void)other;
    throw std::logic_error("Not implemented");
}
