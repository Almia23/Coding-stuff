'''
def solution(forth):
    # Implement your solution here
    print(forth)
    l = {"N":0, "E":0, "W":0}
    count = 0
    furthest = 0
    furtheste = 0
    furthestw = 0
    for i in forth:
        if i=="E":
            count+=1
        elif i=="W":
            count-=1
        if (count>furthest and furthest>=0):
            furthest = count
            furtheste = count
        elif (count<furthest and furthest<=0) or count<0:
            furthestw = count
            furthest = count
        print(count, furthest, furtheste, furthestw)
        l[i]+=1
    #print(count, furthest, furtheste, furthestw)
    ans = ""

    if count>0 and furthestw<furtheste:
        for i in range(count+furthestw+1):
            ans += "W"
    for i in range(l["N"]):
        ans+="S"
    for i in range(furthestw+1):
        ans+="E"
    print(ans)
'''
def solution(forth):
    # Initialize position and the directions
    x, y = 0, 0  # Starting point
    visited = set([(x, y)])  # Keep track of visited points

    # Dictionary to move in the respective directions
    move = {'N': (0, 1), 'E': (1, 0), 'W': (-1, 0)}
    
    # Traverse the 'forth' path
    for direction in forth:
        dx, dy = move[direction]
        x += dx
        y += dy
        visited.add((x, y))

    # Start constructing the shortest return path
    return_path = []
    current_position = (x, y)

    # Dictionary for opposite directions
    opposites = {'N': 'S', 'E': 'W', 'W': 'E'}
    reverse_move = {'N': (0, -1), 'E': (-1, 0), 'W': (1, 0)}

    while current_position != (0, 0):
        cx, cy = current_position
        if (cx, cy - 1) in visited:
            return_path.append('S')
            current_position = (cx, cy - 1)
        elif (cx - 1, cy) in visited:
            return_path.append('W')
            current_position = (cx - 1, cy)
        elif (cx + 1, cy) in visited:
            return_path.append('E')
            current_position = (cx + 1, cy)
        visited.remove(current_position)

    # Return the return path in reverse order
    return ''.join(return_path[::-1])

# Example usage:
forth = "NEENWN"
print(solution(forth))  # Output: should be the shortest path back without reusing any path