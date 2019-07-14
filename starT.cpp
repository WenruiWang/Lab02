#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starT(int width, int height);
void runTests(void);

// Write starT per specifictions in the lab writeup
// so that internal tests pass, and submit.cs system tests pass

// starT is A C++ function that returns a string that, when printed on cout,
// renders the letter T with stars as ASCII art, 
// at any width or height, provided both width is an odd #>=3 and height is >=2
// If either is not, the function should return an empty string.

// When width is an odd #>=3 and height is >=2, the length of the result string
// should be (width + 1) * height (where the +1 is for the \n).    

// For examples, see the test cases in runTests().

// Note that the trailing spaces on each line are REQUIRED
// for the function to be considered correct.


string starT(int width, int height)
{
  string result="";
  // check if parameters are valid
  if ((width<3) || (height < 2) || (width%2!=1)) {
    return result;  // return without printing anything
  }
  
  // add the first row of width stars  
  for (int col=1; col<=width; col++) {
    result += "*";
  }
  result += "\n";    

  // add the height-1 rows that are a single star
  // surrounded by spaces, then a \n
  for (int row=2; row<=height; row++) { // start from second row
    for (int col=1; col<=(width/2); col++) {  // the number of spaces on the left of the single star should be half of the width
      result += " ";
    }
    result += "*"; 
    for (int col=1; col<=(width/2); col++) { // the # of spaces on the right is equal to the left
      result += " ";
    }
    result += "\n";
  }

  return result;   
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starT34Expected = 
    "***\n"
    " * \n"
    " * \n"
    " * \n" ;
  
  assertEquals(starT34Expected,starT(3,4),"starT(3,4)");

  string starT53Expected =     
    "*****\n"
    "  *  \n"
    "  *  \n" ;
  
  assertEquals(starT53Expected,starT(5,3),"starT(5,3)");

  string starT72Expected =     
    "*******\n"
    "   *   \n";
  
  assertEquals(starT72Expected,starT(7,2),"starT(7,2)");

  assertEquals("",starT(1,2),"starT(1,2)");
  assertEquals("",starT(5,1),"starT(5,1)");
  assertEquals("",starT(4,2),"starT(4,2)");
  assertEquals("",starT(6,2),"starT(6,2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[])
{

  // check for parameters
  // and print usage message
  if (argc!=3) {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }
  
  // get width and height from command line args
  int width = stoi(argv[1]);
  int height = stoi(argv[2]);

  // If the program is executed with parameters -1 -1 unit test
  // the starT() function using our automated test framework
  if (width==-1 && height==-1) {  //checks if they are both -1; 
    runTests(); // if so, call runTests()
    exit(0);   // then exit.
  }

  cout << starT(width,height); //calls the starT function and prints the result on cout (without an extra newline)
  return 0;

}
