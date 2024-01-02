import sys
sys.path.insert(0,'/home/ramsai/MathComputing/codes/CoordGeo') #for path to external scripts
import numpy as np
import matplotlib.pyplot as plt

# Taking user input for matrix a
a_values = input("value of a: ")
a = np.array([float(x) for x in a_values.split(',')]).reshape((2, 1))

# Taking user input for matrix b
b_values = input("value of b: ")
b = np.array([float(x) for x in b_values.split(',')]).reshape((2, 1))

# Specifying the value of k
k = 2

# Calculating P, Q, and R
P = 2*a + b
Q = a - 3*b
R = ((a - 3*b) - k*(2*a + b))/(1 - k)

# Extracting x and y coordinates for P, Q, and R
x_P, y_P = P.flatten()
x_Q, y_Q = Q.flatten()
x_R, y_R = R.flatten()

# Plotting in 2D plane with lines
plt.scatter(x_P, y_P, label='P', marker='o')
plt.scatter(x_Q, y_Q, label='Q', marker='o')
plt.scatter(x_R, y_R, label='R', marker='o')

# Connecting P to Q with a solid line
plt.plot([x_P, x_Q], [y_P, y_Q], label='PQ', linestyle='-')

# Connecting Q to R with a dotted line
plt.plot([x_Q, x_R], [y_Q, y_R], label='QR', linestyle='--')

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

