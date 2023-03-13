#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto iter = upper_bound(letters.begin(), letters.end(), target);
        return iter == letters.end() ? letters[0] : *iter;
    }

    char nextGreatestLetter1(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        if (left < letters.size())
            return letters[left];
        return letters[0];
    }
};

void testNextGreatestLetter() {
    Solution solution;
    vector<char> letters1 {'c', 'f', 'j'};
    cout << solution.nextGreatestLetter(letters1, 'a') << endl;
    cout << solution.nextGreatestLetter(letters1, 'c') << endl;
    vector<char> letters2 {'x', 'x', 'y', 'y'};
    cout << solution.nextGreatestLetter(letters2, 'z') << endl;
}

int main() {
    testNextGreatestLetter();
    return 0;
}