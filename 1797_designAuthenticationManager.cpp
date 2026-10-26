#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution1797 {
public:
    Solution1797(int timeToLive) : time_to_live(timeToLive) {}

    void generate(string tokenId, int currentTime) {
        // 生成或覆盖该 token 的过期时间
        expire_time[tokenId] = currentTime + time_to_live;
    }

    void renew(string tokenId, int currentTime) {
        // 只有未过期 token 才能续期，过期时间必须严格大于当前时间
        auto it = expire_time.find(tokenId);
        if (it != expire_time.end() && it->second > currentTime) {
            it->second = currentTime + time_to_live;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for (auto it = expire_time.begin(); it != expire_time.end(); ++it) {
            if (it->second > currentTime) {
                ans++;
            }
        }
        return ans;
    }

private:
    int time_to_live;
    unordered_map<string, int> expire_time;
};

//int main() {
//	Solution1797 authentication_manager(5);
//	authentication_manager.generate("aaa", 1);
//	authentication_manager.renew("aaa", 2);
//	cout << authentication_manager.countUnexpiredTokens(6) << endl;
//	authentication_manager.generate("bbb", 7);
//	authentication_manager.renew("aaa", 8);
//	authentication_manager.renew("bbb", 10);
//	cout << authentication_manager.countUnexpiredTokens(15) << endl;
//	return 0;
//}
