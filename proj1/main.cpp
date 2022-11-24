/* main.cpp 
 *
 * Purpose: Run the CalcYouLater program
 *
 * Created By: Joel Brandinger
 * Date: October 2021 
 */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 #include "RPNCalc.h"
 
 using namespace std;
 
 int main()
 {
     RPNCalc calc;
     calc.run(std::cin);
     
     return 0;
 }
