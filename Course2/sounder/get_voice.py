import requests
import wave

key = "be5f4c47488e4d349dbb06b527492c7c"
auth_url = "https://francecentral.api.cognitive.microsoft.com/sts/v1.0/issueToken"
lang_url = "https://francecentral.tts.speech.microsoft.com/cognitiveservices/voices/list"
auth_headers = { "Ocp-Apim-Subscription-Key": key, \
                 "Content-Length": "0", \
                 "Content-type": "application/x-www-form-urlencoded" }

auth_response = requests.post(auth_url, headers=auth_headers)
token = auth_response.text

print("Token:")
print(token)

lang_headers= { "Authorization": "Bearer " + token }
lang_response = requests.get(lang_url, headers=lang_headers)
json_langs = lang_response.json()

print(json_langs)

filename = "text.txt"

print()
print("Params:")
lang = 'en-US'
gender = "Female"
name = "en-US-AriaRUS"
output_format = "riff-24khz-16bit-mono-pcm"
print("lang:\t\t", lang)
print("gender:\t", gender)
print("name:\t\t", name)
text_length = 0

xml_request = None
with open(filename) as file:
    text = file.read()
    text_length = len(text.replace(' ', '').replace('\n', ''))
    xml_request = "<speak version='1.0' xml:lang='{}'><voice xml:lang='{}' xml:gender='{}' name='{}'>{}</voice></speak>".format(lang, lang, gender, name, text)
        
headers = {
    "Authorization": "Bearer " + token,
    "X-Microsoft-OutputFormat": output_format,
    "Content-Type": "application/ssml+xml",
    "User-Agent": "Pam"
}

url = "https://francecentral.tts.speech.microsoft.com/cognitiveservices/v1"
response = requests.post(url, headers=headers, data=xml_request)

output = "voiced_text.wav"

with open(output, 'wb') as file:
    file.write(response.content)


# Задание на доп баллы
'''
wav_file = wave.open(output, "rb")

duration = wav_file.getnframes() / wav_file.getframerate()
print(20*'=')
print()
print("File duration:\t\t", duration)
print("Text length:\t\t", text_length)
print("Symbol duration:\t", duration/text_length)

'''
