#include "hash.h"

size_t Hash::operator()(const LinePtr& ptr) const {
    return std::hash<std::string>()(std::to_string((size_t)&*ptr->first) + std::to_string((size_t)&*ptr->second));
}

bool operator==(const LinePtr& lhs, const LinePtr& rhs) {
    return lhs->first == rhs->first && lhs->second == rhs->second;
}