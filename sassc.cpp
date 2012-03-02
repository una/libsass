#include <iostream>
#include <string>
#include <map>
#include "document.hpp"

using namespace Sass;
using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "Hey, I at least need a file to read!" << endl;
    return 0;
  }
  
  char* path;
  Document::CSS_Style style = Document::nested;
  
  for (int i = 1; i < argc; ++i) {
    if (string(argv[i]) == "--style") {
      string style_name(argv[++i]);
      if (style_name == "nested") style = Document::nested;
      else if (style_name == "expanded") style = Document::expanded;
    }
    else {
      path = argv[i];
    }
  }
    
  Document doc(path, 0);
  doc.parse_scss();
  string output = doc.emit_css(style);
  cout << output;

  return 0;
}