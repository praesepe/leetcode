#include <iostream>
#include <string>

using namespace std;

string trim(const string& str) {
  size_t first = str.find_first_not_of("\v\f\r\n\t ");
  if (string::npos == first) {
    return "";
  }
  size_t last = str.find_last_not_of("\v\f\r\n\t ");
  return str.substr(first, (last - first + 1));
}

string clearSign(const string& str) {
  if (str.length() == 0) {
    return str;
  }

  if (str[0] == '+' || str[0] == '-') {
    return str.substr(1, str.length() - 1);
  }

  return str;
}

bool isUnsignedDigitNumber(string s) {
  size_t first_dot = s.find_first_of('.');
  if (first_dot == string::npos) {
    if (s.length() > 0 && s.find_first_not_of("1234567890") == string::npos) {
      return true;
    }

    return false;
  }

  size_t last_dot = s.find_last_of('.');
  if (first_dot != last_dot) {
    return false;
  }

  if (first_dot == 0) {
    return isUnsignedDigitNumber(s.substr(1, s.length() - 1));
  } else if (last_dot == s.length() -1) {
    return isUnsignedDigitNumber(s.substr(0, s.length() - 1));
  }

  return isUnsignedDigitNumber(s.substr(0, first_dot)) &&
      isUnsignedDigitNumber(s.substr(first_dot + 1, s.length()-first_dot-1));
}

bool isDigitNumber(string s) {
  return isUnsignedDigitNumber(clearSign(s));
}

bool isNumber(string s) {
  s = trim(s);
  
  size_t first_e = s.find_first_of("Ee");
  if (first_e == string::npos) {
    return isDigitNumber(s);
  }

  size_t last_e = s.find_last_of("Ee");
  if (first_e != last_e) {
    return false;
  }

  if (first_e == 0 || last_e == s.length() - 1) {
    return false;
  }

  string first_part = s.substr(0, first_e);
  string last_part = s.substr(first_e + 1, s.length()-first_e-1);

  return isDigitNumber(first_part) && isDigitNumber(last_part) && last_part.find_first_of('.') == string::npos;
}

int main() {
  const string ss[] = {
    "0",
    " 0.1",
    "abc",
    " 1 a",
    "2e10",
    "+3",
    "-5",
    " -2.0",
    " .01",
    "1.",
    ".",
    "6e6.5",
  };

  for (string s : ss) {
    cout << s << endl;
    cout << boolalpha << isNumber(s) << endl;
  }

  return 0;
}
