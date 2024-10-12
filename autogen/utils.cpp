#include "utils.h"

std::string posautogen_utils_camel2snake(const std::string& camel) {
    std::string snake_case;
    
    for (char ch : camel) {
        if (std::isupper(ch)) {
            if (!snake_case.empty()) {
                snake_case += '_';
            }
            snake_case += std::tolower(ch);
        } else {
            snake_case += ch;
        }
    }
    
    return snake_case;
}
