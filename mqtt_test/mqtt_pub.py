from config import MQTT_HOSTNAME, MQTT_PORT, FULLNESS_PATH, PHOTO_PATH
import paho.mqtt.publish as publish


if __name__ == "__main__":
    # Send fullness msg
    publish.single(
        topic=FULLNESS_PATH,
        payload=50,
        hostname=MQTT_HOSTNAME,
        port=MQTT_PORT,
    )
    print("Fullness msg sent")

    # Send photo msg
    photo = open("test_image.jpg", "rb")
    photoContent = photo.read()
    photo.close()
    photoByteArr = bytearray(photoContent)
    publish.single(
        topic=PHOTO_PATH,
        payload=photoByteArr,
        hostname=MQTT_HOSTNAME,
        port=MQTT_PORT,
    )
    print("Photo message sent")
