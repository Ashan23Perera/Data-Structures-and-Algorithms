#swap function
def swap(num1,num2):
    temp = num2
    num1 = num2
    num2 = num1
    return num1,num2

#quick sort functon
def quicksort(array,firstIndex,lastIndex):
    #index variable
    pivotIndex = 0;
    temp = 0
    index1 = 0
    index2 = 0
    if(firstIndex < lastIndex):

        #first element index =  pivot
        pivotIndex = firstIndex
        index1 = firstIndex
        index2 = lastIndex

        #sort 
        while(index1 < index2):
            while(( array[index1] <=array[pivotIndex]) & (index1 < lastIndex)):
                index1 = index1 + 1;
            while(array[index2] > array[pivotIndex]):
                index2 = index2 - 1;
            if(index1 < index2):
                arr = swap(array[index1],array[index2])
                array[index1] = arr[0];
                array[index2] = arr[1];
                
        #swap pivot element with index2 element 
        arr = swap(array[pivotIndex],array[index2]) 
        array[pivotIndex] = arr[0]
        array[index2] = arr[1]
        
        #recursive call
        quicksort(array,firstIndex,index2 - 1)
        quicksort(array,index2+1,lastIndex)

#Test case

array = [1,56,10,23,56,89]
quicksort(array,0,len(array) - 1);
for i in range(0,len(array)):
    print array[i]
        

            
