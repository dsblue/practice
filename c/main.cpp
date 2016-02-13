#include "BinaryTree.h"

#include "gen.h"
#include "print.h"
#include "Array.h"

extern "C" {
    void reverseStringInPlace(char *);
    int runLinkedList();
}

int main() {

    // Simple Linked List test
    runLinkedList();

    // Simple Binary tree traversal
    BinaryTree tree;
    int values[] = {10,5,20,21,1,6};

    int i;
    for (i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
        tree.addNode(values[i]);
    }
    std::cout << "Traverse Binary Tree" << std::endl;
    tree.traverse();

    char test_string[] = "This is a test";

    // Reverse a string
    std::cout << "Reverse a string" << std::endl;
    printf("%s\n", test_string);
    reverseStringInPlace(test_string);
    printf("%s\n", test_string);

    int *temp;
    const int len = 1000;

    Array<int> A(1000);

    A.generate_random();
    A.bubbleSort();
    A.print();

    i = 10;
    printf("Find %d: index %d\n", i, A.find(i));

    generate_random_array_int(&temp, len);
    print_array_int(temp, len);


}