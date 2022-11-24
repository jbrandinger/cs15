/* RPNCalc.h
 *
 * Interface for RPN calc class that runs the CalcYouLater proogram
 *
 * Created By: Joel Brandinger
 * Date: October 2021
 */
 
#include "DatumStack.h"
 
#ifndef RPN_CALC_H
#define RPN_CALC_H

class RPNCalc
{
public:
        //default constructor 
        RPNCalc();
        // destructor 
        ~RPNCalc();
        // run the command loop 
        void run(std::istream &input);

private:
        //stack used by CalcYouLater
        DatumStack stack;
        //switches value of boolean at the top of the stack 
        void switch_bool();
        //swaps top two Datums on the stack 
        void swap();
        // perform desired operation on top two integers on stack 
        void perform_operation(std::string s);
        // perform comparison of top two ints, push boolean onto stack 
        void perform_comparison(std::string s);
        // execute RPN string at the top of the stack
        void execute_rstring(std::string rstring);
        // read the file in RPN string 
        void readFile(std::string rstring);
        //peform if command 
        void perform_if();
};

#endif
