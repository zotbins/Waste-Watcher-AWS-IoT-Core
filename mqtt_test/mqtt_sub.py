from config import MQTT_HOSTNAME, MQTT_PORT, FULLNESS_PATH, PHOTO_PATH
import paho.mqtt.client as mqtt


def on_fullness_message(mos, obj, msg):
    fullness = float(msg.payload)
    print("Fullness = {}".format(fullness))


def on_photo_message(mos, obj, msg):
    photo = open("output.jpg", "wb")
    photo.write(msg.payload)
    photo.close()
    print("Image received")


if __name__ == "__main__":
    client = mqtt.Client()
    client.message_callback_add(FULLNESS_PATH, on_fullness_message)
    client.message_callback_add(PHOTO_PATH, on_photo_message)
    client.connect(MQTT_HOSTNAME, MQTT_PORT, 60)

    print("MQTT Connected")

    client.subscribe(FULLNESS_PATH)
    client.subscribe(PHOTO_PATH)

    client.loop_forever()
