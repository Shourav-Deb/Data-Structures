/*
                                                Lab Mini Project
                                              ---------------------
# Problem:
Create a student Record Management system that can perform the following operations using Linked List:
    • Insert Student record
    • Delete student record
    • Show student record
    • Search student record

The student record should contain the following items
    • Name of Student
    • Roll Number of Student
    • Course in which Student is Enrolled
    • Total Marks of Student

# Approach: With the basic knowledge of operations on Linked Lists like
insertion, deletion of elements in the Linked list, the student record
management system can be created. Below are the functionalities explained
that are to be implemented:
    
    • Check Record: It is a utility function of creating a record it checks
                    before insertion whether the Record Already Exists or not. It uses the
                    concept of checking for a Node with given Data in a linked list.
    • Create Record: It is as simple as creating a new node in the Empty
                    Linked list or inserting a new node in a non-Empty linked list.
    • Search Record: Search a Record is similar to searching for a key in
                    the linked list. Here in the student record key is the roll number as the
                    roll number is unique for every student.
    • Delete Record: Delete Record is similar to deleting a key from a
                    linked list. Here the key is the roll number. Delete record is an integer
                    returning function it returns -1 if no such record with a given roll
                    number is found otherwise it deletes the node with the given key and
                    returns 0.
    • Show Record: It shows the record is similar to printing all the
                    elements of the Linked list.
# Exception Handling: Although the implementation of exception handling is quite simple few things
must be taken into consideration before designing such a system:
        • Roll Number must be used as a key to distinguish between two
        different records so while inserting a record check whether this record
        already exists in our database or not if it already exists then
        immediately report to the user that the record already exists and
        insert that record in the database.
        • The record should be inserted in sorted order for this to make the roll
        number a key and use the inserting node in the sorted linked list.
*/


package studentportal;

/**
 *
 * @author SD
 */
public class Home {

    public static void main(String[] args) {
        Portal welcome = new Portal();
        welcome.show();
    }
}