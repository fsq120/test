#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;
#define debug(format, ...) printf (format, __VA_ARGS__)
#define debug1(...) test(__VA_ARGS__);

class Base
{
public:
  Base(int ii) : i(ii) {}
  virtual void f()
  {
    cout<<i<<endl;
	cout << "this is father." << endl;
  }
  virtual void ff() {
	f();
	cout << "this is father's ff" << endl;
  }

protected:
  int i;
};

class Derived: public Base
{
public:
  Derived(int i) : Base(i) {}
  void f()
  {
    cout<<i<<endl;
    cout<<s<<endl;
	cout << "this is child." <<endl;
  }
  Derived& set_s(int n) {
	s = n;	  
	return *this;
  }
  Derived& set_i(int n) {
	i = n;
	return *this;
  } 
  /*
  void ff() {
	f();
    cout << "this is ff()." << endl;	  
  }
  */
private:
  int s = 10;
  int i = 1;
};


template <typename T> void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    cout << first << ", " << sizeof...(Rest) << " ";
    print(rest...); // recursive call using pack expansion syntax
}

void printt(int a, string b = "haha", char c = 'a', float d = 2.2) {
    cout << a << b << c << d << endl;	
}

template <typename... Args> void test(const Args&... args) {
   printt(args...);
}

int main()
{
  Base* p=new Derived(1);
  Derived* q=new Derived(1);
  q->set_s(5).set_i(6);
  //p->f(); //输出的是0
  //q->f();
  p->ff();
  //debug("fsq %d\n", 10);
  print("fsq", "haha", 123);
  //printt(1, "fsq", 'c', 1.2345);
  test(1);
  debug1(1);
}
