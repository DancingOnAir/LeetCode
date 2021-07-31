#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool mutated = false;
        for (int i = 0; i < num.size(); ++i) {
            int before = num[i] - '0';
            int after = change[before];

            if (before < after) {
                mutated = true;
                num[i] = after + '0';
            }
            else if (before > after && mutated) {
                break;
            }
        }

        return num;
    }
};

void testMaximumNumber() {
    Solution solution;

    vector<int> change1{9,8,5,0,3,6,4,2,6,8};
    assert(solution.maximumNumber("132", change1) == "832");

    vector<int> change2{9,4,3,5,7,2,1,9,0,6};
    assert(solution.maximumNumber("021", change2) == "934");

    vector<int> change3{1,4,7,5,3,2,5,6,9,4};
    assert(solution.maximumNumber("5", change3) == "5");
}

int main() {
    testMaximumNumber();

    return 0;
}