import pyautogui
import time
import os
import pyaudio
from abc import abstractmethod

class Joke:
    @abstractmethod
    def scherzo(self):
        pass
    wait_time = 0
TIMES = 0
class Google(Joke):
    def scherzo(self):
        os.system("start chrome")
        time.sleep(5)
        pyautogui.typewrite("youtube.com")
        pyautogui.press("enter")
        time.sleep(5)
        if TIMES == 0:
            pyautogui.click(x=335,y=418,clicks=1,interval=0.1,button='left')
            time.sleep(2)
        pyautogui.click(x=919,y=148,clicks=1,interval=0,button='left')
        pyautogui.typewrite("LO SCHIFO...ADESSO PARLO IO !!!",interval=0.1)
        pyautogui.press("enter")
        time.sleep(1)
        pyautogui.click(x=919,y=300,clicks=1,interval=0,button='left')
        pyautogui.press("f")
    wait_time = 12

class cmd(Joke):
    def scherzo(self):
        for a in range(11):
            os.system(r'echo "Forza Roma" ')
    wait_time = 2

class parrot(Joke):
    def scherzo(self):
        os.system('curl parrot.live')
        time.sleep(3)
        exit(0)
    wait_time = 5
class sium(Joke):
    def scherzo(self):
        os.system("start chrome")
        time.sleep(5)
        pyautogui.typewrite("youtube.com")
        pyautogui.press("enter")
        time.sleep(5)
        if TIMES == 0:
            pyautogui.click(x=335,y=418,clicks=1,interval=0.1,button='left')
            time.sleep(2)
        pyautogui.click(x=919,y=148,clicks=1,interval=0,button='left')
        pyautogui.typewrite("SIUUUUUUUU")
        pyautogui.press("enter")
        time.sleep(2)
        pyautogui.click(x=1200,y=148,clicks=1,interval=0,button='left')
        time.sleep(2)
        pyautogui.click(x=450,y=330,clicks=1,interval=0,button='left')
        time.sleep(3)
        pyautogui.click(x=1381,y=431,clicks=1,interval=1,button='left')
    wait_time = 19
class gerry_scotti(Joke):
    def scherzo(self):
        os.system("start chrome")
        time.sleep(4)
        pyautogui.typewrite("Gerry Scotti",interval=0.1)
        pyautogui.press('enter')
        time.sleep(3)
    wait_time = 9

class PING(Joke):
    def scherzo(self):
        os.system("color 2")
        os.system("PING pornhub.com")

Lista_scherzi = [Google(),gerry_scotti(),cmd(),sium(),parrot(),PING()]

for a in range(Lista_scherzi.__len__()+1):
    Lista_scherzi[a].scherzo()
    TIMES += 1
print("finito")

