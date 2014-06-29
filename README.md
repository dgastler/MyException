# MyException
===========

Example C++ exception class

### Use:
- New exceptions can be added in the MyException.hh file, at the end, using the MyExceptionClass macro.
  It takes two arguments, the name of the new exception type, and the c-string to be returned by the what() method. 
- Exceptions can be caught as std::exception or MyException::exBase, but the additional features of these
  new exceptions is only available using exBase.
- Also, you must catch as a non-const exBase reference to use the Append() functions to add data to the Description() string.
- A working example of the use is in test.cc

### Other notes:
- The makefile included uses -O0 because otherwise the functions in the example are all in-lined and the stacktrace is boring. 

