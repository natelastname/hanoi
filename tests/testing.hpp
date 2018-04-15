/*
Copyright (C) 2018 Nathan Nichols

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the 
"Software"), to deal in the Software without restriction, including 
without limitation the rights to use, copy, modify, merge, publish, 
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL NATHAN NICHOLS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef TESTING_HPP
#define TESTING_HPP

#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstring>

#define MAX_PARAMS 16

typedef uint64_t (*test_procedure) (uint64_t *);

namespace testing{

   // Tests the function "test" by calling it with a pointer to an
   // array of arguments for each case in the given file. It then 
   // compares the result of test() with the corresponding expected
   // result from the test case file. The format of a test case file
   // is simple and can be deduced from looking at the examples.
	uint64_t open_file(std::string file_name, test_procedure test);	
	uint64_t open_file(const char * file_name, test_procedure test);

	uint64_t read_binary_string(std::string binary);
	std::string binary_string(uint64_t binary);
};

#endif // TESTING_HPP
