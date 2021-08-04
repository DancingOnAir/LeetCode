#include <string>

using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (isdigit(s[i]) || isalpha(s[i])) {
                if (res.size() % (k+1) == k)
                    res += '-';
                res += toupper(s[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

void testLicenseKeyFormatting() {
    Solution solution;

    assert(solution.licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
    assert(solution.licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
}

int main() {
    testLicenseKeyFormatting();

    return 0;
}