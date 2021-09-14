def tally_votes(voters):
    election_results = {}
    if len(voters) < 2:
        return voters
    else:
        for votes in voters:
            first_place = votes[0]
            if first_place in election_results.keys():
                election_results[first_place] += 1
            else:
                election_results[first_place] = 1
    return election_results

def all_equal(election_results):
    value = list(election_results.values())[0]
    for result in election_results:
        if election_results[result] != value:
            return False
    return True

def remove_least(election_results, votes):
    loosing_first_key = min(election_results, key=election_results.get)
    loosing_first_value = election_results[loosing_first_key]
    new_ballot = []
    for vote in votes:
        new_vote = []
        for candidate in vote:
            if candidate in election_results.keys():
                if election_results[candidate] != loosing_first_value:
                    new_vote.append(candidate)
        if len(new_vote) > 0:
            new_ballot.append(new_vote)
    return new_ballot

def runoff(voters):
    max_candidate = ""
    if len(voters) < 2:
        return votes[0]
    else:
        while len(voters) > 1:
            election_results = tally_votes(voters)
            max_candidate = max(election_results, key=election_results.get)
            voters = remove_least(election_results, voters)
            total_votes = sum(election_results.values())
            if election_results[max_candidate] > total_votes//2:
                return max_candidate 
            if all_equal(election_results):
                return None
    return max_candidate
    