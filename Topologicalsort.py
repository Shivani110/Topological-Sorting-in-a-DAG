from collections import defaultdict
class TGraph:
    def __init__(self, x):
        self.g = defaultdict(list)
        self.nv = x

    def edge_add(self, m, x):
        self.g[m].append(x)

    def Topological_sortfn(self, x, Visit, s):
        Visit[x] = True
        for a in self.g[x]:
            if Visit[a] == False:
                self.Topological_sortfn(a, Visit, s)
        s.append(x)

    def Topological_sort(self):
        Visit = [False]*self.nv
        s = []
        for a in range(self.nv):
            if Visit[a] == False:
                self.Topological_sortfn(a, Visit, s)
                print(s[::-1])

obj = TGraph(4)
obj.edge_add(4, 0)
obj.edge_add(4, 3)
obj.edge_add(3, 1)
obj.edge_add(2, 1)

print("Topological Sort in a DAG:")
obj.Topological_sort()

