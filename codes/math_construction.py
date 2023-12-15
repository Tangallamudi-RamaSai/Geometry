import matplotlib.pyplot as plt
import numpy as np

# Define vectors P, Q, and R
P = np.array([2, 1])
Q = np.array([1, -3])
R = np.array([3, 5])

# Create a plot
fig, ax = plt.subplots()

# Plot vectors as arrows
ax.quiver(0, 0, P[0], P[1], angles='xy', scale_units='xy', scale=1, color='r', label='P')
ax.quiver(0, 0, Q[0], Q[1], angles='xy', scale_units='xy', scale=1, color='g', label='Q')
ax.quiver(0, 0, R[0], R[1], angles='xy', scale_units='xy', scale=1, color='b', label='R')

# Plot lines connecting the points
ax.plot([P[0], Q[0]], [P[1], Q[1]], 'k--', label='PQ')
ax.plot([Q[0], R[0]], [Q[1], R[1]], 'k--', label='QR')
ax.plot([R[0], P[0]], [R[1], P[1]], 'k', label='RP')

# Plot the origin as O
ax.text(0, 0, 'O', ha='right', va='top')

# Annotate points P, Q, and R
ax.text(P[0], P[1], 'P', ha='right', va='bottom')
ax.text(Q[0], Q[1], 'Q', ha='right', va='bottom')
ax.text(R[0], R[1], 'R', ha='right', va='bottom')

# Set plot limits based on vector magnitudes
lim = max(np.linalg.norm(P), np.linalg.norm(Q), np.linalg.norm(R))
ax.set_xlim([-lim, lim])
ax.set_ylim([-lim, lim])

# Set aspect ratio to be equal
ax.set_aspect('equal')

# Add grid
ax.grid(True)

# Add labels and legend
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.legend()

# Save the plot as a PNG file
plt.savefig('math_construction.png', bbox_inches='tight')

# Show the plot
plt.show()
