/* QUESTION 6: BINARY MARKING [0/04 M]*/
	static void ques6(int[] nums){
		/**
		 * Q6.	An array "A" contains 2 or more adjacent elements
		 * with same value. Such elements are called as
		 * repeating_adjacent_elements.
		 * This function counts the number of repeating_adjacent_elements
		 * in the given array.
		 *
		 * Few examples are given below:
		 * INPUT: [1, 2, 2, 3, 4, 4] 		OUTPUT: 2
		 * INPUT: [1, 1, 2, 1, 1] 			OUTPUT: 2
		 * INPUT: [1, 1, 1, 1, 1] 			OUTPUT: 1
		 */
		int count = 0;
		  /*
		 * WRITE YOUR IMPLEMENTATION BELOW
		 */
     list.sort((q1, q2) -> {
			if (q1.age == q2.age)
				return q1.name.compareTo(q2.name);
			return q2.age.compareTo(q1.age);
		});
		System.out.println(count);
	}//END OF QUES6()
