#include <iostream>
#include <cctype>
using namespace std;
/** Check if a string is a valid password */
bool isValidPassword(string s)
{
  // Only letters and digits?
  int len = s.length();
  for (int i = 0; i < len; i++)
  {
    if (!isalpha(s[i]) &&
        !isxdigit(s[i]))
      return false;
  }

  // Check length
  if (len < 8)
    return false;

  // Count the number of digits
  int count = 0;
  for (int i = 0; i < len; i++)
  {
    if (isxdigit(s[i]))
      count++;
  }

  if (count >= 2)
    return true;
  else
    return false;
}
int main()
{
  // Prompt the user to enter a password
  cout << "Enter a string for password: ";
  string s;
  getline(cin, s);

  if (isValidPassword(s))
  {
    cout << "Valid password" << endl;
  }
  else
  {
    cout << "Invalid password" << endl;
  }
}
