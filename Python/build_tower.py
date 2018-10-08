import math

def tower_builder(n_floors):
    tower = []
    for f in range(n_floors):
        floor = (' '*(n_floors -(f + 1))) + ('*' * (2*f + 1)) + (' '*(n_floors -(f + 1)))
        tower.append(floor)
    return tower


built_tower = tower_builder(5)
for t in built_tower:
	print(t)