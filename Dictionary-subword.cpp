/***        SubWords Dictionary Searcher        ***
 *
 *          Author: Aya Amr      20170359
 */

#include <bits/stdc++.h>

using namespace std;

bool hasWord(vector<char> vec, string str);
string eraseChar(string str, char ch);

int main() {
    cout<<"Enter embedded word: \n";
	string s;
	cin>>s;
	ifstream in("dictionary.txt");
	vector<char> vec;
	for(int i=0;i<s.size();++i)
    {
        vec.push_back(s[i]);
    }
	string word;
	 while(in>>word)
     {
		if (hasWord(vec, word))
        {
			cout << word << endl;
        }

	 }

	return 0;
}

bool hasWord(vector<char> vec, string str) {  // Gets all combinations of *ORDERED* substrings(from left to right)
	if (vec.size()==0) {
		return str == "";
	} else {
		char element = vec[0];
		vector<char> rest = vec;
		rest.erase(rest.begin());
		return hasWord(rest, str) || hasWord(rest, eraseChar(str, element));

	}
}

string eraseChar(string str, char ch) {     //Erases first character of a string if it's equal to the target character
	string result = str;
	if (ch == str[0]) {
		result = result.erase(0, 1);
		return result;
	} else {
		return result;
	}

}
