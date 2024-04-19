import heapq
from collections import Counter, namedtuple

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(text):
    freq_counter = Counter(text)
    priority_queue = [Node(char, freq) for char, freq in freq_counter.items()]
    heapq.heapify(priority_queue)

    while len(priority_queue) > 1:
        left = heapq.heappop(priority_queue)
        right = heapq.heappop(priority_queue)
        merged = Node(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(priority_queue, merged)

    return priority_queue[0]

def build_huffman_codes(node, prefix="", codes={}):
    if node:
        if node.char:
            codes[node.char] = prefix
        build_huffman_codes(node.left, prefix + "0", codes)
        build_huffman_codes(node.right, prefix + "1", codes)
    return codes

def huffman_encode(text, codes):
    encoded_text = ''.join(codes[char] for char in text)
    return encoded_text

def huffman_decode(encoded_text, codes):
    decoded_text = ""
    current_code = ""
    for bit in encoded_text:
        current_code += bit
        for char, code in codes.items():
            if current_code == code:
                decoded_text += char
                current_code = ""
                break
    return decoded_text

# Take input from the user
text = input("Enter the text to be encoded using Huffman coding: ")

# Build Huffman tree and codes
root = build_huffman_tree(text)
codes = build_huffman_codes(root)

# Encode the text
encoded_text = huffman_encode(text, codes)
print("Encoded text:", encoded_text)
print("Huffman Codes:", codes)

# Decode the encoded text
decoded_text = huffman_decode(encoded_text, codes)
print("Decoded text:", decoded_text)
