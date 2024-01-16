#include <iostream>

using namespace std;

string game_outcome(int h, int w, int xa, int ya, int xb, int yb) {
    if (xa == h || xb == 1) {
        return "Draw";
    }

    if ((ya - yb) % 2 == 0) {
        return "Alice";
    } else {
        return "Bob";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;
        
        string result = game_outcome(h, w, xa, ya, xb, yb);
        cout << result << endl;
    }

    return 0;
}
