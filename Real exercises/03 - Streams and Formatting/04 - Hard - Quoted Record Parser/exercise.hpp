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

std::vector<std::string> parseRecord(const std::string& line);

void writeRecord(const std::vector<std::string>& fields, std::ostream& output);
