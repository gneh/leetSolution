#include <iostream>
#include <vector>
#define VECOUT(v) for (int def_i = 0; def_i < v.size(); ++def_i) cout << v[def_i] << ','
#define PRINT(x) cout << x << endl
#define DE cout << "HERE" << endl;
#include <limits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stk;
    int minElement;
    MinStack() {
        minElement = (numeric_limits<int>::max)();
    }
    void push(int x) {
        stk.push_back(x);
        if (!stk.size() || x < minElement)
            minElement = x;
    }

    void pop() {
        int topElement = stk[stk.size() - 1];
        stk.erase(stk.end() - 1);
        if (!stk.size())
            minElement = (numeric_limits<int>::max)();
        if (topElement == minElement) {
            minElement = (numeric_limits<int>::max)();
            for (vector<int>::iterator it = stk.begin(); it != stk.end(); ++it)
                if (*it < minElement)
                    minElement = *it;
        }
    }

    int top() {
        return stk[stk.size() - 1];
    }

    int getMin() {
        return minElement;
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(2);
    obj->push(0);
    obj->push(3);
    obj->push(0);
    cout << obj->getMin() << endl;
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->getMin() << endl;

}
