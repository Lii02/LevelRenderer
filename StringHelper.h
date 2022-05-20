#ifndef STRINGHELPER_H
#define STRINGHELPER_H
#include <string>

namespace StringHelper {
    bool IsWhitespace(char c) {
        return (c == ' ') || (c == '\t') || (c == '\r');
    }

    void TrimString(std::string& str) {
        auto it = str.begin();
        while(it != str.end()) {
            if (IsWhitespace(*it)) {
				it = str.erase(it);
            } else {
                ++it;
            }
        }
    }
}

#endif