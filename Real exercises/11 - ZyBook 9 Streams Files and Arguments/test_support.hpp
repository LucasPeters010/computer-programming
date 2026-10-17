#pragma once
// Supplied TEST infrastructure. No need to study or edit this file.
#include <filesystem>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
namespace test {
inline void check(bool ok, const std::string& label) {
    if (!ok) throw std::runtime_error("Check failed: " + label);
}
template<class Error, class Action>
void expect(Action action, const std::string& message) {
    try { action(); }
    catch (const Error& e) {
        check(e.what() == message, "exception message: " + message);
        return;
    }
    throw std::runtime_error("Expected exception: " + message);
}
// Only files in a NEW, uniquely created temporary directory are touched.
// Test filenames never overwrite the user's files or depend on the working directory.
struct TempFiles {
    std::filesystem::path directory;
    TempFiles() {
        const std::string stamp=std::to_string(std::chrono::steady_clock::now().time_since_epoch().count());
        for (int i=0;i<100;++i) {
            std::filesystem::path candidate=std::filesystem::temp_directory_path()/ ("cp_zy9_"+stamp+"_"+std::to_string(i));
            if (std::filesystem::create_directory(candidate)) { directory=candidate; return; }
        }
        throw std::runtime_error("Could not create test directory");
    }
    ~TempFiles() { std::error_code ignored; std::filesystem::remove_all(directory,ignored); }
    std::string path(const std::string& name) const {return (directory/name).string();}
    std::string write(const std::string& name,const std::string& content) {
        std::ofstream file(path(name),std::ios::binary);
        if(!file) throw std::runtime_error("Test fixture could not open");
        file<<content; file.close();
        if(!file) throw std::runtime_error("Test fixture could not write");
        return path(name);
    }
    std::string read(const std::string& name) const {
        std::ifstream file(path(name));
        if(!file) throw std::runtime_error("Expected output file missing");
        std::ostringstream text; text<<file.rdbuf(); return text.str();
    }
};
}
