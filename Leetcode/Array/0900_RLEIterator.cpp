#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// class RLEIterator {
// private:
//     unordered_map<long long, int> count_;
//     queue<long long> keys_;
//     long long idx_;
//     long long len_;

// public:
//     RLEIterator(vector<int>& A): idx_(0) {
//         long long k = 0;
//         for (int i = 0; i < A.size() - 1; i += 2) {
//             if (A[i] == 0)
//                 continue;

//             k += A[i];
//             count_[k] = A[i + 1];
//             keys_.emplace(k);
//         }

//         len_ = k;
//     }
    
//     int next(int n) {
//         idx_ += n;
//         if (idx_ >= len_)
//             return -1;

//         while (idx_ > keys_.front()) {
//             keys_.pop();
//         }

//         return count_[keys_.front()];
//     }
// };

class RLEIterator {
private:
    vector<int> v_;
    int cur_;

public:
    RLEIterator(vector<int>& A): v_(A), cur_(0) {

    }
    
    int next(int n) {
        while (cur_ < v_.size() && n > v_[cur_]) {
            n -= v_[cur_];
            cur_ += 2;
        }

        if (cur_ >= v_.size())
            return -1;
        v_[cur_] -= n;

        return v_[cur_ + 1];
    }
};

void testRLEIterator() {
    vector<int> A1 {3, 8, 0, 9, 2, 5};
    RLEIterator relIterator1(A1);

    cout << relIterator1.next(2) << endl;
    cout << relIterator1.next(1) << endl;
    cout << relIterator1.next(1) << endl;
    cout << relIterator1.next(2) << endl;

    // [null,303,303,303,583,583,505]
    vector<int> A2 {784,303,477,583,909,505};
    RLEIterator relIterator2(A2);

    cout << relIterator2.next(130) << endl;
    cout << relIterator2.next(333) << endl;
    cout << relIterator2.next(238) << endl;
    cout << relIterator2.next(87) << endl;
    cout << relIterator2.next(301) << endl;
    cout << relIterator2.next(276) << endl;
}

int main() {
    testRLEIterator();

    return 0;
}