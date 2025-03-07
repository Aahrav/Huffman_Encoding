
# Huffman Encoding and Cost Analysis

This C++ project implements Huffman encoding for a given string and analyzes the compression costs.

## Overview

Huffman encoding is a popular lossless data compression algorithm. It assigns variable-length codes to input characters, with shorter codes for more frequent characters and longer codes for less frequent characters. This results in efficient compression.

This project:

1.  **Builds a Huffman Tree:** Constructs a Huffman tree based on the frequency of characters in the input string.
2.  **Generates Huffman Codes:** Generates unique binary codes for each character using the Huffman tree.
3.  **Encodes the String:** Encodes the input string using the generated Huffman codes.
4.  **Calculates Costs:** Analyzes the compression costs, including the original string size, encoded string size, Huffman tree size, and the percentage of data saved.

## Features

* **Huffman Encoding:** Implements the core Huffman encoding algorithm.
* **Cost Analysis:** Provides detailed cost analysis of the compression process.
* **Shared Pointers:** Uses `shared_ptr` for efficient memory management of the Huffman tree nodes.
* **Priority Queue:** Utilizes a priority queue to efficiently build the Huffman tree.
* **Clear Output:** Outputs the original string, encoded string, Huffman codes, and cost analysis in a readable format.



### Prerequisites

* C++ compiler (e.g., g++)
* Standard C++ library

