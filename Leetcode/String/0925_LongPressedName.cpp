#include <string>

using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto m = name.size(), n = typed.size();
        unsigned int i = 0;
        for (auto j = 0; j < n; ++j) {
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        }

        return m == i;
    }
};

void testIsLongPressedName() {
    Solution solution;

    assert(solution.isLongPressedName("alex", "aaleex"));
    assert(!solution.isLongPressedName("saeed", "ssaaedd"));
    assert(solution.isLongPressedName("leelee", "lleeelee"));
    assert(solution.isLongPressedName("laiden", "laiden"));
}

int main() {
    testIsLongPressedName();

    return 0;
}