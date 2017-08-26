/*  Node Class ------------ Defins a One Node   */

class Node<T>
{
    public T data;
    public Node<T> nextNode;

    public Node(T data){
         this.data = data;
    }

}

/*MyList ----------------- IMPLEMENT THE LINKEDLIST CLASS  */

class MyList <T>
{
    public Node<T> node;    

     MyList(){
         node     = null;   
     }

//ADD THE GIVEN DATA ITEM TO THE HEAD OF THE LIST
        public void add(T data){
            Node<T> nodeLink  = new Node<T>(data);
            nodeLink.nextNode = node;
            node              = nodeLink;

        }

//RETURN TRUE IF THE LIST EMPTY        
        public boolean isEmpty(){
               return node == null;
        }

//RETURN TRUE IF THERE IS AT LEAST ONE ELEMENT IN THE LIST        
        public boolean hasElements(){
               return node != null;
        }

//REMOVE THE ITEM AT THE HEAD.RETURN NULL IF THE LIST IS EMPTY         
        public T remove(){
            Node<T> nodEnd = node;
            node = node.nextNode;
            return nodEnd.data;
        }
        
//SIZE OF THE LINKEDLIST
          public  int  size(){
                  Node<T> link = node;
                  int size = 0;
                  while(link != null){
                      link = link.nextNode;
                      size = size + 1;
                  }
                  return size;
          }
          
//PRINT A ELEMENT        
        public void prinElement(int element){
            Node<T> link   = node;
        
            int i = 0;
            while(i < size() - element){
                link  = link.nextNode;
                i     = i  +  1;
            }
            System.out.println(link.data); 
        } 

//PRINT THE LIST        
        public void prinList(){
            int i = 1;
            while(i <= size()){
                prinElement(i); 
                i = i + 1;
            }

        }
}

