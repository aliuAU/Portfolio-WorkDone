#include <iostream>
#include "linkedStack.h"

using namespace std;

void decimalToBinary(int n)
{
    linkedStackType<int> myStack;
    while (n > 0)
    {
        int remainder = n % 2;
        n /= 2;
        myStack.push(remainder);
    }
    while (!myStack.isEmptyStack())
    {
        int count;
        count = myStack.top();
        myStack.pop();
        cout << count;
    }
}

int main()
{
    int n;
    cout << "Enter the decimal number : ";
    cin >> n;

    decimalToBinary(n);

    return 0;
}
