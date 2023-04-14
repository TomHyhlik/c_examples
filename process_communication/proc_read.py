import os

fifo_file = '/tmp/myfifo'

# Open the FIFO file for reading
fifo = open(fifo_file, 'r')

# Read data from the FIFO file
data = fifo.read()

# Print the data
print(data)

# Close the FIFO file
fifo.close()