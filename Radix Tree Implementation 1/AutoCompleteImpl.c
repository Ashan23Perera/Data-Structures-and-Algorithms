#include "AutoCompleteImpl.h"

char *array_array; 

//createArray function
//for copy char array to new created char array
char * createArray(char array[],char letter)
{
    array_array = (char *)malloc(sizeof(char)* (strlen(array) + 1)) ;
    int i = 0; 
    while(i < strlen(array)){
       array_array[i] = array[i];  
       i = i + 1;
    }
    array_array[i] = letter;
    return array_array;  
}


//createNode function
TrieNode *createTrieNode()
{
    TrieNode * trienode = (TrieNode*) malloc(sizeof(TrieNode));       
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
	 trienode->children[i] = NULL;
    }
    return trienode;
}

//insert function
void insert(TrieNode *root, const char *word)
{ 

    int j;
    int i = 0;
    int length                = strlen(word); 
    TrieNode* currentPosition = root;
    
    while(currentPosition->children[word[i]- 'a'] != NULL){
       currentPosition = currentPosition -> children[word[i]- 'a'];   
       i = i + 1;
    }
    j = i;
    while(j < length){
         TrieNode* newPosition           = createTrieNode();
         newPosition -> label            = word[j];
         newPosition -> isEndOfWord      = (j == length -1);
         currentPosition -> children[word[i]- 'a']  = newPosition;
         currentPosition                 = newPosition;
         j = j + 1;
    }	
      
}

//search function
TrieNode *search(TrieNode *root, const char *word) 
{

    if(root == NULL) return NULL;

    int i ;
    int length                = strlen(word); 
    TrieNode* currentPosition = root;
    TrieNode* newPosition     = createTrieNode();

    for(i = 0; i < length; i++){
         newPosition     = currentPosition -> children[word[i] - 'a'];
         if(newPosition == NULL) return NULL;
         currentPosition = newPosition;              
    }      
    return currentPosition;
}



//traverse function
void traverse(char prefix[], TrieNode *root, int e) 
{

    if(root == NULL) return;

    TrieNode * currentPosition = root;
    if(currentPosition -> isEndOfWord == true){
        int i;
        for(i = 0; i < e; i++){
           printf("%c", prefix[i]);
        }
        printf("\n");
    } 
    
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
        TrieNode * currentTemp = currentPosition -> children[i];
        if(currentTemp != NULL){
            prefix[e] = currentTemp->label;
            traverse(prefix, currentTemp, e + 1);
        }
    }  
    
}
