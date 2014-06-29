/*
Copyright (C) 2014 Daniel Gastler

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <iostream>
#include <MyException/MyException.hh>

namespace namespace2{
  void foo5() {
    MyException::Exception2 e;
    e.Append("Something went wrong in foo5!\n");
    throw e;
  }

  void foo4(){foo5();}
}
namespace namespace1{
  void foo3(){namespace2::foo4();}
  void foo2()  {
    try {
      foo3();
    }catch (MyException::exBase &e){
      e.Append("foo2 has something to say about this!\n");
      throw;
    }
  }
  
  void foo1(){foo2();}
}

int main(){
  try {
    namespace1::foo1();
  }catch (MyException::exBase & e){
    std::cout << std::endl;
    std::cout << "Process " << e.GetPID() << " threw: " << e.what() << std::endl;
    std::cout << "Description: " << std::endl;
    std::cout << e.Description()<< std::endl;
    std::cout << "Stack trace:" << std::endl;
    std::cout << e.StackTrace()<< std::endl;
  }
  return 0;
}
