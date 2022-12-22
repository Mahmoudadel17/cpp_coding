

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
//class for each node which has array of children and index of string and id
class TrieNode
{
public:
    int index;
    //number of alphabet is 26 + $ = 27
    TrieNode* arr[27];
    //each node has id = -1 if it isn't the leaf node
    int id = -1;
    //make array of childern empty and dont point to any other node
    TrieNode()
    {
        for (int i = 0; i < 27; i++)
        {
            arr[i] = NULL;
        }

    }
};
//class for the whole tree which has nodes and the text 
class suffixTrie
{
private:
    TrieNode* root;
    char* text;
    int len_text;
    //take index of char in the text to insert it into the tree
    void insert(int i)
    {
        // check if the char is '$'
        if (i == len_text - 1) {
            TrieNode* newNode = new TrieNode();
            newNode->index = i;
            newNode->id = i;
            //make last index in the array point to '$'
            root->arr[26] = newNode;
        }
        // if it is the first time for this char 
        else if (root->arr[text[i] - 97] == NULL)
        {
            TrieNode* newNode = new TrieNode();
            newNode->index = i;
            newNode->id = i;
            //text[i] is A for example and - 97 so it became 0 so the index 0 of arr will point to the newnode
            root->arr[text[i] - 97] = newNode;

        }
        // if we had substrrings for this char
        else
        {
            //make the pointer node point to the root in the first then go next
            TrieNode* currentNode = root->arr[text[i] - 97];
            //check if the pointer node is leaf or not
            if (checkNodeLeaves(currentNode))
            {
                // in this case node dont have children, we can add dirctly
                addNodeInLeaves(currentNode, i);
            }
            else
            {
                // that node have another children 
                // so the current Node pointer will be Change
                // first get edge size of char and compare if all char equal, make current Node equal child node with same char
                addNodeInMiddel(currentNode, root, i);
            }
        }
    }
    //add 2 nodes but one of them in the adge 
    void addNodeInMiddel(TrieNode* currentNode, TrieNode* prevNode, int i) {
        // edge size
        int length, prevLength;
        // get index for two string in the original text.
        int index2 = i;
        int index[len_text] = { -1 };
        int counter = 0;
        //loop in the tree and stop when reach the char of index i
        for (int x = 0; x < i; x++)
        {
            //check if the two charachters is the same so move to the next char
            if (text[x] == text[i])
            {
                index[counter] = x;
                counter++;
            }

        }


        // compare index in text until there become not equal.
        prevLength = length = getEdgeLength(currentNode);
        //to save best index we will find when traverse in the tree
        int bestindex1;
        int size = 0;
        //loop more than one time to check all possible match index and get the best of them
        for (int z = 0; z < counter; z++)
        {
            int temp = index2, temp2 = index[z];
            //to store the best length of best index
            int best_len = 0;
            //check if the two char is the same and stop if not
            while (text[temp2] == text[temp])
            {
                temp++;
                temp2++;
                best_len++;

            }
            //compare the lengths to store the largest of them
            if (best_len > size)
            {
                bestindex1 = index[z];
                size = best_len;
            }


        }
        int index1 = bestindex1;
        //now check each two chars put with the best fit index so we detremine the right branch
        while (text[index1] == text[index2])
        {
            //check if we still on the same edge
            if (length == 0)
            {
                //  update current node and prevNaode.
                prevNode = currentNode;
                //current node will be the next child node which hase index = last length + best index 
                currentNode = currentNode->arr[text[prevLength + bestindex1] - 97];
                length = getEdgeLength(currentNode);

                prevLength += length;

            }
            //go to next nodes and deacrese length to check if we move from edge to onther
            length--;
            index1++;
            index2++;
        }
        //check if we should only add one new node
        if (length == 0)
        {
            TrieNode* newNode = new TrieNode();
            newNode->index = index2;
            newNode->id = i;
            //check if the char is "$"
            if (index2 == len_text - 1)
            {
                currentNode->arr[26] = newNode;
            }
            else
            {
                currentNode->arr[text[index2] - 97] = newNode;
            }
        }
        //if we should add to nodes but one of them in the edge
        else
        {
            //the node which will be on the edge
            TrieNode* newNode1 = new TrieNode();
            //swap the index of current node with new node which has small index
            newNode1->index = currentNode->index;
            currentNode->index = index1;
            newNode1->id = -1;
            //make new node with the large index and assign it's id
            TrieNode* newNode2 = new TrieNode();
            newNode2->index = index2;
            newNode2->id = i;
            // check that index2 in text equal $ for new node and then for current node
            if (index2 == len_text - 1)
            {
                newNode1->arr[26] = newNode2;
            }
            else
            {
                newNode1->arr[text[index2] - 97] = newNode2;
            }
            if (currentNode->index == len_text - 1)
            {
                newNode1->arr[26] = currentNode;
            }
            else
            {
                newNode1->arr[text[currentNode->index] - 97] = currentNode;
            }
            //make the parent of current node point to the new node
            if (prevNode->index == len_text - 1)
            {
                prevNode->arr[26] = newNode1;
            }
            else
            {
                prevNode->arr[text[newNode1->index] - 97] = newNode1;
            }
        }
    }
    //get the length of each edge by Subtract index of current node from the smallest index of it's children
    int getEdgeLength(TrieNode* currentNode) {
        int min_index, c = 0;
        for (int i = 0; i < 27; i++)
        {
            //check if this index has child
            if (currentNode->arr[i] != NULL)
            {
                //for first time when we only have index of current node and can't compare it 
                if (c == 0)
                {
                    min_index = currentNode->arr[i]->index;
                    c++;
                }
                else {
                    // get minimam size from children 
                    min_index = min(currentNode->arr[i]->index, min_index);
                }

            }
        }
        // get length of string in index, which that first char on it 
        // equal first char in new string want to be add.
        return  min_index - currentNode->index;
    }
    //add 2 nodes as the children of current node if it is leaf
    void addNodeInLeaves(TrieNode* currentNode, int i) {
        // get index for two string in the original text.
        int index1 = currentNode->index, index2 = i;
        // compare index in text until there become not equal.
        while (text[index1] == text[index2])
        {
            index1++;
            index2++;
        }
        // ex: anana$    ana$   index 1 , 3
        // aftar while index1 = 4 , index2 = 6
        // create two node under currentNode 
        TrieNode* newNode1 = new TrieNode();
        newNode1->index = index1;
        newNode1->id = currentNode->id;
        currentNode->id = -1;
        TrieNode* newNode2 = new TrieNode();
        newNode2->index = index2;
        newNode2->id = i;
        //check if the char of index is '$'
        if (index2 == len_text - 1)
        {
            //text[index1] is A for example and - 97 so it became 0 so the index 0 of arr will point to the newnode1
            currentNode->arr[26] = newNode2;
            currentNode->arr[text[index1] - 97] = newNode1;
        }
        else
        {
            currentNode->arr[text[index1] - 97] = newNode1;
            currentNode->arr[text[index2] - 97] = newNode2;
        }
    }
    //check if the node is leaf or internal node
    bool checkNodeLeaves(TrieNode* current)
    {
        //counter of how many index in array is empty
        int counter = 0;
        for (int i = 0; i < 27; i++)
        {
            //if the index hasn't any child to point so increase the counter
            if (current->arr[i] == NULL)
            {
                counter++;
            }

        }
        //return true if the node hasn't child and true if has children
        return counter == 27;
    }
public:
    //counstructor which take the string and insert it in the tree
    suffixTrie(char* text)
    {
        len_text = 0;
        this->text = text;
        root = new TrieNode();
        //calc length of text 
        for (int i = 0; text[i] != '\0'; i++)
        {
            len_text++;
        }
        for (int i = 0; i < len_text; i++)
        {
            insert(i);
        }

    }
    //searching for sub text 
    int Search(char* subtext)
    {
        int len_subtext = 0;
        //calc the length of sub text
        while (subtext[len_subtext] != 0)
        {
            len_subtext++;
        }
        //make pointer node start at root
        TrieNode* currentNode = root;
        int i = 0;
        int got = 0;
        //go throw each char in sub text
        for (i = 0; i < len_subtext; i++)
        {
            //check if the pointer node now has child or not
            if (checkNodeLeaves(currentNode->arr[convertCharToInt(subtext[i])]) != true)
            {
                //move the pointer node to the next node
                currentNode = currentNode->arr[convertCharToInt(subtext[i])];
                got++;

                
                int length;
                //check if the node is internal and get the length of it's edge
                if (checkNodeLeaves(currentNode) == false)
                {
                    length = getEdgeLength(currentNode);
                }
                else
                {
                    length = len_text - currentNode->index;
                }
                int counter = 0;
                //compare the char in edge with char of sub text
                for (int j = currentNode->index + 1; j < currentNode->index + length; j++)
                {
                    //check if the char of the sub text and char of text are the same
                    if (text[j] == subtext[got])
                    {
                        i++;
                        counter++;
                        got++;

                    }
                    else break;
                }
            }
            else break;
        }
        //check if reaching the end of sub text
        if (got == len_subtext)
        {
            //start to traverse the tree to get id's
            print(currentNode);
            cout << endl;
            return 0;
        }
    }
    //get index of the char by it's ascii code
    int convertCharToInt(char c) 
    {
        //check if the char is '$' then the index will be the last
        if (c == '$')
        {
            return 26;
        }
        else
        {
            return c - 97;
        }
    }
    //traverse the tree and print the ids of each last node
    void print(TrieNode* current) 
    {
        for (int i = 0; i < 27; i++)
        {
            //check if the node has child
            if (current->arr[i] != NULL)
            {
                //check if the node is leaf then print it's id
                if (checkNodeLeaves(current->arr[i]) == true)
                {
                    cout << current->arr[i]->id << " ";
                }
                //if it's not a leaf take it as sub tree
                else
                {
                    print(current->arr[i]);
                }
            }
        }
    }
    //Destructor of suffix tree
    ~suffixTrie()
    {
        //deleting the tree starting from root
        deleteSuffixTree(root);
        delete root;
    }
    //Delete  suffix tree by recursively way
    void deleteSuffixTree(TrieNode* delnode)
    {
        //traverse all children of the deleted node
        for (int i = 0; i < 27; i++)
        {
            //check if the node has no child
            if (delnode->arr[i] != NULL)
            {
                //move the del node to it's child 
                deleteSuffixTree(delnode->arr[i]);
            }
        }
        //All the Children of a node are recursively called -> delete this node pointers
        delete[] delnode;
    }
};


int main()
{

    // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //            0123456789012
    suffixTrie t("bananabanaba$"); // Test 1
    t.Search("ana"); // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8
    t.Search("ban"); // Prints: 0 6
    t.Search("na"); // Prints: 2 4 8
    t.Search("bana"); // Prints: 0 6
    t.Search("ba"); // Prints: 0 6 10

    suffixTrie r("aabbaaabbaaabbbb$"); // Test 2
    r.Search("aa"); //Prints: 0 4 5 9 10
    r.Search("aab"); //Prints: 0 5 10
    r.Search("bba"); //Prints: 2 7 
    r.Search("aabb"); //Prints: 0 5 10




    return 0;
}