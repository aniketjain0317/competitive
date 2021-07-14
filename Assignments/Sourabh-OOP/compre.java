import java.util.*;
import java.io.*;
/***************************************************************************************************
 ******************************** CSF213 OBJECT ORIENTED PROGRAMMING *******************************
 ********************************             PART A                 *******************************
 ********************************        MAX. MARKS: 30              *******************************
 ********************************     MAX. DURATION: 50 mins          ******************************
 **************************************************************************************************/

// NAME:
// ID:

/*****************************************IMPORTANT INSTRUCTIONS************************************
 * Write your Name and ID Number before solving the questions.
 * Refactor the file as QP_ID_Number, eg. QP_2018A7PS001P
 * There are 4 questions written within 4 static methods.
 * Within each method, problem statement and expected output are mentioned in a comment section.
 * You are not allowed to do the following:
  		-> Modify the main() method.
  		-> Break the single java file into multiple files containing separate class definitions.
 	    -> Modify the code of any class/method unless unless it is mentioned explicitly.
 	    -> Modify the signature of any method unless it is mentioned explicitly.
 	    -> Import any new classes or packages in your solution.
 	    -> Create new methods unless it is mentioned explicitly.
 	    -> Create new classes in your solution unless it is mentioned explicitly.

 ********************************DON'T MODIFY THIS SECTION*****************************************/

public class QP_Compre_SS2021 {
	public static void main(String []args) {
		try {
			System.out.print("Answer 1: ");
			ques1();
		}catch(Exception e) {}
		System.out.print("Answer 2: ");
		ques2();

		System.out.print("Answer 3: ");
		ques3();

		try {
			System.out.print("Answer 4: ");
			ques4();
		}catch(Exception e) {}


	} //END OF MAIN


	/* QUESTION 1: MARKING SCHEME [00/02/04/06 M]*/
	/*
	 * DON'T MODIFY THE IMPLEMENTATION OF THE INTERFACE Intf AND CLASS Ques1
	 */
	interface Intf<C> {
		void fun(C c);
	}

	static void ques1() {
		class Ques1{
			String s;
			Ques1(String s){
				this.s = s;
			}
			public String toString() {
				return s;
			}
		}
		/**
		 * Q1. The generic interface Intf is implemented by a generic class Class1 and a
		 * non-generic class Class2.
		 *
		 * The fun() method in the Generic class Class1 prints the String member of class Ques1
		 * in title case i.e. it capitalizes only the first character if its not already
		 * capitalized.
		 *
		 * The non-Generic class implements the interface for Ques1 type only.
		 * The fun() method in the non-Generic class prints the String member
		 * as it is.
		 *
		 * NOTE: INSERT CODE ONLY AT THE LINES MENTIONED EXPLICITLY.
		 * DONT MODIFY THE REMAINING STATEMENTS.
		 */

		//Q1. A.
		/**
		 * YOU CAN MODIFY THE CLASS SIGNATURE AND METHOD SIGNATURE
		 * CLASS1 SHOULD BE A GENERIC CLASS IMPLEMENTING THE GENERIC INTERFACE OF TYPE C
		 */
		class Class1<C> implements Intf {
			public void fun(Object c) {
				//INSERT YOUR CODE TO PRINT THE STRING MEMBER IN TITLE CASE
				String str = c.toString().substring(0,1).toUpperCase() + c.toString().substring(1);
				c.s = str;
			}
		}
		//Q1. B.
		/**
		 * YOU CAN MODIFY THE CLASS SIGNATURE AND METHOD SIGNATURE
		 * CLASS2 SHOULD BE A NON-GENERIC CLASS IMPLEMENTING THE GENERIC INTERFACE OF TYPE Ques1
		 */
		class Class2 implements Intf{
			public void fun(Object c) {
				//INSERT YOUR CODE TO PRINT THE STRING MEMBER
			}
		}

		//Q1. C.
		Intf<Ques1> c[]= new Intf[3];
		/**
		 * Write a lambda expression for c[0] such that the fun method prints the string member
		 * in capital letters.
		 */
		//INSERT YOUR CODE FOR c[0] HERE
    c[0] (c)=> {

    }

		//DONT MODIFY THE FOLLOWING CODE FRAGMENT
		/**
		 * For the given input in the code skeleton, the Expected Output is:
		   OOP Compre Test
		 */
		c[0].fun(new Ques1("oop "));
		c[1] = new Class1<Ques1>();
		c[1].fun(new Ques1("compre "));
		c[2] = new Class2();
		c[2].fun(new Ques1("Test"));

	} //END OF QUES1()

	/* QUESTION 2: BINARY MARKING [0/01/04/05 M]*/

