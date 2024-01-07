import sys
sys.path.insert(0,'/home/ramsai/MathComputing/codes/CoordGeo') #for path to ext
import numpy as np
import matplotlib.pyplot as plt

# Reading matrix a from .dat file
a = np.loadtxt('a.dat').reshape((2, 1))

# Reading matrix b from .dat file
b = np.loadtxt('b.dat').reshape((2, 1))

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

# Marking points P, Q, R on the lines with labels without using a for loop
plt.text(*P.flatten(), 'P', ha='right', va='bottom')
plt.text(*Q.flatten(), 'Q', ha='right', va='top')
plt.text(*R.flatten(), 'R', ha='left', va='top')

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

