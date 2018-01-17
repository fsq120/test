#include <iostream>     // std::cout
#include <algorithm>    // std::partial_sort
#include <vector>       // std::vector
#include <unistd.h>
#include <fstream>
#include <atomic> 
#include <thread> 
#include <math.h>

using namespace std;
bool myfunction (int i,int j) { return (i<j); }
std::atomic<int> foo;

int test(void* data) {
  int *d = (int*)data;
  cout << *d << endl;
  if (1) {
  string data = "haha";
  cout << data << endl;
  }
}

double GetFloatPrecision(double value, double precision) {
  return (floor((value * pow(10, precision) + 0.5)) / pow(10, precision)); 
}

int main () {
  int myints[] = {9,8,7,6,5,4,3,2,1};
  std::vector<int> myvector (myints, myints+9);
  vector<int> vv;
  string f = "";
  if (!access(f.c_str(), 0)) 
	 cout << "file " << f << endl;

  cout << vv.size() << endl;

  float v = 0.11;
  cout << v << endl;
  cout << GetFloatPrecision(v, 5) << endl;


  // using default comparison (operator <):
  std::partial_sort (myvector.begin(), myvector.begin()+1, myvector.end());

  // using function as comp
  std::partial_sort (myvector.begin(), myvector.begin()+1, myvector.end(),myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  int file;
  close(file);
	
  ofstream out("./test", ofstream::binary);
  out.write((char *)myints, 9);
  out.close();

  string ss(16, 0);
  cout << hex << (int)ss[0] <<endl;
  
  string ff = "";
  cout << !ff.empty() << endl;

  cout << "atomic a=" << foo << endl;
  foo = 5;
  int xx = foo;
  cout << "atomic b=" << xx << endl;

  int h = 100;
  test(&h);

  double d = 1023.0f / 10;
  cout << d << endl;

  std::vector<int> ii = {1,2,3,4,5,6};
  vector<vector<int> > iii;
  for (int i = 0; i < 6; ++i)
  	iii.push_back(ii);
  for (const auto a : iii)
	  for (const auto b : a)
	    cout << b << endl;
  float ffff = 2.3456;
  //float fff = ffff << 2;
  cout << (int)ffff << endl;
  return 0;

}

