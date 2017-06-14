#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

string prepare(string in) {
  string out = "";
  string trueOut = "";
  for(int i = 0; (i < in.length()); i++) {
    if(((in[i] >= 'a') && (in[i] <= 'z')) || ((in[i] >= 'A') && (in[i] <= 'Z')) || ((in[i] >= '0') && (in[i] <= '9'))) {
      out += in[i];
    } else if((in[i] == ' ') || (in[i] == '-')) {
      out += '-';
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
  }
  cout << "Enter song name (Be careful with register and characters!):" << endl;
  cin.ignore(256, '\n');
  getline (cin, name);
  string aaa = "http://audio.ngfiles.com/" + iddqd(id);
  aaa += "/";
  aaa += id;
  aaa += "_";
  aaa += prepare(name);
  aaa.append(".mp3 -O song.mp3");
  string bbb = "wget " + aaa;
  //cout << bbb << endl;
  //cout << bbb.c_str() << endl;
  system(bbb.c_str());
  bbb = "cp song.mp3 ";
  bbb += "\"";
  ifstream in;
  in.open("path(Change it).txt");
  string geometrypath;
  getline(in, geometrypath);
  bbb += geometrypath; //"/Users/samuelcarballogarcia/Downloads/GeometryDownloader-master/gddownloader-linux";
  bbb += id;
  bbb += ".mp3\"";
  system(bbb.c_str());
    cout << "Done,Don't forget that the downloaded songs are in this folder";
  cout << "                  ";
    return 0;
  }
