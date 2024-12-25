def compute_closure(F, type):
  closure = set(F)
  changed = True
  
  while changed:
    changed = False 
    
    new_closure = set(closure)
    
    for (lhs, rhs) in closure:
      for (lhs2, _) in closure:
        argumented_fd = (lhs | lhs2, rhs | lhs2)
        if argumented_fd[0] != argumented_fd[1] and argumented_fd not in new_closure:
          new_closure.add(argumented_fd)
          type[argumented_fd] = 'A'
          changed = True 
    
    for (lhs1, rhs1) in closure:
      for (lhs2, rhs2) in closure:  
        # Check if there's any overlap between rhs1 and lhs2
        common_attrs = rhs1.intersection(set(lhs2))
        if common_attrs:
            # For the new FD, we need:
            # - LHS: All attributes from lhs1 plus any attributes from lhs2 
            #   that aren't derived from rhs1
            # - RHS: All attributes from rhs2       
            # Calculate remaining attributes in lhs2 that aren't in rhs1
            remaining_lhs2 = set(lhs2) - rhs1   
            # New LHS combines lhs1 with remaining attributes from lhs2
            new_lhs = frozenset(set(lhs1).union(remaining_lhs2))
            new_rhs = frozenset(rhs2)
            new_fd = (new_lhs, new_rhs)
            if new_fd not in closure and new_lhs != new_rhs:
                new_closure.add(new_fd)
                type[new_fd] = 'T'
                changed = True

    for (lhs, rhs) in closure:
        # Union: If X → Y and X → Z, then X → YZ
        for (lhs2, rhs2) in closure:
            if lhs == lhs2:
                new_fd = (lhs, rhs | rhs2)
                if new_fd[0] != new_fd[1] and new_fd not in new_closure:
                    new_closure.add(new_fd)
                    type[new_fd] = 'R'
                    changed = True

    for (lhs, rhs) in closure:
        # Decomposition: If X → YZ, then X → Y and X → Z
        for attr in rhs:
            new_fd = (lhs, frozenset([attr]))
            if new_fd[0] != new_fd[1] and  new_fd not in new_closure:
                new_closure.add(new_fd)
                type[new_fd] = 'R'
                changed = True

    closure = new_closure  # Update the closure

  return closure

def compute_attributes_closure(attributes, F):
    """
    Compute the closure of a given set of attributes with respect to a set of functional dependencies (F).

    :param attributes: The set of attributes for which we need to compute the closure.
    :param F: The set of functional dependencies (lhs -> rhs) represented as tuples of frozensets.
    :return: The closure of the given set of attributes.
    """
    # Start with the initial set of attributes in the closure
    closure = set(attributes)

    # Flag to track if the closure changed during the iteration
    changed = True

    while changed:
        changed = False  # Reset the flag
        
        # Iterate over the functional dependencies (lhs -> rhs)
        for lhs, rhs in F:
            # If the LHS is a subset of the current closure, add the RHS to the closure
            if lhs.issubset(closure):
                if not rhs.issubset(closure):  # Check if RHS needs to be added
                    closure.update(rhs)  # Add RHS to closure
                    changed = True  # Mark as changed
    
    return closure
