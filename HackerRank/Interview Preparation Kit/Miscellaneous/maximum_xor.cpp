#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxXor function below.
// Structure of Trie DS
struct trie {
  int value;
  trie* child[2];
};

// Function to initialise a Trie Node
trie* get() {
  trie* root = new trie;
  root->value = 0;
  root->child[0] = NULL;
  root->child[1] = NULL;
  return root;
}

// Computing max xor
int max_xor(trie* root, int key) {
  trie *temp = root;

  // Checking for all bits in integer range
  for (int i = 31; i >= 0; i--) {
    // Current bit in the number
    bool current_bit = (key & (1 << i));

    // Traversing Trie for different bit, if found
    if (temp->child[1 - current_bit] != NULL)
      temp = temp->child[1 - current_bit];

    // Traversing Trie for same bit
    else
      temp = temp->child[current_bit];
  }

  // Returning xor value of maximum bit difference
  // value. Thus, we get maximum xor value
  return (key ^ temp->value);
}

// Inserting key in Trie
void insert(trie* root, int key) {
  trie* temp = root;

  // Storing 31 bits as integer representation
  for (int i = 31; i >= 0; i--) {
    // Current bit in the number
    bool current_bit = key & (1 << i);

    // New node required
    if (temp->child[current_bit] == NULL)
      temp->child[current_bit] = get();

    // Traversing in Trie
    temp = temp->child[current_bit];
  }
  // Assigning value to the leaf Node
  temp->value = key;
}
vector<int> maxXor(vector<int> arr, vector<int> queries) {
  // solve here
  // Forming Trie for arr
  trie* root = get();
  for (size_t i = 0; i < arr.size(); i++){
      insert(root, arr[i]);
  }
  // vector to store the max xor values
  vector<int> ans;
  for(size_t i = 0; i<queries.size(); i++){
      int number = queries[i];
      ans.push_back(max_xor(root, number));
  }
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
