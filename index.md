# Phone Controlled Robotic Arm
I am working on an Arduino robot arm that is controlled by a smartphone app.

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Michael Ding | Monta Vista High School | Electrical Engineering | Incoming Senior
  
# First Milestone

[![Circuit Diagram](https://github.com/michaelding123/MichaelDing_BSE_Portfolio/blob/gh-pages/Start%20Simulating.png)]

My first milestone was assembling and controlling the robot arm using an Arduino. Each servo motor on the robotic arm is connected to a PWM spot on the Arduino, which allows multiple angles for my robotic arm, as well as to a power and ground spot on the breadboard. My code retrieves user input from the serial monitor, and prints it back in order to ensure that the text is being received. The numbers the user enters are then used to determine which servo motor to turn and which angle to turn to using if statements. One problem I faced was that the program simply stopped running after a short amount of time. My input was not getting relayed back, and the servos were not turning. Along with this, my computer would begin to make error noises. I resolved this issue by first running the program to only turn one motor to see if there was a problem with the code or any individual servo. After determining that nothing was wrong with the code or breadboard/wire setup, I found that it was an issue of power supply. I resolved this my plugging in a 9V battery into the Arduino.

[![First Milestone](https://res.cloudinary.com/marcomontalbano/image/upload/v1624304570/video_to_markdown/images/youtube--3LwGtUkshe4-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=3LwGtUkshe4 "First Milestone"){:target="_blank" rel="noopener"}
