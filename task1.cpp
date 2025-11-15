#include <iostream>
#include <stack>
#include <string>

std::stack<int, std::vector<int>> id(
    std::vector<int>{8, 4, 5, 7, 7, 2, 9, 5, 6}
);

int operate(int a, int b){
    if (a % 2 != 0 && b % 2 != 0){
        return a + b;
    }
    else if (a % 2 == 0 && b % 2 == 0){
        return a * b; 
    }
    else {
        return std::abs(a - b);
    }
}

int main() {
    while (id.size() > 1) {
        int a = id.top();
        id.pop();
        int b = id.top();
        id.pop();
        int result = operate(a, b);
        id.push(result);
    }
    std::cout << "Final result: " << id.top() << std::endl;
    return 0;
}
