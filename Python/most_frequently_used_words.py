import re
from string import punctuation

def is_valid_character(character):
    return character.isalpha() or character == "'" or character == " "

def is_not_just_ticks(word):
    no_ticks_word = []
    for character in word:
        if character != "'":
            no_ticks_word.append(character)
    return len(no_ticks_word) != 0 

def top_3_words(text):
    word_occurences = {}
    clean_text = []
    #r = re.compile(r'[^\P{P}\']+'.format("'" + re.escape(punctuation)))
    #words_list = re.split(ur"[^\P{P}']+", text)
    remove = punctuation
    remove = remove.replace("'", "")
    remove += " "
    r = re.compile(re.escape(remove))
    #r = re.compile(remove)
    #words_list = r.split(text)
    words_list = r.split(text)
    words_list_split_by_space = []
    for word in words_list:
        words_list_split_by_space.extend(word.split())
    #print("words list is \n ", words_list)
    for word in words_list_split_by_space:
        clean_word = ""
        for character in word:
            if is_valid_character(character):
                clean_word += character.lower()
        lower_text = clean_word.lower()
        clean_text.append(clean_word)
    no_ticks_words_list = []
    for word in clean_text:
        if is_not_just_ticks(word):
            no_ticks_words_list.append(word)
    #print(no_ticks_words_list)
    no_empty_words_list = filter(lambda x: x != '', no_ticks_words_list)
    for word in no_empty_words_list:
        if word in word_occurences.keys():
            word_occurences[word] += 1
        else:
            word_occurences[word] = 1
    #print(word_occurences)
    sorted_words = sorted(word_occurences.items(), key= lambda item: item[1], reverse = True)
    print(sorted_words)
    if len(sorted_words) < 3:
        if len(sorted_words) == 0:
            return []
        else:
            return [word[0] for word in sorted_words]
    else:
        return [word[0] for word in sorted_words[0:3]]

#TODO(diher) exlcude ' from punctuation' 
print(top_3_words("fMKXQmXWrY./,!fMKXQmXWrY_CeBIKnRw?!/TyXINFt._,CeBIKnRw;.fMKXQmXWrY,;FnM?_ ;,TyXINFt-_fMKXQmXWrY;-;-CeBIKnRw?-cMbbyvQv-/-,dQYt:/;/;dQYt;dQYt,/!/fMKXQmXWrY_ FnM-;_-!cMbbyvQv_;dQYt;! ?TyXINFt?.-_TyXINFt,,cMbbyvQv,._CeBIKnRw_-;dQYt!,TyXINFt.??_dQYt,!?;;TyXINFt_?;;;TyXINFt,?fMKXQmXWrY/ /CeBIKnRw!.fMKXQmXWrY cMbbyvQv,.?TyXINFt?:.CeBIKnRw :.:/fMKXQmXWrY,. .TyXINFt-,,_cMbbyvQv,.CeBIKnRw;!;??TyXINFt.,:fMKXQmXWrY?_.fMKXQmXWrY__dQYt-,CeBIKnRw._??!dQYt/_?!TyXINFt;-TyXINFt;? !.fMKXQmXWrY/!?_.TyXINFt:_.TyXINFt ,._FnM_.!,fMKXQmXWrY/.CeBIKnRw;dQYt_-,!TyXINFt_?cMbbyvQv!,;--TyXINFt;?dQYt dQYt;TyXINFt/_?!:cMbbyvQv ??.;TyXINFt_fMKXQmXWrY?;-TyXINFt!;/ cMbbyvQv-/fMKXQmXWrY;:,/-TyXINFt! TyXINFt /!_TyXINFt; ,;CeBIKnRw:;TyXINFt-::?TyXINFt;/._.TyXINFt,cMbbyvQv/ ;TyXINFt-/CeBIKnRw TyXINFt, _;TyXINFt-!fMKXQmXWrY._?.-TyXINFt;-;dQYt-_/_cMbbyvQv:,_-TyXINFt?/dQYt_"))