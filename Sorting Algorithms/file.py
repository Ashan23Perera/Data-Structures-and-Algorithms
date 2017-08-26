#Some random number write to Data.txt file
#When Insertion,Bubble,Selection sort codes run 
#Inputs send by reading Data.txt file

# Open a file 
import random
fo = open("Data.txt", "wb")

#Enter a amount of numbers
N = input();
for i in range(0,N):
      w = random.randrange(0,1000,2); 
      fo.write(str(w));
      fo.write(",");
 
# Close opend file 
fo.close() 
