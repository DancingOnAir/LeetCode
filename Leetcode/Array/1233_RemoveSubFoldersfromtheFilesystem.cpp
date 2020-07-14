#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        for (auto& f : folder) {
            if (res.empty() || res.back().compare(0, res.back().size(), f, 0, res.back().size()) != 0 || f[res.back().size()] != '/') {
                res.emplace_back(f);
            }
        }

        return res;
    }
};

void printStrings(const vector<string>& strs) {
    for (auto& str : strs) {
        cout << str << ", ";
    }

    cout << endl;
}

void testRemoveSubfolders() {
    Solution solution;

    vector<string> folder1 {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    auto res1 = solution.removeSubfolders(folder1);
    printStrings(res1);

    vector<string> folder2 {"/a", "/a/b/c", "/a/b/d"};
    auto res2 = solution.removeSubfolders(folder2);
    printStrings(res2);

    vector<string> folder3 {"/a/b/c", "/a/b/ca", "/a/b/d"};
    auto res3 = solution.removeSubfolders(folder3);
    printStrings(res3);

    vector<string> folder4 {"/ah/al/am", "/ah/al"};
    auto res4 = solution.removeSubfolders(folder4);
    printStrings(res4);
}

int main() {
    testRemoveSubfolders();

    return 0;
}