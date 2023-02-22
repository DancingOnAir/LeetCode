#include <iostream>
#include <vector>


using namespace std;
class LUPrefix {
private:
    vector<int> parents;
    vector<int> sz;
    int _n;

    int find(int p) {
        while (p != parents[p]) {
            parents[p] = parents[parents[p]];
            p = parents[p];
        }

        return p;
    }

    void unite(int p, int q) {
        int rp = find(p);
        int rq = find(q);

        if (rp != rq) {
            parents[rp] = parents[rq];
            sz[rq] += sz[rp];
        }
    }

    int getSize(int p) {
        return sz[find(p)];
    }

public:
    LUPrefix(int n) {
        for (int i = 0; i <= n; ++i) {
            parents.push_back(i);
        }

        sz.resize(n + 1, 0);
        _n = n;
    }
    
    void upload(int video) {
        ++sz[video];
        if (video > 1 && sz[video - 1] > 0) {
            unite(video - 1, video);
        }

        if (video < _n && sz[video + 1] > 0) {
            unite(video, video + 1);
        }
    }
    
    int longest() {
        return getSize(1);
    }
};

void testLUPrefix() {
    LUPrefix obj(4);
    obj.upload(3);
    cout << obj.longest() << endl;
    obj.upload(1);
    cout << obj.longest() << endl;
    obj.upload(2);
    cout << obj.longest() << endl;
}

int main() {
    testLUPrefix();
    return 0;
}