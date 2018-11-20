#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    // erase whitespaces from s
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' '){
            s.erase(i, 1);
        }
    }

    // calculate floor and ceil
    int L = s.length();
    double sqrtL = sqrt(L);
    int floorL = (int)floor(sqrtL); // rows
    int ceilL = (int)ceil(sqrtL); // columns

    // append each character to specific row accordingly
    vector<string> construct(ceilL);
    for(int i=0; i<s.length(); i++){
        construct[i%ceilL].append(s, i, 1);
    }

    // construct the output string
    string output;
    for(int i=0; i<construct.size(); i++){
        output.append(construct[i]);
        if(i != construct.size() - 1){
            output.append(" ");
        }
    }
    return output;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
