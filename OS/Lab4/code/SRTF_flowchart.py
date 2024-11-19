import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

# Create a new figure
fig, ax = plt.subplots(figsize=(10, 6))
ax.axis('off')  # Turn off the axis

# Draw the decision diamond for "Có tiến trình nào sẵn sàng?"
diamond = mpatches.Polygon(((2, 4), (3, 5), (4, 4), (3, 3)), closed=True, edgecolor="black", facecolor="lightgray")
ax.add_patch(diamond)
ax.text(3, 4, "Có tiến trình nào sẵn sàng?", ha='center', va='center', fontsize=12)

# Draw the decision paths for Yes and No
# "No" path
ax.text(1.5, 2, "No", fontsize=12)
ax.arrow(3, 3, -1, -1, head_width=0.1, head_length=0.2, fc="black", ec="black")

# "Yes" path
ax.text(4.5, 4, "Yes", fontsize=12)
ax.arrow(4, 4, 1, 0, head_width=0.1, head_length=0.2, fc="black", ec="black")

# Draw "Increase currentTime" box for No path
no_box = mpatches.FancyBboxPatch((0.5, 0.5), 1.5, 1, boxstyle="round,pad=0.1", edgecolor="black", facecolor="lightgray")
ax.add_patch(no_box)
ax.text(1.25, 1, "Tăng currentTime\nlên 1 đơn vị", ha='center', va='center', fontsize=10)

# Draw "Chọn tiến trình có thời gian còn lại ngắn nhất" box for Yes path
yes_box = mpatches.FancyBboxPatch((5, 3.5), 2.5, 1, boxstyle="round,pad=0.1", edgecolor="black", facecolor="lightgray")
ax.add_patch(yes_box)
ax.text(6.25, 4, "Chọn tiến trình có\nRemaining Burst Time\nngắn nhất", ha='center', va='center', fontsize=10)

plt.show()
plt.savefig("SRTF_flowchart.png")
