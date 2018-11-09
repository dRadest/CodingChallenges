#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the swapNodes function below.
 */

void swap(vector<vector<int> > &indexes, int node){
    int temp = indexes[node][0];
    indexes[node][0] = indexes[node][1];
    indexes[node][1] = temp;
}

void inOrder(vector<vector<int> > indexes, int node, vector<int> &traversal){
    if(indexes[node][0] - 1 >= 0){
        inOrder(indexes, indexes[node][0] - 1, traversal);
    }
    traversal.push_back(node + 1);
    if(indexes[node][1] - 1 >= 0){
        inOrder(indexes, indexes[node][1] - 1, traversal);
    }
    
}

void swapEveryKDepth(vector<vector<int> > &indexes, int root, int depth, int k){
    // base case
    if (root < 0 || (indexes[root][0] == -1 && indexes[root][1] == -1)){
        return;
    }
    if((depth + 1) % k == 0){
        swap(indexes, root);
    }
    swapEveryKDepth(indexes, indexes[root][0] - 1, depth + 1, k);
    swapEveryKDepth(indexes, indexes[root][1] - 1, depth + 1, k);
}
vector<vector<int>> swapNodes(vector<vector<int>> &indexes, vector<int> queries) {
    vector<vector<int> > tr(queries.size());
    for(int i=0; i< queries.size(); i++){
        int k = queries[i];
        swapEveryKDepth(indexes, 0, 0, k);
        inOrder(indexes, 0, tr[i]);
    }
    return tr;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
