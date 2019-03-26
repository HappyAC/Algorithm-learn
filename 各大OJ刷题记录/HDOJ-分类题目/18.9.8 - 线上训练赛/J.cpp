#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int P, A;
    ll X;
    while (cin >> P >> A)
    {
        bool flag = true;
        for (X = 0; X < P; X++)
        {
            if (X * X % P == A)
            {
                cout << X << ' ';
                flag = false;
            }
        }
        if (flag)
        {
            cout << "No Solution\n";
        }
    }

    return 0;
}
