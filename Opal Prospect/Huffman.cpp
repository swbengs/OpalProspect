//class header
#include "Huffman.hpp"

//std lib includes
#include <iostream>

//other includes

/*
MIT License

Copyright (c) 2020 Scott Bengs

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

//class code
struct HuffmanNode {

    char data;
    unsigned frequency;
    HuffmanNode* left, * right;

    HuffmanNode(char data, unsigned freq)

    {

        left = nullptr;
        right = nullptr;
        this->data = data;
        this->frequency = freq;
    }
};

struct compare {

    bool operator()(HuffmanNode* l, HuffmanNode* r)

    {
        return (l->frequency > r->frequency);
    }
};

Huffman::Huffman()
{

}

const std::unordered_map<char, std::string>& Huffman::getCodeMap() const
{
    return codes;
}

void Huffman::makeHashMap(struct HuffmanNode* root, std::string str)
{

    if (root == nullptr)
    {
        return;
    }

    if (root->data != '#')
    {
        //std::cout << root->data << ": " << str << "\n";
        codes[root->data] = str;
    }

    makeHashMap(root->left, str + "0");
    makeHashMap(root->right, str + "1");
}

void Huffman::generateHuffmanCodes(char data[], int freq[], int size)
{
    struct HuffmanNode* left, * right, * top;

    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
    {
        minHeap.push(new HuffmanNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new HuffmanNode('#', left->frequency + right->frequency);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    makeHashMap(minHeap.top(), "");
}
