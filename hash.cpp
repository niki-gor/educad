#include "hash.h"

size_t Hash::operator()(const std::shared_ptr<Line>& ptr) const {
    return std::hash<std::string>()(std::to_string((size_t)&*ptr->first) + std::to_string((size_t)&*ptr->second));
}

bool operator==(const std::shared_ptr<Line>& lhs, const std::shared_ptr<Line>& rhs) {
    return lhs->first == rhs->first && lhs->second == rhs->second;
}