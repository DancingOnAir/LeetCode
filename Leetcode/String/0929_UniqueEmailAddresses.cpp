#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> seen;
        for (auto& e : emails) {
            string realEmail;
            int i = 0;
            for (i = 0; i < e.size(); ++i) {
                if (e[i] == '+' || e[i] == '@')
                    break;
                if (e[i] == '.')
                    continue;
                realEmail += e[i];
            }

            realEmail += e.substr(e.find('@', i));
            seen.insert(realEmail);
        }
        
        return seen.size();
    }
};

void testNumUniqueEmails() {
    Solution solution;

    vector<string> emails1{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    assert(solution.numUniqueEmails(emails1) == 2);
    vector<string> emails2{"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    assert(solution.numUniqueEmails(emails2) == 3);
}

int main() {
    testNumUniqueEmails();
    return 0;
}
