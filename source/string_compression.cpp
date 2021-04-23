#include <ctci/one_away.hpp>
#include <string>
#include <iostream>

namespace ctci {

std::string string_compression(std::string s) {
    if (s.size() <= 2) {
        return s;
    }

    std::string output = "";
    output.push_back(s[0]);
    int count{0};

    for (unsigned int j = 1; j < s.size(); ++j) {
        ++count; // number of times s[j-1] has been repeated by index = j
        if (j != s.size() - 1) {
            if (s[j] != s[j-1]) {
                 output += std::to_string(count);
                 output += s[j];
                 count = 0;
            }
        } else {
            // Last character requires special logic
            if (s[j] != s[j-1]) {
                 output += s[j];
                 output += '1';
            } else {
                output += std::to_string(count + 1);
            }
        }
    }


    if (output.size() >= s.size()) {
        return s;
    } else {
        return output;
    }
};

} // namespace ctci
