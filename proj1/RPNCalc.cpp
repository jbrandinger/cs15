/* RPNCalc.cpp 
 *
 * Implementation of the RPNCalc class, defines all of its functions
 *
 * Created By: Joel Brandinger
 * Date: October 2021
 */
 
#include "RPNCalc.h"
#include <iostream>
#include <sstream>
#include <fstream>
std::string parseRString(std::istream &input);
bool got_int(std::string s, int *resultp);

/* RPNCalc()
 * Purpose: default constructor, initializes RPNCalc object 
 */
RPNCalc::RPNCalc()
{
    
}

/* ~RPNCalc()
 * Purpose: destructor, deletes/ recycles any heap allocated data used in 
 *          the RPNCalc instance
 */
RPNCalc::~RPNCalc()
{
     
}

/* run()
 * Purpose: run command loop for CalcYouLater
 */
void RPNCalc::run(std::istream &input)
{
    std::string cmd;
    int value;

    while (input >> cmd) {
        try {
        if (cmd == "#t") {
            stack.push(Datum(true));
        } else if (cmd == "#f") {
            stack.push(Datum(false));
        } else if (cmd == "not") {
            switch_bool();
        } else if (cmd == "print") {
            stack.print();
        } else if (cmd == "clear") {
            stack.clear();
        } else if (cmd == "drop") {
            stack.pop();
        } else if (cmd == "dup") {
            stack.push(stack.top());
        } else if (cmd == "swap") {
            swap();
        } else if (got_int(cmd, &value)) {
            stack.push(Datum(value));
        } else if ((cmd == "+") or (cmd == "-") or (cmd == "*") or 
                   (cmd == "/") or (cmd == "mod")) {
            perform_operation(cmd);
        } else if ((cmd == "<") or (cmd == ">") or (cmd == "<=") or 
                   (cmd == ">=") or (cmd == "==")) {
            perform_comparison(cmd);
        } else if (cmd == "{") {
            stack.push(Datum(parseRString(input)));
        } else if (cmd == "exec") {
            execute_rstring(stack.top().toString());
        } else if (cmd == "file") {
            readFile(stack.top().toString());
        } else if (cmd == "if") {
            perform_if();
        } else if (cmd == "quit") {
            std::cerr << "Thank you for using CalcYouLater." << std::endl;
            return;
        } else {
            std::cerr << cmd << ": unimplemented" << std::endl;
        }
        } catch (std::runtime_error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        } 
    }
}

/* switch_bool()
 * Purpose: switches the value of the boolean at the top of the stack 
 */
void RPNCalc::switch_bool()
{
        if (stack.top().getBool() == true) {
            stack.pop();
            stack.push(Datum(false));
        } else if (stack.top().getBool() == false){
            stack.pop();
            stack.push(Datum(true));
        }
}

/* switch_bool()
 * Purpose: swaps the top two Datums on the stack 
 */
void RPNCalc::swap()
{
    Datum prev_top(stack.top());
    stack.pop();
    
    Datum new_top(stack.top());
    stack.pop();
    
    stack.push(prev_top);
    stack.push(new_top);
}

/* perform_operation(std::string cmd)
 * Purpose: performs desired operation on top two integers of stack 
 * Parameters: command string 
 */
void RPNCalc::perform_operation(std::string cmd)
{
    Datum second(stack.top());
    stack.pop();
    
    Datum first(stack.top());
    stack.pop();
    
    if (cmd == "+") {
        stack.push(Datum(first.getInt() + second.getInt()));
    } else if (cmd == "-") {
        stack.push(Datum(first.getInt() - second.getInt()));
    } else if (cmd == "*") {
        stack.push(Datum(first.getInt() * second.getInt()));
    } else if (cmd == "/") {
        if (second.getInt() == 0) {
            std::cerr << "Error: division by 0." << std::endl;
            return;
        } else {
            stack.push(Datum(first.getInt() / second.getInt()));
        }
    } else if (cmd == "mod") {
        stack.push(Datum(first.getInt() % second.getInt()));
    } 
    
}

/* perform_comparison(std::string cmd)
 * Purpose: performs desired operation on top two integers of stack, returns 
 *          appropriate boolean
 * Parameters: command string 
 */
void RPNCalc::perform_comparison(std::string cmd)
{
    Datum second(stack.top());
    stack.pop();
    
    Datum first(stack.top());
    stack.pop();
    
    
    if (cmd == "<") {
        if (first.getInt() < second.getInt()) {
            stack.push(Datum(true));
        } else {
            stack.push(Datum(false));
        }
    } else if (cmd == ">") {
        if (first.getInt() > second.getInt()) {
            stack.push(Datum(true));
        } else {
            stack.push(Datum(false));
        }
    } else if (cmd == "<=") {
        if (first.getInt() <= second.getInt()) {
            stack.push(Datum(true));
        } else {
            stack.push(Datum(false));
        }
    } else if (cmd == ">=") {
        if (first.getInt() >= second.getInt()) {
            stack.push(Datum(true));
        } else {
            stack.push(Datum(false));
        }
    } else if (cmd == "==") {
        if (first.getInt() == second.getInt()) {
            stack.push(Datum(true));
        } else {
            stack.push(Datum(false));
        }
    } 
}

/* execute_rstring(std::string rstring)
 * Purpose: executes RPN string at the top of the stack 
 * Parameters: command string 
 */
void RPNCalc::execute_rstring(std::string rstring)
{
    if (stack.top().isRString() == false) {
        std::cerr << "Error: cannot execute non rstring" << std::endl;
        return;
    }
    
    std::string first_brace, test, to_execute;
    std::stringstream ss1, ss2;
    int left_brace_count = 1;
    int righ_brace_count = 0;
    
    ss1 << rstring;
    ss1 >> first_brace;
    
    while (ss1 >> test) {
        if (test == "{") {
            left_brace_count++;
        } else if (test == "}") {
            righ_brace_count++;
        } 
        
        if (left_brace_count != righ_brace_count) {
            to_execute = to_execute + test + " ";
        }
    }
    
    ss2 << to_execute;
    stack.pop();
    run(ss2);    
}

/* readFile(std::string rstring)
 * Purpose: read file from RPN string 
 * Parameters: RPN string at the top of the stack 
 */
void RPNCalc::readFile(std::string rstring)
{
    if (stack.top().isRString() == false) {
        std::cerr << "Error: file operand not rstring" << std::endl;
        return;
    }
    
    std::string file;
    std::stringstream ss;
    std::fstream input;
    
    ss << rstring;
    ss >> file;
    ss >> file;
    
    input.open(file);
    
    if (not input.is_open()) {
        std::cerr << "Unable to read: " << file << std::endl;
        return;
    }
    stack.pop();
    run(input);
    
}

/* perform_if()
 * Purpose: perform if operation on stack 
 */
void RPNCalc::perform_if()
{
    std::string falseCase = stack.top().toString();
    bool x = stack.top().isRString();
    stack.pop();
    
    std::string trueCase = stack.top().toString();
    bool y = stack.top().isRString();
    stack.pop();
    
    bool testCondition = stack.top().getBool();
    bool z = stack.top().isBool();
    stack.pop();
    
    if ((x == false) or (y == false)) {
        std::cerr << "Error: exepcted rstring in if branch" << std::endl;
        return;
    } else if (z == false) {
        std::cerr << "Error: exepcted boolean in if test" << std::endl;
        return;
    }
    
    
    if (testCondition == true) {
        stack.push(Datum(trueCase));
        execute_rstring(trueCase);
    } else if (testCondition == false) {
        stack.push(Datum(falseCase));
        execute_rstring(falseCase);
    }
}
