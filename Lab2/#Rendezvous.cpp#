/*!
     @author: Ronan Timmons
       @date: 02/10/17
    @version: 0.9
@lastUpdated: 10/10/17
 */
#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> Sem1, std::shared_ptr<Semaphore> Sem2){
  
  std::cout << "A1"<<std::endl;

  /*! wake up threadB */
  Sem2->Signal();

  /*! lock threadA from Sem1  */ 
  Sem1->Wait();
  
  std::cout << "A2"<<std::endl;
  /*! wake up threadB  */ 
  Sem2->Signal();
		   
}
void taskTwo(std::shared_ptr<Semaphore> Sem1, std::shared_ptr<Semaphore> Sem2){
  /*! lock threadB from Sem2 */
  Sem2->Wait();

  std::cout << "b1"<<std::endl;

  /*! wake up threadA */
  Sem1->Signal();

  /*! lock threadB from Sem2 */
  Sem2->Wait();
  
  std::cout << "b2"<<std::endl;
}

int main(void){
  
  std::thread threadA, threadB;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  
  /**< Launch the threads  */
  /* taskTwo calls wait, decrements counter making it -1 and blocks itself */
  threadA=std::thread(taskTwo,sem1, sem2);
  threadB=std::thread(taskOne,sem1, sem2);
  
  
  std::cout << "Launched from the main\n";
  threadA.join();
  threadB.join();
  return 0;
}
