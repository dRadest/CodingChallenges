#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

map<long, vector<long>> m;

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {

  int n = arr.size();

  // hashed list of indices for every value in the array
  for (int i = 0; i < n; ++i)
    m[arr[i]].push_back(i);

  long c = 0, x;
  for (int i = 1; i < n - 1; ++i) {
    // if arr[i] is not divisible be r then no need to further proceed
    if (arr[i] % r)
      continue;

    // Count of elements occur before arr[i] and has a value of arr[i]/r
    long less = upper_bound(m[arr[i] / r].begin(), m[arr[i] / r].end(), i - 1) -
                m[arr[i] / r].begin();

    // Count of elements occur after arr[i] and has a value of arr[i]*r
    long high = m[arr[i] * r].end() -
                lower_bound(m[arr[i] * r].begin(), m[arr[i] * r].end(), i + 1);

    // add the count of total possible combinations of both type of elements
    // describe above
    c += (high * less);
  }
  return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
