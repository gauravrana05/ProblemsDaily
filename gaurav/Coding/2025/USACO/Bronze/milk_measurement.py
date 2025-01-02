NAMES = ['Bessie', 'Elsie', 'Mildred']
START_AMT = 7

with open("measurement.in") as read:
  updated_num = int(read.readline())
  updates = []
  for _ in range(updated_num):
    day, cow, change = read.readline.split()
    updates.append((int(day), cow, int(change)))

updates.sort()

outputs = {c : START_AMT for c in NAMES}
display = NAMES.copy()

display_changes = 0

for u in updates:
  outputs[u[1]]+= u[2]
  max_output = max(outputs.values())
  new_display = [name for name, o in outputs.items() if o == max_output ]
  display_changes += display != new_display
  display = new_display
  
  
with open("measurement.out", 'w') as write:
  print(display_changes)
  
  