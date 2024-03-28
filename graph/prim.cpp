#include <iostream>
#include <vector>
using namespace std;
void read(vector<vector<int>> matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> initlize(int n, int value){
    vector<vector<int>> ajdency_matrix;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int i = 0; i < n; i++){
        temp.push_back(value);
    }
    ajdency_matrix.push_back(temp);
    }
    return ajdency_matrix;
}
vector<vector<int>> prim(vector<vector<int>> matrix){
    vector<vector<int>> temp = initlize(matrix.size(), 0);
    vector<int> visited = {0};
    vector<int> not_visited = {};
    for(int i = 1; i < matrix.size(); i++){
        not_visited.push_back(i);
    }
    while(visited.size() != matrix.size()){
        int index = 100;
        int node1;
        int node2;
        for(const auto &node : visited){
            for(int &i : not_visited){
                if(matrix[node][i] < index){
                    node1 = node;
                    node2 = i;
                    index = matrix[node][i];
                }
            }
        }
        temp[node1][node2] = index;
        temp[node2][node1] = index;
        visited.push_back(node2);
        not_visited.erase(std::remove(not_visited.begin(), not_visited.end(), node2), not_visited.end());
    }
    return temp;
}
int main()
{
    vector<vector<int>> ajdency_matrix = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
    cout << ajdency_matrix[0][0] << endl;
    read(ajdency_matrix);
    vector<vector<int>> ajdency_matrix1;
    ajdency_matrix1 = initlize(10, 0);
    read(ajdency_matrix1);
    vector<vector<int>> result = prim(ajdency_matrix);
    read(result);
    return 0;
}