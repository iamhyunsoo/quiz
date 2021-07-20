#include <sstream>
#include <string>

bool isValidSerialization(std::string preorder) {
    std::istringstream input(preorder);
    std::string val;
    int nums {1};
    while (std::getline(input, val, ',')) {
        if (--nums < 0)
            return false;
        if (val != "#")
            nums += 2;
    }
    return nums == 0;
}
