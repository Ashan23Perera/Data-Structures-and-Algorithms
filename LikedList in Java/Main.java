
/*MAIN CLASS -------- IMPLEMENT THE LINKED LIST */

public class Main
{
    public static void main(String[] args) 
    {

//CHECK FOR INTEGER
             MyList<Integer>  ob = new MyList<Integer>();         
System.out.println("-----------------------CHECK FOR INTEGER-----------------------");

//ADD SOME DATA TO LINKED LIST             
             ob.add(45);
             ob.add(55);
             ob.add(65);
             ob.add(75);
             ob.add(85);

                     System.out.println("PRINT THE LIST");
//PRINT THE LIST         
             ob.prinList();
             
                     System.out.println("\n\nREMOVE THE HEAD AND PRINT THE LIST");

//REMOVE THE HEAD             
             ob.remove();
//PRINT THE LIST
             ob.prinList();
             
                     System.out.println("\n\nCHECK FOR LIST HAS ELEMENTS");

//CHECK THE LIST HAS ELEMENTS
         if(ob.hasElements()){
 	        System.out.println("List is not empty");
         }else{
	        System.out.println("List is empty");
         }

//REMOVE SOME ELEMENTS         
             ob.remove();
             ob.remove();
             ob.remove();
             ob.remove();

         System.out.println("\n\nREMOVE ALL THE ELEMENTS AND CHECK FOR LIST IS EMPTY");

//CHECK THE LIST IS EMPTY
         if(ob.isEmpty()){
 	         System.out.println("List is empty");
         }else{
	         System.out.println("List not empty");
         }


//CHECK FOR STRING
             MyList<String>  obj = new MyList<String>();
System.out.println("\n\n\n-----------------------CHECK FOR STRING-----------------------");

//ADD SOME DATA TO LINKED LIST             
             obj.add("FIRST");
             obj.add("sECOND");
             obj.add("THREE");
             obj.add("FOUR");
             obj.add("FIVE");

                     System.out.println("PRINT THE LIST");

  System.out.println("\n\nREMOVE THE HEAD AND PRINT THE LIST");

//REMOVE THE HEAD             
             obj.remove();
//PRINT THE LIST
             obj.prinList();
             
                     System.out.println("\n\nCHECK FOR LIST HAS ELEMENTS");

//CHECK THE LIST HAS ELEMENTS
         if(obj.hasElements()){
 	        System.out.println("List is not empty");
         }else{
	        System.out.println("List is empty");
         }

//REMOVE SOME ELEMENTS         
             obj.remove();
             obj.remove();
             obj.remove();
             obj.remove();

         System.out.println("\n\nREMOVE ALL THE ELEMENTS AND CHECK FOR LIST IS EMPTY");

//CHECK THE LIST IS EMPTY
         if(obj.isEmpty()){
 	         System.out.println("List is empty");
         }else{
	         System.out.println("List not empty");
         }




    }

}