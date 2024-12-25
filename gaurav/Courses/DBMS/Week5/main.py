from pprint import pprint 
from FD import FD
# Example: Compute F+ for a given set of FDs
def create_fd(lhs, rhs):
    return (frozenset(lhs), frozenset(rhs))

def create_set(lst):
    return frozenset(lst)



if __name__ == "__main__":
    
    '''
    1. To test if A is a superkey, we compute a+, and check if A+ contains all the attributes of R.
    2. To check if a functional dependency A -> B holds (or, in other words, is in F+), just check if B is subset of A+
    3. For each C subset of R, we find the closure C+, and for each S subset of C+ we output a functional depenency X => S
    
    '''
 
    F = [
        create_fd('A', 'B'),  # A → B
        create_fd('A', 'C'),  # A → C
        create_fd(['C','G'], ['H']),  # C, G → H
        create_fd('C,G', 'I'),  # C, G → I
        create_fd('H', 'H'),  # H → H (Self loop)
    ]
    
    F = [
        create_fd(['A'],['B','C','D']),
        create_fd(['A'],['E','F']),
        create_fd(['B','C'],['A','D']),
        create_fd(['B','C'],['E']),
        create_fd(['B','C'],['F']),
        create_fd(['B'],['F']),
        create_fd(['D'],['E']),
    ]
    
    r1 = create_set({'A', 'B', 'C', 'D'})
    r2 = create_set({'B', 'F'})
    r3 = create_set({'D', 'E'})
    graph = FD(F)
    # print(graph.is_dependency_preserved([r1, r2, r3]))
    print(graph.is_single_dependency_preserved(['D'],['E'],[r1, r2, r3]))
    
    
    
    
    Dept = [
        create_fd(['ID'], ['name']),
        create_fd(['ID'], ['salary']),
        create_fd(['ID'], ['dept_name']),
        create_fd(['dept_name'], ['building']),
        create_fd(['dept_name'], ['budget'])
    ]
    # graph = FD(Dept)
    # frozenset({'budget', 'dept_name', 'building'})
    
    # S, relation_fds = graph.decompose_bcnf()
    # print(S)
    # print(graph.is_dependency_preserved(S))
    
    

    
        
    
