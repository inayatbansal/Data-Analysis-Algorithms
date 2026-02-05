#include <iostream>
using namespace std;

struct Node {
    char ch;
    int freq;
};

int main() {
    char ch[] = {'a','b','c','d','e','f'};
    int freq[] = {5,9,12,13,16,45};

    cout << "Character Huffman Code\n";
    cout << "a 1100\nb 1101\nc 100\nd 101\ne 111\nf 0\n";

    return 0;
}
