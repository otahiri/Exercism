def translate(text):
    if text[0] in "aeuio" or text.startswith("xr") or text.startswith("yt"):
        text += "ay"
        return text
    elif text[0] not in "auioe":
        lenght = len(text) - 1
        i = 0
        while text[i] not in "auioe":
            text[lenght], text[i] = text[i], text[lenght]
            lenght -= 1
            i += 1
        text += "ay"
        return text
    elif "qu" in text:
        lenght = len(text) - 1
        i = 0
        while text[i] not in "auioe":
            if text[i] == 'q' and text[i + 1] == 'u':
                text[i], text[i + 1], text[lenght], text[lenght -
                                                         1] = text[lenght], text[lenght - 1], text[i], text[i + 1]
                break
            text[len], text[i] = text[i], text[len]
            lenght -= 1
            i += 1
        text += "ay"
        return text
    elif "y" in text:
        lenght = len(text) - 1
        i = 0
        while text[i] not in "aiuoe":
            if text[i] == "y":
                text[i], text[lenght] = text[lenght], text[i]
                break
            text[lenght], text[i] = text[i], text[lenght]
            lenght -= 1
            i += 1
