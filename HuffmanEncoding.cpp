#include <bits/stdc++.h>
using namespace std;
class HuffmanNode{
public:
   char character;
   int freq;
   shared_ptr<HuffmanNode>left,right; //t has an associated control block that keeps track of the reference count for the managed object. 
//    This reference count is shared among all the copies of the shared_ptr instances pointing to the same object, 
   HuffmanNode(char c,int f):character(c), freq(f), left(nullptr), right(nullptr){}
};
struct CompareNode{
 bool operator()(const shared_ptr<HuffmanNode>& a, const shared_ptr<HuffmanNode>& b){
    return a->freq > b->freq;
 }

};
shared_ptr<HuffmanNode> buildHuffmanTree(const string& str){
    unordered_map<char,int> freq;
    for(char c: str){
        freq[c]++;
    }
    priority_queue<shared_ptr<HuffmanNode>/*type of element stored*/, vector<shared_ptr<HuffmanNode>>/*sequence*/,CompareNode/*order of pQueue*/> pq; 
    for(auto& [c,f]:freq){
        pq.push(make_shared<HuffmanNode>(c,f));
    }
    while(pq.size() > 1){
        auto left = pq.top(); // The auto keyword in C++ specifies that the type of the variable that is being declared will be automatically deducted from its initializer. In the case of functions,
        //  if their return type is auto then that will be evaluated by return type expression at runtime
        pq.pop();
        auto right = pq.top();
        pq.pop();
        auto internal = make_shared<HuffmanNode>('$',left->freq + right->freq); //auto here is used for type deduction 
        //$ is used for denoting the leaf node 
        internal->left = left;
        internal->right = right;
        pq.push(internal);
    }
    return pq.top();
}
void buildHuffman(shared_ptr<HuffmanNode> node, const string& code, unordered_map<char, string>& codes/*final map to store code*/){
    if(node == nullptr){
        return;
    }
    if(node->character != '$'){
        codes[node->character] = code;
    }
    else{
        buildHuffman(node->left,code+"0",codes);
        buildHuffman(node->right,code+"1",codes);
    }
}
pair<string,unordered_map<char, string>> huffmanEncoding(const string& str){
    auto root = buildHuffmanTree(str);
    unordered_map<char,string> codes;
    buildHuffman(root, "", codes);
    string encoded;
    for(char c : str){
        encoded += codes[c];
    }
    return {encoded,codes}; // returns encoded string and the map which contains the data
}
struct Cost{
  int og_bits;
  int encoded_bits;
  int tree_bits;
  int total;
  int savings;
  float saved_percentage;
};

Cost calculateCosts(const string& original, const string& encoded,const unordered_map<char,string>& codes){
    //int og_bits = original.length() * 8 ; //char having 8 bytes memory
    int og_bits = 0;
for (char c : original) {
  og_bits += static_cast<int>(c);
}
    int encoded_bits = encoded.length(); //no of bits in encoded data
    int tree_bits = 0; // to calculate the storage of the tree
    for(auto& [c,code] : codes){
       tree_bits += 8 + code.length(); //This represents the number of bits in the Huffman code for that character + 8 
    }
    int total_encoded_bits = encoded_bits + tree_bits;
    int savings = og_bits - total_encoded_bits;
    float saved_percentage = float((savings*100)/float(og_bits));
    return {og_bits,encoded_bits,tree_bits,total_encoded_bits,savings,saved_percentage};

}
int main(){
    string s = "AaravCannotCode";
    auto [encoded,codes] = huffmanEncoding(s);
    cout<<"Original String: "<< s << endl;
    cout<< "Encoded String: " << encoded <<endl;
    cout<<"Huffman Codes: "<<endl;
    for(auto& [c,code]: codes){
        cout<<"  '"<< c <<"': " <<code <<endl;

    }
    auto costs = calculateCosts(s,encoded,codes);
    cout<<"\nTransmissions Costs: "<<endl;
    cout<<"-> Original: "<< costs.og_bits <<" bits" << endl;
    cout<<"-> Encoded data: "<< costs.encoded_bits <<" bits"<<endl;
    cout<<"-> Huffman Tree: "<<costs.tree_bits <<" bits"<<endl;
    cout<<" After Encoding: "<<costs.total <<" bits"<<endl;
    cout<<" Saved Data: "<<costs.savings <<" bits"<<endl;
    cout<<"Transmission cost saved percentage: "<< setprecision(4) << costs.saved_percentage << "%"<<endl;
    return 0;
}



