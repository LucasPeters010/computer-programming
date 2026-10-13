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

class Catalogue {
public:
    Catalogue();
    int addFolder(int parentId, std::string name);
    void addFile(int folderId, std::string name, int bytes);
    long long totalBytes(int folderId) const;
    std::string outline(int folderId) const;

private:
    // Choose fields and helper declarations.
};