	static void ques2() {
		/**
		 * Q2. GENERIC CLASS QUES2 HAS A GENERIC LIST AND A BOOLEAN VAR AS ITS DATA MEMBERS
		 * THE CONSTRUCTOR IS USED TO INITIALIZE ITS DATA MEMBERS
		 *
		 * WRITE YOUR IMPLEMENTATION FOR THE METHOD EXISITS() THAT SEARCHES IF THE LIST CONTAINS
		 * THE GENERIC VALUE, IF YES, FOUND IS SET TO TRUE ELSE IT IS FALSE.
		 *
		 */
		class Ques2<T>{
			private List<T> data;
			private boolean found;

			public Ques2(List<T> list) {
				this.data = list;
				found = false;
			}

			public void exists(T value, int start, int end) {
				if(true) //Q2.A. INSERT THE CONDITION TO CHECK THE BASE CASE
				{
					found = found; //Q2.B. UPDATE THE VARIABLE
				}else {
					final int middle = start+ (end-start)/2;
					/**
					 * CREATE AND START RECURSIVE ANNONYMOUS THREADS USING LAMBDA EXPRESSIONS.
					 * FIRST RECURSIVE THREAD SEARCHES FOR THE ELEMENT IN SUBSPACE
					   (START TO MIDDLE)
					 * SECOND RECURSIVE THREAD SEARCHES FOR THE ELEMENT IN SUBSPACE
					   (MIDDLE TO END)
					 */
					//Q2. C. INSERT NOT MORE THAN TWO LINES OF CODE HERE
				}
			}
		}
		int search = 7;  //Also test with search = 4;
		/**
		 * INPUT				EXPECTED OUTPUT
		 *   7						false
		 *   4						true
		 *
		 * NOTE: NECESSARY MULTI-THREADING CODE CAN BE INSERTED IN THE FOLLOWING
		 * CODE FRAGMENT
		 */
		List<Integer> d = Arrays.asList(1,2,3,4,5,6);
		Ques2<Integer> t = new Ques2<Integer>(d);
		t.exists(search, 0, d.size());
		System.out.println(t.found);

	}//END OF QUES2()

	/* QUESTION 3: BINARY MARKING [0/02/04 M]*/

	static void ques3() {
		/**
		 * Q3. USE OUTPUTSTREAM TO WRITE THE DATA INTO THE GIVEN FILE, file.txt
		 * THE CHARACTERS IN THE DATA MUST BE CAPITALIZED BEFORE WRITING INTO THE FILE.
		 *
		 * USE SCANNER CLASS TO READ THE FILE, file.txt
		 * AND PRINT ONLY THE CHARACTERS FROM THE FILE.
		 * SYMBOLS AND NUMBERS SHOULD NOT BE PRINTED.
		 *
		 * FOR THE GIVEN INPUT:
		 * THE FILE file.txt SHOULD CONTAIN THE FOLLOWING:
		   J@AV!A9

		 * THE EXPECTED OUTPUT AT THE CONSOLE IS :
		   JAVA

		 * NOTE: MODIFY THE CODE TO GET THE DESIRED OUTPUT. CONSTRAINTS MENTIONED ABOVE SHOULD BE
		 * SATISFIED
		 */

		File f = new File("file.txt");
		try(OutputStream os = null){
			byte[] data = {'j','@','a','v','!','a','9'};
			os.write(data);
		}catch(Exception e) {}

		try(Scanner is = null){
			System.out.println(is);
		}catch(Exception e) {}

	}//END OF QUES3()

	/* QUESTION 4: TOTAL MARKS [15 M]*/

	static void ques4(){
		/**
		 * Q4.  An organization is maintaining a Map that stores the ID and
		 * employee details such as Name and department. An user defined exception,
		 * AddEmpException, should be thrown if the employee with same name and dept is already
		 * found in the Map.
		 */

		class AddEmpException extends RuntimeException {
			private String message;
			//Q4. A. WRITE YOUR IMPLEMENTATION FOR THE USER DEFINED EXCEPTION  - 2 	MARKS
		}
		class Employee{
			String name;
			String dept;

			Employee(String dept,String name){
				this.name = name;
				this.dept = dept;
			}
			//Q4. B. OVERRIDDEN METHODS CAN BE IMPLEMENTED TO GENERATE THE DESIRED OUTPUT - 6 MARKS
		}
		class EmpDB {
			Map hm;

			EmpDB(Map hm){
				this.hm = hm;
			}
			//Q4. C. - 4 MARKS
			void addEmp(Integer id, String dept, String name) throws AddEmpException {
				/**
				 * COMPLETE THE IMPLEMENTATION
				 *
				 * NEW EMPLOYEES ARE ADDED TO THE MAP.
				 * IF THE EMPLOYEE DETAILS ARE ALREADY FOUND, THEN THROW AN EXCEPTION
				 */
			}
		}

		//Q4. D. - 3 MARKS
		/**
		 * USE Map.of() METHOD TO INITIALIZE THE MAP WITH THE FOLLOWING DETAILS
		 *
		   111 CSE Amit
		   112 CSE  Vishal
		   123 Mech Murali
		   124 Mech Vishnu
		   125 EEE  Rajat
		 */
		Map<Integer,Employee> hm = null;   //COMPLETE THE CODE
		/**
		 * INPUT								EXPECTED OUTPUT
		 * db.addEmp(126, "EEE", "Rajat");		Failed!!! Employee Already in DB
		 * db.addEmp(126, "ECE", "Rajat");		Employee Added Successfully
		 */
		try {
			EmpDB db = new EmpDB(hm);
			db.addEmp(126, "EEE", "Rajat");  //INPUT
			System.out.println("Employee Added Successfully");
		}catch(AddEmpException e) {
			System.out.println("Failed!!! "+e);
		}
		hm.forEach((key, value) -> {System.out.println( "Key: " + key + " " + value);});
	}//END OF QUES4()
} //END
