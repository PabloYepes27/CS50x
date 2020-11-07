#!/usr/bin/python3


def count_letters(txt):
    i = 0
    l = 0.0
    for i in range(len(txt)):
        if ((txt[i] <= 'z' and txt[i] >= 'a') or (
             txt[i] <= 'Z' and txt[i] >= 'A')):
            l = l + 1
    return (l)


def count_words(txt):
    i = 0
    w = 0.0
    for i in range(len(txt)):
        if (txt[i] == ' '):
            w = w + 1
    w += 1
    return (w)


def count_sentences(txt):
    i = 0
    s = 0.0
    for i in range(len(txt)):
        if (txt[i] == '!' or txt[i] == '?' or txt[i] == '.'):
            s = s + 1
    return (s)

if __name__ == "__main__":
    text = input("Text: ")
    let = count_letters(text)
    print(let)
    wrd = count_words(text)
    print(wrd)
    stc = count_sentences(text)
    print(stc)
    l = (let * 100) / wrd
    print(l)
    s = (stc * 100) / wrd
    print(s)
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print("Grade {}".format(index))
