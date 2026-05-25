#include <iostream>
#include <stack>
#include <cctype>  // for isalpha, isdigit
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string expr) {
    stack<char> st;
    string output = "";

    for(char ch : expr) {
        // 1. If operand → append to output
        if(isalpha(ch) || isdigit(ch)) {
            output += ch;
        }
        // 2. If '(' → push to stack
        else if(ch == '(') {
            st.push(ch);
        }
        // 3. If ')' → pop till '('
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        }
        // 4. Operator
        else {
            while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                output += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // 5. Pop remaining operators
    while(!st.empty()) {
        output += st.top();
        st.pop();
    }

    return output;
}

// Driver code
int main() {
    string expr;
    cout << "Enter infix expression: ";
    cin >> expr;

    string postfix = infixToPostfix(expr);
    cout << "Postfix: " << postfix << endl;

    return 0;
}