import RPi.GPIO as GPIO
import time
from timeit import timeit  

PIN_NO = 17

def beep(seconds):
    GPIO.output(PIN_NO, True)
    time.sleep(seconds)
    GPIO.output(PIN_NO, False)

def beepAction(secs, sleepsecs, times):
    for i in range(times):
        beep(secs)
        time.sleep(sleepsecs)

def checkdist1():
        GPIO.output(TRIG1, GPIO.HIGH)
        time.sleep(0.000015)
        GPIO.output(TRIG1, GPIO.LOW)
        while not GPIO.input(ECHO1):
                pass
        t1 = time.time()
        while GPIO.input(ECHO1):
                pass
        t2 = time.time()
        return (t2-t1)*340/2

def checkdist2():
        GPIO.output(TRIG2, GPIO.HIGH)
        time.sleep(0.000015)
        GPIO.output(TRIG2, GPIO.LOW)
        while not GPIO.input(ECHO2):
                pass
        t1 = time.time()
        while GPIO.input(ECHO2):
                pass
        t2 = time.time()
        return (t2-t1)*340/2

def checkdist3():
        GPIO.output(TRIG3, GPIO.HIGH)
        time.sleep(0.000015)
        GPIO.output(TRIG3, GPIO.LOW)
        while not GPIO.input(ECHO3):
                pass
        t1 = time.time()
        while GPIO.input(ECHO3):
                pass
        t2 = time.time()
        return (t2-t1)*340/2

GPIO.setmode(GPIO.BCM)

TRIG1 = 2
ECHO1 = 3

TRIG2 =5
ECHO2 =6

TRIG3 =16
ECHO3 =20

# if ():
GPIO.setup(PIN_NO, GPIO.OUT)

GPIO.setup(TRIG1, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ECHO1, GPIO.IN)

GPIO.setup(TRIG2, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ECHO2, GPIO.IN)

GPIO.setup(TRIG3, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(ECHO3, GPIO.IN)

time.sleep(2)
m1,m2,m3=0,0,0

timesetup=0
beepAction(0.5,0.5,3)
beep(2)
time_start=time.time()
try:
	while True:
			print("Distance1: {:.2f} m Distance2:{:.2f} m Distance3: {:.2f} m".format(checkdist1(),checkdist2(),checkdist3()))
			t1 = checkdist1()
			t2 = checkdist2()
			t3 = checkdist3()

			if (t1 > 0.20 and t1 < 0.30):
					m1=1
			if (t2 > 0.20 and t2 < 0.30):
					m2=1
			if (t3 > 0.20 and t3 < 0.30):
					m3=1
			if (m3==1 or m1==1  or m2==1):  
					print("hit")
					beepAction(0.1, 0.1, 5)
					m1,m2,m3=0,0,0
					continue
			if (timesetup>3): 
					time_end=time.time()
					break
			else:
					timesetup = timesetup+1  

			time.sleep(0.5)
			times=times+1
	print('time cost{:.2f}'.format(time_end-time_start),'s')
                
except KeyboardInterrupt:
        GPIO.cleanup()


