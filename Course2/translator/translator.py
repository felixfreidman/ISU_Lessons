import requests
import json
import uuid

REGION = "westeurope"
API_KEY = "82e622ccc27b4ad0af0918182329a742"
URL = "https://api.cognitive.microsofttranslator.com/translate?api-version=3.0&to="
text = ""

with open("text.txt", encoding='utf-8') as f:
    while True:
        string = f.readline()[:-1]
        if not string:
            break
        text += string
f.close()

def translateText(lang_code):
    headers = {"Ocp-Apim-Subscription-Key": API_KEY,
               "Ocp-Apim-Subscription-Region": REGION,
               "Content-Type": "application/json"
               }
    body = [{
        'Text': text
    }]
    request = requests.post(URL + lang_code, headers=headers, data=json.dumps(body))
    response = request.json()
    return response

lang = input("Enter lang code: ")
translated = (translateText(lang))[0]['translations'][0]['text']
if (translated):
    with open('output lang=' + lang + '.txt', 'w', encoding='utf-8') as f:
        f.write(translated)
    f.close()
