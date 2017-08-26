#copy arrays
def copyArray(array1,array2,a,b):
    while(a < b):
        array1[a] = array2[a]
        a = a + 1;
        
#merge function
def merge(array,l,m,r):
    n1 = m - l + 1
    n2 = r - m;

    #Temporary L,R arrays
    L = {};
    R = {};
    i = 0;

    #copy array Array to L,R Arrays
    while(i < n1):
        L[i] = array[l+i];
        i = i + 1;
    j = 0;    
    while(j < n2):
        R[j] = array[m + 1 + j];
        j = j + 1;
    #Merge L,R Arrys back to array Array    
    i = 0;
    j = 0;
    k = l;
    while((i < n1) & (j < n2)):
        if(L[i] <= R[j]):
            array[k] = L[i];
            i = i + 1;
        else:
            array[k] = R[j]
            j = j + 1
        k = k + 1;
    #copy the remaining elements L,R Arrays    
    while(i < n1):
        array[k] = L[i];
        i = i + 1
        k = k + 1
    while(j < n2):
        array[k] = R[j]
        j = j + 1;
        k = k + 1

#mergesort function    
def mergesort(array,n):
    curr_size = 1;
    #merge sub Arrays
    while(curr_size <= n - 1):
        left_start = 0;
        while(left_start < n - 1):
            #find ending point of left sub array
            #mid + 1 is starting point of right
            mid = left_start + curr_size - 1;
            right_end  = 0;
            num = left_start + 2*curr_size - 1  
            if(num < (n - 1)):
                right_end = num
            else:
                right_end = n - 1;
            #merge sub arrays    
            merge(array,left_start,mid,right_end);
            left_start = left_start + 2*curr_size
        curr_size = 2*curr_size;



#Test case

array = [1,12,11,56,89,50];
mergesort(array,len(array))
for i in range(0,len(array)):
    print array[i]
     

