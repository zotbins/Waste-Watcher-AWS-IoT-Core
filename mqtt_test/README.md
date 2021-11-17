# MQTT Test Scripts

These Python scripts are used to make sure the Waste Watcher's MQTT messages are correct and valid.

## Setup

1. Create a Python virtual environment using the command
```bash
python -m venv venv
```

2. Activate your Python virtual environment using one of the following commands.

On Windows Powershell, use this command
```
venv\Scripts\activate.ps1
```
(If you use cmd, use the alternative ```activate.bat```)

On Mac/Linux, use this command
```bash
source venv/bin/activate
```
(If you use the csh or fish shells, there are alternate ```activate.csh``` and ```activate.fish``` scripts you should use instead.)

3. Install the dependencies using the command
```bash
pip install -r requirements.txt
```

4. Create an ```.env``` file using the ```.env.txt``` file as a template. Fill in the MQTT hostname and port number

## Running the Script
1. Run the Python script ```mqtt_sub.py``` to subscribe to the broker and incoming messages will be printed out to the console.
```bash
python mqtt_sub.py
```

2. Run the script ```mqtt_sub.py``` to send test messages to the broker
```bash
python mqtt_pub.py
```
