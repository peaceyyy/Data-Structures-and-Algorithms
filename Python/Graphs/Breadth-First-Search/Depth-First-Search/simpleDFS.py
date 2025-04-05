class Graph:
    def __init__(self, edges):
        self.edges = edges
        self.edges_dict = {}

        for loc, des in edges:
            if loc in self.edges_dict:
                self.edges_dict[loc].append(des)
            else:
                self.edges_dict[loc] = [des]

    def get_pathsDFS (self, start, end, path=[]):
        
       
            

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
 