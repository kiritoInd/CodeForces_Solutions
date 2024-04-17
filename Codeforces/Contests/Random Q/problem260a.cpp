#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    bool isexist = false;
    for (int i = 0; i < 10; ++i)
    {
        if ((a * 10 + i) % b == 0)
        {
            cout << a * 10 + i;
            string s(n - 1, '0');
            cout << s << endl;
            isexist = true;
            break;
        }
    }
    if (!isexist)
    {
        cout << -1 << endl;
    }
    return 0;
}