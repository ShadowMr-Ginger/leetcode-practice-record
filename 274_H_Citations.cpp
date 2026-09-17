#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution274 {
public:

	// 计数排序法，O(n)
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) {
            return 0;
        }
        vector<int> citation_cnts(n + 1);
        for (int i = 0;i < n;i++) {
            if (citations[i] > n) {
                citation_cnts[n]++;
            }
            else {
                citation_cnts[citations[i]]++;
            }
        }

        int current_citation_papers = 0;
        for (int i = n;i >= 0;i--) {
            current_citation_papers += citation_cnts[i];
            if (i <= current_citation_papers) {
                return i;
            }
        }

        return 0;
    }
};

//int main() {
//	vector<int> citations = { 3, 0, 6, 1, 5 };
//	Solution274 sol;
//	int h_index = sol.hIndex(citations);
//	cout << "H-index: " << h_index << endl;
//	return 0;
//}