#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>


using namespace std;

string prepare(string in) {
  string out = "";
  string trueOut = "";
  for(int i = 0; (i < in.length()); i++) {
		if(((in[i] >= 'a') && (in[i] <= 'z')) || ((in[i] >= 'A') && (in[i] <= 'Z')) || ((in[i] >= '0') && (in[i] <= '9'))) {
			out += in[i];
		} else if((in[i] == ' ') || (in[i] == '-')) {
			out += '-';
		} else if(in[i] == '_') {
			out += '_';
		} else if(in[i] == '"') {
			out += "quot";
		} else if(in[i] == '&') {
			out += "amp";
		} else if(in[i] == '>') {
			out += "gt";
		} else if(in[i] == '<') {
			out += "lt";
		}
  }
  for(int i = 0; i < 26; i++) {
    if(i < out.length()) {
      trueOut += out[i];
    }
  }
  return trueOut;
}

string iddqd(string id) {
  string idkfa = "";
  if(id.length() >= 4) {
    for (int i = 0; i < id.length() - 3; i++) {
      idkfa += id[i];
    }
  } else {
     return "0";
  }
  return idkfa + "000";
}

int main() {
  cout << "Enter song id:" << endl;
  string id;
  string name;
  cin >> id;
  if(id.length() <= 5) {
    cout << "No support for small IDs!";
    return 0;
  }
  cout << "Enter song name (Be careful with register and characters!):" << endl;
  cin.ignore(256, '\n');
  getline (cin, name);
  string aaa = "http://audio.ngfiles.com/" + iddqd(id);
  aaa += "/";
  aaa += id;
  aaa += "_";
  aaa += prepare(name);
  aaa.append(".mp3 -O file.mp3");
  string bbb = "wget " + aaa;
  system(bbb.c_str());
  bbb = "copy file.mp3 ";
  bbb += "\"";
  ifstream in;
  in.open("geometryPath.txt");
  string geometrypath;
  getline(in, geometrypath);
  bbb += geometrypath;
  bbb += id;
  bbb += ".mp3 \"";
  ifstream song("file.mp3", std::ios::ate);
  if(song.tellg() != 0) {
    system(bbb.c_str());
  } else {
	cout << "Couldn't find a song." << endl;
  }
  bool a = remove("file.mp3");
  cout << "DONE" << endl;
}
