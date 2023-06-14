#include "utils.h"

using namespace std;

int evalRPN(vector<string> &tokens)
{
    if (tokens.size() == 1)
        return stoi(tokens[0]);
    unordered_set<string> op = {"+", "-", "*", "/"};
    stack<int> my_stack;
    int32_t num1, num2, result;
    for (string token : tokens)
    {
        if (op.find(token) == op.end())
            my_stack.push(stoi(token));
        else
        {
            num2 = my_stack.top();
            my_stack.pop();
            num1 = my_stack.top();
            my_stack.pop();
            if (token == "+")
                result = num1 + num2;
            else if (token == "-")
                result = num1 - num2;
            else if (token == "*")
                result = num1 * num2;
            else
                result = num1 / num2;
            my_stack.push(result);
        }
    }    
    return static_cast<int>(result);
}

void solution(vector<string> &tokens, int target)
{
    check(evalRPN(tokens), target);
}

int main(int argc, char **argv)
{
    vector<string> tokens;
    int target;

    // case 1
    tokens = {"2", "1", "+", "3", "*"};
    target = 9;
    solution(tokens, target);

    // case 2
    tokens = {"4", "13", "5", "/", "+"};
    target = 6;
    solution(tokens, target);

    // case 3
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    target = 22;
    solution(tokens, target);
}
