#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
  map<string, int> words;
  int index = 0;
  char s[1000];
  string ss;
  string word;
  while(cin.getline(s, 1000)) {
  	words.clear();
  	ss = (string)s;
  	word = "";
  	if(ss == "#") break;
  	
  	for(int i = 0; i < ss.size(); i++) {
 		if(s[i] == ' ' && word != "") { //一个单词结束 
 			//cout << word << endl;
 			words.insert(pair<string, int>(word, index++));
 			word = "";
		}
		if(s[i] != ' ')
			word += s[i];
		//cout << word << endl;
	}
	if(word != "") 
		words.insert(pair<string, int>(word, index++));
  	cout << words.size() << endl;
  }
  return 0;
}
