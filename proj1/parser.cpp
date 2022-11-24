/* parser.cpp
 *
 * purpose: read input from a referenced input stream 
 *
 * Create By: Joel Brandinger 
 * Date: October 2021 
 */
 
 #include <iostream>
 
 using namespace std;

 std::string parseRString(std::istream &input)
 {
    
     int left_brace_count = 1;
     int righ_brace_count = 0;
     
     std::string element;
     std::string final = "{";
     
     while(left_brace_count != righ_brace_count) {
         
         if (input.eof()) {
             throw runtime_error("eof, braces not matched");
         }
         
         input >> element;
         final = final + " " + element;
         
         if (element == "{") {
             left_brace_count++;
         } 
         if (element == "}") {
             righ_brace_count++;
         }
     }
     return final;
 }