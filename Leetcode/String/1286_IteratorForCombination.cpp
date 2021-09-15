#include <string>
#include <vector>

using namespace std;
class CombinationIterator {
private:
    string s_;
    bool finished_;
    vector<int> pos_;

public:
    CombinationIterator(string characters, int combinationLength): s_(characters), finished_(false) {
        for (int i = 0; i < combinationLength; ++i) {
            pos_.push_back(i);
        }
    }
    
    string next() {
        string res;
        for (int p : pos_) {
            res.push_back(s_[p]);
        }

        int i = -1;
        for (int k = pos_.size() - 1; k >= 0; --k) {
            if (pos_[k] != s_.size() - pos_.size() + k) {
                i = k;
                break;
            }
        }

        if (i == -1)
            finished_ = true;
        else {
            ++pos_[i];
            for (int j = i + 1; j < pos_.size(); ++j) {
                pos_[j] = pos_[j - 1] + 1;
            }
        }

        return res;
    }
    
    bool hasNext() {
        return !finished_;
    }
};

void testCombinationIterator() {
    CombinationIterator ci("abc", 2);
    assert(ci.next() == "ab");
    assert(ci.hasNext());
    assert(ci.next() == "ac");
    assert(ci.hasNext());
    assert(ci.next() == "bc");
    assert(!ci.hasNext());
}

int main() {
    testCombinationIterator();

    return 0;
}