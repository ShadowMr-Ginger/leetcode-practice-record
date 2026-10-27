#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution207 {
public:
    // 1. 构建邻接表和入度数组
    // 2. 用 Kahn 算法做拓扑排序，能学完所有课程说明无环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (int i = 0;i < prerequisites.size();i++) {
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            graph[pre].push_back(course);
            indegree[course]++;
        }

        // 入度为 0 的课程先入队
        queue<int> que;
        for (int i = 0;i < numCourses;i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        // BFS 不断取出并移除课程
        int finished = 0;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            finished++;
            for (int i = 0;i < graph[cur].size();i++) {
                int next = graph[cur][i];
                if (--indegree[next] == 0) {
                    que.push(next);
                }
            }
        }

        // 全部修完则无环，可以完成课程
        return finished == numCourses;
    }
};

//int main() {
//	Solution207 s;
//	int numCourses = 2;
//	vector<vector<int>> prerequisites = {{1, 0}};
//	cout << s.canFinish(numCourses, prerequisites) << endl;
//	return 0;
//}
