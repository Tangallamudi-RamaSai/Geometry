import sys
sys.path.insert(0,'/home/ramsai/MathComputing/codes/CoordGeo') #for path to external scripts
import numpy as np
import matplotlib.pyplot as plt

# Function to read matrix from file
def read_file(filename):
    with open(filename, 'r') as file:
        values = file.readline().strip().split(',')
    return np.array([float(x) for x in values])

# Reading matrices a and b from .dat files
a = read_file('a.dat').reshape((2, 1))
b = read_file('b.dat').reshape((2, 1))

# Specifying the value of k
k = 2

# Calculating P, Q, and R
P = 2 * a + b
Q = a - 3 * b
R = ((a - 3 * b) - k * (2 * a + b)) / (1 - k)

# Plotting in 2D plane with lines
plt.scatter(*P, label='P', marker='o')
plt.scatter(*Q, label='Q', marker='o')
plt.scatter(*R, label='R', marker='o')

# Connecting P to Q with a solid line
plt.plot([P[0, 0], Q[0, 0]], [P[1, 0], Q[1, 0]], label='PQ', linestyle='-')

# Connecting Q to R with a dotted line
plt.plot([Q[0, 0], R[0, 0]], [Q[1, 0], R[1, 0]], label='QR', linestyle='--')

# Marking points P, Q, R on the lines with labels
for point, label in zip([P, Q, R], ['P', 'Q', 'R']):
    plt.text(*point, label, ha='right' if label == 'P' else 'left', va='bottom' if label == 'P' else 'top')

# Print values for P, Q, R
print("P:", P.flatten())
print("Q:", Q.flatten())
print("R:", R.flatten())

plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.legend()

# Save the image as a PNG file
plt.savefig('external-bisector.png')

# Show the plot
plt.show()

