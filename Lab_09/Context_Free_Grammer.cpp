#include <bits/stdc++.h>
using namespace std;

// Function to check if a given string is in the grammar
bool isInGrammar(const string& s) {
    string p[] = {"e", "0", "1", "0P0", "1P1"};
    return find(p, p + 5, s) != p + 5;
}

// Function to process and validate the input string
bool processString(const string& str, string& path) {
    int length = str.size();
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j] || !isInGrammar(string(1, str[i]) + "P" + string(1, str[j]))) {
            return false;
        }
        int pos = path.find_last_of('P');
        if (pos == string::npos) {
            return false;
        }
        string x = string(1, str[i]);
        string y = string(1, str[j]);
        string temp = x + "P" + y;
        path.replace(pos, 1, temp);
        if (path == "p") {
            return false;
        }
    }
    return true;
}

int main() {
    string str, path = "P";
    cout << "Enter P: ";
    cin >> str;
    cout << "P -> ";
    if (processString(str, path)) {
        cout << path << " -> " << str << endl;
    } else {
        cout << "Not in this grammar or something is missing." << endl;
    }
    return 0;
}
