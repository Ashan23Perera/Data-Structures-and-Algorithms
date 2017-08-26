/**
 *
 * @author Nathasha Naranpanawa
 */
 import java.util.HashMap;
    
    
    public class SparseMatrix {

    private int size;
    private HashMap<Long,Integer> map ;

    public SparseMatrix(){
        this.map = new HashMap<Long,Integer>();      
    }
    // create an empty square matrix of given size

    public void createEmptyMatrix(int size){
       this.size = size;       
    }

//Overload  set method for two varables     set(int i,int j)
//                         three variables  set(int i.int j, int value)   
 
    // put A[i][j] = 1
     public void set(int i, int j){
  
      long hash = (long)(i*size+j);
        map.put(hash,1);
    }
  
    // put A[i][j] = value
    public void set(int i, int j,int value){
        
      long hash = (long)(i * size + j);
        map.put(hash,value);
    } 

     
  // return value at A[i][j]
    public int get(int i, int j){
  
     long hash = (long)(i * size + j);
     
         if(map.containsKey(hash))
         return map.get(hash);
    
         return 0;
    }

}
    

