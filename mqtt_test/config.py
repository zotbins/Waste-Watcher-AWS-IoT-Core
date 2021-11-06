import os
from dotenv import load_dotenv

load_dotenv()

MQTT_HOSTNAME = os.getenv("MQTT_HOSTNAME")
MQTT_PORT = int(os.getenv("MQTT_PORT"))
FULLNESS_PATH = os.getenv("FULLNESS_PATH")
PHOTO_PATH = os.getenv("PHOTO_PATH")

print("MQTT_HOSTNAME={}".format(MQTT_HOSTNAME))
print("MQTT_PORT={}".format(MQTT_PORT))
print("FULLNESS_PATH={}".format(FULLNESS_PATH))
print("PHOTO_PATH={}".format(PHOTO_PATH))
