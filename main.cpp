#include <iostream>
#include <exception>
#include "IntArr.h"



int main(){
  
   IntArr array(15);

   try {
      for (int i = 0; i < 15; ++i) {
         array[i] = i + 1;
     }

      array.resize(7);//resize the array to 7 elements

      array.insertBefore(10, 3);//insert the number 10 before element with index 3

      array.remove(6);//remove the element with index 6

      array.insertAtEnd(54);//add 54 to the end

      array.insertAtBeginning(14);//add 14 to the beginning

      for (int i = 0; i < array.getLength(); ++i) {
         std::cout << array[i] << ' ';
      }

   }
   catch (std::exception &e){
      e.what();
   }

   return 0;
}

