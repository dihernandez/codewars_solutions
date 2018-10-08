def goodVsEvil(good, evil):
    good_split = [int(i) for i in good.split(" ")]
    evil_split = [int(i) for i in evil.split(" ")]
    good_score = good_split[0] + good_split[1]*2 + good_split[2]*3 + good_split[3]*3 + good_split[4]*4 + good_split[5]*10
    evil_score = evil_split[0] + evil_split[1]*2 + evil_split[2]*2 + evil_split[3]*2 + evil_split[4]*3 + evil_split[5]*5 + evil_split[6]*10
    if evil_score == good_score:
        return "Battle Result: No victor on this battle field"
    else:
        return "Battle Result: Evil eradicates all trace of Good" if evil_score > good_score else "Battle Result: Good triumphs over Evil"
        
