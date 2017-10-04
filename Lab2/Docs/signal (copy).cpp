/*!
@author Ronan Timmons
@date 02/10/17
@version 1.0
 */
#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> Sem1){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  Sem1->Signal();
		   
}
void taskTwo(std::shared_ptr<Semaphore> Sem1){
  Sem1->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  /* taskTwo calls wait, decrements counter making it -1 and blocks itself */
  threadOne=std::thread(taskTwo,sem);

  /*taskOne called, carries out instructions, increments counter, wakes up threadOne */
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
