import speech_recognition as sr  # recognise speech
import playsound  # to play an audio file
from gtts import gTTS  # google text to speech
import random
from time import ctime  # get tm details
import webbrowser  # open browser
import ssl
import certifi
import time
import os  # to remove created audio files
from selenium import webdriver
import pyautogui

import subprocess
from pydub import AudioSegment
from pydub.playback import play


class person:
    name = ''

    def setName(self, name):
        self.name = name


def there_exists(terms):
    for term in terms:
        if term in voice_data:
            return True


r = sr.Recognizer()  # initialise a recogniser
r.energy_threshold = 800



# listen for audio and convert it to text:
def record_audio(ask=False):
    with sr.Microphone() as source:  # microphone as source
        if ask:
            speak(ask)
        audio = r.record(source, duration=5)  # listen for the audio via source
        voice_data = ''
        try:
            voice_data = r.recognize_google(audio, language="en-UK")  # convert audio to text
        except sr.UnknownValueError:  # error: recognizer does not understand
            speak('I did not get that')
        except sr.RequestError:
            speak('Sorry, the service is down')  # error: recognizer is not connected
        print(f">> {voice_data.lower()}")  # print what user said
        return voice_data.lower()


def speak(audio_string):
    audio_string = str(audio_string)
    name = "temp"
    roz = ".mp3"
    filename = name + roz

    tts = gTTS(text=audio_string, lang='en')
    tts.save(filename)

    subprocess.call(['ffmpeg', '-i', filename, name + '.wav'])

    sound = AudioSegment.from_wav(name + '.wav')
    play(sound)
    os.remove(filename)
    os.remove(name + '.wav')


def respond(voice_data):
    speak('How can I help you?')
    # 1: pogoda
    if there_exists(['weather for']):
        search_term = voice_data.split("for")[-1]
        url = f"https://www.google.com/search?q=weather+{search_term}"
        webbrowser.get().open(url)
        speak(f'Here is the weather for {search_term}')

    # 2: imie
    if there_exists(["what's your name", "tell me your name", "what is your name"]):
            speak("my name is... well... I don't know")

    # 2: wiek
    if there_exists(["what's your age", "how old are you"]):
        speak("i'm 22")


    # 3: longman
    if there_exists(["explain what is"]):
        text= voice_data.split("is")[-1]
        text=text[1:]
        print(text)
        driver = webdriver.Firefox(executable_path=r'geckodriver')
        link = "https://www.ldoceonline.com/dictionary/"+text
        driver.get(link)
        time.sleep(1)
        driver.find_element_by_id('onetrust-accept-btn-handler').click()
        element = driver.find_element_by_xpath("//span[@class='DEF']");
        print(element.text)
        speak(element.text)
        time.sleep(5)
        pyautogui.hotkey('alt', 'f4')

    # 5: search bing
    if there_exists(["search for"]):
        search_term = voice_data.split("for")[-1]
        url = f"https://www.bing.com/search?q={search_term}"
        webbrowser.get().open(url)
        speak(f'Here is what I found for {search_term} on bing')

    #6: pozegnanie
    if there_exists(["exit", "quit", "goodbye", "thank you", "thanks"]):
        speak("bye, have a nice day")
        exit()


time.sleep(1)

person_obj = person()
while (1):
    voice_data = record_audio()  # get the voice input
    respond(voice_data)  # respond


