#include<random>;
#include<ctime>;
#include<vector>;
#include<unordered_map>
#include <iostream>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        if (indices.count(val)) {
            return false;
        }
        nums.push_back(val);
        indices.emplace(val, nums.size() - 1);
        return true;
    }

    bool remove(int val) {
        if (!indices.count(val)) {
            return false;
        }
        int n = nums.size() - 1;
        int index = indices[val];
        nums[index] = nums[n];
        nums.pop_back();
        indices[nums[index]] = index;
        indices.erase(val);
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
private:
    vector<int> nums;
    unordered_map <int, int> indices;
};


//int main() {
//	RandomizedSet randomizedSet;
//	// Test insert
//	cout << "Insert 1: " << randomizedSet.insert(1) << endl; // true
//	cout << "Insert 2: " << randomizedSet.insert(2) << endl; // true
//	cout << "Insert 1 again: " << randomizedSet.insert(1) << endl; // false
//	// Test getRandom
//	cout << "Random element: " << randomizedSet.getRandom() << endl;
//	// Test remove
//	cout << "Remove 1: " << randomizedSet.remove(1) << endl; // true
//	cout << "Remove 3 (not present): " << randomizedSet.remove(3) << endl; // false
//	// Test getRandom after removal
//	cout << "Random element after removal: " << randomizedSet.getRandom() << endl;
//	return 0;
//}