#include <bits/stdc++.h>
#include <boost/date_time.hpp>
#include <boost/date_time/date.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace boost;
using namespace boost::posix_time;
using namespace boost::gregorian;

#define error(args...) { string _s = #args; \
replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); \
istream_iterator<string> _it(_ss); \
err(_it, args); }

void err(istream_iterator<string> it) {}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

template<typename... Args>
auto Func(Args... args) {
    return (args + ...);
}

void stupidSort(vector<int> &nums) {
    vector<int> idx(nums.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int k) {
        return floor(log10(nums.at(i))) < floor(log10(nums[k])) || (i < k);
    });
    vector<int> temp;
    temp.reserve(nums.size());
    for (auto i : idx) {
        temp.emplace_back(nums[i]);
    }
    std::copy(temp.begin(), temp.end(), nums.begin());
}

int findLongestChain(vector<pair<int, int>> pairs) {
    sort(pairs.begin(), pairs.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first || p1.second < p2.second;
    });
    vector<int> dp;
    dp.reserve(pairs.size());

    int i = 0;
    for (auto &p : pairs) {
        auto p2 = lower_bound(dp.begin(), dp.end(), p.second);
        if (p2 == dp.end() || p2 == dp.begin()) {
            dp.emplace_back(1);
        } else {
            dp.emplace_back(*(p2 - 1) + 1);
        }
    }
    return dp[pairs.size() - 1];
}

int main(int argc, char **argv) {
    cout << "Hello World!" << endl;
    return 0;
}
