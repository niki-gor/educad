#pragma once

#include <memory>
#include "line.h"

struct Hash {
    size_t operator()(const LinePtr& ptr) const;
};

bool operator==(const LinePtr& lhs, const LinePtr& rhs);