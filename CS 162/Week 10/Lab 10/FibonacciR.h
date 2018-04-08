// Code sourced from https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

 /*
 * FibonacciR.h
 *
 *  Created on: Sep 10, 2010
 *      Author: julian
 */

#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_

class FibonacciR {
public:
   FibonacciR(const int &n);
   virtual ~FibonacciR();
   void PrintFibonacci();
private:
   FibonacciR();
   int Fibonacci(const int &n);
   const int *n_;
};

#endif /* FIBONACCIR_H_ */
