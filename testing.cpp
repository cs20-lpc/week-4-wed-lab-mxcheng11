#include <iostream>
#include <string>
#include "DoublyList.hpp"

using namespace std; 

int main()
{
    cout << "Testing Doubly Linked List" << endl;
    
    cout << "TEST 1: basic operations w/ ints \n";
    {
        DoublyList<int> list1;
        
        cout << "Initial list (should be empty): " << list1;
        
        cout << "\nAppending 10, 20, 30:\n";
        list1.append(10);
        list1.append(20);
        list1.append(30);
        cout << "List: " << list1;
        cout << "getLength(): " << list1.getLength() << " (should be 3)\n";
        
        cout << "\nTesting getElement:\n";
        cout << "getElement(0): " << list1.getElement(0) << " (should be 10)\n";
        cout << "getElement(1): " << list1.getElement(1) << " (should be 20)\n";
        cout << "getElement(2): " << list1.getElement(2) << " (should be 30)\n";
        
        cout << "\nTesting search:\n";
        cout << "search(20): " << list1.search(20) << " (should be 1)\n";
        cout << "search(99): " << list1.search(99) << " (should be 0)\n";
        
        cout << "\nTesting isEmpty on non-empty list: " << list1.isEmpty() << " (should be 0)\n";
    }
    
    cout << "\n\nTEST 2: insert \n";
    {
        DoublyList<int> list2;
        
        cout << "Insert at beginning:\n";
        list2.insert(0, 30);
        list2.insert(0, 20);
        list2.insert(0, 10);
        cout << "List: " << list2;
        
        cout << "\nInsert in middle (position 2):\n";
        list2.insert(2, 25);
        cout << "List: " << list2;
        
        cout << "\nInsert at end (position " << list2.getLength() << "):\n";
        list2.insert(list2.getLength(), 40);
        cout << "List: " << list2;
        
        cout << "\nTest invalid insert (position -1):\n";
        try {
            list2.insert(-1, 999);
            cout << "FAILED\n";
        } catch (...) {
            cout << "PASSED\n";
        }
    }
    
    cout << "\n\nTEST 3: remove \n";
    {
        DoublyList<int> list3;
        for (int i = 0; i < 5; i++) {
            list3.append(i * 10);
        }
        cout << "Initial list: " << list3;
        
        cout << "\nRemove from beginning (position 0):\n";
        list3.remove(0);
        cout << "List: " << list3;
        
        cout << "Remove from middle (position 1):\n";
        list3.remove(1);
        cout << "List: " << list3;
        
        cout << "Remove from end (position " << list3.getLength() - 1 << "):\n";
        list3.remove(list3.getLength() - 1);
        cout << "List: " << list3;
        
        cout << "\nTest invalid remove (position 5):\n";
        try {
            list3.remove(5);
            cout << "FAILED\n";
        } catch (...) {
            cout << "PASSED\n";
        }
    }
    
    cout << "\n\nTEST 4: replace \n";
    {
        DoublyList<int> list4;
        list4.append(100);
        list4.append(200);
        list4.append(300);
        cout << "Initial list: " << list4;
        cout << "Expected: 100 <--> 200 <--> 300\n";
        
        cout << "\nReplace position 0 with 999:\n";
        list4.replace(0, 999);
        cout << "List: " << list4;
        cout << "Expected: 999 <--> 200 <--> 300\n";
        
        cout << "Replace position 2 with 777:\n";
        list4.replace(2, 777);
        cout << "List: " << list4;
        cout << "Expected: 999 <--> 200 <--> 777\n";
        
        cout << "\nTest invalid replace (position 5):\n";
        try {
            list4.replace(5, 123);
            cout << "FAILED\n";
        } catch (...) {
            cout << "PASSED\n";
        }
    }
    
    cout << "\n\nTEST 5: clear and edge cases\n";
    {
        DoublyList<int> list5;
        
        cout << "Empty list: " << list5;
        
        cout << "\nAppend to empty list:\n";
        list5.append(42);
        cout << "List: " << list5;
        cout << "Expected: 42\n";
        
        cout << "\nRemove only element:\n";
        list5.remove(0);
        cout << "List: " << list5;
        cout << "Expected: (empty)\n";
        
        cout << "\nTest getElement on empty list:\n";
        try {
            list5.getElement(0);
            cout << "FAILED\n";
        } catch (...) {
            cout << "PASSED\n";
        }
        
        cout << "\nAdd elements then clear:\n";
        list5.append(10);
        list5.append(20);
        list5.append(30);
        cout << "Before clear: " << list5;
        list5.clear();
        cout << "After clear: " << list5;
        cout << "isEmpty(): " << list5.isEmpty() << " (should be 1)\n";
    }
    
    cout << "\n\nTEST 6: different data types\n";
    {
        cout << "Testing with double:\n";
        DoublyList<double> doubleList;
        doubleList.append(3.14);
        doubleList.append(2.718);
        cout << "Double list: " << doubleList;
        
        cout << "\nTesting with string:\n";
        DoublyList<string> stringList;
        stringList.append("Hello");
        stringList.append("World");
        cout << "String list: " << stringList;
        cout << "search('World'): " << stringList.search("World") << " (should be 1)\n";
        cout << "search('boo'): " << stringList.search("boo") << " (should be 0)\n";
    }
    
    cout << "\n\nTEST 7: copy constructor and assignment\n";
    {
        DoublyList<int> original;
        original.append(1);
        original.append(2);
        original.append(3);
        cout << "Original: " << original;
        
        cout << "\nCopy constructor:\n";
        DoublyList<int> copy(original);
        cout << "Copy: " << copy;
        
        cout << "\nAssignment operator:\n";
        DoublyList<int> assigned;
        assigned = original;
        cout << "Assigned: " << assigned;
        
        cout << "\nModify original (replace position 0 with 999):\n";
        original.replace(0, 999);
        cout << "Original now: " << original;
        cout << "Copy (should be unchanged): " << copy;
        cout << "Assigned (should be unchanged): " << assigned;
    }
    
    cout << "\n\nTEST 8: Multiple Operations Sequence\n";
    {
        DoublyList<int> list8;
        
        cout << "Starting with empty list\n";
        cout << "Append 5, 15, 25:\n";
        list8.append(5);
        list8.append(15);
        list8.append(25);
        cout << "List: " << list8;
        
        cout << "\nInsert 10 at position 1:\n";
        list8.insert(1, 10);
        cout << "List: " << list8;
        
        cout << "\nInsert 20 at position 3:\n";
        list8.insert(3, 20);
        cout << "List: " << list8;
        
        cout << "\nRemove position 2:\n";
        list8.remove(2);
        cout << "List: " << list8;
        
        cout << "\nReplace position 1 with 99:\n";
        list8.replace(1, 99);
        cout << "List: " << list8;
        
        cout << "\nFinal length: " << list8.getLength() << " (should be 4)\n";
        cout << "Search for 20: " << list8.search(20) << " (should be 1)\n";
        cout << "Search for 15: " << list8.search(15) << " (should be 0)\n";
    }
    
    cout << "\nTESTS COMPLETED\n";
    
    return 0;
}