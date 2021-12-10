#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream os;
  char fileName[] = "0.txt";
  for(int i = '1'; i <= '5'; i++)
  {
     fileName[0] = i;
     os.open(fileName,fstream::app);
     os << "Hello " << (i-'1'+1) << "\n";
     os.close();
  }
}
