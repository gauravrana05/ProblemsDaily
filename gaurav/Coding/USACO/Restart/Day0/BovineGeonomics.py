from itertools import combinations

def can_explain_spottiness(spotted, plain, pos):
    spotted_set = set()
    plain_set = set()
    
    for s in spotted:
        triplet = (s[pos[0]], s[pos[1]], s[pos[2]])
        spotted_set.add(triplet)
    
    for p in plain:
        triplet = (p[pos[0]], p[pos[1]], p[pos[2]])
        if triplet in spotted_set:
            return False
    
    return True

def count_explaining_sets(N, M, spotted, plain):
    valid_sets = 0
    
    # Iterate over all combinations of 3 positions from M possible positions
    for pos in combinations(range(M), 3):
        if can_explain_spottiness(spotted, plain, pos):
            valid_sets += 1
    
    return valid_sets

def main():
    # Read input
    with open("cownomics.in") as file:
        data = file.read().splitlines()
    
    N, M = map(int, data[0].split())
    spotted = [data[i + 1] for i in range(N)]
    plain = [data[N + 1 + i] for i in range(N)]
    
    result = count_explaining_sets(N, M, spotted, plain)
    
    # Write output
    with open("cownomics.out", "w") as file:
        file.write(f"{result}\n")

if __name__ == "__main__":
    main()
