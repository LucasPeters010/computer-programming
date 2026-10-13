#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Preserve the public signatures; choose your own private representation.

void encodeRuns(std::istream& input, std::ostream& output);

void decodeRuns(std::istream& input, std::ostream& output);
