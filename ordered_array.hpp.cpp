#ifndef ordered_array_hpp
#define ordered_array_hpp

#include <iostream>
#include <stdexcept> // For out_of_range

using namespace std;

class ordered_array {
  public:
    ordered_array(int cap){ 
      max = cap;
      leng = 0;
      arr = new int[max];
    }
    
    ~ordered_array(){
      delete []arr;
    }

    int size(){
      return leng;
    
    }
    int capacity(){
      return max;
    }
    
    void insert(int elem){
      if(size() == capacity())
        return;
      if((size() > max) || (elem == -2147483648))
        return;
      if(size() == 0){
        arr[leng] = elem;
        leng++;
        return;
      }
      int k = -1; // To find where the new input will be inserted
      for(int i = 0; i < size(); i++){
        if(elem < arr[i]){
          k = i;
          break;
        }  
      }
      if(k != -1){
        for(int i = size(); i > k; i--){
          arr[i] = arr[i-1]; // Shift all inputs after it up
        }
        arr[k] = elem; // Update the new input into place
      }
      else{
        arr[leng] = elem;
      }
      leng++;
    }

    void remove(int elem){
      if(!exists(elem)){
        return;
      }
      for(int i = 0; i < size(); i++){
        if(arr[i] == elem){
          for(int j = i; j < (size()-1); j++){
            arr[j] = arr[j+1];
          }
	break;
        }
      }
      leng--;
    }

    bool exists(int elem){
      for(int i = 0; i < size(); ++i){
        if(arr[i] == elem){
          return true;
        }
      }
      return false;
    }
    
    int at(int i){
      if(i < 0 || i >= size()){
        throw("Out of range");
      }
      return arr[i];
    }
  private:
    int *arr;
    int max;
    int leng;
};

#endif