from collections import deque

class SocialNetwork:
    def __init__(self):
        # Using a dictionary to represent the graph, where keys are people and values are lists of their friends
        self.graph = {}

    def add_person(self, person):
        """Add a new person to the network."""
        if person not in self.graph:
            self.graph[person] = []

    def add_friendship(self, person1, person2):
        """Add a bidirectional friendship between two people."""
        self.add_person(person1)
        self.add_person(person2)
        self.graph[person1].append(person2)
        self.graph[person2].append(person1)

    def bfs_shortest_path(self, start, goal):
        """Find the shortest path between two people using BFS."""
        # Queue stores (current_person, path_so_far)
        queue = deque([(start, [start])])
        visited = set()  # To track visited people

        while queue:
            current_person, path_so_far = queue.popleft()

            if current_person == goal:
                return path_so_far  # Return the path if goal is found

            # Mark the person as visited
            visited.add(current_person)

            # Explore all friends of the current person
            for friend in self.graph[current_person]:
                if friend not in visited:
                    # Add the friend to the queue with the updated path
                    queue.append((friend, path_so_far + [friend]))

        return None  # Return None if no path exists

# Example usage
if __name__ == "__main__":
    network = SocialNetwork()
    network.add_friendship("Alice", "Bob")
    network.add_friendship("Bob", "Charlie")
    network.add_friendship("Alice", "David")
    network.add_friendship("David", "Eve")
    network.add_friendship("Eve", "Charlie")

    # Find the shortest path between Alice and Charlie
    path = network.bfs_shortest_path("Alice", "Charlie")
    if path:
        print("Shortest path:", " -> ".join(path))
    else:
        print("No path found.")
