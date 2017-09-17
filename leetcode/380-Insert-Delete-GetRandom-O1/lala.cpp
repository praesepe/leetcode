#include <unordered_set>
#include <climits>
#include <random>

using namespace std;

class RandomizedSet {
private:
    int dice() {
        return this->_distribution(this->_generator);
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        random_device rd;
        this->_generator = default_random_engine(rd());
        this->_distribution = uniform_int_distribution<int>(0, INT_MAX);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto itr = this->_s.find(val);
        if (itr != this->_s.end()) {
            return false;
        }

        this->_s.insert(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto itr = this->_s.find(val);
        if (itr == this->_s.end()) {
            return false;
        }

        this->_s.erase(itr);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto itr = this->_s.begin();

        advance(itr, this->dice() % this->_s.size());

        return *itr;
    }
private:
    unordered_set<int> _s;
    default_random_engine _generator;
    uniform_int_distribution<int> _distribution;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
