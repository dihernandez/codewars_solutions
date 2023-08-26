def meeting(rooms, need):
    filled = 0
    room_on = 0
    take = []
    to_take_with_negatives = []
    new_need = need
    if need > 8:
        new_need = 8
    if new_need == 0:
        return "Game On"
    while len(take) < len(rooms) and filled < new_need:    
        #print(rooms, room_on, rooms[room_on], need)
        print("need is", new_need)
        print(rooms)
        taken = rooms[room_on][1] -  len(rooms[room_on][0])
        room_on += 1
        to_take_with_negatives.append(taken)
        if filled + taken > new_need:
            taken = new_need - filled
        if taken >= 0:
            take.append(taken)
        else:
            take.append(0)
            print("appended 0")
        filled = sum(take)
        print("taken is", taken, "to_take with negatives is ", to_take_with_negatives, "take is ", take, "filled is", filled)
    if filled == new_need:
        return take
    else:
        print(take)
        return "Not enough!"