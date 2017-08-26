#Insertion sort
import timeit

#Enter number of elements 
N = input("Enter number of elements:");

#Reading the Data.txt file 
#Take N number of elements to array
array=[]
with open("Data.txt", "r") as filestream:
        for line in filestream:
            currentline = line.split(",");            

for i in range(0, N):  
     array.append(int(currentline[i]));
     
#Sort
start  = timeit.default_timer()

i = 1;
while(i < N):
    j = i - 1;
    k = array[i];
    while((j >= 0) & (k < array[j])):
        array[j+1] = array[j];
        j = j - 1;
    array[j+1] = k;
    i = i + 1;

stop  = timeit.default_timer();

#print the sorted array
print("Sorted Array");
i = 0;
while(i < N):
    print(array[i]);
    i = i + 1;

#print the time taken to sort 
print "Time taken to sort: %(time)d " % {"time": stop - start};
