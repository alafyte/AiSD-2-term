#include <iostream>
#include <stack>

using namespace std;

void main()
{
    setlocale(0, "Rus");

    string str;
    stack <char> stack1;
    int countOpen = 0, countEnd = 0;

    cout << "Введите строку: " << endl;
    cin >> str;

    for (auto c : str)
    {
        if (c == '(' || c == '[' || c == '{')
            countOpen++;
        if (c == ')' || c == '}' || c == ']')
            countEnd++;
    }
    if (countOpen != countEnd)
        cout << "Скобки расставлены неверно" << endl;
    else {
        for (auto c : str)
        {
            if (c == '(' || c == '[' || c == '{')
                stack1.push(c);

            if (c == ')' || c == '}' || c == ']')
            {
                if (c == ')' && stack1.top() == '(')
                    stack1.pop();
                else if (c == ']' && stack1.top() == '[')
                    stack1.pop();
                else if (c == '}' && stack1.top() == '{')
                    stack1.pop();
                else {
                    cout << "Скобки расставлены неверно" << endl;
                    exit(0);
                }
            }
        }
         cout << "Скобки расставлены верно" << endl;
    }
}
