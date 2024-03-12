#include <iostream>
#include <vector>

using namespace std;

int main (){
    int n = 5;
    vector<vector<int>> result(n, vector<int>(n));
     pair<int,int> valueOne;
     for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> result[i][j];
            if(result[i][j] == 1) valueOne = {i,j};
        }
    }

    int count = 0;
    int row = valueOne.first;
    int col = valueOne.second;

    while(row != 2)
    {
        if(row > 2) {
            row--;
            count++;
        }
        else{
            row++;
            count++;
        }
    }
    while(col != 2)
    {
        if(col > 2) {
            col--;
            count++;
        }
        else{
            col++;
            count++;
        }
    }
    cout<<count;
    
    return 0;

}   