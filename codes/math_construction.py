import matplotlib.pyplot as plt
import numpy as np

# Given points
A = np.array([2, 1])
B = np.array([1, -3])

# External ratio
n = 2/1

# Calculate point C using the external bisector formula
C = (B - n * A) / (1 - n)

# Plotting the points
plt.scatter(*A, label='A', color='red')
plt.scatter(*B, label='B', color='blue')
plt.scatter(*C, label='C', color='green')

# Plotting the line segments
plt.plot([A[0], B[0]], [A[1], B[1]], label='AB', linestyle='-', color='gray')
plt.plot([B[0], C[0]], [B[1], C[1]], label='BC', linestyle='--', color='purple')

# Adding labels and legend
plt.text(A[0], A[1], '  A', fontsize=12, color='red')
plt.text(B[0], B[1], '  B', fontsize=12, color='blue')
plt.text(C[0], C[1], '  C', fontsize=12, color='green')

plt.title('External Bisector')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.grid(color='gray', linestyle='--', linewidth=0.5)
plt.legend()

# Save the plot as a .png file
plt.savefig('external_bisector.png')

# Show the plot
plt.show()
