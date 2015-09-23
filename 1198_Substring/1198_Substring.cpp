#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a+b < b+a;
}


int main() {
    int cases;
    int n;
    string temp;
    cin >> cases;
    while (cases--) {
        cin >> n;
        vector<string> output;
        vector<string>::iterator i_t;
        for (int i = 0; i < n; ++i)
        {   

            cin >> temp;
            output.push_back(temp);
        }

        sort(output.begin(), output.end(), cmp);

        for(i_t = output.begin(); i_t != output.end(); i_t++) {
            cout << *i_t;
        }
        cout << endl;
    }

    return 0;
}
