#include <bits/stdc++.h>

using namespace std;

const int size = 10;

int main(int argc, char * argv[])
{
    stack<int> s;
    for (int i = 0; i < size; i++)
        s.push(i);
    
    cout << "Stack Size:" << s.size() << endl;

    while (!s.empty()){
        cout << "Data:" << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}