#include<iostream>
#include<queue> // Required for std::queue
#include<string> // Required for std::string (though not directly used, good practice if manipulating strings)

// It's generally better to use specific std members like std::cout, std::endl, std::queue
// rather than 'using namespace std;' in larger projects to avoid name collisions.
// For small examples like this, it's often fine.

int main(){
  
  //create a queue
  std::queue<int> q; 
  
  std::cout << "Pushing 11, 15, 18 into the queue." << std::endl;
  q.push(11); // Adds 11 to the back of the queue
  q.push(15); // Adds 15 to the back of the queue
  q.push(18); // Adds 18 to the back of the queue
  
  // Print the current size of the queue
  std::cout << "Size of queue is: " << q.size() << std::endl; 
  
  // Remove the front element (11)
  if (!q.empty()) {
    std::cout << "Popping the front element: " << q.front() << std::endl;
    q.pop(); 
  } else {
    std::cout << "Queue is empty, cannot pop." << std::endl;
  }
  
  std::cout << "Current size of queue after pop: " << q.size() << std::endl;
  
  // Print the remaining elements in the queue.
  // std::queue does not support iterators, so a range-based for loop (for(auto i : q)) won't work.
  // To print elements, we typically process them one by one from the front.
  std::cout << "Elements remaining in the queue:" << std::endl;
  std::queue<int> temp_q = q; // Create a temporary copy if you need to preserve the original queue
                              // For this example, we'll print and empty the original queue.

  if (q.empty()) {
    std::cout << "Queue is now empty." << std::endl;
  } else {
    // This loop will print and remove elements from the original queue 'q'.
    // If you needed to preserve 'q', you would loop through 'temp_q'.
    while(!q.empty()){
      std::cout << q.front() << std::endl; // Access the front element
      q.pop(); // Remove the front element
    }
  }
  
  std::cout << "Queue size after printing all elements: " << q.size() << std::endl;
  
  return 0; 
}
