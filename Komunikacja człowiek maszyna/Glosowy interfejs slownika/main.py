#KCM 4 z 5
#Mikołaj Stefaniszyn, nr. ind 46651, gr. 311

import os
from gtts import gTTS
import playsound
from googletrans import Translator
import speech_recognition as sr
import pyautogui
import time
from selenium import webdriver


def powiedz(text):
    tts = gTTS(text=text, lang='en-UK')
    filename = "voicePl.mp3"
    tts.save(filename)
    playsound.playsound(filename)
    os.remove(filename)

r= sr.Recognizer()
r.energy_threshold = 800



with sr.Microphone() as source:
    audio_data = r.record(source, duration=3)
    text = r.recognize_google(audio_data, language="en-UK")
    print(text)

driver = webdriver.Firefox(executable_path=r'geckodriver')

link="https://www.ldoceonline.com/dictionary/"+text

driver.get(link)

page_title = driver.title
print(page_title)

time.sleep(1)
driver.find_element_by_id('onetrust-accept-btn-handler').click()

element=driver.find_element_by_xpath("//span[@class='DEF']");
print(element.text)

powiedz(element.text)
time.sleep(5)
pyautogui.hotkey('alt','f4')

