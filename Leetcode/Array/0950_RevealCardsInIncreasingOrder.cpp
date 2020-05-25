#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> d;
        d.emplace_back(deck[0]);
        
        for (int i = 1; i < deck.size(); ++i) {
            d.emplace_front(d.back());
            d.pop_back();
            d.emplace_front(deck[i]);
        }

        vector<int> res(d.begin(), d.end());
        return res;
    }

    vector<int> deckRevealedIncreasing1(vector<int>& deck) {
        int n = deck.size();
        if (n < 2)
            return deck;
        
        deque<int> index;
        for (int i = 0; i < n; ++i) {
            index.emplace_back(i);
        }

        vector<int> res(n);
        sort(deck.begin(), deck.end());
        for (int x : deck) {
            res[index.front()] = x;
            index.pop_front();

            if (!index.empty()) {
                index.emplace_back(index.front());
                index.pop_front();
            }
        }

        return res;
    }
};

void printRes(const vector<int>& res) {
    for (int x : res)
        cout << x << ", ";
    cout << endl;
}

void testDeckRevealedIncreasing() {
    Solution solution;
    vector<int> deck1 {17, 13, 11, 2, 3, 5, 7};
    auto res1 = solution.deckRevealedIncreasing(deck1);
    printRes(res1);
}

int main() {
    testDeckRevealedIncreasing();

    return 0;
}