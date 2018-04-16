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

#include "testing.hpp"


std::string testing::binary_string(uint64_t binary){
	
	std::string bin_string = "";
	uint64_t mask = 1;

	for(int i = 0; i < 64; i++){
				
		if((binary & mask) != 0){
			bin_string = "1" + bin_string;
		} else{
			bin_string = "0" + bin_string;
		}
		mask = mask * 2;
	}
	return bin_string;
	
};

uint64_t testing::read_binary_string(std::string binary){
	
	const char * instr = binary.c_str();
	uint64_t mask = 1;
	uint64_t bit = 0;
	uint64_t res = 0;

	for(int i = 63; i >= 0; i--){
		if(instr[i] == '0'){
			bit = 0;
		} else if(instr[i] == '1'){
			bit = 1;
		} else{
			std::cout << "Error: string passed not binary" << std::endl;
			return 0;
		}
		res += mask * bit;
		mask = mask + mask;
	}
	return res;
};

uint64_t testing::open_file(std::string file_name,
								test_procedure test){
	return open_file(file_name.c_str(),test);
};

uint64_t testing::open_file(const char * file_name,
								test_procedure test){

	std::ifstream input;
	input.open(file_name);

	if (!input) {
		std::cout << "Unable to open " << file_name << std::endl;
		return 1;
	} else{
		std::cout << "Running " << file_name << std::endl;
	}
	
	std::string line = "";

	uint64_t expected_output = 0;

	bool expecting_param = false;
	bool expecting_identifier = true;

	std::string identifier = "";

	uint64_t args[MAX_PARAMS];

	int num_params = 0;

	while(true){
		
		input >> line;
		if(input.eof()){
			return 0;
		}

		const char * line_cstr = line.c_str();
		if(line_cstr[0] == '#'){
			continue;
		}

		if(expecting_identifier){
			//std::cout << "identifier:" << line << std::endl;
			identifier = line;
			expecting_identifier = false;
		}

		if(line == "Out"){
			input >> line;
			expected_output = testing::read_binary_string(line);

			uint64_t res = test(args);

			if(res != expected_output){
			   std::cout << identifier << ":";
				std::cout << "Fail" << std::endl;
				std::cout << "Args[0]:"
				<< testing::binary_string(args[0])
				<< std::endl;
				std::cout << "Args[1]:"
				<< testing::binary_string(args[1]) 
				<< std::endl;
				std::cout << " Answer:"
				<< testing::binary_string(expected_output) 
				<< std::endl;
			   std::cout << " Output:"
				<< testing::binary_string(res) 
            << std::endl;
			} else{
				//std::cout << "Pass" << std::endl;
			}
		
			memset(args,0,MAX_PARAMS*sizeof(uint64_t));
			expecting_param = false;
			num_params = 0;

		}
	
		if(expecting_param){
			if(num_params >= MAX_PARAMS){
				std::cout << "ERROR: Increase MAX_PARAMS constant." 
				<< std::endl;
				return 1;
			}
			args[num_params] = testing::read_binary_string(line);
			num_params++;
		}
	
		if(line == "In"){
			expecting_param = true;
		}

		if(line == "END"){
			expecting_identifier = true;
		}

	}
};


















