# Phone Controlled Robotic Arm
I am working on an Arduino robot arm that is controlled by a smartphone app.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Michael Ding | Monta Vista High School | Computer Engineering | Incoming Senior

# Second Milestone

For this milestone, I have created a mobile app using the MIT App Inventor. I also connect my smartphone with an ESP32, a controller with built-in Wi-Fi and Bluetooth capabilities. After plugging the ESP32 into my computer and setting it up with the Arduino interface, I created a program that reads input from the app on my phone through Bluetooth.

![App Inventor 1](https://github.com/michaelding123/MichaelDing_BSE_Portfolio/blob/gh-pages/inventor.png)

I have designed the app to incorporate sliders for each servo motor on my robotic arm that I will eventually implement control for.
Right now, the servo number and angle or position values are being printed to the serial monitor. I have also included a drop-down menu for Bluetooth connections and an option to disconnect.

One issue that came up for me during this milestone was that the Arduino program implementing the ESP32 was not uploading. I eventually downloaded a separate driver for an additional COM6 port, as I figured that something was going wrong with the COM4 port that I had previously been using. After doing this, my program ran successfully.

[![Second Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1624562567/video_to_markdown/images/youtube--yFn0BqtVl9k-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/yFn0BqtVl9k "Second Milestone"){:target="_blank" rel="noopener"}

# First Milestone

![Circuit Diagram](https://github.com/michaelding123/MichaelDing_BSE_Portfolio/blob/gh-pages/Start%20Simulating.png)

My first milestone was assembling and controlling the robot arm using an Arduino. Each servo motor on the robotic arm is connected to a PWM spot on the Arduino, which allows multiple angles for my robotic arm, as well as to a power and ground spot on the breadboard. My code retrieves user input from the serial monitor, and prints it back in order to ensure that the text is being received. The numbers the user enters are then used to determine which servo motor to turn and which angle to turn to using if statements. One problem I faced was that the program simply stopped running after a short amount of time. My input was not getting relayed back, and the servos were not turning. Along with this, my computer would begin to make error noises. I resolved this issue by first running the program to only turn one motor to see if there was a problem with the code or any individual servo. After determining that nothing was wrong with the code or breadboard/wire setup, I found that it was an issue of power supply. I resolved this by plugging in a 9V battery into the Arduino.

[![First Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1624304570/video_to_markdown/images/youtube--3LwGtUkshe4-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=3LwGtUkshe4 "First Milestone"){:target="_blank" rel="noopener"}
