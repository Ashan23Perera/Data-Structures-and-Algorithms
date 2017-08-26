#Selection sort
import timeit

#Enter number of elements
N = input("Enter number of elements:");

#Reading the Data.txt file 
#Take N number of elements to array
array=[]
with open("Data.txt", "r") as filestream:
        for line in filestream:
            currentline = line.split(",")              

for i in range(0, N):  
     array.append(int(currentline[i]));         

#Sort
start = timeit.default_timer();

i = 0;
while(i < N):
    minimum = i;
    j = i + 1;
    while(j < N):
        if(array[j] > array[minimum]):
            minimum = j;
        j = j + 1;    
    t        = array[i];
    array[i] = array[minimum];
    array[minimum] = t;
    i = i + 1;
    
stop = timeit.default_timer();

#print the sorted array
print("Sorted Array");
i = N -1;
while(i >= 0):
    print(array[i]);
    i = i - 1;

#print th etime taken to sort
print "Time taken to sort: %(time)d " % {"time": stop - start};
