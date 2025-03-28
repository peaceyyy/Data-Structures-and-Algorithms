class Graph:
    def __init__(self, edges):
        self.edges = edges
        self.edges_dict = {}

        for loc, des in edges:
            if loc in self.edges_dict:
                self.edges_dict[loc].append(des)
            else:
                self.edges_dict[loc] = [des]

    def get_paths(self, start, end, path=[]):
        path = path + [start]

        if start == end:
            return [path]   

        if start not in self.edges_dict:
            return []

        paths = []
        for node in self.edges_dict[start]:
            if node not in path:
                new_paths = self.get_paths(node, end, path)
                for p in new_paths:
                    paths.append(p)

        return paths
            

if __name__ == '__main__':

    routes = [
        ("Mumbai","Pune"),
        ("Mumbai", "Surat"),
        ("Surat", "Bangaluru"),
        ("Pune","Hyderabad"),
        ("Pune","Mysuru"),
        ("Hyderabad","Bangaluru"),
        ("Hyderabad", "Chennai"),
        ("Mysuru", "Bangaluru"),
        ("Chennai", "Bangaluru")
    ]

    routes = [
        ("Mumbai", "Paris"),
        ("Mumbai", "Dubai"),
        ("Paris", "Dubai"),
        ("Paris", "New York"),
        ("Dubai", "New York"),
        ("New York", "Toronto"),
    ]

    route_graph = Graph(routes)
    start = "Mumbai"
    end = "New York"

    print(f"All paths between {start} and {end}:  {route_graph.get_paths(start,end)}")
 