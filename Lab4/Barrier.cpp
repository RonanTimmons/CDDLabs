/*! 
      @author: Ronan Timmons
@date created: 20/10/17
     @version: 0.9
 @lastUpdated: 24/10/17
     @purpose: demonsrate reuseable barrier
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <string>
#include <vector>

int numT = 6;
int counter = 0;

void funcOne(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> bar1, std::shared_ptr<Semaphore> bar2, int tNum) {

  /*! atomic action on counter */
  mutex->Wait();
  counter++;
  if (counter == numT) {
     bar2-> Wait();
     bar1-> Signal();
  }


  mutex->Signal();
  bar1->Wait();
   /*rendezvous1 */
  std::cout << tNum <<  "meet here before doing important stuff lads" <<std::endl;
  bar1->Signal();
  mutex->Wait();
  counter--;

  if(counter == 0) {
    bar1->Wait();
    bar2->Signal();
  }
  mutex->Signal();
  bar2->Wait();
  bar2->Signal();
   /*rendezvous2 */
  std::cout << tNum << "important stuff done, now have a breather " <<std::endl;
  
}

int main(void) {

   /*for turnstyle */
  std::shared_ptr<Semaphore> bar1(new Semaphore(0));
  std::shared_ptr<Semaphore> bar2(new Semaphore(1));
  /*For number of threads */
  std::thread tArray[numT];
  /*for lock */
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));

  /*send each to func */
  for (int i = 0; i < numT; i++) {
    tArray[i] = std::thread(funcOne,mutex,bar1,bar2,i);
  }

  /*for output*/
  for (int i = 0; i < numT; i++) {
    tArray[i].join();
  }
  return 0;
}
