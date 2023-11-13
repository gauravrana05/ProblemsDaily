#include <iostream>
using namespace std;
int main()
{
// cout outputs integers as decimal integers:
cout.setf(ios::showpos);
(cout << "\033[2J");
cout<<cout.precision(4)<<cout.fill('*')<<cout.width(15);


cout << "Value of 0xFF = "<<showpos << 0xFF << " decimal\'"
<< endl; // Output: 255 decimal
// The manipulator hex changes output to hexadecimal
// format (dec changes to decimal format):

cout << "Value of 27 = " << oct << 27 <<" hexadecimal"
<< endl; // Output: 1b hexadecimal

return 0;
}