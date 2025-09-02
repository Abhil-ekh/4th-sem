x, y = 4, 3     
goal_j1, goal_j2 = 2, 0
j1, j2 = 0, 0   

print("----- Water Jug Problem -----")
print(f"Initial state = (0, 0)")
print(f"Capacities = ({x}, {y})")
print(f"Goal state = ({goal_j1}, {goal_j2})\n")

print("Available actions:")
print("1: Fill jug 1")
print("2: Fill jug 2")
print("3: Empty jug 1")
print("4: Empty jug 2")
print("5: Pour from jug 1 to jug 2")
print("6: Pour from jug 2 to jug 1")
print("7: Pour all from jug 1 to jug 2")
print("8: Pour all from jug 2 to jug 1\n")

steps = []

steps.append(1)  
steps.append(5) 
steps.append(4) 
steps.append(5)  
steps.append(1) 
steps.append(5)  

for i, r in enumerate(steps, 1):
    print(f"Step {i}: Applying rule {r}")

    match r:
        case 1:  
            j1 = x
        case 2:  
            j2 = y
        case 3:  
            j1 = 0
        case 4:  
            j2 = 0
        case 5:  
            t = min(j1, y - j2)
            j1 -= t
            j2 += t
        case 6:  
            t = min(j2, x - j1)
            j1 += t
            j2 -= t
        case 7:  
            j2 = min(j1 + j2, y)
            j1 = max(j1 + j2 - y, 0)
        case 8:  
            j1 = min(j1 + j2, x)
            j2 = max(j1 + j2 - x, 0)

    print(f"   Current state: ({j1}, {j2})")

print(f"Goal state reached: ({goal_j1}, {goal_j2})")
