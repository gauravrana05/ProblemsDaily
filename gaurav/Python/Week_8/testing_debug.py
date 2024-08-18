# test_debugger.py
from debugger import debug

# Example variables
a_var = 42
a_dict = {"name": "Alice", "age": 30, "details": {"hobbies": ["reading", "biking"], "job": "Engineer"}}
a_list = [1, 2, ["nested", "list"], {"nested": "dict"}]
a_tuple = (1, 2, {"key": "value"}, [3, 4])

# Using the debug function
debug("a_dictionary", a_tuple)
