#include <vector>
#include <string>

using namespace std;
class Solution {
private: 
    bool isMatch(const string& q, const string& p) {
        int i = 0;
        for (auto& c : q) {
            if (i < p.size() && c == p[i])
                ++i;
            else if (c < 'a')
                return false;
        }

        return i == p.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (auto& q : queries)
            res.push_back(isMatch(q, pattern));
        return res;
    }
};

void testCamelMatch() {
    Solution solution;

    vector<string> q1{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string p1{"FB"};
    vector<bool> res1{true,false,true,true,false};
    assert(solution.camelMatch(q1, p1) == res1);

    vector<string> q2{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string p2{"FoBa"};
    vector<bool> res2{true,false,true,false,false};
    assert(solution.camelMatch(q2, p2) == res2);

    vector<string> q3{"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string p3{"FoBaT"};
    vector<bool> res3{false,true,false,false,false};
    assert(solution.camelMatch(q3, p3) == res3);
}

int main() {
    testCamelMatch();

    return 0;
}