#include <iostream>
#include <string>
using namespace std;



int main() {
	
	string   result = ""
         , word
         , temp = ""
         , hr
         ;
  hr.assign(80, '-');
	while(cin >> word) {
    if(word == "<br>") {
      cout << result << endl;
      result = "";
      temp = "";
      continue;
    }
    if(word == "<hr>") {
      if(result == "") {
        cout << hr << endl;
        continue;
      }
      cout << result << endl << hr << endl;
      
      result = "";
      temp = "";
      continue;
    }
    if(temp == "") temp = word;
		else temp = temp + " " + word;
    if(temp.length() > 80) {
      
      cout << result << endl;
      
      result = word;
      temp   = word;
      continue;
    }
    if(result == "") result = word;
    else result = result + " " + word;
	}
  cout << result << endl;
	return 0;
} 
