from pprint import pprint 

class FD:  
  def __init__(self, fds=None):
      # Initialize the list of FDs and theself.type dictionary.
      self.FDs = fds if fds is not None else []
      self.type = self._initialize_type()
      self.attributes = self._update_attributes()


  def _initialize_type(self):
      """Helper method to initialize theself.type dictionary for FDs."""
      return {(lhs, rhs): 'G' for lhs, rhs in self.FDs}

  def _update_attributes(self):
    """Helper method to update the class-level 'attributes' set."""
    attributes = set()
    for lhs, rhs in self.FDs:
        attributes.update(lhs)  # Add all attributes from LHS
        attributes.update(rhs)  # Add all attributes from RHS
    return attributes

  def add_fd(self, lhs, rhs):
      """
      Add a functional dependency (lhs -> rhs) to the FDs.
      """
      new_fd = (frozenset([lhs]), frozenset([rhs]))
      if new_fd not in self.FDs:
          self.FDs.append(new_fd)
          self.type[new_fd] = 'G'  # Initializing as a generic FD (G).
          print(f"Added FD: {lhs} -> {rhs}")
      else:
          print(f"FD {lhs} -> {rhs} already exists.")

  def remove_fd(self, lhs, rhs):
      """
      Remove a functional dependency (lhs -> rhs) from the FDs.
      """
      fd_to_remove = (frozenset([lhs]), frozenset([rhs]))
      if fd_to_remove in self.FDs:
          self.FDs.remove(fd_to_remove)
          del self.tldfkjlsqqwnype[fd_to_remove]
          print(f"Removed FD: {lhs} -> {rhs}")
      else:
          print(f"FD {lhs} -> {rhs} not found.")

  def _compute_fd_closure(self):
      """
      Compute the closure of all functional dependencies (F+).
      Returns the closure and updates theself.type.
      """
      closure = set(self.FDs)
      changed = True

      while changed:
        changed = False 
        
        new_closure = set(closure)
        
        for (lhs, rhs) in closure:
          for (lhs2, _) in closure:
            argumented_fd = (lhs | lhs2, rhs | lhs2)
            if argumented_fd[0] != argumented_fd[1] and argumented_fd not in new_closure:
              new_closure.add(argumented_fd)
              self.type[argumented_fd] = 'A'
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
                    self.type[new_fd] = 'T'
                  
                    changed = True

        for (lhs, rhs) in closure:
            # Union: If X → Y and X → Z, then X → YZ
            for (lhs2, rhs2) in closure:
                if lhs == lhs2:
                    new_fd = (lhs, rhs | rhs2)
                    if new_fd[0] != new_fd[1] and new_fd not in new_closure:
                        new_closure.add(new_fd)
                        self.type[new_fd] = 'R'
                        changed = True

        for (lhs, rhs) in closure:
            # Decomposition: If X → YZ, then X → Y and X → Z
            for attr in rhs:
                new_fd = (lhs, frozenset([attr]))
                if new_fd[0] != new_fd[1] and  new_fd not in new_closure:
                    new_closure.add(new_fd)
                    self.type[new_fd] = 'R'
                    changed = True

        closure = new_closure  # Update the closure

      return closure

  def compute_attributes_closure(self, attributes):
      """
      Compute the closure of a given set of attributes with respect to self.FDs.
      """
      closure = set(attributes)
      changed = True

      while changed:
          changed = False
          for lhs, rhs in self.FDs:
              if lhs.issubset(closure) and not rhs.issubset(closure):
                  closure.update(rhs)
                  changed = True

      return closure

  def print_closure_set(self):
      """
      Prints the closure (F+) for all functional dependencies.
      """
      closure = self._compute_fd_closure()
      print(f"{'LHS':<20} {'RHS':<20} {'Type'}")
      print(f"Closure (F+): {len(closure)}")

      # Sorting the closure by 'type', LHS length, and RHS length
      for lhs, rhs in sorted(closure, key=lambda x: (self.type.get((x[0], x[1]), 'Unknown'), len(x[0]), len(x[1]))):
          lhs_str = ','.join(sorted(lhs))  # Sort LHS attributes for consistency
          rhs_str = ','.join(sorted(rhs))  # Sort RHS attributes for consistency
          print(f"{lhs_str:<20} {rhs_str:<60} {self.type.get((lhs, rhs), 'Unknown')}")

  def print_attribute_closure_set(self, attributes):
      """
      Prints the closure of a given set of attributes.
      """
      closure = self.compute_attributes_closure(attributes)
      print(f"The closure of {', '.join(sorted(attributes))} is: {', '.join(sorted(closure))}")

  def calculate_max_rhs_elements(self):
    """
    Calculates the maximum RHS elements for each LHS in the closure.
    
    Returns:
        dict: A dictionary where the key is the LHS and the value is the RHS 
              with the maximum number of elements.
    """
    max_rhs_map = {}
    closure = self._compute_fd_closure()
    
    for lhs, rhs in closure:
        # Find the maximum rhs size for each lhs
        if lhs not in max_rhs_map or len(rhs) > len(max_rhs_map[lhs]):
            max_rhs_map[lhs] = rhs

    return max_rhs_map
    
  def display_max_rhs_elements(self):
    """
    Displays the maximum RHS elements for each LHS -> RHS.
    """
    max_rhs_map = self.calculate_max_rhs_elements()

    print(f"\n{'LHS':<20} {'Max RHS':<60}")
    for lhs, rhs in sorted(max_rhs_map.items(), key=lambda x: len(x[0])):  # Sorting by LHS
        lhs_str = ','.join(sorted(lhs))  # Sort LHS attributes for consistency
        rhs_str = ','.join(sorted(rhs))  # Sort RHS attributes for consistency
        print(f"{lhs_str:<20} {rhs_str:<60}")

            
  def decompose_bcnf(self):
    """
    Decomposes the FDs into relations based on BCNF using the given pseudocode.
    Returns a list of relations in BCNF.
    """
    # Step 1: Initialize S with all attributes
    S = [frozenset(self.attributes)]  # Start with all attributes in the initial relation
    relation_fds = {}
    # Step 2: Iterate until there is no relation violating BCNF
    for relation in list(S):  # Loop over a copy of S since S may change during the loop
        # Step 3: Check if the relation violates BCNF
      lhs, rhs = self.find_bcnf_violation(relation)
        
      if lhs:  # If a BCNF violation is found
          # Step 4: Add the violating FD (LHS ∪ RHS) as a new relation to S
          S.append(frozenset(lhs.union(rhs)))
          
          # Step 5: Update the current relation by removing RHS (since it is now decomposed)
          new_relation = relation - ( rhs - lhs)  
          if new_relation and new_relation not in S:  # Avoid adding empty relations or duplicates
              S.append(new_relation)
              S.remove(relation)
    
    for relation in list(S):
        relation_fds[relation] = self.get_relation_fds(relation)

    return (S,relation_fds)

  def find_bcnf_violation(self, relation):
      """
      Finds a functional dependency X -> Y that violates BCNF in the given relation.
      Returns the violating LHS and RHS, or (None, None) if no violation is found.
      """
      closure = self.calculate_max_rhs_elements()
      for lhs, rhs in closure.items():
          # Check if the FD holds in the current relation and violates BCNF
          if lhs.issubset(relation) and not self.is_superkey(lhs):
            return lhs, rhs  # Found a violation: return LHS and RHS
      return None, None  # No violation found
  
  def is_superkey(self, lhs):
    closure = self.compute_attributes_closure(lhs)
    return self.attributes.issubset(closure)
    
  def get_relation_fds(self, relation):
    """
    Extracts the functional dependencies that hold in the given relation.
    """
    relation_fds = []
    for lhs, rhs in self.FDs:
        if lhs.issubset(relation) and rhs.issubset(relation):
            relation_fds.append((lhs, rhs))
    return relation_fds
  
  def is_dependency_preserved(self, decomposed_relations):
    """
    Check if the decomposition preserves all functional dependencies.

    Args:
        decomposed_relations (list of frozenset): Decomposed relations as a list of frozensets of attributes.

    Returns:
        bool: True if all functional dependencies are preserved, False otherwise.
    """
    # Step 1: Compute F+ for the entire relation
    full_closure = self._compute_fd_closure()

    # Step 2: Compute closure for each decomposed relation
    decomposed_closure = set()
    for relation in decomposed_relations:
        # Extract FDs relevant to the current relation
        relevant_fds = self.get_relation_fds(relation)

        # Create a temporary FD object with relevant FDs
        temp_fd_obj = FD(relevant_fds)

        # Add the closure of the relation to the decomposed closure
        decomposed_closure.update(temp_fd_obj._compute_fd_closure())
        
        temp_fd_obj = FD(decomposed_closure)
        decomposed_closure.update(temp_fd_obj._compute_fd_closure())

    # Step 3: Compare the union of decomposed closures with F+
    return full_closure == decomposed_closure

  def is_single_dependency_preserved(self, lhs, rhs, decomposed_relations):
    result = set(lhs)
    
    changed = True
    
    for relation in decomposed_relations:
      while changed:
        changed = False
        
        new_rel = result.intersection(relation)
        
        temp = self.compute_attributes_closure(new_rel)
        temp = temp.intersection(relation)
        
        if temp:
          result1 = result.union(temp)
          if result1 != result:
            changed = True
            result = result1
      print(decomposed_relations,relation,result, changed)
    
    return set(rhs).issubset(result)
      