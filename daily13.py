# thanks sarah :)
class Node:
    def __init__(self) -> None:
        self.blue_neighbours = []
        self.neighbours = {1: [], 2: []}
        self.visited = False
        self.visited_2 = {1: False, 2: False}

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        blue_edges = 0

        nodes = [Node() for _ in range(n)]

        for type, i, j in edges:
            if type == 1:
                nodes[i - 1].neighbours[1].append(nodes[j - 1])
                nodes[j - 1].neighbours[1].append(nodes[i - 1])
            elif type == 2:
                nodes[i - 1].neighbours[2].append(nodes[j - 1])
                nodes[j - 1].neighbours[2].append(nodes[i - 1])
            else:
                nodes[i - 1].blue_neighbours.append(nodes[j - 1])
                nodes[j - 1].blue_neighbours.append(nodes[i - 1])

        for node in nodes:
            blue_edges += self.countNewBlueEdges(node)

        for i in [1, 2]:
            num = self.traverse(nodes[0], i)
            if num != n:
                return -1

        return len(edges) - (2 * n) + 2 + blue_edges


    def countNewBlueEdges(self, v: Node) -> int:
        if v.visited:
            return 0

        total = 0
        v.visited = True
        for neighbour in v.blue_neighbours:
            if not neighbour.visited:
                total += 1 + self.countNewBlueEdges(neighbour)

        return total


    def traverse(self, u: Node, type: int) -> int:
        if u.visited_2[type]:
            return 0

        total_nodes = 1
        u.visited_2[type] = True
        for v in set(u.blue_neighbours + u.neighbours[type]):
            total_nodes += self.traverse(v, type)

        return total_nodes

