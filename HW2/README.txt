Name: Mitchell Baker
###########################################
To compile: g++ problem(insert the number here).cpp
To run: ./a.out
###########################################
Problem 1
I created a program to check if a string contains a xYz sequence, aka palindrome.
It asks a user for a string, checks that there is a Y in the middle, then uses two
integers to iterate from front to back and back to front and compares the character
of the string at each index with each other. if at any point the two characters are not
equal, prints out that it is not a xYz sequence and the exits. If all are equal, prints
out that it is a xYz sequence and exits.

Runs at O(N)

###########################################
Problem 2
It was unclear whether or not we needed to write out the find() function being used or write out 
the find function's code itself so I did both

The find function works by accepting two iterators and a value. in this case the two iterators are
the beginning and end of the the vector. then the find function loops through from front to back to
find the iterator that contains the specified value, but not including the last iterator.

Runs at O(N)

Find function being used
	std::vector<int> vectorOfInts = {1,2,3,4,5};
	std::vector<int>::iterator it;

	it = find(vectorOfInts.begin(), vectorOfInts.end(), 3);

	if(it == vectorOfInts.end()){
		std::cout << "Not found" << std::endl;
	}
	else {
		std::cout << "Found" << endl;
	}

Find function's code 
	while(start != end) {
		if(*start == x) {
			return start
		}
		++first;
	}
	return last;

###########################################
Problem 3
	I used the implementation of a linked list that Dr.Thompson provided but changed the main and added a reverse function.
	The reverse function iterates through the list and stores the two nodes previous the iterating
	node. It then sets the first previous node's pointer to the second previous node. Once the iteration is done, it sets the head to be the old end of the list.

###########################################
Problem 4
	I created an algorithm that uses an stack with three functions and three variables. It holds two stacks, one for all
	numbers entered and one for the minimum elements, and one variable to hold the current minimum element for easy
	retrieval. It starts by pushing, if stack is empty or if x is less than the minimum element, it will push x onto
	both stacks and set the minimum element to x. since this is a boolean OR statement, when the program runs the first
	time, it will not check if x is less than the minimum element since the OR statement only needs the first to be true.
	If both are false, it will only push onto the stack of integers. For pop, if pops the first element of the stack of 
	integers and then checks if the the integer that was popped from the main stack is also the first element of the stack
	of minimum elements. If true, it will pop the first integer in the stack of minimum elements and set the minimum
	element variable to the value from the top of the stack of minimum elements. The findMin function just returns the
	minimumElement variable from the class

	class Stack 
		public:
			push(int x)
			pop()
			findMin()
		private:
			stack<int> stackOfInts
			stack<int> stackOfMinimumElement
			minimumElement
	
	push(x)
		if stackOfInts is empty or x < minimumElement
			stackOfMinimumElement.push(x)
			stackOfInts.push(x)
			minimumElement = x
			return
		
		else
			stackOfInts.push(x)
			return
	
	pop()
		y = stackOfInts.pop()
		stackOfInts.pop()

		if y equals stackOfMinimumElement.pop()
			stackOfMinimumElement.pop()
			minimumElement = stackOfMinimumElement.pop()
			return
		else
			return

	findMin()
		return minimumElement

###########################################
Problem 5
	I created an algorithm that calculates the sum of the array A. Then I calculate the sum of numbers 1 through N.
	I then calculate the difference of the sum of the array A from the sum of numbers 1 through N. This will give the
	user the missing number since the difference will be the missing number. The time complexity is N + N-1 since we 
	use	two for loops. This can be simplified to 2N then to O(N). 