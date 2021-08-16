#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class BIT {
private:
    vector<int> tree;
    int n;

public:
    BIT(int _n): n(_n), tree(n + 1) {

    }

    static int lowbit(int x) {
        return x & (-x);
    }

    void update(int x) {
        while (x <= n) {
            ++tree[x];
            x += lowbit(x);
        }
    }

    int query(int x) const {
        int res = 0;
        while (x) {
            res += tree[x];
            x -= lowbit(x);
        }

        return res;
    }

    int query(int x, int y) const {
        return query(y) - query(x - 1);
    }
};

class Solution {
public:
    // BIT
    string minInteger(string num, int k) {
        int n = num.size();
        vector<queue<int>> pos(10);

        for (int i = 0; i < n; ++i) {
            pos[num[i] - '0'].push(i + 1);
        }

        string res;
        BIT bit(n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (!pos[j].empty()) {
                    int behind = bit.query(pos[j].front() + 1, n);
                    int dist = pos[j].front() + behind - i;

                    if (dist <= k) {
                        bit.update(pos[j].front());
                        pos[j].pop();

                        res += (j + '0');
                        k -= dist;
                        break;
                    }
                }
            }
        }

        return res;
    }

    // TLE
    string minInteger1(string num, int k) {
        if (k <= 0)
            return num;

        int n = num.size();
        if (k >= n * (n - 1) / 2) {
            sort(num.begin(), num.end());
            return num;
        }

        for(int i = 0; i < 10; ++i){
            int idx = num.find(to_string(i));
            if(idx >= 0 && idx <= k)
                return num[idx] + minInteger(num.substr(0, idx) + num.substr(idx + 1), k - idx);
        }

        return num;
    }
};

void testMinInteger() {
    Solution solution;

    assert(solution.minInteger("4321", 4) == "1342");
    assert(solution.minInteger("100", 1) == "010");
    assert(solution.minInteger("36789", 1000) == "36789");
    assert(solution.minInteger("22", 22) == "22");
    assert(solution.minInteger("9438957234785635408", 23) == "0345989723478563548");
}

int main() {
    testMinInteger();

    return 0;
}