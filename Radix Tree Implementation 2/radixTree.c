#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define ALPHABET_SIZE (26)
#define NUMBER_OF_WORDS (354935)
#define INPUT_WORD_SIZE (100)


typedef struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    char* edgeLabel[ALPHABET_SIZE]; 
    bool isEndOfWord;
} TrieNode;

typedef struct TrieNode TrieNode;


char* string;

//TAKE THE PREFIX OF THE WORD
char* prefix(char* str, int index)
{
      string = (char*)malloc(sizeof(char)*index);
      int i, j = 0;
      for(i = index; i < strlen(str); i++){
          string[j] = str[i];  
          j++; 
      }
      return string;
}
//TAKE THE SUFFIX OF THE WORD
char* suffix(char* str, int index)
{
      string = (char*)malloc(sizeof(char)*index);
      int i;
      for(i = 0; i < index; i++){
          string[i] = str[i];  
      }
      return string;
}

//CREATE A NEW TRIENODE
TrieNode *createTrieNode(bool isEnd)
{
    TrieNode * trienode = (TrieNode*) malloc(sizeof(TrieNode));       
    int i;
    for(i = 0; i < ALPHABET_SIZE; i++){
	 trienode->children[i] = NULL;
    }
    trienode -> isEndOfWord  = isEnd;
    return trienode;
}

//INSERT A GIVEN WORD TO TRIE
void insert(TrieNode *root, char *word)
{ 
      TrieNode* Position = root;
      int i = 0;
      int length = strlen(word); 
      
      while((i < length) && (Position -> edgeLabel[word[i] -'a'] != NULL)){
            int index = word[i] -'a';
            int j = 0;
            char * string;
            if(Position -> edgeLabel[index] != NULL){
                 string = (char*)malloc(sizeof(char)*strlen(Position -> edgeLabel[index]));    
            }

            while(j < strlen(string) && i < strlen(word) && string[j] == word[i] ){
                ++i;
                ++j;
            }

            if(j == strlen(string)){
                  Position = Position -> children[index];
            }else{    //INSERT A PREFIX OF EXISTING WORD
                  if(i == strlen(word)){
                    TrieNode* existingNode =  Position -> children[index];
                    TrieNode* newNode      =  createTrieNode(true);
                    char * newString       =  prefix(string, j);
                    string                 =  suffix(string, j);
                    Position -> children[index] = newNode;
                    newNode  -> children[newString[0] - 'a']  = existingNode;
                    newNode  -> edgeLabel[newString[0] - 'a'] = newString;  
                  }else{ //INSERT WORD WHICH HAS A PARTIAL MATCH WITH EXISTING WORD
                     char * newString       =  prefix(string, j);
                     TrieNode* newNode      =  createTrieNode(false);
                     char* newWord          =  prefix(word, i);
                     TrieNode* temp         =  Position -> children[index];
                     string                 =  suffix(string, j);
                     Position -> children[index] = newNode;
                     newNode  -> edgeLabel[newString[0] - 'a'] = newString;
                     newNode  -> children[newString[0] - 'a'] = temp;
                     newNode  -> edgeLabel[newWord[0] - 'a'] = newWord;
                     newNode  -> children[newWord[0] - 'a'] = createTrieNode(true);
                          
                  } 
                  return; 
            }
      }  
      
      if(i < strlen(word)){
           Position -> edgeLabel[word[i] - 'a'] = prefix(word, i);
           Position -> children[word[i] - 'a']  = createTrieNode(true);
      }else{
            Position -> isEndOfWord = true;  
      }
}

//SERACH FOR A GIVEN PREFIX IS IN THE NODE 
bool search(char* string, char* prefix)
{ 
    int i = 0; 
    while(string[i] == prefix[i]){
        i++;
    } 
    return i == strlen(prefix); 
}

//TRAVERSE 
void traverse(TrieNode* node, char* str, char* prefix) 
{
        

        if (node -> isEndOfWord) {
            if(search(str, prefix)){
            	printf("%s\n", str);
            }
        }

        if (node -> edgeLabel[str[0] - 'a'] != NULL) {
            	str = node -> edgeLabel[str[0] - 'a'];
            	traverse(node -> children[str[0] - 'a'], str, prefix);
        }
}

char *receiveInput(char *s) {
    scanf("%99s", s);
    return s;
}





int main(){
   
 //CREATE THE ROOT
    TrieNode* Node = createTrieNode(false);

//sample test cases
insert(Node,"aa");
insert(Node,"aaa");
insert(Node,"aah");
insert(Node,"aahed");
insert(Node,"aahing");
insert(Node,"aahs");
insert(Node,"aal");
insert(Node,"aalii");
insert(Node,"aaliis");
insert(Node,"aals");
insert(Node,"aam");
insert(Node,"aardvark");
insert(Node,"aardvark");
insert(Node,"aardwolf");
insert(Node,"aardwolv");
insert(Node,"s");
insert(Node,"aargh");
insert(Node,"aaron");
insert(Node,"aaronic");
insert(Node,"aarrgh");
insert(Node,"aarrghh");
insert(Node,"aas");
insert(Node,"aasvogel");
insert(Node,"aasvogel");
insert(Node,"ab");
insert(Node,"aba");
insert(Node,"abac");
insert(Node,"abaca");
insert(Node,"abacas");
insert(Node,"abacate");
insert(Node,"abacaxi");
insert(Node,"abacay");
insert(Node,"abaci");
insert(Node,"abacinat");
insert(Node,"ovendry");
insert(Node,"ovened");
insert(Node,"ovenful");
insert(Node,"ovening");
insert(Node,"ovenlike");
insert(Node,"ovenly");
insert(Node,"ovenman");
insert(Node,"ovenmen");
insert(Node,"ovenpeel");
insert(Node,"ovens");
insert(Node,"ovensman");
insert(Node,"ovenston");
  

//Enter only prefixes starting in a and o
//Because only that words are inserted

    while (1) {
        printf("Enter keyword: ");
        char str[100];
        receiveInput(str);
        printf("\n==========================================================\n");
        printf("\n********************* Possible Words ********************\n");

        traverse(Node, str,str);
 
        printf("==========================================================\n");
    }
    free(Node);
 
  return 0;
}

