#pragma once

#include <memory>
#include "line.h"

struct Hash {
    size_t operator()(const std::shared_ptr<Line>& ptr) const;
};

bool operator==(const std::shared_ptr<Line>& lhs, const std::shared_ptr<Line>& rhs);