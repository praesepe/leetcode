# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        
        self.nodes = {}
        self.dfs(node)
        
        return self.nodes[node.label]
        
    def dfs(self, node):
        if node.label in self.nodes:
            return
        
        self.nodes[node.label] = UndirectedGraphNode(node.label)
        for neighbor in node.neighbors:
            if neighbor.label not in self.nodes:
                self.dfs(neighbor)
            self.nodes[node.label].neighbors.append(self.nodes[neighbor.label])
            
        return
